#include "Adafruit_BluefruitLE_SPI.h"
#include <Adafruit_MotorShield.h>

// motor terminals
#define MOTOR_A_TERMINAL 1 //TL
#define MOTOR_B_TERMINAL 2 //BL
#define MOTOR_C_TERMINAL 3 //TR
#define MOTOR_D_TERMINAL 4 //BR

// IR sensor pins
#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3
#define IR5 A4

#define MA BACKWARD
#define MB FORWARD
#define MC BACKWARD
#define MD BACKWARD

// sensitivity threshold
const int threshold = 300;


Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *MOTOR_A = AFMS.getMotor(MOTOR_A_TERMINAL);
Adafruit_DCMotor *MOTOR_B = AFMS.getMotor(MOTOR_B_TERMINAL);
Adafruit_DCMotor *MOTOR_C = AFMS.getMotor(MOTOR_C_TERMINAL);
Adafruit_DCMotor *MOTOR_D = AFMS.getMotor(MOTOR_D_TERMINAL);

void setup() {
  AFMS.begin();
  // release all motors
  MOTOR_A->run(RELEASE);
  MOTOR_B->run(RELEASE);
  MOTOR_C->run(RELEASE);
  MOTOR_D->run(RELEASE);

   pinMode(IR1, INPUT);
   pinMode(IR2, INPUT);
   pinMode(IR3, INPUT);
   pinMode(IR4, INPUT);
   pinMode(IR5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // forward, left, right, 90right, 90left
  
  //WBBBW
   if(analogRead(IR1) < threshold && analogRead(IR5) < threshold){
     forward();
  }
  
  // //WWBBB
   else if(analogRead(IR5) > threshold){
     right();
   }

  // //BBBWW
   else if(analogRead(IR1) > threshold){
    left();
   }
  
  //WBBBB

  else{
    forward();
  }
 
}
void forward() {
  MOTOR_A->setSpeed(100);
  MOTOR_B->setSpeed(100);
  MOTOR_C->setSpeed(100);
  MOTOR_D->setSpeed(100);
  MOTOR_A->run(MA);
  MOTOR_B->run(MB);
  MOTOR_C->run(MC);
  MOTOR_D->run(MD);
}

// ─── Modified right() ───
void right() {
   // Properly declared here
  
  // Left side (outer wheels) - faster
  MOTOR_A->setSpeed(100);
  MOTOR_B->setSpeed(100);
  // Right side (inner wheels) - slower
  MOTOR_C->setSpeed(100);
  MOTOR_D->setSpeed(100);

  while (analogRead(IR3) > threshold) && 
        !(analogRead(IR4) < threshold)) 
    {
    // Left side forward/backward based on your original definitions
    MOTOR_A->run(MA);
    MOTOR_B->run(MB);
    // Right side both forward (overriding definitions for turn)
    MOTOR_C->run(FORWARD);
    MOTOR_D->run(FORWARD);
    
    
    
    // 1-second timeout safety
   
  }
}



void left() {
  
  
  // Right side (outer wheels) - faster
  MOTOR_C->setSpeed(100);
  MOTOR_D->setSpeed(100);
  // Left side (inner wheels) - slower
  MOTOR_A->setSpeed(50);
  MOTOR_B->setSpeed(50);

  while (analogRead(IR3) > threshold) && 
        !(analogRead(IR1) < threshold)
        {
    // Left side modified for turn
    MOTOR_A->run(FORWARD);
    MOTOR_B->run(BACKWARD);
    // Right side follows original definitions
    MOTOR_C->run(MC);
    MOTOR_D->run(MD);
    
    
    
    // 1-second timeout safety
  
  }
}
