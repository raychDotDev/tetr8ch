#ifndef BOARD_H
#define BOARD_H

#include <raylib.h>

#define BOARD_WIDTH 13
#define BOARD_HEIGHT 20


typedef struct t_board {
	int* cells;
	int width;
	int height;
	int* shape;
	int shape_width;
	int shape_height;
	int shape_x;
	int shape_y;
	int shape_r;
} Board;

Board new_Board();

void Board_draw(Board board);

void Board_dispose(Board *board);

void Board_moveLeft(Board *board);
void Board_moveRight(Board *board);
#endif
