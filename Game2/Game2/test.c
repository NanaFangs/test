#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu() {
	printf("###########################################\n");
	printf("Game Menu:\n");
	printf("1. Start Game\n");
	printf("0. Exit Game\n");
	printf("###########################################\n");
}

void game() {
	char board[ROWS][COLS] = { 0 }; //set game board
	char mine[ROWS][COLS] = { 0 }; //set minefield

	// Initialize the game board and minefield
	InitBoard(board, ROWS, COLS, '*');
	InitBoard(mine, ROWS, COLS, '0');
	SetMine(mine, ROW, COL); // Function to set mines in the minefield

	// Display the initial game board
	DisplayBoard(board, ROW, COL);
	DisplayBoard(mine, ROW, COL);

	printf("Game started! Good luck!\n");

	FindMine(mine,board,ROW,COL);

}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL)); // Seed the random number generator
	do {
		menu();
		printf("Enter your choice: ");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("Welcome to the game\n");
			game();
			break;
		case 0:
			printf("Exiting the game...\n");
			//exitGame();
			break;
		default:
			printf("Invalid choice. Please try again.\n");
			break;
		}
	} while (input);
	return 0;
}