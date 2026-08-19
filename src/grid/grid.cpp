#include <iostream>
#include "grid.h"

grid::grid(int in_rows, int in_cols){
    if (in_rows <= 0 || in_cols <= 0){
        throw std::invalid_argument("grid dimensions must be positive");
    }
    rows = in_rows;
    cols = in_cols;
    // initiate a 2d array for the grid
    cell_grid.resize(rows, std::vector<cell>(cols));

    std::cout<<"grid constructor: grid constructed"<<std::endl;
    std::cout<<"rows: "<<rows<<" cols: "<<cols<<std::endl;
}

int grid::get_rows(){
    return rows;
}

int grid::get_cols(){
    return cols;
}

void grid::make_move(int row, int col, player player_value){
    if (row < 0 || row >= rows || col < 0 || col >= cols){
        throw std::out_of_range("row or column is out of range");
    }

    if (cell_grid[row][col].get_owner() != player_value){
        throw std::invalid_argument("player can only make a move on a cell they own");
    }

    // if the player is placing on his own cell, the increment
    // the value

    cell_grid[row][col].increment(player_value);
    std::cout<<"grid: owner "<<static_cast<int>(player_value)<<" placed value on cell at row "<<row<<" col "<<col<<std::endl;
}

void grid::make_initial_move(int row, int col, player player_value){
    if (row < 0 || row >= rows || col < 0 || col >= cols){
        throw std::out_of_range("row or column is out of range");
    }

    if (cell_grid[row][col].get_owner() != player::none){
        throw std::invalid_argument("cell is already owned by a player");
    }

    // if no one owns the cell, then the player can place their value on it
    cell_grid[row][col].increment(player_value);
}
