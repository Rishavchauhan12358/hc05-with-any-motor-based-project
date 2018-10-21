#include <AFMotor.h>
AF_DCMotor motor1(1),motor2(2),motor3(3),motor4(4);

/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Social networks:            http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use Arduino with HC-06/HC-05
  Bluetooth 2.0 Serial Port Profile (SPP) module
  to connect your project to Blynk.

  Note: This only works on Android! iOS does not support SPP :(
        You may need to pair the module with your smartphone
        via Bluetooth settings. Default pairing password is 1234

  Feel free to apply it to any other example. It's simple!

  NOTE: Bluetooth support is in beta!

 *************************************************************/

#define BLYNK_USE_DIRECT_CONNECT

// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#define BLYNK_PRINT DebugSerial
#include <BlynkSimpleSerialBLE.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "26c5b3da1a764e32b071baa83a086c18";

void setup()
{
  // Debug console
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  DebugSerial.begin(9600);

  DebugSerial.println("Waiting for connections...");

  // Blynk will work through Serial
  // 9600 is for HC-06. For HC-05 default speed is 38400
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}

void loop()
{
  Blynk.run();
  

}
BLYNK_WRITE(V0)
  { 
    motor1.run(BACKWARD);
     delay(500);
     motor1.run(RELEASE);
      
    }
    BLYNK_WRITE(V1){
      motor1.run(FORWARD);
      delay(500);
      motor1.run(RELEASE);
      
      }
      BLYNK_WRITE(V2){
        motor2.run(BACKWARD);
      delay(500);
      motor2.run(RELEASE);
     delay(500);
        }
        BLYNK_WRITE(V3){
           motor2.run(FORWARD);
      delay(500);
      motor2.run(RELEASE);
      delay(500);
    
           }
           BLYNK_WRITE(V4){
             motor3.run(BACKWARD);
      delay(500);
      motor3.run(RELEASE);
     
            }
            BLYNK_WRITE(V5){
               motor3.run(FORWARD);
      delay(500);
      motor3.run(RELEASE);
      
              }
              BLYNK_WRITE(V6){
                 motor4.run(BACKWARD);
      delay(400);
      motor4.run(RELEASE);
     
                }
                BLYNK_WRITE(V7)
                {
      motor4.run(FORWARD);
      delay(400);
      motor4.run(RELEASE);
      
                }

