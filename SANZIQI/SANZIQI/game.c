#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void InitlizationBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void DispalyBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			for (int j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col) {
	printf("Player Move: ");
	int x, y;

	while (1) {
		printf("Enter your move (row and column): ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = 'X'; // Player's move
				break;
			}
			else {
				printf("Invalid move. Cell already occupied. Try again.\n");
			}
		}
		else {
			printf("Invalid input. Please enter valid row and column.\n");

		}

	}

}

// Returns 1 if the given symbol has a winning line, otherwise 0
int CheckWin(char board[ROW][COL], char symbol) {
	// Check rows
	for (int i = 0; i < ROW; i++) {
		if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
			return 1;
		}
	}

	// Check columns
	for (int j = 0; j < COL; j++) {
		if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
			return 1;
		}
	}

	// Check diagonals
	if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
		return 1;
	}
	if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
		return 1;
	}

	return 0; // No win found
}

int TryToWinOrBlock(char board[ROW][COL], char symbol) {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (board[i][j] == ' ') {
				board[i][j] = symbol;
				// Check if this move wins the game
				if (CheckWin(board, symbol)) {
					if (symbol == 'O') return 1; // PC plays to win
					else {
						board[i][j] = 'O'; // block player
						return 1;
					}
				}
				board[i][j] = ' '; // undo
			}
		}
	}
	return 0;
}



void PCMove(char board[ROW][COL], int row, int col) {
	printf("PC Move: \n");
	if (TryToWinOrBlock(board, 'O')) {
		return; // PC wins
	}
	if (TryToWinOrBlock(board, 'X')) {
		return; // Block player
	}

	if (board[1][1] == ' ') {
		board[1][1] = 'O';
		return;
	}

	int x, y;

	while (1) {
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = 'O'; // PC's move
			break;
		}
	}
}

/*
* player wins: return 'X'
* PC wins: return 'O'
* draw: return 'D'
* continue: return 'C'
*/
char IsWin(char board[ROW][COL], int row, int col) {
	//row
	for (int i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			if (board[i][0] == 'X') {
				return 'X'; // Player wins
			}
			else if (board[i][0] == 'O') {
				return 'O'; // PC wins
			}
		}
	}
	//col
	for (int j = 0; j < col; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
			if (board[0][j] == 'X') {
				return 'X';//player wins
			}
			else if (board[0][j] == 'O') {
				return 'O';//PC wins
			}
		}
	}
	//diagonal
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		if (board[0][0] == 'X') {
			return 'X'; // Player wins
		}
		else if (board[0][0] == 'O') {
			return 'O'; // PC wins
		}
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		if (board[0][2] == 'X') {
			return 'X'; // Player wins
		}
		else if (board[0][2] == 'O') {
			return 'O'; // PC wins
		}
	}
	//check if the board is full
	int full = 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				full = 0;
				break;
			}
		}
	}
	if (full) {
		return 'D'; // Draw
	}

	return 'C'; // Continue
}