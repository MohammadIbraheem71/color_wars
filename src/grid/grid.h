#pragma once

#include <queue>
#include "../cell/cell.h"

struct position{
    int row;
    int col;
};

class grid{
    private:
        int rows;
        int cols;

        cell** cell_grid;

        std::queue<position> explosion_queue;
    public:
        // constructor
        grid(int in_rows, int in_cols);



};
