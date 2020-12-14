#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void displayBoard(uint8_t* board) {
	char t[]{ '-', 'X', 'O' };
	printf(
		"\n"
		"%c %c %c\n"
		"%c %c %c\n"
		"%c %c %c\n",
		t[board[0]], t[board[1]], t[board[2]],
		t[board[3]], t[board[4]], t[board[5]],
		t[board[6]], t[board[7]], t[board[8]]
	);
}

int main(void) {
	printf(
		"Welcome to Tic Tac Toe!\n"
		"Enter the number of the place you want to play!\n"
		"1 2 3\n"
		"4 5 6\n"
		"7 8 9\n"
	);

	// 0 = empty, 1 = X, 2 = O
	uint8_t board[9]{};

	// false = X, true = O
	// uint8_t(player) + 1 converts bool (X=0, O=1) to same format as board array (X=1, O=2)
	bool player = false;

	// Main loop
	while (true) {
		displayBoard(board);

		// Retrieve input
		bool retryInput;
		do {
			retryInput = false;

			printf("Player %c: ", (player ? 'O' : 'X'));
			int input;
			scanf_s("%i", &input);
			getchar();

			// Validate input
			input--;
			if (input < 0 || input >= 9) {
				printf("Please enter a number between 1 and 9!\n");
				retryInput = true;
			}
			else if (board[input]) {
				printf("That space is taken! Choose another space!\n");
				retryInput = true;
			}
			else board[input] = uint8_t(player) + 1;
		} while (retryInput);


		// Check for winning board state
		bool win = false;
		for (int i = 0; i < 3; i++) {
			win |= ( // Check row i
				uint8_t(player) + 1 == board[i * 3 + 0] &&
				uint8_t(player) + 1 == board[i * 3 + 1] &&
				uint8_t(player) + 1 == board[i * 3 + 2]
				) || ( // Check column i
					uint8_t(player) + 1 == board[0 + i] &&
					uint8_t(player) + 1 == board[3 + i] &&
					uint8_t(player) + 1 == board[6 + i]
					);
		}
		// Check for both diagonals
		win |= (
			uint8_t(player) + 1 == board[0] &&
			uint8_t(player) + 1 == board[4] &&
			uint8_t(player) + 1 == board[8]
			) || (
				uint8_t(player) + 1 == board[2] &&
				uint8_t(player) + 1 == board[4] &&
				uint8_t(player) + 1 == board[6]
				);

		// Display winning text
		if (win) {
			displayBoard(board);
			printf("Player %c Wins! Press Enter to Escape!", (player ? 'O' : 'X'));
			getchar();
			break;
		}


		// Display draw text
		int acc = 0;
		for (int i = 0; i < 9; i++)
			acc += int(board[i]);
		if (acc == 13) {
			displayBoard(board);
			printf("Draw! Press Enter to Escape!");
			getchar();
			break;
		}


		// Change player before looping
		player = !player;
	}


	return 0;
}
