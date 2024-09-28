#include "Application.h"
#include <iostream>
#include "Corners.h"

using namespace std;

void MainLoop()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    int currentLine = 0;
    int currentPosition = START;
    Line myLines[LINES_AMOUNT];

    InitWindow(screenWidth, screenHeight, "Quads");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        CheckLinesCreated(myLines, currentPosition, currentLine);

        BeginDrawing();

        SearchCorner(myLines);

        ClearBackground(BLACK);

        DrawText("Clic on two positions to make a line.", 20, 20, 20, RAYWHITE);
        DrawText("Then continue until you have 4 lines!", 20, 45, 20, RAYWHITE);
        DrawText("Your compliance is not a factor.", 20, 70, 20, RED);

        DrawLines(myLines);

        EndDrawing();
    }

    CloseWindow();
}