#ifndef GRID_H
#define GRID_H
#include <Arduino.h>

class Grid {
    private:
        bool grid[4][16] = {
            // {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            // {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            // {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
            // {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}
            {true, false, false, false, true, false, false, false, true, false, false, false, true, false, false, false},
            {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true},
            {false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false}
        };
    
    public:
        String getGridState(int step);
        String getGrid();
        bool updateGridSingle(int channel, int step);
        void gridFlipState(int channel, int step);
        String getGridChannel(int channel);
        bool getSingleGrid(int channel, int step);
};

#endif