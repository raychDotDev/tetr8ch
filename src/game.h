#ifndef GAME_H
#define GAME_H

#include "scene.h"

static Scene current_scene;

//INIT BEFORE CHANGE SCENE!!
void Game_init();
void Game_run();
void Game_close();
void Game_change_scene(Scene scene);
#endif

