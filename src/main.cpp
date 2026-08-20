
#include "grid_manager/grid_manager.h"
#include "renderer/renderer.h"

int main(){

    grid_manager test_game(10, 10);
    renderer test_renderer(800, 800);

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        test_renderer.draw_grid(test_game.get_grid());

        EndDrawing();
    }

    return 0;
}
