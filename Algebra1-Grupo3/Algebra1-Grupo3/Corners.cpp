#include "Corners.h"

void SearchCorner(Line line[], Line corners[])
{
	Line auxLine;

	for (int i = 0; i < LINES_AMOUNT; i++)
	{
		auxLine = line[i];

		for (int j = 0; j < LINES_AMOUNT; j++)
		{
			if (auxLine.Start.x != line[j].Start.x && auxLine.Start.y != line[j].Start.y)
			{
				LineIntersections(auxLine.Start.x, auxLine.Start.y, auxLine.Finish.x, auxLine.Finish.y, line[j].Start.x, line[j].Start.y, line[j].Finish.x, line[j].Finish.y, corners);
			}
		}
	}
}

void LineIntersections(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, Line intersections[])
{
	Line auxCorner;

	// calculate the distance to intersection point
	float uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
	float uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

	// if uA and uB are between 0-1, lines are colliding
	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
	{
		// optionally, draw a circle where the lines meet
		float intersectionX = x1 + (uA * (x2 - x1));
		float intersectionY = y1 + (uA * (y2 - y1));

		AddCorner(intersections, intersectionY, intersectionX);

		DrawCircle(intersectionX, intersectionY, 5, RED);
	}
}

void AddCorner(Line intersections[], int newY, int newX)
{
	for (int i = 0; i < MAX_CORNERS; i++)
	{
		if (!intersections[i].Done)
		{
			intersections[i].Corners[i].x = newX;
			intersections[i].Corners[i].y = newY;
			intersections[i].Done = true;
			return;
		}
	}

}

bool IsSameCorner(const Vector2& corner1, const Vector2& corner2)
{
	return corner1.x < FLT_EPSILON + corner2.x && corner1.x > corner2.x - FLT_EPSILON
		&& corner1.y < FLT_EPSILON + corner2.y && corner1.y > corner2.y - FLT_EPSILON;
}