// ESC Sweep 
// This example code is in the public domain.


#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
// a maximum of eight servo objects can be created 

int pos = 0;    // variable to store the servo position 
const int cycleButtonPin = 2;
const int thUpButtonPin = 4;
const int thDownButtonPin = 7;

// variables will change:
int cycleButtonState = 0;         // variable for reading the pushbutton status
int thUpButtonState = 0;
int thDownButtonState = 0;
int cycleState = 0;
int thUpState = 0;
int thDownState = 0;
void setup() {     
  // initialize the pushbutton pin as an input:
  pinMode(cycleButtonPin, INPUT);
  pinMode(thUpButtonPin, INPUT);
  pinMode(thDownButtonPin, INPUT);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  // myservo.write(0);  
}




void loop() 
{ 
  //if (cycleState == 0) {
  cycleButtonState = digitalRead(cycleButtonPin);
  thUpButtonState = digitalRead(thUpButtonPin);
  thDownButtonState = digitalRead(thDownButtonPin);
  if (cycleButtonState == HIGH || cycleState == 1) {
    cycleState = 1;
    thUpState = 0;
    thDownState = 0;
  }
  else if (thUpButtonState == HIGH) {
    cycleState = 0;
    thUpState = 1;
    thDownState = 0;
  }
  else if (thDownButtonState == HIGH ) {
    cycleState = 0;
    thUpState = 0;
    thDownState = 1;
  }  
  //}
  if (cycleState == 1) {
    for(pos = 1; pos < 176; pos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    } 
    delay(3000);
    for(pos = 176; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    } 
    cycleState = 0;  
  }
  else if (thUpState == 1) {
    //if (d
    for(pos = 1; pos < 176; pos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    }  
  }
  else if (thDownState == 1) {
    for(pos = 176; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    } 
  }

} 



