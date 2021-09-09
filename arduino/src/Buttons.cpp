#include "Buttons.h"

char Buttons::check_button() {
  return keypad.getKey();
}

void Buttons::action() {
// //   for (int currentButton=0; currentButton<NUMBUTTONS; currentButton++){
//     for (int currentButton = 0; currentButton < 4; currentButton++){
//     if (buttonIsPressed[currentButton]){
//       Serial.println("Buttons is pressed");
//     //   digitalWrite(ledPin, LOW);
//       // if (buttonIsPressed[currentButton] == 2) {
//       //   // action 2
//       //   Serial.println("1");
//       // }
//       // if (buttonIsPressed[currentButton] == 3) {
//       //   // action 3
//       //   Serial.println("2");
//       // }
//       // if (buttonIsPressed[currentButton] == 4) {
//       //   // action 4
//       //   Serial.println("3");
//       // }
//       // if (buttonIsPressed[currentButton] == 5) {
//       //   // action 3
//       //   Serial.println("4");
//       // }
//     }  
//     else {
//       digitalWrite(ledPin, HIGH);
//     }  
//   }
}
