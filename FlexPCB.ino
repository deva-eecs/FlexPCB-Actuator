//KnightRider sketch for turning all actuators
/*int ledPins[] = {2, 3, 4, 5, 6, 7,8,9,10};
int numLEDs = 9;

void setup() {
  // Set all LED pins as OUTPUT
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Loop for left to right movement
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }

  // Loop for right to left movement
  for (int i = numLEDs - 2; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}
*/
/*
 //all actuators up

void setup(){
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
  
  }
  void loop() {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    }
    */


    // wireless power transmission using dac of esp32
#include <driver/dac.h>
#include <math.h>

const dac_channel_t dacChannel = DAC_CHANNEL_1; // DAC1 is GPIO25
const int sampleRate = 1000; // Sample rate in Hz
const float frequency = 150; // Frequency of the sine wave in Hz
const int amplitude = 250; // Amplitude of the sine wave (0-255)
const float pi = 3.14159;

void setup() {
  // Initialize the DAC
  dac_output_enable(dacChannel);
}

void loop() {
  // Generate a sine wave
  for (int i = 0; i < sampleRate; i++) {
    float sample = amplitude + amplitude * sin(2 * pi * frequency * i / sampleRate);
    dac_output_voltage(dacChannel, (uint8_t)sample);
    delayMicroseconds(1000000 / sampleRate);
  }
}


/*
//flexPCB as Speaker
#include "pitches_h.h"


void playJingleBells() {
  // Jingle Bells melody
  int melody[] = {
NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
  };

  // Note durations
  int noteDurations[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
  };

 
  // Play Jingle Bells
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    tone(11, melody[i], 1000 / noteDurations[i]);
    delay(100);
  }

  delay(1000); // Pause before playing "Ho Ho Ho"
}


void setup() {

  pinMode(11,OUTPUT);
}

void loop() {
  playJingleBells();
 
  
}
*/

/*
//Actuator for mimicing butterfly
void setup(){
   pinMode(13, OUTPUT);

  
  }
  void loop() {
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
   
    }*/

/*

//combined code


#include "pitches_h.h"

// Define LED pins
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
int numLEDs = 9;
int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};
int noteDurations[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

unsigned long previousMillisBlink = 0;
unsigned long previousMillisMelody = 0;
unsigned long previousMillisMove = 0;

const long intervalBlink = 500;
const long intervalMelody = 100; // Adjust as needed
const long intervalMove = 100;

int ledState = LOW;
int melodyIndex = 0;
int moveIndex = 0;
bool moveForward = true;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  // Blink LED
  if (currentMillis - previousMillisBlink >= intervalBlink) {
    previousMillisBlink = currentMillis;
    ledState = !ledState;
    digitalWrite(13, ledState);
  }

  // Play Jingle Bells melody
  if (currentMillis - previousMillisMelody >= intervalMelody) {
    previousMillisMelody = currentMillis;
    tone(11, melody[melodyIndex], 1000 / noteDurations[melodyIndex]);
    melodyIndex++;
    if (melodyIndex >= sizeof(melody) / sizeof(melody[0])) {
      melodyIndex = 0;
    }
  }

  // Move LEDs
  if (currentMillis - previousMillisMove >= intervalMove) {
    previousMillisMove = currentMillis;
    if (moveForward) {
      digitalWrite(ledPins[moveIndex], HIGH);
      delay(100);
      digitalWrite(ledPins[moveIndex], LOW);
      moveIndex++;
      if (moveIndex >= numLEDs) {
        moveIndex = numLEDs - 2;
        moveForward = false;
      }
    } else {
      digitalWrite(ledPins[moveIndex], HIGH);
      delay(100);
      digitalWrite(ledPins[moveIndex], LOW);
      moveIndex--;
      if (moveIndex < 0) {
        moveIndex = 1;
        moveForward = true;
      }
    }
  }
}*/
