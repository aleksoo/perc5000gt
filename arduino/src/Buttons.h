#ifndef BUTTONS_H
#define BUTTONS_H

#include <Keypad.h>

class Buttons {
    private:
        static const byte KEYPAD_ROWS = 4;
        static const byte KEYPAD_COLS = 4;

        int menuStates[3] = {0, 1, 2};

        int keys[KEYPAD_ROWS][KEYPAD_COLS] = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11},
            {12, 13, 14, 15}
        };

        byte rowPins[KEYPAD_ROWS] = {2, 3, 4, 5};
        byte colPins[KEYPAD_COLS] = {6, 7, 8, 9};

        Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS );

    public:

        void action();
        char check_button();
};

#endif