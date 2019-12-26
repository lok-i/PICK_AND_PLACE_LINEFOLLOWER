/*Copyright 555timerIC All Rights Reserved
  Team Effort of 
  Nishant Kr
  Lokesh Krishna
  Poojit Valasingham
  Ritwik Ghouri
  Niranth Sai
*/ 
#include <Servo.h>
Servo myservo;
#define lt 3
#define rt 5
#define r2 7 
#define r1 8
#define l2 9
#define l1 10
#define rt0 130
#define lt0 100
#define rt1 175
#define lt1 150
#define rt2 220
#define lt2 200
#define rt3 250
#define lt3 250
#define rIR 130
#define lIR 100
#define led1 11
#define led2 12
int tight=8;
int c=0;
int crr[]={20,20,20,40};
int r=rt0, l=lt0;
char data;
int a=0,q=0,y=0;
int trans=0;
void setup() 
{
  
  myservo.attach(6);
  myservo.write(90);
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
    Blue();digitalWrite(led1,HIGH);digitalWrite(led2,LOW);
  }
  else if(trans==1)
  { 
    lineFoll();digitalWrite(led2,HIGH);digitalWrite(led1,LOW);
  }
}
void lineFoll()
{
  
  a=analogRead(A0);
  q=analogRead(A1);
  y=analogRead(A2);
  /*if(a<200&&q>400&&y<200)
  {ford();}
  else if(a>400&&q<200&&y<200)
  {lft();}
  else if(a<200&&q<200&&y>400)
  {rgt();}*/

  a=a>400?1:0;
  q=q>400?1:0;
  y=y>400?1:0;
  int i=a*100+q*10+y;
  switch (i)
  {
    case 10:
    {ford();break;}
    case 100:
    {lftF();break;}
    case 110:
    {lft();break;}
    case 11:
    {rgt();break;}
    case 1:
    {rgtF();break;}
    default:
    {stp();break;}
  }
  
  
  if(Serial.available()>0)
  {
    data=Serial.read();
    Serial.println(data);
    if(data=='w')
    trans=0;
    switch (data)
    { 
        case '0':
        {r=rt0,l=lt0;break;c=0;}
        case '1':
        {r=rt0,l=lt0;break;c=0;}
        case '2':
        {r=rt0,l=lt0;break;c=0;}
        case '3':
        {r=rt1,l=lt1;break;c=1;}
        case '4':
        {r=rt1,l=lt1;break;c=1;}
        case '5':
        {r=rt1,l=lt1;break;c=1;}
        case '6':
        {r=rt2,l=lt2;break;c=2;}
        case '7':
        {r=rt2,l=lt2;break;c=2;}
        case '8':
        {r=rt2,l=lt2;break;c=2;}
        case '9':
        {r=rt3,l=lt3;break;c=3;}
        case 'q':
        {r=rt3,l=lt3;break;c=3;}
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
        {r=rt0,l=lt0;break;c=0;}
        case '1':
        {r=rt0,l=lt0;break;c=0;}
        case '2':
        {r=rt0,l=lt0;break;c=0;}
        case '3':
        {r=rt1,l=lt1;break;c=1;}
        case '4':
        {r=rt1,l=lt1;break;c=1;}
        case '5':
        {r=rt1,l=lt1;break;c=1;}
        case '6':
        {r=rt2,l=lt2;break;c=2;}
        case '7':
        {r=rt2,l=lt2;break;c=2;}
        case '8':
        {r=rt2,l=lt2;break;c=2;}
        case '9':
        {r=rt3,l=lt3;break;c=3;}
        case 'q':
        {r=rt3,l=lt3;break;c=3;}
        case 'X':
        {ope();break;}
        case 'x':
        {clo();break;}
        case 'U':
        {tight=0;clo();break;}
        case 'u':
        {tight=8;clo();break;}
        case 'W':
        {trans=1; break;}
        case 'w':
        {trans=0; break;}
        
        
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
  void ope()
  {
    myservo.write(90);  
    delay(50); 
  }
  void clo()
  {
    myservo.write(tight);
    delay(50); 
  }
  void ford()
  {
    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(l1,HIGH);
    digitalWrite(l2,LOW);
    analogWrite(rt,r);
    analogWrite(lt,l);
  }
  void rgt()
  {
    digitalWrite(r1,LOW);
    digitalWrite(r2,LOW);
    digitalWrite(l1,LOW);
    digitalWrite(l2,HIGH);
    analogWrite(rt,r-10);
    analogWrite(lt,l-10);
  }
  void lft()
  {
    digitalWrite(r1,LOW);
    digitalWrite(r2,HIGH);
    digitalWrite(l1,LOW);
    digitalWrite(l2,LOW);
    analogWrite(rt,r-10);
    analogWrite(lt,l-10);
  }
  void rgtF()
  {
    digitalWrite(r1,LOW);
    digitalWrite(r2,LOW);
    digitalWrite(l1,LOW);
    digitalWrite(l2,HIGH);
    analogWrite(rt,r+10);
    analogWrite(lt,l+10);
  }
  void lftF()
  {
    digitalWrite(r1,LOW);
    digitalWrite(r2,HIGH);
    digitalWrite(l1,LOW);
    digitalWrite(l2,LOW);
    analogWrite(rt,r+10);
    analogWrite(lt,l+10);
  }
