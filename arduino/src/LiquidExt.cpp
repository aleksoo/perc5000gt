#include "LiquidExt.h"

LiquidExt::LiquidExt(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows)
{
    this->lcd = new LiquidCrystal_I2C(lcd_Addr, lcd_cols, lcd_rows);

    _Addr = lcd_Addr;
    _cols = lcd_cols;
    _rows = lcd_rows;
}


LiquidExt::~LiquidExt()
{
    delete this->lcd;
}

// inicjalizacja i tworzenie znaków customowych
void LiquidExt::init()
{
    this->lcd->init();
    this->lcd->createChar((uint8_t)EMPTY, this->empty);
    this->lcd->createChar((uint8_t)FILL, this->fill);
    this->lcd->backlight();  
}
// ustawienie cursora na danej pozycji z uwzględnieniem poprawionej tablicy offsetów
void LiquidExt::setCursor(uint8_t col, uint8_t row)
{
	if ( row > _rows ) {
		row = _rows-1;    // we count rows starting w/0
	}
	this->lcd->command(LCD_SETDDRAMADDR | (col + this->row_offsets[row]));
}

// wypisanie stringa na danej pozycji
void LiquidExt::printInPosition(uint8_t col, uint8_t row, const char* str)
{
    this->setCursor(col, row);
    this->lcd->print(str);
}

// wypisanie customowego znaku na danej pozycji
void LiquidExt::printSignInPosition(uint8_t col, uint8_t row, uint8_t sign)
{
    this->setCursor(col, row);
    this->lcd->write((uint8_t) sign);
}

// Print pustego grida
void LiquidExt::clearGrid()
{
    for(uint8_t i = 0; i < this->_rows; ++i)
    {
        for(uint8_t j = 0; j < this->_cols; ++j)
        {
           this->printSignInPosition(j, i, (uint8_t) EMPTY);
        }
    }
}

void LiquidExt::printGrid(uint8_t* gridArray)
{
    for(uint8_t i = 0; i < this->_rows; ++i)
    {
        for(uint8_t j = 0; j < this->_cols; ++j)
        {
            // jeśli na pozycji [i][j] w przekazanej tablicy jest "1", 
            // wyświetli tam znak FILL
            if(*(gridArray+i*this->_cols + j))
                this->printSignInPosition(j, i, (uint8_t) FILL);
        }
    }
}