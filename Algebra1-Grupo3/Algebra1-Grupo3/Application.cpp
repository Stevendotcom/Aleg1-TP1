#include "Application.h"
#include <iostream>
#include "Corners.h"

using namespace std;

bool isIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, Line myLine);
void GetQuad(Line myLines[], Line Intersect[]);

void MainLoop()
{
	const int screenWidth = 800;
	const int screenHeight = 600;
	int MAX_LINES = 4;

	int currentLine = 0;
	int currentPosition = START;

	Line myLines[LINES_AMOUNT];

	Line Intersect[MAX_CORNERS];

	Line Quad[MAX_CORNERS];



	InitWindow(screenWidth, screenHeight, "Quad test");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		CheckLinesCreated(myLines, currentPosition, currentLine);

		BeginDrawing();

		SearchCorner(myLines, Intersect->Corners);

		ClearBackground(BLACK);

		DrawText("Clic on two positions!", 20, 20, 20, WHITE);

		if (myLines->lineCounter == LINES_AMOUNT)
		{
			GetQuad(myLines, Quad);
		}

		DrawLines(myLines);

		EndDrawing();
	}

	CloseWindow();
}

bool isIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, Line myLine)
{
	// calculate the distance to intersection point
	float uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
	float uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

	// if uA and uB are between 0-1, lines are colliding
	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
	{
		float intersectionX = x1 + (uA * (x2 - x1));
		float intersectionY = y1 + (uA * (y2 - y1));

		myLine.quadCorners->x = intersectionX;
		myLine.quadCorners->y = intersectionY;

		return true;
	}
	else
	{
		return false;
	}
}

void GetQuad(Line myLines[], Line Intersect[])
{
	Line actualLine;
	Line nextLine;
	Line oldLine1;
	Line oldLine2;
	Line oldLine3;
	Line oldLine4;

	bool isIntersect1 = false;
	bool isIntersect2 = false;
	bool isIntersect3 = false;
	bool isIntersect4 = false;
	bool isOpen = false;

	if (!Intersect->isquadDraw)
	{
		for (int i = 0; i < LINES_AMOUNT; i++)
		{
			actualLine = myLines[i];

			for (int j = 0; j < LINES_AMOUNT; j++)
			{

				if (actualLine.Start.x != myLines[j].Start.x && actualLine.Start.y != myLines[j].Start.y)
				{
					isIntersect1 = isIntersect(actualLine.Start.x, actualLine.Start.y, actualLine.Finish.x, actualLine.Finish.y, myLines[j].Start.x, myLines[j].Start.y, myLines[j].Finish.x, myLines[j].Finish.y, Intersect[i]);
					nextLine = myLines[j];
				}

				//si la primera linea es intersectada paso a analizar la que sigue
				if (isIntersect1)
				{
					for (int i = 0; i < LINES_AMOUNT; i++)
					{
						actualLine = nextLine;

						for (int j = 0; j < LINES_AMOUNT; j++)
						{

							isIntersect2 = isIntersect(actualLine.Start.x, actualLine.Start.y, actualLine.Finish.x, actualLine.Finish.y, myLines[j + 2].Start.x, myLines[j + 2].Start.y, myLines[j + 2].Finish.x, myLines[j + 2].Finish.y, Intersect[i + 1]);


							//si la segunda linea es intersectada paso a analizar la que sigue
							if (isIntersect2)
							{

								for (int i = 0; i < LINES_AMOUNT; i++)
								{
									actualLine = myLines[i + 2];

									for (int j = 0; j < LINES_AMOUNT; j++)
									{

										isIntersect3 = isIntersect(actualLine.Start.x, actualLine.Start.y, actualLine.Finish.x, actualLine.Finish.y, myLines[j + 3].Start.x, myLines[j + 3].Start.y, myLines[j + 3].Finish.x, myLines[j + 3].Finish.y, Intersect[i + 2]);



										//si la tercera linea es intersectada paso a analizar la que sigue
										if (isIntersect3)
										{
											for (int i = 0; i < LINES_AMOUNT; i++)
											{
												actualLine = myLines[i + 3];

												for (int j = 0; j < LINES_AMOUNT; j++)
												{

													isIntersect3 = isIntersect(actualLine.Start.x, actualLine.Start.y, actualLine.Finish.x, actualLine.Finish.y, myLines[j].Start.x, myLines[j].Start.y, myLines[j].Finish.x, myLines[j].Finish.y, Intersect[i + 3]);

													//si la tercera linea es intersectada paso a analizar la que sigue
													if (isIntersect4)
													{
														DrawLine(Intersect[i].Corners->x, Intersect[i].quadCorners->y, Intersect[i + 1].Corners->x, Intersect[i + 1].quadCorners->y, BLUE);
														DrawLine(Intersect[i + 1].Corners->x, Intersect[i + 1].quadCorners->y, Intersect[i + 2].Corners->x, Intersect[i + 2].quadCorners->y, BLUE);
														DrawLine(Intersect[i + 2].Corners->x, Intersect[i + 2].quadCorners->y, Intersect[i + 3].Corners->x, Intersect[i + 3].quadCorners->y, BLUE);
														DrawLine(Intersect[i + 3].Corners->x, Intersect[i + 3].quadCorners->y, Intersect[i].Corners->x, Intersect[i].quadCorners->y, BLUE);
														Intersect->isquadDraw = true;
													}

												}
											}
										}

									}
								}

							}

						}
					}
				}

			}

			break;
		}

	}

}