#include <iostream>
#include "grid.h"

grid::grid(int in_rows, int in_cols){
    if (in_rows <= 0 and in_cols <= 0){
        std::cout<<"grid constructor: a parameter value is below 0, cannot construct grid"<<std::endl;
        return;
    }
    rows = in_rows;
    cols = in_cols;
    // initiate a 2d array for the grid
    cell_grid = new cell* [rows];
    for (int i = 0; i <= rows; i++){
        cell_grid[i] = new cell[cols];
    }

    std::cout<<"grid constructor: grid constructed"<<std::endl;
    std::cout<<"rows: "<<rows<<" cols: "<<cols<<std::endl;
}
