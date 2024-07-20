#ifndef BOARD_H
#define BOARD_H

#include <raylib.h>

#define BOARD_WIDTH 12
#define BOARD_HEIGHT 20


typedef struct t_board {
	int* cells;
	int width;
	int height;
	int* shape;
	int shape_width;
	int shape_height;
} Board;

Board new_Board();

void Board_draw(Board board);

void Board_dispose(Board board);

#endif
