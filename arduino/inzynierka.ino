// Buttons pins
byte buttons[] = {2, 3, 4, 5};
#define NUMBUTTONS sizeof(buttons)

// Buttons states
int buttonState[NUMBUTTONS];

// Variables for debounce
int lastButtonState[NUMBUTTONS];
boolean buttonIsPressed[NUMBUTTONS];
long lastDebounceTime[] = {0, 0, 0, 0};
long debounceDelay[] = {50, 50, 50, 50};
// long lastDebounceTime = 0; // the last time the output pin was toggled
// long debounceDelay = 50; // the debounce time; increase if the output flickers

// Potentiometer
int potPin = 21;
int potVal = 0;

// Sequencing grid
int lenght = 16; // TBD: lenght of pattern
int stepCounter = 0;
bool grid[4][16] = {
  // {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
  // {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
  // {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
  // {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}
  {true, false, false, false, true, false, false, false, true, false, false, false, true, false, false, false},
  {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false},
  {false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false}
};

// Temporary variables
const int ledPin =  17;


void setup() {
  Serial.begin(9600);
  Serial.println("init");

  for (int i=0; i<(NUMBUTTONS-1); i++) {
    pinMode(i, INPUT);
    lastButtonState[i]=LOW;
    buttonIsPressed[i]=false;
  }

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void updateGridSingle(int channel, int step) {
    grid[channel][step] = !grid[channel][step];
}

String getGridState (int step) {
  String gridString = "";

  for (int channel = 0; channel < 4; ++channel) {
    String tempChannelSymbol = "";
    if (grid[channel][step] == true) {
      switch(channel) {
        case 0:
          tempChannelSymbol = "0";
          break;
        case 1:
          tempChannelSymbol = "1";
          break;
        case 2:
          tempChannelSymbol = "2";
          break;
        case 3:
          tempChannelSymbol = "3";
          break;
      }
    }
    gridString = String(gridString + tempChannelSymbol);
  }
  if (gridString.length()) {
    gridString = String(gridString + "%");
  }
  return gridString;
}

void loop() {
  int bpmVal = map(analogRead(potPin), 0, 1023, 60, 180);
  String msgToRpi = getGridState(stepCounter);
  delay(60000 / bpmVal / 2); // TODO: podzialke
  if(msgToRpi.length()) {
    Serial.println(msgToRpi); // Sending msg to RPI
  }  
  stepCounter++;
  if (stepCounter > 15) stepCounter = 0;
}

void check_buttons() {
  for (int currentButton = 0; currentButton < NUMBUTTONS; currentButton++){
    int readButton = digitalRead(buttons[currentButton]);
    if (readButton) Serial.println(currentButton);

    if (readButton != lastButtonState[currentButton]) { lastDebounceTime[currentButton] = millis(); }

    if ((millis() - lastDebounceTime[currentButton]) > debounceDelay[currentButton]) {
      if (readButton != buttonState[currentButton]) {
        buttonState[currentButton] = readButton;
        if (buttonState[currentButton] == HIGH) {
          buttonIsPressed[currentButton] = true;
        }
      }
    }

    lastButtonState[currentButton] = readButton;
  }
}

void action() {
  for (int currentButton=0; currentButton<NUMBUTTONS; currentButton++){
    if (buttonIsPressed[currentButton]){
      Serial.println("Buttons is pressed");
      digitalWrite(ledPin, LOW);
      // if (buttonIsPressed[currentButton] == 2) {
      //   // action 2
      //   Serial.println("1");
      // }
      // if (buttonIsPressed[currentButton] == 3) {
      //   // action 3
      //   Serial.println("2");
      // }
      // if (buttonIsPressed[currentButton] == 4) {
      //   // action 4
      //   Serial.println("3");
      // }
      // if (buttonIsPressed[currentButton] == 5) {
      //   // action 3
      //   Serial.println("4");
      // }
    }  
    else {
      digitalWrite(ledPin, HIGH);
    }  
  }
}
