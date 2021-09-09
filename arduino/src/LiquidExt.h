#include <LiquidCrystal_I2C.h>

#define EMPTY 0
#define FILL 1

class LiquidExt
{
public:
  LiquidCrystal_I2C* lcd;
  LiquidExt(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows);
  ~LiquidExt();

  void init();
  void setCursor(uint8_t col, uint8_t row);
  void printInPosition(uint8_t col, uint8_t row, const char* str);
  void printSignInPosition(uint8_t col, uint8_t row, uint8_t sign);
  void clearGrid();
  void printGrid(uint8_t* gridArray);

private:
  uint8_t _Addr;
  uint8_t _numlines;
  uint8_t _cols;
  uint8_t _rows;
  uint8_t row_offsets[4] = {0x00, 0x40, 0x10, 0x50};

////////// Znaki customowe, można utworzyć do 8
  uint8_t empty[8] = {
    0b11111,
    0b10001,
    0b10001,
    0b10101,
    0b10001,
    0b10001,
    0b10001,
    0b11111};

  uint8_t fill[8] = {
    0b11111,
    0b11111,
    0b11111,
    0b10001,
    0b11111,
    0b11111,
    0b11111,
    0b11111};
};