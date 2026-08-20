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

void grid::add_to_explosion_queue(int row, int col){
    if (row < 0 || row >= rows || col < 0 || col >= cols){
        throw std::out_of_range("row or column is out of range");
    }

    //check if the cell is critical before adding it to the explosion queue
    if (!cell_grid[row][col].critical()){
        throw std::invalid_argument("grid: cell is not critical, cant add it to explosion queue");
    }

    explosion_queue.push({row, col});
}

std::vector<position> grid::get_neighbors(int row, int col){
    std::vector<position> neighbors;

    // check the cell above
    if (row > 0){
        neighbors.push_back({row - 1, col});
    }

    // check the cell below
    if (row < rows - 1){
        neighbors.push_back({row + 1, col});
    }

    // check the cell to the left
    if (col > 0){
        neighbors.push_back({row, col - 1});
    }

    // check the cell to the right
    if (col < cols - 1){
        neighbors.push_back({row, col + 1});
    }

    return neighbors;
}

// this is the private function
void grid::process_explosions(player player_value){
    while (!explosion_queue.empty()){
        position explosion_position = explosion_queue.front();
        explosion_queue.pop();

        // reset the current exploded cell
        cell_grid[explosion_position.row][explosion_position.col].reset();

        // now we need to get the neighboring cells and increment them
        std::vector<position> neighbors = get_neighbors(explosion_position.row, explosion_position.col);

        // now increment each of the neighbouring cells and
        // switch the owner
        // if any are critical after the increment,
        // then we need to add them to the explosion queue
        for (const auto& neighbor : neighbors){
            cell_grid[neighbor.row][neighbor.col].increment(player_value);

            if (cell_grid[neighbor.row][neighbor.col].critical()){
                explosion_queue.push(neighbor);
            }
        }

    }
}

int grid::get_rows() const{
    return rows;
}

int grid::get_cols() const{
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

    if (cell_grid[row][col].critical()){
        std::cout<<"grid: cell at row "<<row<<" col "<<col<<" is critical, adding to explosion queue"<<std::endl;
        add_to_explosion_queue(row, col);
    }
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

void grid::manage_explosions(){
    if (!explosion_queue.empty()){
        std::cout<<"grid: processing explosions"<<std::endl;
        process_explosions(cell_grid[explosion_queue.front().row][explosion_queue.front().col].get_owner());
    }
}

const cell& grid::get_cell(int row, int col) const{
    if (row < 0 || row >= rows || col < 0 || col >= cols){
        throw std::out_of_range("row or column is out of range");
    }

    return cell_grid[row][col];
}
