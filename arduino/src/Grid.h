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
        void updateGridSingle(int channel, int step);
        void gridFlipState(int channel, int step);
};

#endif