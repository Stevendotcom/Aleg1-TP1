#pragma once
#include "Squares.h"

void SearchCorner(Line lines[]);
void LineIntersections(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, Line lineCorners[], int lineIndex);
void AddCorner(Vector2 lineCorners[], int newY, int newX);