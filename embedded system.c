/*------ Arduino Fire Fighting Robot Code----- */
#include <Servo.h>
Servo myservo;

int pos = 0;    
//bool fire = false;

/-------defining Inputs------/

#define Left_S 9      // left sensor
#define Right_S 10      // right sensor
#define Forward_S 8 //forward sensor


/-------defining Outputs------/

#define LM1 2       // left motor
#define LM2 3       // left motor
#define RM1 4       // right motor
#define RM2 5       // right motor
#define pump 6

void setup()
{

  pinMode(Left_S, INPUT);
  pinMode(Right_S, INPUT);
  pinMode(Forward_S, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);

  //myservo.attach(11);
  //myservo.write(90); 

  Serial.begin(9600);

}

void put_off_fire()
{

    delay(500);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);\
    digitalWrite(RM2, HIGH);

    Serial.println("Pump to low");
     digitalWrite(pump, HIGH); delay(2000);
    Serial.println("Pump to high");

  digitalWrite(pump,LOW);

  //myservo.write(90);
  //fire=false;

}

// void(* resetFunction)(void)=0; reset function

void loop()

{
   //myservo.write(90); //Sweep_Servo();  
    if (digitalRead(Left_S) ==1 && digitalRead(Right_S)==1 && digitalRead(Forward_S) ==1) //If Fire not detected all sensors are zero

    {

    //Do not move the robot
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);

    }

    else if (digitalRead(Forward_S) ==0) //If Fire is straight ahead

    {

    //Move the robot forward
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);

    //fire = true;

    }

    else if (digitalRead(Left_S) ==0) //If Fire is to the left

    {

      //Move the robot right

      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);

    } 
    else if (digitalRead(Right_S) ==0) //If Fire is to the right
    {

      //Move the robot left

      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, HIGH);

    }

    delay(300); //Slow down the speed of robotds

     while (digitalRead(Forward_S) ==0)
     {
        delay(300);
        digitalWrite(LM1, LOW);
        digitalWrite(LM2, LOW);
        digitalWrite(RM1, LOW);
        digitalWrite(RM2, LOW);
        Serial.println("Pump to low");
        digitalWrite(pump, HIGH); delay(2000);
        Serial.println("Pump to high");

       // myservo.write(90);
        }

        delay(100);
        digitalWrite(pump,LOW);

}