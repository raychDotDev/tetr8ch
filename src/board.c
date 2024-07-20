#include <raylib.h>
#include <stdlib.h>

#include "board.h"

Board new_Board()
{
	Board b;
	b.cells = malloc(sizeof(int)*BOARD_WIDTH*BOARD_HEIGHT);
	b.width = BOARD_WIDTH;
	b.height = BOARD_HEIGHT;
	for(int i=0;i<b.width*b.height;i++)b.cells[i] = 0;	
	b.shape_height = 4;
	b.shape_width = 2;
	b.shape = malloc(sizeof(int)*b.shape_width*b.shape_height);
	for(int i=0;i<b.shape_width*b.shape_height;i++)b.shape[i] = 0;	
	return b;
}

void Board_draw(Board board)
{
	int sw = GetScreenWidth();
	int sh = GetScreenHeight();
	int v = sh/board.height;
	int h = sw/board.width;
	v > h ? v = h : 0;
	int h_off = (sw / 2) - (board.width*v)/2;
	int v_off = (sh /2) - (board.height*v)/2;
	for(int i = 0; i < board.height; i++)
	{
		for(int j = 0; j < board.width; j++)
		{
			DrawRectangleLines(j*v+h_off,i*v+v_off,v,v,WHITE);
			if(!(board.cells[i*board.width+j] > 0)) continue;
			
		}
	}
}

void Board_dispose(Board board)
{
	free(board.cells);
	free(board.shape);
}



