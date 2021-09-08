#include <Keypad.h>
#include <Button.h>

#include "src/Grid.h"
#include "src/LiquidExt.h"
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

byte rowPins[KEYPAD_ROWS] = {9, 8, 7, 6};
byte colPins[KEYPAD_COLS] = {5, 4, 3, 2};


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS );

  // Play/Pause button variable
// Button playPauseButton(10);
// bool playPauseButtonState = true;

  // Screen variables
// LiquidCrystal_I2C lcd(0x27, 16, 4);
// Screen *screenDriver;
LiquidExt screen = LiquidExt(0x27, 16, 4);

  // Variables for millis() (to omit delay() function)
unsigned long time = 0;
unsigned long timeLastAction = 0;

// Temporary variables
const int ledPin =  17;
  // Encoder
// Encoder encoder(16, 14);
// long oldPosition = -999;



void setup() {
  Serial.begin(9600);
  screen.init();

  for(int i=0; i<4; ++i){
    for(int j=0; j<16; ++j){
      screen.printSignInPosition(j, i, grid.getSingleGrid(i, j));
    }
  }
    // screen.printInPosition(0, i, grid.getGridChannel(i))
  // playPauseButton.begin();
  // pinMode(ledPin, OUTPUT);
  // digitalWrite(ledPin, HIGH);
}


void loop() {
  // long newPosition = encoder.read();
  // if (newPosition != oldPosition) {
  //   oldPosition = newPosition;
  //   Serial.println(newPosition);
  // }

  // Serial.println("Test");

  // BPM setting
  // int bpmTime = 120;
  // bpmTime = bpmCheck();


  // Step sequencer editing
  if(sequenceEdit()) {
    // Serial.print(0);
    // Screen print
    // String sequence = grid.getGrid();
    // Serial.print(sequence);
    // Serial.println(0);
    
  }

 
  // Play/Pause button
  // playPause();

 
 // Send msg to RPI after delay time between steps
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


int bpmCheck() {
  int bpmVal = map(analogRead(potPin), 0, 1023, 60, 180); 
  return 60000 / bpmVal / 4;
}

int sequenceEdit() {
  int key = keypad.getKey();
  if (key != NO_KEY){
    // Serial.println(key);
    
    screen.printSignInPosition(1, key - 97, grid.updateGridSingle(1, key - 97));
    // grid.getGrid();
    return 1;
  }
  return 0;
}


// void playPause() {
//   if (playPauseButton.released()) {
//     playPauseButtonState = !playPauseButtonState;
//     if (playPauseButtonState == true) stepCounter = 0;
//   }
// }
