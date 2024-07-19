#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

static int *field;

#define FIELD_W 10
#define FIELD_H 24
#define CELL_SIZE 16

void init()
{
	field = (int*)malloc(sizeof(int)*(FIELD_W*FIELD_H));

	for(int i = 0; i < FIELD_H; i++)
	{
		for (int j = 0; j < FIELD_W; j++)
		{	
			field[i*FIELD_W+j] = 0;
		}
	}
}

void dispose()
{
	free(field);

}

void update(float dt)
{
}

void draw() 
{
	for(int i = 0; i < FIELD_H; i++)
	{
		for (int j = 0; j < FIELD_W; j++)
		{
			int cell = field[i*FIELD_W+j];
			if(cell > 0)
			{
				DrawRectangle(j*CELL_SIZE, i*CELL_SIZE, CELL_SIZE, CELL_SIZE, RED);
			}
			
			{
				DrawRectangleLines(j*CELL_SIZE, i*CELL_SIZE, CELL_SIZE, CELL_SIZE, WHITE);
			}
			//switch(field[i*FIELD_H + j]){}
		}
	}
}

int main()
{
	InitWindow(720, 640, "TETR8CH");
	SetTargetFPS(60);
	init();
	while(!WindowShouldClose())
	{	
		update(GetFrameTime());
		BeginDrawing();
		{
			ClearBackground(BLACK);
			draw();
		}
		EndDrawing();
	}
	CloseWindow();
	dispose();
	return 0;
}





