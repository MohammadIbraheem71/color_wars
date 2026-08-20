#pragma once

#include "../grid/grid.h"
#include <raylib.h>

class renderer{
    private:
        int cell_size;
        int screen_width;
        int screen_height;

    public:
        renderer(int width, int height);

        void draw_grid(const grid& game_grid);
};
