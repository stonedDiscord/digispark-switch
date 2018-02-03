#include "DigiKeyboard.h"

#define PIN_LED 1
String run_uri="http://youtu.be/DLzxrzFCyOs";
int payload=0;
#define INTERVAL_MIN 60*2  // The minimum time between rickrolls, in seconds
#define INTERVAL_MAX 60*5 // The minimum time between rickrolls, in seconds

void blink(int times) {
  for (int i=0; i<times; i++) {
    digitalWrite(PIN_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(400);               // wait for a second
    digitalWrite(PIN_LED, LOW);    // turn the LED off by making the voltage LOW
    delay(250);
  }
}

// Send the key sequence to open a rickroll
void rickroll() {
  //signal rickroll sequence start
  blink(1);
  DigiKeyboard.sendKeyStroke(0); 
  // Open Safari via Spotlight
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(300);
  DigiKeyboard.print(run_uri);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for (int i=0; i<10; i++) {
    DigiKeyboard.delay(10);
    DigiKeyboard.sendKeyStroke(KEY_VOLUP);
  }
  //signal rickroll sequence complete
  blink(2);
}
void check_payload() {
  payload=0;
    if (digitalRead(0)==HIGH){
    payload=+1;
  }
  if (digitalRead(2)==HIGH){
    payload=+2;
  }
}
void setup()
{
  //Set Pins 0 and 1 as outputs.
  //Some Digisparks have a built-in LED on pin 0, while some have it on
  //pin 1. This way, we can all Digisparks.
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
// 0 0 = 0
// 1 0 = 1
// 0 1 = 2
// 1 1 = 3
}
void loop()
{
  //Set the LED pins to HIGH. This gives power to the LED and turns it on
  check_payload();
  switch(payload){
    case 0:
      run_uri="http://youtu.be/DLzxrzFCyOs";
      break;
    case 1:
      run_uri="http://youtu.be/L_jWHffIx5E";
      break;
    case 2:
      run_uri="http://youtu.be/sIlNIVXpIns";
      break;
    case 3:
      run_uri="http://youtu.be/SW-BU6keEUw";
      break;
    default:
      run_uri="http://youtu.be/OLpeX4RRo28";
      break;
  }
  double sec = INTERVAL_MIN + (rand() % (INTERVAL_MAX - INTERVAL_MIN));
  DigiKeyboard.delay(sec*1000);
  rickroll();
}
