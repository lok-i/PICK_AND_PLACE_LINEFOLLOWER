/*
Bluetooth Arduino Version3
Copyright 555timerIC All Rights Reserved
Coded by @Nishantkr18
*/ 
#include <Servo.h>
Servo oldServo,newServo;
//Pins
#define lt 3
#define rt 5
#define r2 7 
#define r1 8
#define l2 9
#define l1 10
#define led1 11
#define led2 12
#define target 2
//speeds
#define rt0 130
#define lt0 100
#define rt1 175
#define lt1 150
#define rt2 220
#define lt2 200
#define rt3 235
#define lt3 235

//Servo
#define loose 24
#define tight 20
#define servoOpen 100

boolean flag=false;
int c=0,sevo=loose;
int crr[]={20,20,20,40};
int crr2[]={20,20,25,30};
int r=rt0, l=lt0;
char data;int cnode=0;
int a=0,q=0,y=0;
int trans=0;
void setup() 
{
  
  oldServo.attach(A0);
  newServo.attach(A1);
  oldServo.write(loose);
  newServo.write(90);
  Serial.begin(9600);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(rt,OUTPUT);
  pinMode(lt,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  
}

void loop()
{ 
  if(trans==0)
  {
    Blue();
  }
  else if(trans==1)
  { 
     lineFoll();
  }
}

void lineFoll()
{
  
  a=analogRead(A3);
  q=analogRead(A4);
  y=analogRead(A5);
  a=a>400?1:0;
  q=q>400?1:0;
  y=y>400?1:0;
  int i=a*100+q*10+y;
  switch (i)
  {
    case 101:
   {if(flag==true)
    {digitalWrite(led1,LOW);break;}
    else 
    {stp();digitalWrite(led2,HIGH);delay(4000);digitalWrite(led2,LOW);
    //for(int iot=0; iot<cnode; iot++){digitalWrite(led1,HIGH);delay(1000);digitalWrite(led1,LOW);delay(1000);}
    trans=0;cnode=0;break;}
  }
    case 111:
    {
      if(cnode<target){f();digitalWrite(led1,HIGH);flag=true;break;}
      else{f();digitalWrite(led1,LOW);flag=true;break;}
    }
    case 10:
    {f();digitalWrite(led1,LOW);if(flag==true){flag=false;cnode++;}break;}
    case 100:
    {lftF();digitalWrite(led1,LOW);break;}
    case 110:
    {lft();digitalWrite(led1,LOW);break;}
    case 11:
    {rgt();digitalWrite(led1,LOW);break;}
    case 1:
    {rgtF();digitalWrite(led1,LOW);break;}
    default:
    {stp();digitalWrite(led1,LOW);break;}
  }
  if(flag==true&&cnode==4)
  {r=rt1; l=lt1;}
  
  if(Serial.available()>0)
  {
    data=Serial.read();
    Serial.println(data);
    if(data=='w')
    trans=0;
    switch (data)
    { 
        case '0':
        {crr2[2]=25;crr2[3]=30;break;}
        case 'X':
        {crr2[3]+=5;break;}
        case 'x':
        {crr2[3]+=5;break;}
        case 'U':
        {crr2[2]+=5;break;}
        case 'u':
        {crr2[2]+=5;break;}
        
        default:
        break;
    }
  }




}
void Blue()
{
  if(Serial.available()>0)
  {
    data=Serial.read();
    Serial.println(data);
    if(data=='S')
    stp();
    else if(data=='F')
    f();
    else if(data=='B')
    b();
    else if(data=='L')
    L();
    else if(data=='R')
    R();
    else if(data=='G')
    fl();
    else if(data=='I')
    fr();
    else if(data=='H')
    bl();
    else if(data=='J')
    br();
    switch (data)
    {
        case '0':
        {r=rt0,l=lt0;c=0;break;}
        case '1':
        {r=rt0,l=lt0;c=0;break;}
        case '2':
        {r=rt0,l=lt0;c=0;break;}
        case '3':
        {r=rt1,l=lt1;c=1;break;}
        case '4':
        {r=rt1,l=lt1;c=1;break;}
        case '5':
        {r=rt1,l=lt1;c=1;break;}
        case '6':
        {r=rt2,l=lt2;c=2;break;}
        case '7':
        {r=rt2,l=lt2;c=2;break;}
        case '8':
        {r=rt2,l=lt2;c=2;break;}
        case '9':
        {r=rt3,l=lt3;c=3;break;}
        case 'q':
        {r=rt3,l=lt3;c=3;break;}
        
        case 'X':
        {oldServo.write(servoOpen);delay(50);break;}
        case 'x':
        {oldServo.write(sevo);delay(50);break;}
        case 'U':
        {sevo=tight;oldServo.write(sevo);delay(50);break;}
        case 'u':
        {sevo=loose;oldServo.write(sevo);delay(50);break;}
        case 'V':
        {newServo.write(0);delay(50);break;}
        case 'v':
        {newServo.write(85);delay(50);break;}
        case 'W':
        {trans=1; digitalWrite(led1,HIGH); delay(800); digitalWrite(led1, LOW);break;}
        
        
        
      default:
        {break;}
    }
  }
}


void stp()
  {
    digitalWrite(r1,LOW);
    digitalWrite(r2,LOW);
    digitalWrite(l1,LOW);
    digitalWrite(l2,LOW);
    analogWrite(rt,0);
    analogWrite(lt,0);
  }
  void f()
  {
    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(l1,HIGH);
    digitalWrite(l2,LOW);
    analogWrite(rt,r);
    analogWrite(lt,l);
  }
  void b()
  {
    digitalWrite(r2,HIGH);
    digitalWrite(r1,LOW);
    digitalWrite(l2,HIGH);
    digitalWrite(l1,LOW);
    analogWrite(rt,r);
    analogWrite(lt,l);
  }
  void R()
  {
    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(l1,LOW);
    digitalWrite(l2,HIGH);
    analogWrite(rt,r-crr[c]);
    analogWrite(lt,l-crr[c]);
  }
  void L()
  {
    digitalWrite(r1,LOW);
    digitalWrite(r2,HIGH);
    digitalWrite(l1,HIGH);
    digitalWrite(l2,LOW);
    analogWrite(rt,r-crr[c]);
    analogWrite(lt,l-crr[c]);
  }
  void fl()
  {
    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(l1,HIGH);
    digitalWrite(l2,LOW);
    analogWrite(rt,r);
    analogWrite(lt,l-crr[c]);
  }
  void fr()
  {
    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(l1,HIGH);
    digitalWrite(l2,LOW);
    analogWrite(rt,r-crr[c]);
    analogWrite(lt,l);
  }
  void bl()
  {
    digitalWrite(r2,HIGH);
    digitalWrite(r1,LOW);
    digitalWrite(l2,HIGH);
    digitalWrite(l1,LOW);
    analogWrite(rt,r);
    analogWrite(lt,l-crr[c]);
  }
  void br()
  {
    digitalWrite(r2,HIGH);
    digitalWrite(r1,LOW);
    digitalWrite(l2,HIGH);
    digitalWrite(l1,LOW);
    analogWrite(rt,r-crr[c]);
    analogWrite(lt,l);
  } 
  
  void rgt()
  {
    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(l1,LOW);
    digitalWrite(l2,LOW);
    analogWrite(rt,r-15);
    analogWrite(lt,l-15);
  }
  void lft()
  {
    digitalWrite(r1,LOW);
    digitalWrite(r2,LOW);
    digitalWrite(l1,HIGH);
    digitalWrite(l2,LOW);
    analogWrite(rt,r-15);
    analogWrite(lt,l-15);
  }
  void rgtF()
  {
    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(l1,LOW);
    digitalWrite(l2,HIGH);
    analogWrite(rt,r-crr2[c]);
    analogWrite(lt,l-crr2[c]);
  }
  void lftF()
  {
    digitalWrite(r1,LOW);
    digitalWrite(r2,HIGH);
    digitalWrite(l1,HIGH);
    digitalWrite(l2,LOW);
    analogWrite(rt,r-crr2[c]);
    analogWrite(lt,l-crr2[c]);
  }
  
