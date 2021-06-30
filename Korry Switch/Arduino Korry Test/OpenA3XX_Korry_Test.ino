/* This Arduino sketch has been designed to test the OpenA3XX Korry Switch */
/* 
  @file OpenA3XX_Korry_Test.ino
  @version 1.0
  @author Jak Kav

  @description
  | This sketch has been designed to test the OpenA3XX Korry Switch.
  | It's a simple little sketch that tests both the LED's and the switch.
  | When the switch is open, the onboard LED will be illuminated.
  | When the switch is closed, the onboard LED will go out, and the 2 LED's in the Korry will cycle
  | between going on individually, both at the same time and both off.
  | It will continue running through this cycle until the switch is pressed again and is open.
  | It will finish it's current cycle, stop, then illuminate the onboard LED again.
  |
  | Connect Arduino pin 2 to Korry pin 1
  | Connect Arduino pin 9 to Korry pin 3
  | Connect Arduino pin 10 to Korry pin 4
  | Connect Korry pin 2 and 5 to a GND pin on the Arduino
*/

int led = 9;
int led2 = 10;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  int buttonVal = digitalRead(2);

  if(buttonVal == HIGH) {
    digitalWrite(13, HIGH);
  } else {
    ledCycle();
    digitalWrite(13, LOW);
  }
  
}

void ledCycle() {
  analogWrite(led, 250);
  analogWrite(led2, 0);

  delay(3000);

  analogWrite(led, 0);
  analogWrite(led2, 250);

  delay(3000);

  analogWrite(led, 250);
  analogWrite(led2, 250);

  delay(3000);

  analogWrite(led, 0);
  analogWrite(led2, 0);

  delay(3000);
}
