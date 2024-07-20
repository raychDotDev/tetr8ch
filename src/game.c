#include <raylib.h>

#include "game.h"

void Game_init()
{
	InitWindow(320,640, "TETR8CH");
	SetTargetFPS(120);
	//ещё ченить точно надо, хз
}

void Game_run()
{
	while(!WindowShouldClose())
	{
		if(current_scene.update)
		{
			current_scene.update(GetFrameTime());
		}

		BeginDrawing();
		{
			ClearBackground(BLACK);
			if (current_scene.draw)
			{
				current_scene.draw();
			}
		}
		EndDrawing();
	}

	Game_close();
}

void Game_change_scene(Scene scene)
{
	if (current_scene.dispose)
	{
		current_scene.dispose();
	}
	current_scene = scene;
	if (current_scene.init) 
	{
		current_scene.init();
	}
}

void Game_close()
{
	if (current_scene.dispose)
	{
		current_scene.dispose();
	}
}

