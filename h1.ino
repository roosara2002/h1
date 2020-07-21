#include <Servo.h>
int value = 0;
int avg_value = 0;
int sensorPin = A5;  
int buttonPin = 13; 
boolean buttonState = LOW; 
int ledPin = 8;
int hForState = 0;
int rotating = 0;
Servo myservo;  




void setup() {
  
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buttonPin, LOW);
  myservo.attach(3);
}

void loop() {
  
    buttonState = digitalRead(buttonPin);
    value = analogRead(sensorPin);
    Serial.println(value);//this line print value from ir resever(only for debug)
    Serial.println("91");
    digitalWrite(ledPin, HIGH);

    if(value > 0){//this value was only assumed by me . maybe this value doesn't match with hardware. please adjust this if not working
      //hForState = 0;
      
      if(buttonState==LOW && hForState==0){
        
        myservo.write(360);
        Serial.println("roting");
        rotating = 1;
        
      }
      else{
        myservo.write(90);
        Serial.println("stoprot");
        rotating = 0;
        hForState = 1;
      }
    }
    else{
      hForState = 1;
      hForState = 0;
      Serial.println("return");
    }
    
}
