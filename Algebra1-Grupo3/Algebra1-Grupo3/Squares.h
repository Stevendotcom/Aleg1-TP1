#pragma once
#include "raylib.h"

const int LINES_AMOUNT = 4;

struct Line
{
	Vector2 Start;
	Vector2 Finish;
};

/**
 * @brief saves a coord when left click
 * @return Vector with coordinates
 */
Vector2 GetMouseCoord();

/**
 * @brief Draw a line on screen with COLOR_LINE and save it on an array
 * @param line
 * @param lines 
 */
void DrawLine(Line &line, Line lines[LINES_AMOUNT]);

/**
 * @brief checks if lines form a quad
 * @param lines Array with lines
 * @return true if is it a quad
 */
bool IsAQuad(Line lines[LINES_AMOUNT]);