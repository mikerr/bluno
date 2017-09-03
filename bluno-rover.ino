#include <Servo.h>

// sketch for use with bluno beetle and bluno remote android app:
// https://play.google.com/store/apps/details?id=com.redrobe.robotremote

Servo myservo1;
Servo myservo2;

// use two continuous rotation servos as motors

int motor1=90;
int motor2=90;

void setup()
{
  Serial.begin(115200);

    myservo1.attach(2);
    myservo2.attach(3);
}


void loop()
{
     if(Serial.available())
    {
        char c = Serial.read();    //send what has been received

        
        switch (c) {
          case 'L': 
                    motor1 = 45;
                    motor2 = 45;
                    break;
          case 'R': 
                    motor1 = 135;
                    motor2 = 135;
                    break;
          case 'D': 
                    motor1 = 135;
                    motor2 = 45;
                    break;
          case 'U': 
                    motor1 = 45;
                    motor2 = 135;
                    break;
        
        }
        Serial.print (motor1);
        
    }

  
    myservo1.write(motor1);              
    myservo2.write(motor2); 
    
    delay(250);

    motor1 = motor2 = 90;
 
}






