/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include <IRremote.h>
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio


// Pin definitions for LED connections
#define RED_LED_PIN 13
#define GREEN_LED_PIN 12
#define BLUE_LED_PIN 11
#define WHITE_LED_1 5
#define WHITE_LED_2 6
#define WHITE_LED_3 9
#define WHITE_LED_4 10

// Pin definitions for IR receiver
#define IR_RECEIVE_PIN 3

// IR Remote button codes
#define CHANNEL_UP_CODE 64    // Update the correct code for Volume Up
#define CHANNEL_DOWN_CODE 68  // Update the correct code for Volume Down
#define VOLUME_DOWN_CODE 22   // Update the correct code for Channel Down
#define VOLUME_UP_CODE 25     // Update the correct code for Volume Up

int ledState = 0;  //All off when power on
int brightness = 255;
int clr = 1;

void turnOffRGBLED();

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);

  // Initialize white LEDs as outputs
  pinMode(WHITE_LED_1, OUTPUT);
  pinMode(WHITE_LED_2, OUTPUT);
  pinMode(WHITE_LED_3, OUTPUT);
  pinMode(WHITE_LED_4, OUTPUT);

  // Initialize RGB LEDs as outputs
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int irCode = IrReceiver.decodedIRData.command;
    //Serial.println(irCode);
    if (irCode == CHANNEL_UP_CODE) {
      if (ledState >= 5) {
        ledState = 5;
        clr++;
      } else {
        ledState++;
      }
    } else if (irCode == CHANNEL_DOWN_CODE) {
      if (ledState <= 0) {
        ledState = 0;
      } else {
        ledState--;
      }
    } else if (irCode == VOLUME_UP_CODE) {
      if (brightness < 255) {
        brightness +=10 ;
      }
     
    } else if (irCode == VOLUME_DOWN_CODE) {
      if (brightness > 0) {
        brightness -= 10;
      } else {
        brightness--;
      }
    }
  }
  if (clr == 4) { clr = 1; }
  switch (ledState) {
    case 0:
      digitalWrite(WHITE_LED_1, LOW);
      digitalWrite(WHITE_LED_2, LOW);
      digitalWrite(WHITE_LED_3, LOW);
      digitalWrite(WHITE_LED_4, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(BLUE_LED_PIN, HIGH);
      break;
    case 1:
      analogWrite(WHITE_LED_1, brightness);
      digitalWrite(WHITE_LED_2, LOW);
      digitalWrite(WHITE_LED_3, LOW);
      digitalWrite(WHITE_LED_4, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(BLUE_LED_PIN, HIGH);
      break;
    case 2:
      analogWrite(WHITE_LED_1, brightness);
      analogWrite(WHITE_LED_2, brightness);
      digitalWrite(WHITE_LED_3, LOW);
      digitalWrite(WHITE_LED_4, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(BLUE_LED_PIN, HIGH);
      break;
    case 3:
      analogWrite(WHITE_LED_1, brightness);
      analogWrite(WHITE_LED_2, brightness);
      analogWrite(WHITE_LED_3, brightness);
      digitalWrite(WHITE_LED_4, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(BLUE_LED_PIN, HIGH);
      break;
    case 4:
      analogWrite(WHITE_LED_1, brightness);
      analogWrite(WHITE_LED_2, brightness);
      analogWrite(WHITE_LED_3, brightness);
      analogWrite(WHITE_LED_4, brightness);
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(BLUE_LED_PIN, HIGH);
      break;
    case 5:
      if (clr == 1) {
        analogWrite(WHITE_LED_1, brightness);
        analogWrite(WHITE_LED_2, brightness);
        analogWrite(WHITE_LED_3, brightness);
        analogWrite(WHITE_LED_4, brightness);
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, HIGH);
        digitalWrite(BLUE_LED_PIN, HIGH);
      } else if (clr == 2) {
        analogWrite(WHITE_LED_1, brightness);
        analogWrite(WHITE_LED_2, brightness);
        analogWrite(WHITE_LED_3, brightness);
        analogWrite(WHITE_LED_4, brightness);
        digitalWrite(RED_LED_PIN, HIGH);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, HIGH);
      } else if (clr == 3) {
        analogWrite(WHITE_LED_1, brightness);
        analogWrite(WHITE_LED_2, brightness);
        analogWrite(WHITE_LED_3, brightness);
        analogWrite(WHITE_LED_4, brightness);
        digitalWrite(RED_LED_PIN, HIGH);
        digitalWrite(GREEN_LED_PIN, HIGH);
        digitalWrite(BLUE_LED_PIN, LOW);
      }
      break;
  }
}


