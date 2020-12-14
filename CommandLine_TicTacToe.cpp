#include <iostream>
#include <numeric>
#include <limits>
#include <array>

void displayBoard(const std::array<uint8_t, 9>& board) {
	char t[] { '-', 'X', 'O' };
	std::cout << std::endl <<
		t[board[0]] << " " << t[board[1]] << " " << t[board[2]] << std::endl <<
		t[board[3]] << " " << t[board[4]] << " " << t[board[5]] << std::endl <<
		t[board[6]] << " " << t[board[7]] << " " << t[board[8]] << std::endl;
}

int main(void) {
	std::cout <<
		"Welcome to Tic Tac Toe!\n"
		"Enter the number of the place you want to play!\n"
		"1 2 3\n"
		"4 5 6\n"
		"7 8 9" << std::endl;

	// 0 = empty, 1 = X, 2 = O
	std::array<uint8_t, 9> board {};

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

			std::cout << "Player " << (player ? 'O' : 'X') << ": ";
			int input;
			std::cin >> input;
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');

			// Validate input
			input--;
			if (input < 0 || input >= 9) {
				std::cout << "Please enter a number between 1 and 9!" << std::endl;
				retryInput = true;
			}
			else if (board[input]) {
				std::cout << "That space is taken! Choose another space!" << std::endl;
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
			std::cout << "Player " << (player ? 'O' : 'X') << " Wins! Press Enter to Escape!";
			while (std::cin.get() != '\n');
			break;
		}


		// Display draw text
		if (std::accumulate(board.begin(), board.end(), 0) == 13) {
			displayBoard(board);
			std::cout << "Draw! Press Enter to Escape!";
			while (std::cin.get() != '\n');
			break;
		}


		// Change player before looping
		player = !player;
	}

	
	return 0;
}
