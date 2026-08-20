#include "renderer.h"

renderer::renderer(int width, int height){
    cell_size = 50;
    screen_width = width;
    screen_height = height;

    InitWindow(screen_width, screen_height, "Color Wars");
    SetTargetFPS(60);
}

void renderer::draw_grid(const grid& game_grid){
    int rows = game_grid.get_rows();
    int cols = game_grid.get_cols();

    float cell_width = static_cast<float>(screen_width) / cols;
    float cell_height = static_cast<float>(screen_height) / rows;

    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            float x = col * cell_width;
            float y = row * cell_height;

            const cell& current_cell = game_grid.get_cell(row, col);
            Color cell_color;

            switch(current_cell.get_owner()){
                case player::none:
                    cell_color = GRAY;
                    break;
                case player::player1:
                    cell_color = RED;
                    break;
                case player::player2:
                    cell_color = BLUE;
                    break;
            }

            DrawRectangleLines(
                x,
                y,
                cell_width,
                cell_height,
                cell_color
            );
        }
    }
}
