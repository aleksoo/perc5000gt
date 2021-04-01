#include "Grid.h"

void Grid::updateGridSingle(int channel, int step) {
    grid[channel][step] = !grid[channel][step];
}

String Grid::getGridState(int step) {
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
};

void Grid::gridFlipState(int channel, int step) {
  grid[1][step] != grid[1][step];
}