#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "scene_game.h"

int main()
{
	Game_init(20*30,20*30);
	Game_change_scene(new_SceneGame());
	Game_run();
	return 0;
}





