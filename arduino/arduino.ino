#include <Keypad.h>
#include <Button.h>
#include <Encoder.h>

#include "src/Grid.h"

  // Potentiometer
int potPin = 21;
int potVal = 0;

  // Sequencing grid
Grid grid;
int lenght = 16; // TBD: lenght of pattern
int stepCounter = 0;

  // Keypad variables
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;

char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'a','b','c','d'},
  {'e','f','g','h'},
  {'i','j','k','l'},
  {'m','n','o','p'}  
};

byte rowPins[KEYPAD_ROWS] = {5, 4, 3, 2};
byte colPins[KEYPAD_COLS] = {9, 8, 7, 6};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS );


  // Encoder
Encoder encoder(14, 16);
long oldPosition = -999;

  // Play/Pause button variable
Button playPauseButton(10);
bool playPauseButtonState = true;

  // Variables for millis() (to omit delay() function)
unsigned long time = 0;
unsigned long timeLastAction = 0;

// Temporary variables
const int ledPin =  17;

void setup() {
  Serial.begin(9600);
  Serial.println("init");

  playPauseButton.begin();

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void loop() {
  long newPosition = encoder.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }
  
//  // BPM setting
//  int bpmVal = map(analogRead(potPin), 0, 1023, 60, 180); 
//  int bpmTime = 60000 / bpmVal / 4;
//  
//  // Step sequencer editing
//  int key = keypad.getKey();
//  if (key != NO_KEY){
//    grid.gridFlipState(1, key - 97);
//  }
//  
//  // Play/Pause button
//  if (playPauseButton.released()) {
//    playPauseButtonState = !playPauseButtonState;
//    if (playPauseButtonState == true) stepCounter = 0;
//  }
//  
//  // Send msg to RPI after delay time between steps
//  if ( (millis() - timeLastAction > bpmTime) && playPauseButtonState) {
//    String msgToRpi = grid.getGridState(stepCounter);
//    timeLastAction = millis();
//    if(msgToRpi.length()) {
//      // grid.getGrid();
//      Serial.println(msgToRpi); // Sending msg to RPI
//    }  
//
//    // Move to another step
//    stepCounter++;
//    if (stepCounter > 15) stepCounter = 0;
//  }  
}
