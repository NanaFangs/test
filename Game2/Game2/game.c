#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char c) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = c;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	printf("------ Game ------\n"); // Print top-left corner
	for (int j = 0; j <= col; j++) {
		printf("%d ", j); // Print column numbers
	}
	printf("\n");
	for (int i = 1; i <= row; i++) {
		printf("%d ", i); // Print row numbers
		for (int j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	while (count) {
		int x = rand() % row + 1; // Random row index
		int y = rand() % col + 1; // Random column index
		if (mine[x][y] == '0') { // Check if mine is not already placed
			mine[x][y] = '1'; // Place a mine
			count--;
		}
	}
}
int get_mine_count(char mine[ROWS][COLS], int x, int y) {
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (i >= 1 && i < ROWS - 1 && j >= 1 && j < COLS - 1 && mine[i][j] == '1') {
				count++;
			}
		}
	}
	return count;
}
void FindMine(char mine[ROWS][COLS], char board[ROWS][COLS], int row, int col) {
	int x = 0, y = 0;
	int win = 0; // Variable to track if the player has won
	while (win<row*col-EASY_COUNT) {
		printf("Enter coordinates to find mine (row col): ");
		scanf("%d %d", &x, &y);
		if (x < 1 || x > row || y < 1 || y > col) {
			printf("Invalid coordinates. Please try again.\n");
			continue;
		}
		if (board[x][y] != '*') {
			printf("You have already checked this cell. Please try again.\n");
			continue; // Skip if the cell has already been checked
		}
		if (mine[x][y] == '1') {
			printf("Boom! Mine found at (%d, %d)!\n", x, y);
			DisplayBoard(mine, row, col);
			break; // Exit the loop if a mine is found, game over
		}
		else {
			expand_blank(mine, board, x, y);
			win = 0;
			for (int i = 1; i <= row; i++) {
				for (int j = 1; j <= col; j++) {
					if (board[i][j] != '*') {
						win++;
					}
				}
			}
			//win++;
			//int count = get_mine_count(mine, x, y);
			//board[x][y] = count + '0'; // Update the board with the mine count
			DisplayBoard(board, row, col);
			
		}
		
	}
	if (win == row * col - EASY_COUNT) {
		printf("Congratulations! You've cleared the minefield!\n");
		DisplayBoard(mine, row, col); // Show the minefield at the end
	}
	
}

void expand_blank(char mine[ROWS][COLS], char board[ROWS][COLS], int x, int y) {
	if (x < 1 || x >= ROWS - 1 || y < 1 || y >= COLS - 1) {
		return; // Out of bounds
	}
	if (board[x][y] != '*') {
		return; // Already checked or not a blank cell
	}
	int count = get_mine_count(mine, x, y);
	board[x][y] = count + '0'; // Update the board with the mine count
	if (count == 0) {
		// If no mines around, recursively expand to adjacent cells
		for (int i = x - 1; i <= x + 1; i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (i != x || j != y) { // Avoid calling itself
					expand_blank(mine, board, i, j);
				}
			}
		}
	}
}