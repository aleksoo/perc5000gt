#include "Grid.h"

bool Grid::updateGridSingle(int channel, int step) {
    grid[channel][step] = !grid[channel][step];
}

String Grid::getGridState(int step, int soundChoice[]) {
    String gridString = "";

  for (int channel = 0; channel < 4; ++channel) {
    String tempChannelSymbol = "";
    if (grid[channel][step] == true) {
      switch(channel) {
        case 0:
          tempChannelSymbol = "0:" + String(soundChoice[0]);
          break;
        case 1:
          tempChannelSymbol = "1:" + String(soundChoice[1]);
          break;
        case 2:
          tempChannelSymbol = "2:" + String(soundChoice[2]);
          break;
        case 3:
          tempChannelSymbol = "3:" + String(soundChoice[3]);
          break;
      }
    gridString = String(gridString + tempChannelSymbol + "$");
    }
  }
  if (gridString.length()) {
    gridString = String(gridString + "%");
  }
  return gridString;
};

String Grid::getGrid() {
  String channelSequence = "";
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 16; ++i) {
      if (grid[j][i] == true) {
        channelSequence += 'X';
      } else {
        channelSequence += 'O';
      }
    }
  }
  return channelSequence;

  
  // // Serial.println("Grid: ");
  // for (int j = 0; j < 4; j++){
  //   // Serial.print("Channel ");
  //   // Serial.print(j);
  //   // Serial.print(" ");
  //   for (int i = 0; i < 16; i++) 
  //     Serial.print(grid[j][i]);
  // // Serial.println(" ");
  // }
  // // Serial.println(" ");
}

String Grid::getGridChannel(int channel) {
  String channelSequence = "";
  for (int i = 0; i < 16; ++i) {
    if (grid[channel][i] == true) {
      channelSequence += 'X';
    } else {
      channelSequence += 'O';
    }
  }  
  return channelSequence;
}

bool Grid::getSingleGrid(int channel, int step) {
  return this->grid[channel][step];  
}

void Grid::gridFlipState(int channel, int step) {
  // Serial.print("Flipped: ");
  // Serial.println(step);
  // Serial.print("State before: ");
  // Serial.println(grid[1][step]);

  grid[1][step] = !grid[1][step];
}