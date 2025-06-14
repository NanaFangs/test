#pragma once

#include <stdio.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

void InitBoard(char board[ROWS][COLS], int rows, int cols,char c);

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char mine[ROWS][COLS], int row, int col);

void FindMine(char mine[ROWS][COLS], char board[ROWS][COLS], int row, int col);

int get_mine_count(char mine[ROWS][COLS], int x, int y);

void expand_blank(char mine[ROWS][COLS], char board[ROWS][COLS], int x, int y);

