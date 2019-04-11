

#include<SoftwareSerial.h>
#include <LiquidCrystal.h> //Please replace the single quote characters ('') with the parenthesis character (<>)

//flame

int sensorPin = A0; // select the input pin for the LDR
int sensorValue = 0; // variable to store the value coming from the sensor
int led = 11; // Output pin for LED
int buzzer = 21; // Output pin for Buzzer

//LDR 

const int ledPin = 49;
const int ldrPin = A8;

//line tracking
int lsensor;
int Rsensor;
int rightsensor = 13;
int leftsensor =12;

// sound sensor 
int sss=39;


//ultrasonic
LiquidCrystal lcd(41, 43, 31, 33, 35, 37); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 47;
const int echoPin = 45;
long duration;
int distanceCm, distanceInch;
const int sensorpin=A14;
int reading;
float voltage;
float temp;

//gas detector
int gas_led = 29;
int sensor = A15;
int sensorValue1=0;

//rain sensor
int rainSensePin= A13; 
int alertPin= 27; 


 //object sensor
int objectsensor =25;
int object_buzzer =23;
 
int IN11 = 4;
int IN12 = 5;
int IN13 = 6;
int IN14 = 7;
int IN21 = 50;
int IN22 = 51;
int IN23 = 52;
int IN24 = 53;


void setup() {
//FLAME SENSOR
pinMode(led, OUTPUT);
pinMode(buzzer,OUTPUT);
//LDR
pinMode(ledPin,OUTPUT);
pinMode (ldrPin, INPUT);

// line tracking
pinMode(leftsensor,INPUT);
pinMode(rightsensor,INPUT);
//sound
pinMode(sss,INPUT);
//ultrasonic
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
//gas detector
pinMode(gas_led, OUTPUT);
//rain sensor
pinMode(alertPin, OUTPUT);
pinMode(rainSensePin, INPUT);

//object sensor
pinMode(objectsensor,INPUT);
pinMode(object_buzzer,OUTPUT);

 // put your setup code here, to run once:
pinMode(IN11,OUTPUT);
pinMode(IN12,OUTPUT);
pinMode(IN13,OUTPUT);
pinMode(IN14,OUTPUT);
pinMode(IN21,OUTPUT);
pinMode(IN22,OUTPUT);
pinMode(IN23,OUTPUT);
pinMode(IN24,OUTPUT);
Serial.begin(9600);
}


void Forword()
{
digitalWrite(IN11,HIGH);
digitalWrite(IN12,LOW);

digitalWrite(IN13,HIGH);
digitalWrite(IN14,LOW);  

digitalWrite(IN21,HIGH);
digitalWrite(IN22,LOW);

digitalWrite(IN23,HIGH);
digitalWrite(IN24,LOW);  
}

void Right()
{
digitalWrite(IN11,HIGH);
digitalWrite(IN12,LOW);

digitalWrite(IN14,HIGH);
digitalWrite(IN13,LOW);

digitalWrite(IN21,HIGH);
digitalWrite(IN22,LOW);

digitalWrite(IN23,HIGH);
digitalWrite(IN24,LOW);  
  
}

void Left()
{
digitalWrite(IN12,HIGH);
digitalWrite(IN11,LOW);

digitalWrite(IN13,HIGH);
digitalWrite(IN14,LOW);
  
digitalWrite(IN21,HIGH);
digitalWrite(IN22,LOW);

digitalWrite(IN23,HIGH);
digitalWrite(IN24,LOW);  

}


void Backword()
{
digitalWrite(IN12,HIGH);
digitalWrite(IN11,LOW);

digitalWrite(IN14,HIGH);
digitalWrite(IN13,LOW);

digitalWrite(IN22,HIGH);
digitalWrite(IN21,LOW);

digitalWrite(IN24,HIGH);
digitalWrite(IN23,LOW);  
}

void Stop ()
{

digitalWrite(IN11,LOW);
digitalWrite(IN12,LOW);

digitalWrite(IN13,LOW);
digitalWrite(IN14,LOW);

digitalWrite(IN21,LOW);
digitalWrite(IN22,LOW);

digitalWrite(IN23,LOW);
digitalWrite(IN24,LOW);  
    
}
void loop() {
  
 if(Serial.available()>0)
{

//bluetooth
int Data = Serial.read();

  if(Data == '1')  Forword();
  else if(Data == '2') 
  {
    //object sensor
    Backword();
    /*if(digitalRead(objectsensor)==LOW)
    {
      digitalWrite(object_buzzer,HIGH);
      delay(1000);
    
    }
    else 
    digitalWrite(object_buzzer,LOW);
  }*/
  else if(Data == '3') Left();
  else if(Data == '4') Right();
 /* else if (Data=='5')
   {
     lsensor=digitalRead(leftsensor);
     Rsensor=digitalRead(rightsensor);
     if ((lsensor==LOW)&&(Rsensor==LOW))
       {
        Forword();
        }
     else if ((lsensor==LOW)&&(Rsensor==HIGH))
        {
         Right();
         
        }
     else if((Rsensor==LOW)&& (lsensor==HIGH))
       {
        Left();
        
       }
   }
   else if(Data=='6')
   {
    //ultrasonic
 
     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distanceCm= duration*0.034/2;
     reading=analogRead(sensorpin);
     voltage=reading*5.0;
     voltage /=1024.0;
    temp=(voltage-0.5)*100;
    lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
    lcd.print("Distance: "); // Prints string "Distance" on the LCD
    lcd.print(distanceCm); // Prints the distance value from the sensor
km    lcd.print("  cm");
    delay(10);
     lcd.setCursor(0,1);
   lcd.print("temp is: ");
   lcd.print(temp);
   lcd.print(" C");
   delay(1000);
  
 }
 else if(Data=='8')
 {
  //rain sensor
   if(analogRead(rainSensePin)<=500)
   {
    digitalWrite(alertPin,HIGH);
    delay(200);
   }
   else
       digitalWrite(alertPin,LOW); 
 }
else if(Data == '0') Stop();

else if(Data == '7')
{
  //sound sensor
  int statussensor=digitalRead(sss);
  if(statussensor==LOW)
  {
    Forword_sound();
    delay(1000);
    Stop_sound(); 
  }
}
}
else
{    
  //LDR 
int ldrStatus = analogRead (ldrPin); 
if(ldrStatus <=300)
digitalWrite (ledPin,HIGH);
else
 digitalWrite(ledPin,LOW);

 //flame sensor
  sensorValue = analogRead(sensorPin);
if (sensorValue < 150)
{
Serial.println("Fire Detected");
Serial.println("LED on");
digitalWrite(led,HIGH);
digitalWrite(buzzer,HIGH);
delay(1000);
}
digitalWrite(led,LOW);
digitalWrite(buzzer,LOW);
delay(sensorValue);

//gas detector
 sensorValue1 = analogRead(sensor);
  Serial.println(sensorValue1, DEC);
  if (sensorValue1 > 400) {
    digitalWrite(gas_led, HIGH);
  }
  else {
    digitalWrite(gas_led, LOW);
  }
   }*/
   
}

 

