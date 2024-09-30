#pragma once
#include <raylib.h>

const int MAX_CORNERS = 6;

struct Line
{
	Vector2 Start;
	Vector2 Finish;
	Vector2 Corners[MAX_CORNERS];
	Vector2 quadCorners[4];
	int CornersAmount;
	int lineCounter;
	bool Done = false;
	bool isquadDraw = false;
};

const int START = 1;
const int FINISH = 2;
const int LINES_AMOUNT = 4;

/**
 * @brief saves a coord when left click
 * @return Vector with coordinates
 */
Vector2 GetMouseCoord();

/**
 * @brief Draw a line on screen with color red and save it in an array
 * @param line
 * @param lines
 */
void DrawLine(Line line, Line lines[LINES_AMOUNT], int currentPos);

void CheckLinesCreated(Line myLines[], int& currentPosition, int& currentLine);

void DrawLines(Line myLines[]);