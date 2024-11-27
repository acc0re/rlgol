#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "game.h"
#include "array.h"

const Color COLOR_GRID = {40, 40, 40, 255};
const Color COLOR_BG = {10, 10, 10, 255};
const Color COLOR_DIE_NEXT = {170, 170, 170, 255};

#define GRID_HEIGHT 90
#define GRID_WIDTH 160

static int **cells;
static int **updated_cells;
static RenderTexture2D screen;
static bool running = false;



void InitGame(const int screenWidth, const int screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Raylib - Conways Game of Life");
    SetTargetFPS(20);

    cells = createArray(GRID_HEIGHT, GRID_WIDTH);
    updated_cells = createArray(GRID_HEIGHT, GRID_WIDTH);

    screen = LoadRenderTexture(screenWidth, screenHeight);
    update(screen, cells, updated_cells, 10, false);
}

void UpdateGame(void)
{
    if (IsKeyReleased(KEY_SPACE)) {
        running = !running;
        update(screen, cells, updated_cells, 10, false);
    }
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 pos = GetMousePosition();
        int x = (int)pos.x;
        int y = (int)pos.y;
        if ((x >= 0 && x < GetScreenWidth()) && (y >= 0 && y < GetScreenHeight())) {
            cells[y/10][x/10] = 1;
            update(screen, cells, updated_cells, 10, false);
        }
    }
    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
        srand(time(NULL)); // Seed the random number generator
        for (int i = 0; i < GRID_HEIGHT; i++) {
            for (int j = 0; j < GRID_WIDTH; j++) {
                cells[i][j] = rand() % 2; // Set each cell to either 0 or 1 randomly
            }
        }
        update(screen, cells, updated_cells, 10, false);
    }

    if (running) {
        copyArray(cells, update(screen, cells, updated_cells, 10, true), GRID_HEIGHT, GRID_WIDTH);
    }
}

void DrawGame(void)
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTextureRec(screen.texture, (Rectangle){0, 0, GetScreenWidth(), -GetScreenHeight()}, (Vector2){0, 0}, WHITE);

    if (!running) {
        Color customColor = ColorFromHex("25D36F");
        DrawText("Press MOUSE LEFT  to draw alive cells", 10, 10, 20, customColor);
        DrawText("Press MOUSE RIGHT to generate random pattern", 10, 30, 20, customColor);
        DrawText("Press SPACE to start the simulation", 10, 50, 20, customColor);
    }

    EndDrawing();
}

void UnloadGame(void)
{
    destroyArray(cells);
    destroyArray(updated_cells);
    UnloadRenderTexture(screen);
    CloseWindow();
}

int **update(const RenderTexture2D screen, int **cells, int **updated_cells, const int size, const bool with_progress) {
    fillArray(updated_cells, GRID_HEIGHT, GRID_WIDTH, 0);

    BeginTextureMode(screen);
    ClearBackground(COLOR_GRID);
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++) {
            const int alive = sumArray(cells, GRID_HEIGHT, GRID_WIDTH, (Range){row-1, col-1, 3, 3}) - cells[row][col];
            Color color = cells[row][col] == 0 ? COLOR_BG : BLUE;

            if (cells[row][col] == 1) {
                if (alive < 2 || alive > 3) {
                    if (with_progress) {
                        color = COLOR_DIE_NEXT;
                    }
                } else if (alive >= 2 && alive <= 3) {
                    updated_cells[row][col] = 1;
                    if (with_progress) {
                        color = BLUE;
                    }
                }
            } else {
                if (alive == 3) {
                    updated_cells[row][col] = 1;
                    if (with_progress) {
                        color = BLUE;
                    }
                }
            }

            DrawRectangle(col * size, row * size, size - 1, size - 1, color);
        }
    }
    EndTextureMode();

    return updated_cells;
}

Color ColorFromHex(const char *hex) {
    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    return (Color){r, g, b, 255};
}