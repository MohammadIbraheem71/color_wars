#include "grid_manager.h"

grid_manager::grid_manager(int rows, int cols){
    player1_initial_move = false;
    player2_initial_move = false;

    current_player = player::player1;

    game_grid = std::unique_ptr<grid>(new grid(rows, cols));
}



player grid_manager::get_current_player(){
    return current_player;
}

void grid_manager::switch_player(){
    if (current_player == player::player1){
        current_player = player::player2;
    } else {
        current_player = player::player1;
    }
}

void grid_manager::make_move(int row, int col){
    if(!initial_moves_complete()){
        // some player's initial move is not complete
        game_grid->make_initial_move(row, col, current_player);
    } else {
        // both players have made their initial moves
        game_grid->make_move(row, col, current_player);

        grid_manager::switch_player();
    }
}
