#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void init_board(char board[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	for(i = 0; i<ROWS; i++)
	{
		for(j=0; j<COLS; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void print_board(char board[ROWS][COLS])
{
	int i = 0;
	for(i=0; i<ROWS; i++)
	{
		printf(" %c | %c | %c \n", board[i][0],board[i][1],board[i][2]);
		if(i != 2)
			printf("---|---|---\n");
	}
}


void play_move(char board[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	printf("请输入对应的坐标:>");
	scanf("%d%d", &x, &y);
	x--;
	y--;
	//assert( (x>=0) && (x<=2) );
	//assert( (y>=0) && (y<=2) );
	if(board[x][y] == ' ')
	{
		board[x][y] = 'X';
	}
	else
	{	
		play_move(board);
	}
}

int check_full(char board[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	for(i=0; i<ROWS; i++)
	{
		for(j = 0;j<COLS; j++)
		{
			if(board[i][j]==' ')
				return 0;//未满
		}
	}
	return 1;//满
}

char check_win(char board[ROWS][COLS])
{
	int i = 0;
	for(i = 0; i<ROWS; i++)
	{
		if((board[i][0] == board[i][1])
			&&(board[i][1] == board[i][2]) 
			&& (board[i][0]!=' '))
			return board[i][0];
	}
	for(i = 0; i<COLS; i++)
	{
		if((board[0][i] == board[1][i])
		 &&(board[1][i] == board[2][i]) 
		 &&(board[0][i]!=' '))
			return board[0][i];
	}

	if((board[0][0]==board[1][1]) && 
	   (board[1][1]==board[2][2]) && 
	   (board[0][0]) != ' ')
	   return board[0][0];

	if((board[0][2]==board[1][1]) && 
		(board[1][1]==board[2][0]) && 
		(board[1][1]) != ' ')
		return board[1][1];

	return ' ';
}

void computer_move(char board[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	printf("电脑玩！！！！！\n");
	srand((uint)time(NULL));
	if(check_full(board) == 0)
	{
		while(1)
		{
			x = rand()%3;
			y = rand()%3;
			if(board[x][y] == ' ')
			{
				board[x][y] = '0';
				break;
			}
		}
	}
}


