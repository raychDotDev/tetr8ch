#include <raylib.h>
#include <stdlib.h>

#include "board.h"
static int shapes[7][5*5] = {
	{
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,0,0,0
	},
	{
		0,0,0,0,0,
		0,0,1,1,0,
		0,1,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
	{
		0,0,0,0,0,
		0,1,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
	{
		0,0,0,0,0,
		0,0,1,1,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
	{
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
	{
		0,0,1,0,0,
		0,0,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
	{
		0,0,1,0,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	}

};
Board new_Board()
{
	Board b;
	b.cells = malloc(sizeof(int)*BOARD_WIDTH*BOARD_HEIGHT);
	b.width = BOARD_WIDTH;
	b.height = BOARD_HEIGHT;
	for(int i=0;i<b.width*b.height;i++)b.cells[i] = 0;	
	b.shape_height = 5;
	b.shape_width = 5;
	b.shape = shapes[GetRandomValue(0,6)];
	b.shape_x = BOARD_WIDTH/2;
	b.shape_y = BOARD_HEIGHT/2;
	b.shape_r = 0;
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

	for(int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{	
			if(board.shape[y*5+x] > 0)
			{
				DrawRectangle((x-2 + board.shape_x)*v+h_off,(y-2 + board.shape_y)*v+v_off,v,v,WHITE);
			}
		}
	}

	for(int i = 0; i < board.height; i++)
	{
		for(int j = 0; j < board.width; j++)
		{
			DrawRectangleLines(j*v+h_off,i*v+v_off,v,v,WHITE);
			


			if(!(board.cells[i*board.width+j] > 0)) continue;
			
		}
	}
}

void Board_dispose(Board *board)
{	
	free(board->cells);
}

int tryMove(Board board, int dir)
{
	for (int i = 0; i < board.shape_height; i++)
	{
		for (int j = 0; j < board.shape_width; j++)
		{
			int cell = board.shape[i*board.shape_width+j];
			if (cell > 0)
			{
				if ((j - 2) + (board.shape_x+dir) < 0 ||
					(j - 2) + (board.shape_x+dir) >= board.width)
				{
					return false;
				}
			}
		}
	}
	return true;
}

void Board_moveLeft(Board *board)
{
	if (!tryMove(*board, -1)) return;
	board->shape_x--;
}

void Board_moveRight(Board *board)
{
	if (!tryMove(*board, 1)) return;
	board->shape_x++;
}
