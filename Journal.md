author: Youssef Ayman Mohamed

description: M-O-Y is an abbreviation for Microbe-Obliterator For Youssef.in other words its is Virtual colleague compannion on my desk customized for me.Can answer i ask him abut weather , latest news, movies.it not just ai agent,but it interactive colleague react with mu during dancing or working lockin.I powered by esp32 S3 It is originated from the M-O cleaning robot form Wall-E movie,with his funny character and decipline to clean.It has vioce and make can hear me.


 
created_at: "2026-08-10"

## Entry 1 
created at:2026-8-10

### Content 
During this session i worked mainly on searching for components and worflow,Firsly,i decided to make my desk robot on shape of M-O robot in Wall -e,then i started searching for componets ,i used esp s3 as MCU,then i watched vidoe about desk robot componets,then i searched for audio and MIc .after that i decided to use 2 servo motors for movement.

<img width="300" height="346" alt="image" src="https://github.com/user-attachments/assets/246e75ab-f986-4d7e-a3b6-40217ecd65be" />

then,i worked on power managemnt,i decided to use 2 lithium batteries,and connect them to BMS protection board and battery charger.then using stepdown to 5v
finally,i searched for suitable tft screen for robot face.
<img width="792" height="405" alt="Screenshot 2026-09-09 230737" src="https://github.com/user-attachments/assets/d824a2d9-3ad9-4d43-8bc4-65949742a8ce" />

### Recording (27 min) :
https://lapse.hackclub.com/timelapse/0pda_EBY_YpM

## Entry 2
created at:2026-8-10

### Content 
During this session ,i workd mainly on schematic,firstly,i added esp s3 ,then i sketched rectangles for each part in circuit to organize schematic.After that i found most of componets deosnot have sybmol on kicad.So i created new library,then i searched for pinout for max91 amplifier and MIC then i make sybmol for them and sybmol +ve and -ve pins input for speaker and touch sensor , then i searched fro BMS module and charger pins and made them,after that i searched alot for stepdown footprint and found one,then i searched for its 3d model on crabcad,then i made symbol for it.Last things,i made symbol for tft screen display.

<img width="433" height="332" alt="Screenshot 2026-09-14 145925" src="https://github.com/user-attachments/assets/8d7608f2-fad4-4ede-97da-c84f4ac98557" />
<img width="649" height="408" alt="Screenshot 2026-09-14 145931" src="https://github.com/user-attachments/assets/8cc875c2-6073-4cec-908e-2f455d6a048c" />
<img width="367" height="376" alt="Screenshot 2026-09-14 145955" src="https://github.com/user-attachments/assets/61474e4d-e808-4533-933b-fdbd9c0649b8" />
<img width="526" height="634" alt="Screenshot 2026-09-14 145937" src="https://github.com/user-attachments/assets/a1adc925-4f4d-400b-9add-c920a19d965f" />
<img width="438" height="217" alt="Screenshot 2026-09-14 145944" src="https://github.com/user-attachments/assets/df3b3a99-5479-4636-96e4-bdf4d1db9787" />

Secondly,I watch videos about connectino of max19 amiplifer ,Mic,touch sensor and tft screen with esp 32 ,then i started routing them ,after that i added 2 servo motors and connect them direct to esp.After that,i worked on BMS board , connecting batteries in parallel,then to BMS and battery charger.After that to stepdown to 5v ,but i found tft need 3v ,so i seacrhed for voltage regulator to 3.3 v and added it to schematic.

Thirdly,i added pin header on pcb where componets will wired using jumpers,the i routed them with MCU,after that i organized schematic more,adding description,and sketch worflow diagram of power cycle for batteries to esp and componets.then i assigned footprints to each part.but i found 3d models for esp and stepdown failed to uppload so i added them manually.
<img width="500" height="466" alt="Screenshot 2026-09-14 145952" src="https://github.com/user-attachments/assets/f7c3ac4a-126d-4d25-9170-f5cc358ca561" />
<img width="845" height="261" alt="Screenshot 2026-09-14 145753" src="https://github.com/user-attachments/assets/6398a7de-03df-49a3-95b1-aa827916f022" />
<img width="352" height="250" alt="Screenshot 2026-09-14 145747" src="https://github.com/user-attachments/assets/64b5e8ae-cb4e-41df-aab2-f7a2b9ead648" />
<img width="560" height="351" alt="Screenshot 2026-09-14 145743" src="https://github.com/user-attachments/assets/1a843d63-8143-4506-8961-473c0f161bef" />

### Recording (2 hour & 6 min) :
https://lapse.hackclub.com/timelapse/sBWthzzsaIdN

## Entry 3
created at:2026-8-11

### Content 
During this session , i worked on PCB,firstly,i draw pcb edges  in rectangular shape and circle in the middle for holder.then,i started routing pinheaders with ESP.i rerouted some parts multiple time to avoid overlapping and make PCB shape goood.
After that,i started routing stepdown and power parts,i found voltage regulator was connectin wrong on schematic ,so i edit it ,then i added copper layer on the top for vcc and another on on the back for GND.
Finally,i searched for HC stickers and added one to PCB and signed my name,then i export .step file and gerbers.
<img width="1056" height="694" alt="Screenshot 2026-09-14 143955" src="https://github.com/user-attachments/assets/fdfd83e2-1be0-45b3-97e8-5d7c41ca6be2" />
<img width="1141" height="819" alt="Screenshot 2026-09-14 143949" src="https://github.com/user-attachments/assets/ee73dee9-9c94-461c-b600-e89310167f6c" />
<img width="590" height="388" alt="Screenshot 2026-09-14 143940" src="https://github.com/user-attachments/assets/8a88739c-bb34-4dac-b184-448c8f363a18" />

### Recording (27 min) :
https://lapse.hackclub.com/timelapse/CuC4dDIBFFFC

## Entry 5
created at:2026-8-11

### Content 

Firstly,i searched for 3d models on grabcad for max amplifier , MIC , BMS , charger module, stepdown  ,battiers and their holders.After that,i uploaded pcb to fusion then,added manully stepdown 3d model again,the project it dimensions in dxf file.After that ,i sketch base circle for PCb and power management.
then i extruded i this circle ,and added power part and audio amplifier ,then i adjusted base dimension on them after mutiple tries of polishing.then i offset this circ and extrude the offset with height double base ,so cover will be in.then,i added batteries holder after adding 2 lituam batteries to it.
<img width="1318" height="682" alt="Screenshot 2026-09-15 024403" src="https://github.com/user-attachments/assets/29a78855-91e0-4a35-bd75-58519dd89c0f" />

After that,i sketched circular columns with offset smaller than columns height,where pcb will be holded on ,and buy using section analysis,i adjust pcb position on the base.then i construct 2 circles  one bigger that another making for concave shape ,then i used loft shape ,and by changing heigt of small circle of type of loft using section analysis to avoide interaction with circuit componets and cover all the base with min height.After muliple tries i made ,as my first time using loft i reach best shape and heigth.
then ,i cut hole on the top on the cover where jumpers and wires will be in

finally,i sketched robot body then extrude it,after that i made chamber inside it ,but,i found it was to big compare with image so i reduced it dimensions more,after that ,  searched for M-O full 3d model on crab cad to get from it arms.

### Recording (1 h && 44 min) :

https://lapse.hackclub.com/timelapse/eAX-vrbeMfxc

## Entry 6
created at:2026-8-12

### Content 
During this session , i worked mainly on moving parts,Firstly,i edit on main body dimensions reduce it,to be suitable for space on my desk and hands of robot,then i add roller from M-O robot,then i scaled it on y axis to increase it length to reach 2 end of body ,then i added arms ,and align them with roller and motors for felixbale movement.
After that,i wann make holder picece that hold 2 servo and is settled and joined to extruding hanging in main body like lego,so i contruct on inner body and make the hanging part on two sides ,then extrude them.

After that,i record servo dimensions,then i sketch rectangle part with circle hole in the middle,after that i add fillset,but romved it later,then i project servo on this peice the extrude this edges for holding servo with serwes in the edges.then,i removed the hole in the middle and replace it with 2 big and small circle connected by loft making like hanging or joint for coloumn of the head.then i reedit on it dimensions from beginng as found it was wrong,then i added in the back extrudtion in shape of rectangle to be joint in hanging in the body.

<img width="761" height="602" alt="Screenshot 2026-09-15 062142" src="https://github.com/user-attachments/assets/8a92bd20-6963-4aad-a4bf-f26ccf09cfcf" />

### Recording (1 h & 27 min) :

https://lapse.hackclub.com/timelapse/VlEdoGxMToQe

## Entry 7
created at:2026-8-13

### Content 
firslty,i continued polishing and editing on motors holder,I tried to work on joing holder in body like lego cube,then i contined editiing on it dimensions and positions to align with 2 joints in the body,I use section analysis to align them together.after various tries ,they join togehter ,then i cut hole in the side of robot for servo opening with arms.
<img width="727" height="527" alt="Screenshot 2026-09-15 062201" src="https://github.com/user-attachments/assets/faa45bea-8656-44e1-94ed-30ff62c6f940" />
<img width="583" height="625" alt="Screenshot 2026-09-15 062124" src="https://github.com/user-attachments/assets/666d0e25-e3e8-4f44-a2ee-97ebeed3d360" />

After that,i searched for 4 ohm speaker 3d model,then i assembled it with main body from back,after that , i project it dimesions,then cut part for speakers only.then extrude inner columns to hold speaker through moutning holes.

After that,i tried to take head from M-O  crabcad version,but i found i can't edit on it efficietly and cut inside it,so i decided to make head ,i tried to make one with big and small rectangle using loft tool,but after assemblt it with main body i found it no suitable,so i decided to increse number of sketches to give me head shape and polished curved one.

I sketched 4 rectangles withh specife space between them start from bigger one in dimensions to least one,then used loft ,but i tried to construct chamber it all loft but i can not,so i made chamber between two sketched then connect the next one till end,froming curved polihed head with free space inside.

After that,i opened circular hole in the head for wires and connetino columns with the body,then i assebled head with main body,and extrude column from the head to motor holder and used section analysis to join them togther like lego.after that,i added tft screen to assebmly in the head,then cut part from head show screen only and extrude circular columns to hold it from mouting holes.
<img width="561" height="712" alt="Screenshot 2026-09-15 062311" src="https://github.com/user-attachments/assets/1dfc9005-56fc-4ad7-affa-0c50853832c5" />

### Recording (2 h & 3 min) :

https://lapse.hackclub.com/timelapse/6rtRAi-SotMc
https://lapse.hackclub.com/timelapse/jW-a1tJhF879

## Entry 8
created at:2026-8-14

### Content 
During this session ,i worked on finishing head and rendering,first i sketch rectangular on/off box and extrude it,then i checked it  aligment wih robot head.after that i project touch sensor on it ,then cut hole for sensor part.then i extrude holders for mounting holes in the sensors and align it with section analysis.
After that,i started rendering robot based on its colour in the movie,then i made changes to it arm colour in black and white.then i signed robot name on head and extrude it.
Then ,i extrude columns holders for stepdown, BMS , charger,MAx amplifier ,sketching their moutning holes ,the extrude them,then used section analysis to align them over holders.finally,i cut hole from the bottom of the base and rectangular part ,where plug for chargin module will be setlled in .

After that,i worked on head
<img width="1120" height="744" alt="Screenshot 2026-09-15 024259" src="https://github.com/user-attachments/assets/242f2777-4053-4cb3-a33e-7d49a4062575" />

Finally,i worked on BOM, searching for component prices in egypt then convert it to usd,and uploaded PCB gerbers to JLCPCB

<img width="667" height="530" alt="Screenshot 2026-09-15 023728" src="https://github.com/user-attachments/assets/ef124d1e-72e1-4475-b43a-ae77de8c0565" />

### Recording (47 min) :
https://lapse.hackclub.com/timelapse/OG2kiaZDmdEX
https://lapse.hackclub.com/timelapse/LKEx2WzyLZDa
https://lapse.hackclub.com/timelapse/AStCnOR_yT7o


