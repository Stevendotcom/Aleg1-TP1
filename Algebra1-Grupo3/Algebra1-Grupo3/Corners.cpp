#include "Corners.h"

void SearchCorner(Line lines[])
{
	Line auxLine;

	for (int i = 0; i < LINES_AMOUNT; i++)
	{
		auxLine = lines[i];

		for (int j = 0; j < LINES_AMOUNT; j++)
		{
			if (auxLine.Start.x != lines[j].Start.x && auxLine.Start.y != lines[j].Start.y)
			{
				LineIntersections(auxLine.Start.x, auxLine.Start.y, auxLine.Finish.x, auxLine.Finish.y, lines[j].Start.x, lines[j].Start.y, lines[j].Finish.x, lines[j].Finish.y, lines, j);
			}
		}
	}
}

void LineIntersections(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, Line lines[], int lineIndex)
{

	// calculate the distance to intersection point
	float uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
	float uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

	// if uA and uB are between 0-1, lines are colliding
	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
	{
		// optionally, draw a circle where the lines meet
		float intersectionX = x1 + (uA * (x2 - x1));
		float intersectionY = y1 + (uA * (y2 - y1));

		AddCorner(lines[lineIndex].Corners, intersectionY, intersectionX);

		DrawCircle(intersectionX, intersectionY, 5, RED);
	}
}

void AddCorner(Vector2 lineCorners[], int newY, int newX)
{
	Vector2 newCorner = { newX, newY };

	for (int i = 0; i < MAX_CORNERS; i++)
	{
		if (!IsSameCorner(lineCorners[i], newCorner))
		{
			lineCorners[i] = newCorner;
			return;
		}
	}
}

bool IsSameCorner(Vector2& corner1, Vector2& corner2)
{
	return corner1.x < FLT_EPSILON + corner2.x && corner1.x > corner2.x - FLT_EPSILON
		&& corner1.y < FLT_EPSILON + corner2.y && corner1.y > corner2.y - FLT_EPSILON;
}

void DrawCorners(Line line[])
{
	for (int i = 0; i < LINES_AMOUNT; i++)
		for (int j = 0; j < MAX_CORNERS; j++)
			DrawCircle(line[i].Corners[j].x, line[i].Corners[j].y, 5, RED);
}