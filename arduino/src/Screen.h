#ifndef BUTTONS_H
#define BUTTONS_H

#include <LiquidCrystal_I2C.h>

class Screen {
    private:
        LiquidCrystal_I2C *lcd; // lcdColumns, lcdRows

    public:
        Screen(LiquidCrystal_I2C lcdObject);

        void printToScreen(int row, String sequence);
};

#endif