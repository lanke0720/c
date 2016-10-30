#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include <stdlib.h>
#include <stdio.h>

enum OP
{
	EXIT,
	GAME
};

void menu()
{
	printf("*********   1.play    *********\n");
	printf("*********   0.exit    *********\n");
}
void game()
{
	//printf("play game\n");
	char board[ROWS][COLS] = {0};
	char ret = ' ';
	init_board(board);
	print_board(board);
	do
	{	
		play_move(board);
		ret = check_win(board);
		if(ret != ' ')
			break;
		if(check_full(board) == 1)
			ret = 'q';
		print_board(board);
		computer_move(board);
		ret = check_win(board);
		if(ret != ' ')
			break;
		if(check_full(board) == 1)
			ret = 'q';
		print_board(board);
	}while(ret == ' ');
	print_board(board);
	if(ret == 'X')
		printf("玩家赢\n");
	else if(ret == '0')
		printf("电脑赢\n");
	else if(ret == 'q')
		printf("平局\n");
}
int main()
{
	int input = 1;
	while(input)
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch(input)
		{
		case GAME:
			game();
			break;
		case EXIT:
			exit(EXIT_SUCCESS);
			break;
		}
	}
	return 0;
}





