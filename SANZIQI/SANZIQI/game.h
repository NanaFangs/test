#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 3
#define COL 3

void InitlizationBoard(char board[ROW][COL], int row, int col);

void DispalyBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void PCMove(char board[ROW][COL], int row, int col);

int CheckWin(char board[ROW][COL], char symbol);

int TryToWinOrBlock(char board[ROW][COL], char symbol);

char IsWin(char board[ROW][COL], int row, int col);
