#include <Servo.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include "driver/i2s.h"
#include "esp_heap_caps.h"

Servo servo1;
Servo servo2;

#define SERVO1_PIN 5
#define SERVO2_PIN 6

#define TOUCH_SENSOR 4

bool systemON = false;
bool lastTouch = LOW;

#define I2S_BCLK_MIC 18
#define I2S_LRC_MIC 17
#define I2S_DIN_MIC 15

#define I2S_BCLK_SPK 3
#define I2S_LRC_SPK 7
#define I2S_DOUT_SPK 16
#define I2S_SD_SPK 46

#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8
#define TFT_MOSI 11
#define TFT_SCLK 12

Adafruit_ST7789 tft = Adafruit_ST7789(
    TFT_CS,
    TFT_DC,
    TFT_RST);

#define SAMPLE_RATE 16000
#define RECORD_TIME 5

#define AUDIO_SIZE \
    (SAMPLE_RATE * RECORD_TIME * sizeof(int16_t))

int16_t *audioBuffer = NULL;

unsigned long lastServoMove = 0;
bool servoPosition = false;

void setup()
{

    Serial.begin(115200);

    servo1.attach(SERVO1_PIN);
    servo2.attach(SERVO2_PIN);

    servo1.write(90);
    servo2.write(90);

    pinMode(TOUCH_SENSOR, INPUT);

    pinMode(I2S_SD_SPK, OUTPUT);
    digitalWrite(I2S_SD_SPK, LOW);

    SPI.begin(
        TFT_SCLK,
        -1,
        TFT_MOSI,
        TFT_CS);

    tft.init(240, 320);
    tft.setRotation(3);

    tft.fillScreen(ST77XX_BLUE);

    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(2);

    tft.setCursor(20, 40);
    tft.println("M-O ROBOT");

    tft.setTextSize(1);
    tft.setCursor(20, 80);
    tft.println("Touch sensor to START");

    if (!psramFound())
    {

        tft.fillScreen(ST77XX_RED);

        tft.setTextColor(ST77XX_WHITE);
        tft.setTextSize(2);

        tft.setCursor(20, 50);
        tft.println("PSRAM ERROR");

        Serial.println("PSRAM ERROR");

        while (1)
            ;
    }

    i2s_config_t micConfig = {

        .mode = (i2s_mode_t)(I2S_MODE_MASTER |
                             I2S_MODE_RX),

        .sample_rate = SAMPLE_RATE,

        .bits_per_sample =
            I2S_BITS_PER_SAMPLE_16BIT,

        .channel_format =
            I2S_CHANNEL_FMT_ONLY_LEFT,

        .communication_format =
            I2S_COMM_FORMAT_STAND_I2S,

        .intr_alloc_flags = 0,

        .dma_buf_count = 8,

        .dma_buf_len = 1024,

        .use_apll = false,

        .tx_desc_auto_clear = false,

        .fixed_mclk = 0};

    i2s_pin_config_t micPins = {

        .bck_io_num = I2S_BCLK_MIC,

        .ws_io_num = I2S_LRC_MIC,

        .data_out_num =
            I2S_PIN_NO_CHANGE,

        .data_in_num = I2S_DIN_MIC};

    i2s_driver_install(
        I2S_NUM_0,
        &micConfig,
        0,
        NULL);

    i2s_set_pin(
        I2S_NUM_0,
        &micPins);

    i2s_config_t speakerConfig = {

        .mode = (i2s_mode_t)(I2S_MODE_MASTER |
                             I2S_MODE_TX),

        .sample_rate = SAMPLE_RATE,

        .bits_per_sample =
            I2S_BITS_PER_SAMPLE_16BIT,

        .channel_format =
            I2S_CHANNEL_FMT_ONLY_LEFT,

        .communication_format =
            I2S_COMM_FORMAT_STAND_I2S,

        .intr_alloc_flags = 0,

        .dma_buf_count = 8,

        .dma_buf_len = 1024,

        .use_apll = false,

        .tx_desc_auto_clear = true,

        .fixed_mclk = 0};

    i2s_pin_config_t speakerPins = {

        .bck_io_num = I2S_BCLK_SPK,

        .ws_io_num = I2S_LRC_SPK,

        .data_out_num = I2S_DOUT_SPK,

        .data_in_num =
            I2S_PIN_NO_CHANGE};

    i2s_driver_install(
        I2S_NUM_1,
        &speakerConfig,
        0,
        NULL);

    i2s_set_pin(
        I2S_NUM_1,
        &speakerPins);

    Serial.println("M-O system ready");
}

void loop()
{

    bool touch = digitalRead(TOUCH_SENSOR);

    if (touch == HIGH && lastTouch == LOW)
    {

        systemON = !systemON;

        delay(300);

        if (systemON)
        {

            digitalWrite(I2S_SD_SPK, HIGH);

            tft.fillScreen(ST77XX_GREEN);

            tft.setTextColor(ST77XX_BLACK);
            tft.setTextSize(2);

            tft.setCursor(30, 50);
            tft.println("M-O ON");

            tft.setTextSize(1);
            tft.setCursor(30, 90);
            tft.println("Touch again to OFF");

            Serial.println("SYSTEM ON");
        }
        else
        {

            digitalWrite(I2S_SD_SPK, LOW);

            tft.fillScreen(ST77XX_BLUE);

            tft.setTextColor(ST77XX_WHITE);
            tft.setTextSize(2);

            tft.setCursor(30, 50);
            tft.println("M-O OFF");

            Serial.println("SYSTEM OFF");
        }
    }

    lastTouch = touch;

    if (!systemON)
    {
        return;
    }

    if (millis() - lastServoMove >= 10000)
    {

        lastServoMove = millis();

        if (!servoPosition)
        {

            servo1.write(40);
            servo2.write(140);

            Serial.println("Arms position 1");
        }
        else
        {

            servo1.write(140);
            servo2.write(40);

            Serial.println("Arms position 2");
        }

        servoPosition = !servoPosition;
    }

    if (touch == HIGH)
    {

        delay(300);

        recordAndPlay();

        while (digitalRead(TOUCH_SENSOR) == HIGH)
        {
            delay(10);
        }
    }
}

void recordAndPlay()
{

    audioBuffer =
        (int16_t *)heap_caps_malloc(
            AUDIO_SIZE,
            MALLOC_CAP_SPIRAM);

    if (audioBuffer == NULL)
    {

        Serial.println("Memory error");

        tft.fillScreen(ST77XX_RED);

        tft.setTextColor(ST77XX_WHITE);
        tft.setTextSize(2);

        tft.setCursor(20, 50);
        tft.println("MEMORY ERROR");

        return;
    }

    tft.fillScreen(ST77XX_RED);

    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(2);

    tft.setCursor(30, 50);
    tft.println("LISTENING");

    tft.setTextSize(1);

    tft.setCursor(30, 90);
    tft.println("Speak now...");

    Serial.println("Recording...");

    size_t bytesRead = 0;

    i2s_read(
        I2S_NUM_0,
        audioBuffer,
        AUDIO_SIZE,
        &bytesRead,
        portMAX_DELAY);

    tft.fillScreen(ST77XX_GREEN);

    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(2);

    tft.setCursor(30, 50);
    tft.println("PLAYING");

    Serial.println("Playing...");

    digitalWrite(I2S_SD_SPK, HIGH);

    size_t bytesWritten = 0;

    i2s_write(
        I2S_NUM_1,
        audioBuffer,
        bytesRead,
        &bytesWritten,
        portMAX_DELAY);

    free(audioBuffer);

    audioBuffer = NULL;

    Serial.println("Audio finished");

    tft.fillScreen(ST77XX_BLUE);

    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(2);

    tft.setCursor(30, 50);
    tft.println("M-O ON");

    tft.setTextSize(1);

    tft.setCursor(30, 90);
    tft.println("Touch to record");
}