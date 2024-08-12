#include "MainLoop.h"

void MainLoop()
{
	Line lines[LINES_AMOUNT];
	Vector2 start;
	Vector2 finish;

	bool hasFirstPointSet = false;
	bool hasQuadBeenMade = false;
	int linesSet = 0;

	while (!WindowShouldClose())
	{
		if (linesSet < LINES_AMOUNT)
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if (!hasFirstPointSet)
				{
					hasFirstPointSet = true;
					start = GetMouseCoord();
				}
				else
				{
					hasFirstPointSet = false;
					finish = GetMouseCoord();

					Line line = {start, finish};
					DrawLine(line, lines);
					linesSet++;
				}
			}
		}
		else
		{
			hasQuadBeenMade = IsAQuad(lines);

			if (!hasQuadBeenMade)
			{
				BeginDrawing();

				DrawText("You did not made a Quad!", 10, 10, 20, LINE_COLOR);

				EndDrawing();
			}
			else
			{
				// TODO Calc area and per
			}
		}
	}
}
