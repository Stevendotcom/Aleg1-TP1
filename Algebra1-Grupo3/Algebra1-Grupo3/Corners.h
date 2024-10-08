#pragma once
#include "Squares.h"

void SearchCorner(Line line[], int linesCreated);
void LineIntersections(Line& lineA, const Line& lineB);
void AddCorner(Line& line, float newX, float newY);
float FindSlope(const Line& line);
float FindB(const Line& line, float m);
void DrawCorners(Line line[]);

