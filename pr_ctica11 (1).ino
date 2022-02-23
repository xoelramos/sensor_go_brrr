// C++ code

//distancia diante
//
const int Echo=A5;
const int Trigger=A4;
//distancia atras
const int Echo2=A3;
const int Trigger2=A2;

int distance;
int distance2;
//motor1//
const int DIRA=11;
const int DIRB=7;
//motor2
const int DIRC=12;
const int DIRD=6;


void setup()
{
  
 Serial.begin(9600);
  
 //distancia //
 pinMode(Trigger,OUTPUT);
 pinMode(Echo,INPUT);
 digitalWrite(Trigger,LOW);
  
 pinMode(Trigger2,OUTPUT);
 pinMode(Echo2,INPUT);
 digitalWrite(Trigger2,LOW);
  
//motor//
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(DIRC,OUTPUT);
  pinMode(DIRD,OUTPUT);
}

int detecta_sensor(int chisme, int cosa) 
{
 long t;
 long d;
 digitalWrite(chisme,LOW);
 delayMicroseconds(5);
 digitalWrite(chisme,HIGH);
 delayMicroseconds(15);
 digitalWrite(chisme,LOW);
 t=pulseIn(cosa,HIGH);
 d=t*0.01657;
 return (d);
}

void loop() 
{
 distance=detecta_sensor(Trigger,Echo);
 Serial.print("Distancia-diante: ");
 Serial.print(distance);
 Serial.println ("cm");
 delay(100);
  
 distance2=detecta_sensor(Trigger2,Echo2);
 Serial.print("Distancia-atras: ");
 Serial.print(distance2);
 Serial.println ("cm");
 delay(100);
  
  if (distance<40&&distance2<40)
    {
       digitalWrite(DIRA,LOW);
       digitalWrite(DIRB,LOW);
       digitalWrite(DIRC,LOW);
       digitalWrite(DIRD,LOW);
    }
  else
  {
    if(distance>distance2&&distance>30)
    {
    
       digitalWrite(DIRA,HIGH);
       digitalWrite(DIRB,LOW);
       digitalWrite(DIRC,HIGH);
       digitalWrite(DIRD,LOW);
  }
    
   else
    {
       digitalWrite(DIRA,LOW);
       digitalWrite(DIRB,HIGH);
       digitalWrite(DIRC,LOW);
       digitalWrite(DIRD,HIGH);
    }
  
 }
 
}