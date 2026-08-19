#pragma once

#include "../grid/grid.h"
#include <memory>

class grid_manager{
    private:
        bool player1_initial_move;
        bool player2_initial_move;

        player current_player;

        std::unique_ptr<grid> game_grid;

    public:
        grid_manager(int rows, int cols);

        // returns the current player
        player get_current_player();

        // switches the current player to the other player
        void switch_player();

        // makes a move on the grid at the specified row and column
        void make_move(int row, int col);

        // returns true if both players have made their initial moves
        bool initial_moves_complete();
};
