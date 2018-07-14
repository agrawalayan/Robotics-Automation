#include <Dynamotor.h>  //include this library in Library folder of arduino. The H file is provided along with the code in the 'SCARA' folder  
#include <Servo.h>      // for crankshaft, roll and gripper servo motors
#include <SoftwareSerial.h> // software serial communication is used for communicating with the python

//all the parameters
Dynamotor motor1(0x01,0xFF, 0x01);
Dynamotor motor2(0x02,0xFD, 0x07);
SoftwareSerial mySerial(3, 6); // 3-> RX, 6->TX
Servo myservo5,myservo9,myservo11;  //initialize servo parameters   //connection done at pin 5,9,11 of arduino UNO
byte servoID, posl,posh,movspdl, movspdh;   //initilize dynamixel motor parameters
//storage of the hex values of the motors to reach the desired position
byte baseh[70];   //higher value of base motor
byte linkh[70];   //higher value of link motor
byte basel[70];   //lower value of base motor
byte linkl[70];   //lower value of link motor 
int m; //m used for mode selection in while loop initialization
char mode;  // mode selection received from python
//setup mode variables
int si[2]={};
int ssi;
//testing mode variables
int ti[2]={};
int tti;
//user mode variables
int ri[2]={};
int rri;
//placing blocks back to original position variables
int di[2]={};
int ddi;

char back;
int bck;
char test;
int k;
char check;
  
  

//setup of the controller
void setup() {
  Serial.begin(57600);  //baud rate for dynamixel motor
  mySerial.begin(9600); // baud rate for communicating with python
  pinMode(2,OUTPUT);     //for dynamixel motor-----PIN 2-> LOW for sending packets to motor; PIN 2-> HIGH for receiving packets from motor
  myservo11.attach(11); //for roll motor
  myservo9.attach(9);  //for gripper
  myservo5.attach(5);    //for crank shaft  

  //Make an array of all the blocks position with higher byte and lower byte for both motor i.e. 4 arrays
 
  m=1;
}


void loop(){
  
  //              a1,  a2,  a3,  b1,  b2,  b3,  c1,  c2,  c3,  d1,  d2,  d3,  e1,  e2,  e3,  f1,  f2,  f3,  g1,  g2,  g3,  h1,  h2,  h3,  i1,  i2,  i3,  j1,  j2,  j3,  k1,  k2,  k3,  l1,  l2,  l3,  m1,  m2,  m3,  n1,  n2,  n3,  o1,  o2,  o3,  p1,  p2,  p3,  q1,  q2,  q3,  r1,  r2,  r3,  s1,  s2,  s3,  t1,  t2,  t3,  u1,  u2,  u3,  V1, V2,  W1,  X1,  Y1, Y2,  Z1   
  byte baseh[]={0x0E,0x02,0x00,0x01,0x0D,0x01,0x0B,0x0C,0x04,0x03,0x0B,0x0B,0x0D,0x01,0x0D,0x0F,0x03,0x01,0x04,0x0D,0x02,0x03,0x01,0x00,0x05,0x02,0x0E,0x02,0x0C,0x0C,0x0B,0x04,0x03,0x04,0x0B,0x00,0x0B,0x0B,0x0A,0x0F,0x03,0x04,0x02,0x04,0x0C,0x0D,0x01,0x0C,0x03,0x0B,0x03,0x02,0x0A,0x00,0x0E,0x0D,0x02,0x0D,0x05,0x0F,0x0A,0x0C,0x05,0x03,0x0,0x0E,0x0D,0x0F,0x0,0x0E};
  byte basel[]={0x6D,0x38,0xAA,0x8D,0xC2,0x77,0x51,0xA6,0x70,0x1B,0xC3,0xA1,0x51,0x54,0xC2,0xA0,0x5A,0xFF,0xE2,0x89,0x5A,0x8D,0xC6,0x4F,0x1A,0xA9,0xDE,0xEE,0x35,0x84,0xFC,0x37,0x76,0x59,0xFC,0xAA,0xAa,0x51,0xE0,0x50,0xFE,0xA9,0xE2,0xA9,0xDF,0x18,0x1C,0x6D,0xFE,0x18,0xC5,0x38,0xA7,0x5A,0x83,0xFB,0xE2,0x18,0x53,0xAB,0x35,0xA6,0x35,0x5A,0x0,0xA6,0xA0,0x50,0x0,0x34};
  byte linkh[]={0x05,0x07,0x0A,0x0A,0x07,0x0D,0x04,0x05,0x07,0x07,0x05,0x02,0x07,0x0B,0x04,0x02,0x0B,0x0A,0x07,0x05,0x0D,0x07,0x0B,0x02,0x0B,0x07,0x05,0x02,0x05,0x02,0x07,0x0A,0x0D,0x0D,0x04,0x0A,0x07,0x05,0x04,0x04,0x07,0x0A,0x0B,0x0B,0x07,0x05,0x0A,0x07,0x0B,0x07,0x0A,0x0B,0x07,0x0D,0x02,0x05,0x0A,0x04,0x07,0x0D,0x07,0x04,0x07,0x0A,0x0,0x04,0x02,0x05,0x0,0x04};
  byte linkl[]={0x53,0xFD,0xA7,0xA7,0xFD,0x7E,0x70,0x53,0xFD,0xFD,0x53,0x7C,0xFD,0x8A,0x70,0x7C,0x8A,0xA7,0xFD,0x53,0x7E,0xFD,0x8A,0x7C,0x8A,0xFD,0x53,0x6D,0x53,0x7C,0xFD,0xA7,0x7E,0x7E,0x70,0xA7,0xFD,0x53,0x70,0x70,0xFD,0xA7,0x8A,0x8A,0xFD,0x53,0xA7,0xFD,0x8A,0xFD,0xA7,0x8A,0xFD,0x7E,0x7C,0x53,0xA7,0x70,0xFD,0x7E,0xFD,0x70,0xFD,0xA7,0x0,0x70,0x7C,0x53,0x0,0x70};

  Serial.println(" Mode selection or power is switched ON ");
  //crankshaft motors in their reset position                 
  myservo5.write(30);               
  delay(2000); 
  myservo9.write(160); 
  delay(200); 
  myservo11.write(45);   //roll angle
  delay(200); 
  
  while(m==1){
   mode=mySerial.read();
   //Using serial communication receive alphabet to decide which mode (i.e s for setup, t for testing, d for reset position, r to start operation)
      while(mode!='s' && mode!='t'&& mode!='d'&& mode!='r'){      
        mode=mySerial.read();
      }
   m=0;
   mySerial.flush();
   Serial.println("Mode is set");
  }
  m=1;
  //mySerial.println(mode);
  
  if(mode=='t'){
    
    Serial.println("Enter in testing mode");
    bck = 2;
    //receive which motor to test and perform that action
    while(bck == 2){
    Serial.println("waiting for pyhon to send");
    while(mySerial.available()==0){
    }
    test=mySerial.read();
    //b= base motor; l= link motor; k=crankshaft motor; g= grippr motor; m=camera;w= back
    while(test!='b' && test!='l'&& test!='k' && test!= 'w'){      
      test=mySerial.read();
     }
    mySerial.flush();
    
    if ( test=='b'){
      motor2.activateServos(0x02, 0xFD, 0x07);
      delay(250);
      motor1.activateServos(0x01, 0xFF, 0x01);
      delay(10000);
      //delay(2500);
      motor1.activateServos(0x01, 0x50, 0x0D);
      delay(10000);
      motor1.activateServos(0x01, 0xFF, 0x01);
      delay(10000);
      motor1.activateServos(0x01, 0x50, 0x0D);
      delay(10000);
      motor1.activateServos(0x01, 0xFF, 0x01);
      delay(10000); 
      mySerial.write('3');
      mySerial.flush();
    }
    
    if (test=='l'){
       motor2.activateServos(0x02, 0xFD, 0x07);
       delay(250);
       motor1.activateServos(0x01, 0xFD, 0x07);
       delay(7000);
       motor2.activateServos(0x02, 0xFF, 0x01);
       delay(8000);
       motor2.activateServos(0x02, 0x50, 0x0D);
       delay(8000);
       motor2.activateServos(0x02, 0xFF, 0x01);
       delay(8000);
       motor2.activateServos(0x02, 0x50, 0x0D);
       delay(8000);
       motor2.activateServos(0x02, 0xFD, 0x07);
       delay(8000);
       mySerial.write('4');
       mySerial.flush();
    }
    
    if (test=='k'){
      motor2.activateServos(0x02, 0xFD, 0x07);
      delay(250);
      motor1.activateServos(0x01, 0xFD, 0x07);
      delay(6000);
      Serial.println("Testing");
      //pick operation
      gripper1();
      crankshaft2();
      gripper2();
      crankshaft1();
      //place operation
      crankshaft2();
      gripper1();
      crankshaft1();
      
       mySerial.write('5');
       mySerial.flush();
    }
    if (test == 'w'){
       bck=3;
    } 
    }
    Serial.println("Testing is done");
   }
  
  
  if ( mode=='s'){
    Serial.println("Enter in setup mode and repeat the operation for 70 blocks");
    while(1){
      //complete the operation of base motor, link motor, pick and place.
      motor2.activateServos(0x02, 0xFD, 0x07);
      delay(250);
      motor1.activateServos(0x01, 0xFF, 0x01);
      delay(8000); 
      
      mySerial.write('1');
      //1 is for camera on arduino will send to python
      mySerial.flush();
      Serial.println("waiting for pyhon to send");
      Serial.println("Camera On");
      while(mySerial.available()==0){
      }
      si[0]=mySerial.read()-48;
      Serial.println(si[0]);
      //mySerial.flush();
      while(mySerial.available()==0){
      }
      si[1]=mySerial.read()-48;
      mySerial.flush();
      Serial.println(si[1]);
      ssi=(si[0]*10)+si[1];
      Serial.println(ssi);
      if(ssi==70){
        Serial.println("Exit setup mode");
        break;
      }
      //pick operation
      gripper1();
      crankshaft2();
      gripper2();
      crankshaft1();
      
      motor2.activateServos(0x02, linkl[ssi], linkh[ssi]);
      delay(250);
      motor1.activateServos(0x01, basel[ssi], baseh[ssi]);
      delay(8000);
      
      //place operation
      crankshaft2();
      gripper1();
      crankshaft1();
      }
    mySerial.flush();
    Serial.println("Setup mode ends");
  }
  
  if(mode=='r'){
    Serial.println("Enter in start operation mode ");
    motor2.activateServos(0x02, 0xFD, 0x07);
    delay(250);
    motor1.activateServos(0x01, 0xFD, 0x07);
    delay(5500);
    Serial.println("waiting for pyhon to send");
    mySerial.write('8');//
    mySerial.flush();//
    while(mySerial.available()==0){//
    }
    k=mySerial.read()-48;//
    mySerial.flush();//
    k=k+1;
    Serial.println(k);
    //placing the blocks in the display area
    for(int a=0;a<k;a++){
      mySerial.write('7');
      mySerial.flush();
      Serial.println("waiting for pyhon to send");
      while(mySerial.available()==0){
      }
      ri[0]=mySerial.read()-48;
      Serial.println(ri[0]);
      while(mySerial.available()==0){
      }
      ri[1]=mySerial.read()-48;
      Serial.println(ri[1]);
      mySerial.flush();
      rri=ri[0]*10+ri[1];
      
      Serial.println(rri);
      myservo11.write(45);
      delay(500);
      motor2.activateServos(0x02, linkl[rri], linkh[rri]);
      delay(250);
      motor1.activateServos(0x01, basel[rri], baseh[rri]);
      delay(5500);
      pick();
      
      disp(a);
      //to display the blocks in the straight line. 
      roll(a);
      
      place();
      
      Serial.println("Block placed" );
      }
   delay(3000); //wait after the blocks has been placed in the display area. 
   Serial.println("Placing the Blocks to original place");
   mySerial.write('9');
   mySerial.flush();
   for(int b=0;b<k;b++){
     disp(b);
     roll(b);
     pick();
     mySerial.write('7');
     mySerial.flush();
     Serial.println("waiting for pyhon to send");
     while(mySerial.available()==0){
     }
     di[0]=mySerial.read()-48;
     Serial.println(di[0]);
     while(mySerial.available()==0){
     }
     di[1]=mySerial.read()-48;
     Serial.println(di[1]);
     mySerial.flush();
     ddi=di[0]*10+di[1];
     Serial.println(ddi);
     myservo11.write(45);
     delay(500);
     motor2.activateServos(0x02, linkl[ddi], linkh[ddi]);
     delay(250);
     motor1.activateServos(0x01,  basel[ddi], baseh[ddi]);
     delay(5500);
     place();
   }
  }
 }

void crankshaft1(){
 
  Serial.println("upwards motion");
  myservo5.attach(5);     
  myservo5.write(30);              
  delay(1500);
 }

void crankshaft2(){
 Serial.println("Downwards motion");
 myservo5.attach(5);     
 myservo5.write(170);               
 delay(1500); 
}

void gripper1(){
 Serial.println("Gripper open");
 myservo9.attach(9);  
 myservo9.write(160);               
 delay(1000); 
 }

void gripper2(){
  Serial.println("Gripper close");
  myservo9.attach(9);  
  myservo9.write(10);               
  delay(1000); 
}
  
void disp(int q){
  Serial.println("in display area");
  Serial.println(q);
	switch(q){
		case 0:
                motor2.activateServos(0x02, 0x00, 0x08);
                delay(250);
		motor1.activateServos(0x01, 0xC4, 0x09);
		delay(5500);
		break;
    
		case 1:
                motor2.activateServos(0x02, 0xD3, 0x09);
                delay(250);
		motor1.activateServos(0x01, 0x8A, 0x08);
		delay(5500);
		break;
     
		case 2:
                motor2.activateServos(0x02, 0x7B, 0x0A);
                delay(250);
		motor1.activateServos(0x01, 0xE8, 0x07);
		delay(5500);
		break;
   
		case 3:
                motor2.activateServos(0x02, 0xE2, 0x0A);
                delay(250);
		motor1.activateServos(0x01, 0x5B, 0x07);
		delay(5500);
		break;
   
		case 4:
                motor2.activateServos(0x02, 0x13, 0x0B);
                delay(250);
		motor1.activateServos(0x01, 0xE3, 0x06);
		delay(5500);
		break;
   
		case 5:
                motor2.activateServos(0x02, 0x0D, 0x05);
                delay(250);
		motor1.activateServos(0x01, 0x88, 0x09);
		delay(5500);
		break;
   
		case 6:
                motor2.activateServos(0x02, 0x34, 0x05);
                delay(250);
		motor1.activateServos(0x01, 0x15, 0x09);
		delay(5500);
		break;
   
		case 7:
                motor2.activateServos(0x02, 0xB3, 0x05);
                delay(250);
		motor1.activateServos(0x01, 0x86, 0x08);
		delay(5500);
		break;
   
		case 8:
                motor2.activateServos(0x02, 0x27, 0x06);
                delay(250);
		motor1.activateServos(0x01, 0xE6, 0x07);
		delay(5500);
		break;
  
		case 9:
                motor2.activateServos(0x02, 0x10, 0x08);
                delay(250);
		motor1.activateServos(0x01, 0xA6, 0x06);
		delay(5500);
		break;
	}
}

void pick(){
 myservo9.attach(9);  //for gripper
  myservo5.attach(5); 
    Serial.println("in pick");
    myservo9.write(160);               
    delay(1500);                   
    myservo5.write(170);               
    delay(2000);                       
    myservo9.write(10);               
    delay(1500);                       
    myservo5.write(30);               
    delay(2000);                      
}

void place(){
  myservo9.attach(9);  //for gripper
  myservo5.attach(5); 
  Serial.println("in place");
  myservo5.write(170);               
  delay(2000);                       
  myservo9.write(160);             
  delay(1500);                     
  myservo5.write(30);              
  delay(2000);
}

void roll(int z){
  Serial.println("roll motor setting");
  Serial.println(z);
	switch(z){
		case 0:
                myservo11.write(9); 
                delay(1000);   
		break;
    
		case 1:
                myservo11.write(0); 
                delay(1000);   
		break;
     
		case 2:
                myservo11.write(0); 
                delay(1000);   
		break;
   
		case 3:
                myservo11.write(0); 
                delay(1000);   
		break;
   
		case 4:
                myservo11.write(3); 
                delay(1000);   
		break;
   
		case 5:
                myservo11.write(90); 
                delay(1000);   
		break;
   
		case 6:
                myservo11.write(90); 
                delay(1000);   
		break;
   
		case 7:
                myservo11.write(90); 
                delay(1000);   
		break;
   
		case 8:
                myservo11.write(90); 
                delay(1000);   
		break;
  
		case 9:
                myservo11.write(82); 
                delay(1000);   
		break;
	}
}






