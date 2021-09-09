#include "Screen.h"

Screen::Screen(LiquidCrystal_I2C lcdObject) {
    lcd = &lcdObject;
    lcd->init();
    lcd->backlight();
    lcd->setCursor(0, 0);
    lcd->print("aaaa    aaaa");
}

void Screen::printToScreen(int row, String sequence) {    
    lcd->setCursor(0, 0);
    lcd->print("Welcome");

    // lcd.setCursor(0, 0); // First row

    // lcd.setCursor(0,1); // Second row

    // lcd.setCursor(-4,2); // Third row

    // lcd.setCursor(-4,3); // Forth row
}