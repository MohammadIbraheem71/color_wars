#include "raylib.h"

int main()
{
    InitWindow(800, 450, "My Raylib Game");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello Raylib!", 300, 200, 30, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
