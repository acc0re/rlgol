#include "game.h"

int main(void)
{
    InitGame(800, 600);

    while (!WindowShouldClose())
    {
        UpdateGame();
        DrawGame();
    }

    UnloadGame();

    return 0;
}