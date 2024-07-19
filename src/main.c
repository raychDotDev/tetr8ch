//#include <stdio.h>
#include <raylib.h>

void update(float dt);
void draw(void);

int main()
{
	InitWindow(720, 640, "TETR8CH");
	SetTargetFPS(60);

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
	return 0;
}

void update(float dt)
{
	
}

void draw() 
{

}




