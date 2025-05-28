#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

void menu() {
	printf("#############\n");
	printf("1. play \n");
	printf("0. exit \n");
	printf("#############\n");
}

void game() {
	char res = 0;
	char board[ROW][COL] = { 0 };
	
	InitlizationBoard(board, ROW, COL);
	DispalyBoard(board, ROW, COL);

	while (1) {
		PlayerMove(board,ROW,COL);
		//judge the game status
		//if the game is over, break the loop
		res = IsWin(board, ROW, COL);
		if (res != 'C') {
			break;
		}
		DispalyBoard(board, ROW, COL);
		//PC move
		PCMove(board, ROW, COL);
		res = IsWin(board, ROW, COL);
		if (res != 'C') {
			break;
		}
		DispalyBoard(board, ROW, COL);
		
	}
	if (res == 'X') {
		printf("Player wins!\n");
	}
	else if (res == 'O') {
		printf("PC wins!\n");
	}
	else {
		printf("It's a draw!\n");
	}
	DispalyBoard(board, ROW, COL);

}
int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("Please select an option: ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("Exiting...\n");
			break;
		default:
			printf("Invalid option. Please try again.\n");
			break;
		}
	} while (input);
}