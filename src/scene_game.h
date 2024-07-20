#ifndef SCENE_GAME_H
#define SCENE_GAME_H
#include "scene.h"
#include "board.h"

void SceneGame_init();
void SceneGame_dispose();
void SceneGame_update(float dt);
void SceneGame_draw();
Scene new_SceneGame();

#endif
