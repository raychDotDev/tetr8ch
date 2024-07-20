#include <raylib.h>
#include "scene_game.h"
#include "scene.h"
#include "board.h"

Board board;

void SceneGame_init(){
	board = new_Board();
}

void SceneGame_dispose(){
	Board_dispose(board);
}

void SceneGame_update(float dt)
{

}

void SceneGame_draw()
{
	DrawText("BEBRA", 10, 10, 20, WHITE);

	Board_draw(board);
}

Scene new_SceneGame()
{
	return (Scene){
		.draw = SceneGame_draw,
		.update = SceneGame_update,
		.init = SceneGame_init,
		.dispose = SceneGame_dispose
	};
}
