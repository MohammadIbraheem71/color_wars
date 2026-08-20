#pragma once

#include <vector>
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

        std::vector<std::vector<cell>> cell_grid;

        // this stores what position "exploded"
        std::queue<position> explosion_queue;

        // this function adds a cell to the explosion queue
        void add_to_explosion_queue(int row, int col);

        // this function returns the neighboring cells of a given cell
        std::vector<position> get_neighbors(int row, int col);

        // this function processes the explosions in the explosion queue
        // requires the player value because if player a explodes a cell,
        // the neighboring cells will be incremented and their owner will
        // be set to player a
        void process_explosions(player player_value);
    public:
        // constructor
        grid(int in_rows, int in_cols);

        // returns the number of rows in the grid
        int get_rows();

        // returns the number of columns in the grid
        int get_cols();

        // makes a player's move on the grid at the specified row and column
        // this does not account for the initial move
        // (for the first move, the player can place their value anywhere on the grid)
        // (for subsequent moves, the player can only place their value on a cell that is already owned by them)
        void make_move(int row, int col, player player_value);

        //this function manages the initial moves
        void make_initial_move(int row, int col, player player_value);

        // you can just call this function in the game loop
        // to manage the explosions
        // if theres no explosions, then this function will do nothing
        void manage_explosions();
};
