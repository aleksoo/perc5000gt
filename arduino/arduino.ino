#include <Keypad.h>
#include <Button.h>

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
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'a','b','c','d'},
  {'e','f','g','h'}
};

byte rowPins[KEYPAD_ROWS] = {2, 3, 4, 5};
byte colPins[KEYPAD_COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS );


// Additional variables
//int playButton = 10;
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

  // for (int i=0; i<(NUMBUTTONS-1); i++) {
  //   pinMode(i, INPUT);
  //   lastButtonState[i]=LOW;
  //   buttonIsPressed[i]=false;
  // }

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void loop() {
  

  char key = keypad.getKey();
  if (key != NO_KEY){
    Serial.println(key);
  }

  
  int bpmVal = map(analogRead(potPin), 0, 1023, 60, 180); 
  int bpmTime = 60000 / bpmVal / 4;

  if (playPauseButton.released()) {
      // Serial.println("Button pressed");
      playPauseButtonState = !playPauseButtonState;
      if (playPauseButtonState == true) stepCounter = 0;
  }
  // Serial.println(playPauseButtonState);
  
  // Send msg to RPI after delay time between steps
  if ( (millis() - timeLastAction > bpmTime) && playPauseButtonState) {
    String msgToRpi = grid.getGridState(stepCounter);
    
    timeLastAction = millis();
    if(msgToRpi.length()) {
      Serial.println(msgToRpi); // Sending msg to RPI
    }  
    stepCounter++;
    if (stepCounter > 15) stepCounter = 0;
  }  
}
