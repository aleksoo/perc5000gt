#include <Keypad.h>
#include <Button.h>
#include <Encoder.h>

#include "src/Grid.h"
#include "src/LiquidExt.h"
// #include "src/Grid.h"



  // Keypad variables
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;

char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'a','b','c','d'},
  {'e','f','g','h'},
  {'i','j','k','l'},
  {'m','n','o','p'}  
};

byte rowPins[KEYPAD_ROWS] = {6, 7, 8, 9};
byte colPins[KEYPAD_COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS );

  // Play/Pause button variable
Button playPauseButton(53);
bool playPauseButtonState = true;

  // Channels variables
Button channels[4] = {Button(46), Button(48), Button(50), Button(52)};
int currentChannel = 0;

  // Screen variables
LiquidExt screen = LiquidExt(0x27, 16, 4);

  // Potentiometer and BPM
int bpmTime = 120;
int potPin = 54;
int potVal = 0;

  // Sequencing grid
Grid grid;
int lenght = 16; // TBD: lenght of pattern
int stepCounter = 0;

  // Variables for millis() (to omit delay() function)
unsigned long time = 0;
unsigned long timeLastAction = 0;

// Temporary variables
const int ledPin =  17;
  // Encoder
Encoder encoder(39, 37);
long oldPosition[4] = {-999, -999, -999, -999};
int soundChoice[4] = {0, 0, 0, 0};



void setup() {
  Serial.begin(9600);

    // Screen init
  screen.init();
  for(int i=0; i<4; ++i){
    for(int j=0; j<16; ++j){
      screen.printSignInPosition(j, i, grid.getSingleGrid(i, j));
    }
  }
    // Channel buttons init
  for(int i = 0; i < 4; ++i) {
    channels[i].begin();
  }

    // screen.printInPosition(0, i, grid.getGridChannel(i))
  // playPauseButton.begin();
  // pinMode(ledPin, OUTPUT);
  // digitalWrite(ledPin, HIGH);
}


void loop() {
  // Serial.println(0);
  long newPosition = encoder.read();
  // Serial.println(newPosition);
  if (newPosition != oldPosition[currentChannel]) {
    // Serial.println(newPosition, oldPosition);
    // if (newPosition > oldPosition) {
    //   soundChoice[currentChannel] = (soundChoice[currentChannel] + 1) % 4; 
    //   oldPosition = newPosition -1;
    // }
    // if (newPosition < oldPosition){
    //   soundChoice[currentChannel] = (soundChoice[currentChannel] - 1) % 4;
    //   oldPosition = newPosition + 1;
    // }

    oldPosition[currentChannel] = newPosition;
    // encoder increments by 2, hence why dividing to keep one "step" 1, not 2
    soundChoice[currentChannel] = oldPosition[currentChannel] / 2; 
  }

    // BPM setting
  
  bpmTime = bpmCheck();

    // Check if channel was changed
  changeChannels();

   // Step sequencer editing
  if(sequenceEdit()) {    
  }
    // Play/Pause button
  playPause();
 
 // Send msg to RPI after delay time between steps
 if ( (millis() - timeLastAction > bpmTime) && playPauseButtonState) {
   String msgToRpi = grid.getGridState(stepCounter, soundChoice);
   timeLastAction = millis();
   if(msgToRpi.length()) {
     // grid.getGrid();
     Serial.println(msgToRpi); // Sending msg to RPI
   }  

   // Move to another step
   stepCounter++;
   if (stepCounter > 15) stepCounter = 0;
 }  
}


int bpmCheck() {
  int bpmVal = map(analogRead(potPin), 0, 1023, 60, 180); 
  return 60000 / bpmVal / 4;
}

int sequenceEdit() {
  int key = keypad.getKey();
  if (key != NO_KEY){
    // Serial.println(key);
    grid.updateGridSingle(currentChannel, key - 97);
    screen.printSignInPosition(key - 97, currentChannel, grid.getSingleGrid(currentChannel, key - 97));
    // grid.getGrid();
    return 1;
  }
  return 0;
}

void changeChannels() {
  for(int i = 0; i < 4; ++i) {
    if (channels[i].released()) currentChannel = i;    
  }
}

void playPause() {
  if (playPauseButton.released()) {
    playPauseButtonState = !playPauseButtonState;
    if (playPauseButtonState == true) stepCounter = 0;
  }
}
