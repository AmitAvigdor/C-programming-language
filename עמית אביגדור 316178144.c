//Amit Avigdor עמית אביגדור 316178144
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOARD_SIZE 8

int playGame();
void initBoard(char[][8]);
void printBoard(char[][8]);
int is_move_legal(char board[][BOARD_SIZE], char, int, int, int, int);
int is_move_legal_x(char board[][BOARD_SIZE], int, int, int, int);
int is_move_legal_o(char board[][BOARD_SIZE], int, int, int, int);
int is_pawn_moveable(char board[][BOARD_SIZE], char, int, int);
int play_single_turn(char board[][BOARD_SIZE], char);
int checkIfPawnIsCorrect(char board[][BOARD_SIZE], char, int, int);
int makeMove(char board[][BOARD_SIZE], char, int, int, int, int);

void main() {

	while (playGame());

}
//the function will be the main of the game reference to function play that must
int playGame() {
	char board[BOARD_SIZE][BOARD_SIZE];
	int pn = 1, scoreX = 0, scoreO = 0, game = 0, pawnNum = 0;
	char pawnArr[2] = { 'X','O' };
	char newGame;
	initBoard(board);
	printf("Lets play Draughts!\n\n");
	printf("----------Play number:%d----------\n", pn);
	printBoard(board);
	while (1) { 
		
		game = play_single_turn(board, pawnArr[pawnNum]);
		if (game == 2) {
			printf("Player %c decided to quit!\n", pawnArr[pawnNum]);
			printBoard(board);
			break;
		}
		// printf("game value is: %d\n",game);
		if (game == 1 || game == 4) {
			printf("Ho nice move! you got him...\n");
			if (pawnNum == 0) {
				scoreX++;
			}
			else {
				scoreO++;
			}
		}
		if (game == 4 || game == 3 || scoreO == 12 || scoreX == 12) {
			printf("Wooohooo! player %c Won!\n", pawnArr[pawnNum]);
			printBoard(board);
			break;
		}
		pawnNum++;
		pn++;
		if (pawnNum == 2)
			pawnNum = 0;
		printf("X score:%d       O score:%d\n", scoreX, scoreO);
		printf("----------Play number:%d----------\n", pn);
		printBoard(board);

	}
	printf("Would you like to play another game?(y\\n)");
	scanf("%c", &newGame);
	if (newGame == 'y') {
		return 1;
	}
	else {
		return 0;
	}


}
//Clean the board, by fill the array in the correct place in 'X' and 'O' like the function place_pawns that must
void initBoard(char b[][8]) {
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			if ((i + j) % 2 == 0)
				b[i][j] = ' ';
			else
				b[i][j] = 'X';
	for (i = 3; i < 5; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			if ((i + j) % 2 == 0)
				b[i][j] = ' ';
			else
				b[i][j] = '.';

	for (i = 5; i < 8; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			if ((i + j) % 2 == 0)
				b[i][j] = ' ';
			else
				b[i][j] = 'O';


}
//Function that print the board to the user screen
void printBoard(char b[][8]) {
	int i, j;
	printf("\n");
	printf("  |0 1 2 3 4 5 6 7  \n  *----------------\n");
	for (i = 0; i < BOARD_SIZE; i++) {
		printf(" %d|", i);
		for (j = 0; j < BOARD_SIZE; j++)
			printf("%c ", b[i][j]);
		printf("\n");
	}
	printf("\n");
}

// The function get the board, row and col of the element.
// The function check if there is a legal move to element, first check if the the element is 'X' or 'O' ans sent dor other function.
int is_pawn_moveable(char board[][BOARD_SIZE], char pawn, int row, int col) {
	if (pawn == 'X') {
		// return is_pawn_x_moveable(board,row,col);
		if (is_move_legal_x(board, row, col, row + 1, col + 1))
			return 1;
		if (is_move_legal_x(board, row, col, row + 2, col + 2))
			return 1;
		if (is_move_legal_x(board, row, col, row + 1, col - 1))
			return 1;
		if (is_move_legal_x(board, row, col, row + 2, col - 2))
			return 1;
	}
	if (pawn == 'O') {
		// return is_pawn_o_moveavle(board,row,col);
		if (is_move_legal_o(board, row, col, row - 1, col + 1))
			return 1;
		if (is_move_legal_o(board, row, col, row - 2, col + 2))
			return 1;
		if (is_move_legal_o(board, row, col, row - 1, col - 1))
			return 1;
		if (is_move_legal_o(board, row, col, row - 2, col - 2))
			return 1;
	}
	return 0;

}

//The function know that the element is 'X'. And check if there is a legal move for the elemnt
int is_pawn_x_moveable(char board[][BOARD_SIZE], int row, int col) {
	if (col == 0) {
		if (board[col + 1][row + 1] != 'X') {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (col == 7) {
		if (board[col - 1][row + 1] != 'X') {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (board[col + 1][row + 1] != 'X' && board[col - 1][row + 1] != 'X') {
		return 1;
	}
	else {
		return 0;
	}
}

//The function know that the element is 'X'. And check if there is a legal move for the elemnt
int is_pawn_o_moveavle(char board[][BOARD_SIZE], int row, int col) {
	if (col == 0) {
		if (board[col + 1][row - 1] != 'O') {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (col == 7) {
		if (board[col - 1][row - 1] != 'O') {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (board[col + 1][row - 1] != 'O' && board[col - 1][row - 1] != 'O') {
		return 1;
	}
	else {
		return 0;
	}

}
//The function will be the single play of the game
int play_single_turn(char board[][BOARD_SIZE], char pawn) {
	int row, col, rowDes, colDes, eat;
	printf("Player %c - Please enter pawn's location (row number followed by column number):\n", pawn);
	while (1) {
		scanf("%d", &row);
		scanf("%d", &col);
		if (row == 999 || col == 999) {
			return 2;
		}
		if (checkIfPawnIsCorrect(board, pawn, row, col))
			if (is_pawn_moveable(board, pawn, row, col))
				break;
			else
				printf("This pawn has nowhere to move!\n");
		printf("Player %c - Bad pawn's selection please enter pawn's location again:\n", pawn);
	}

	printf("Player %c - Please enter pawn's destination (row number followed by column number):\n", pawn);
	while (1) {
		scanf("%d", &rowDes);
		scanf("%d", &colDes);
		if (is_move_legal(board, pawn, row, col, rowDes, colDes))
			break;
		printf("Player %c - Bad pawn's destination please enter pawn's destination again:\n", pawn);
	}
	eat = makeMove(board, pawn, row, col, rowDes, colDes);
	// printf("eat value is: %d\n",eat);
	if (rowDes == 0 || rowDes == 7)
		if (eat == 1)
			return 4;
		else
			return 3;
	return eat;

}



//The function check is the pown == board[row][col] and return 1 or 0
int checkIfPawnIsCorrect(char board[][BOARD_SIZE], char pawn, int row, int col) {
	if (row >= 0 && row <= 7 && col >= 0 && col <= 7) {
		if (board[row][col] == pawn) {
			return 1;
		}
	}
	return 0;
}

int is_move_legal(char board[][BOARD_SIZE], char pawn, int row, int col, int rowDes, int colDes) {
	if (rowDes >= 0 && rowDes <= 7 && colDes >= 0 && colDes <= 7) {
		if (pawn == 'X') {
			return is_move_legal_x(board, row, col, rowDes, colDes);
		}
		else if (pawn == 'O') {
			return is_move_legal_o(board, row, col, rowDes, colDes);
		}
	}
	return 0;
}
// the function chack if the move of player "O" is legal
int is_move_legal_o(char board[][BOARD_SIZE], int row, int col, int rowDes, int colDes) {
	if (col == 0 && colDes == 1 && rowDes == row - 1 && board[rowDes][colDes] == '.') {
		return 1;
	}
	else if (col == 0 && colDes == 2 && rowDes == row - 2 && board[row - 1][col + 1] == 'X' && board[rowDes][colDes] == '.') {
		return 1;
	}
	else if (col == 7 && colDes == 6 && rowDes == row - 1 && board[rowDes][colDes] == '.') {
		return 1;
	}
	else if (col == 7 && colDes == 5 && rowDes == row - 2 && board[row - 1][col - 1] == 'X' && board[rowDes][colDes] == '.') {
		return 1;
	}
	else if (col >= 1 && col <= 6) {
		if (col == 6 && colDes == 7 && rowDes == row - 1 && board[rowDes][colDes] == ".") {
			return 1;
		}
		else if (col == 6 && colDes == 5 && rowDes == row - 1 && board[rowDes][colDes] == '.') {
			return 1;
		}
		else if (col == 6 && colDes == 4 && rowDes == row - 2 && board[row - 1][col - 1] == 'X' && board[rowDes][colDes] == '.') {
			return 1;
		}
		else if (col == 1 && colDes == 0 && rowDes == row - 1 && board[rowDes][colDes] == '.') {
			return 1;
		}
		else if (col == 1 && colDes == 2 && rowDes == row - 1 && board[rowDes][colDes] == '.') {
			return 1;
		}
		else if (col == 1 && colDes == 3 && rowDes == row - 2 && board[row - 1][col + 1] == 'X' && board[rowDes][colDes] == '.') {
			return 1;
		}
		else {
			if (colDes == col + 1 && rowDes == row - 1 && board[rowDes][colDes] == '.') {
				return 1;
			}
			else if (colDes == col + 2 && rowDes == row - 2 && board[row - 1][col + 1] == 'X' && board[row - 2][col + 2] == '.') {
				return 1;
			}
			else if (colDes == col - 1 && rowDes == row - 1 && board[rowDes][colDes] == '.') {
				return 1;
			}
			else if (colDes == col - 2 && rowDes == row - 2 && board[row - 1][col - 1] == 'X' && board[rowDes][colDes] == '.') {
				return 1;
			}
			else {
				return 0;
			}
		}

	}
	return 0;
}
// The function will chack is the move ofplaye "X" is legal
int is_move_legal_x(char board[][BOARD_SIZE], int row, int col, int rowDes, int colDes) {
	if (col == 0 && colDes == 1 && rowDes == row + 1 && board[rowDes][colDes] == '.') {
		return 1;
	}
	else if (col == 0 && colDes == 2 && rowDes == row + 2 && board[row + 1][col + 1] == 'O' && board[rowDes][colDes] == '.') {
		return 1;
	}
	else if (col == 7 && colDes == 6 && rowDes == row + 1 && board[rowDes][colDes] == '.') {
		return 1;
	}
	else if (col == 7 && colDes == 5 && rowDes == row + 2 && board[row + 1][col - 1] == 'O' && board[rowDes][colDes] == '.') {
		return 1;
	}
	else if (col >= 1 && col <= 6) {
		if (col == 6 && colDes == 7 && rowDes == row + 1 && board[rowDes][colDes] == ".") {
			return 1;
		}
		else if (col == 6 && colDes == 5 && rowDes == row + 1 && board[rowDes][colDes] == '.') {
			return 1;
		}
		else if (col == 6 && colDes == 4 && rowDes == row + 2 && board[row + 1][col - 1] == 'O' && board[rowDes][colDes] == '.') {
			return 1;
		}
		else if (col == 1 && colDes == 0 && rowDes == row + 1 && board[rowDes][colDes] == '.') {
			return 1;
		}
		else if (col == 1 && colDes == 2 && rowDes == row + 1 && board[rowDes][colDes] == '.') {
			return 1;
		}
		else if (col == 1 && colDes == 3 && rowDes == row + 2 && board[row + 1][col + 1] == 'O' && board[rowDes][colDes] == '.') {
			return 1;
		}
		else {
			if (colDes == col + 1 && rowDes == row + 1 && board[rowDes][colDes] == '.') {
				return 1;
			}
			else if (colDes == col + 2 && rowDes == row + 2 && board[row + 1][col + 1] == 'O' && board[row + 2][col + 2] == '.') {
				return 1;
			}
			else if (colDes == col - 1 && rowDes == row + 1 && board[rowDes][colDes] == '.') {
				return 1;
			}
			else if (colDes == col - 2 && rowDes == row + 2 && board[row + 1][col - 1] == 'O' && board[rowDes][colDes] == '.') {
				return 1;
			}
			else {
				return 0;
			}
		}

	}
	return 0;
}
//The function get the destionation move and move the pawn
int makeMove(char board[][BOARD_SIZE], char pawn, int row, int col, int rowDes, int colDes) {
	if (colDes == col + 2) {
		if (pawn == 'X') {
			board[row][col] = '.';
			board[row + 1][col + 1] = '.';
			board[rowDes][colDes] = 'X';
			return 1;
		}
		else {
			board[row][col] = '.';
			board[row - 1][col + 1] = '.';
			board[rowDes][colDes] = 'O';
			return 1;
		}
	}
	else if (colDes == col - 2) {
		if (pawn == 'X') {
			board[row][col] = '.';
			board[row + 1][col - 1] = '.';
			board[rowDes][colDes] = 'X';
			return 1;
		}
		else {
			board[row][col] = '.';
			board[row - 1][col - 1] = '.';
			board[rowDes][colDes] = 'O';
			return 1;
		}
	}
	else {
		board[row][col] = '.';
		board[rowDes][colDes] = pawn;
		return 0;
	}

}
