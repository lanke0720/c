#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <time.h>
#include <stdlib.h>



#define COLS 3
#define ROWS 3

typedef unsigned int uint;

void init_board(char board[ROWS][COLS]);
void print_board(char board[ROWS][COLS]);
char check_win(char board[ROWS][COLS]);
void play_move(char board[ROWS][COLS]);
void computer_move(char board[ROWS][COLS]);
int check_full(char board[ROWS][COLS]);

#endif    //__GAME_H__