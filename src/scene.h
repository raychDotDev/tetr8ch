#ifndef SCENE_H
#define SCENE_H

typedef struct scene {
	void (*init)();
	void (*dispose)();
	void (*update)(float dt);
	void (*draw)();
} Scene;

#endif
