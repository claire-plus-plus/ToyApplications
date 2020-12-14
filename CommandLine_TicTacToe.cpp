#include <iostream>
#include <numeric>
#include <array>
/* Text stuff
intro...
Welcome to Tic Tac Toe!

Enter the number of the place you want to play
1 2 3
4 5 6
7 8 9

Press Enter to Start!


while playing...
- - -
- - -
- - -
Player X: 1

X - -
- - -
- - -
Player O: 5

X - -
- O -
- - -
Player X:

...

X O -
X O -
X - -
Player X wins!
Enter "R" to replay, or press Enter to escape!
*/

int main(void) {
	std::cout <<
		"Welcome to Tic Tac Toe!\n"
		"Enter the number of the place you want to play!\n"
		"1 2 3\n"
		"4 5 6\n"
		"7 8 9"
	<< std::endl;

	// 0 = empty, 1 = X, 2 = O
	std::array<uint8_t, 9> board{};
	char t[] {'-', 'X', 'O'}; // Converts board data to displayable text

	// false = X, true = O
	bool player = false;

	// Main game loop
	while (true) {
		std::cout << std::endl <<
			t[board[0]] << " " << t[board[1]] << " " << t[board[2]] << std::endl <<
			t[board[3]] << " " << t[board[4]] << " " << t[board[5]] << std::endl <<
			t[board[6]] << " " << t[board[7]] << " " << t[board[8]] << std::endl;

		// Get input
		bool retryInput;
		do {
			retryInput = false;

			std::cout << "Player " << (player ? 'O' : 'X') << ": ";
			int input;
			std::cin >> input;
			std::cin.ignore(INT_MAX, '\n');

			// Validate input
			input--;
			if (input >= 9) { // Reject input if out of bound
				std::cout << "Please enter a number between 1 and 9!\a" << std::endl;
				retryInput = true;
			}
			else if (board[input]) { // Reject input if chosen space unavailable
				std::cout << "That space is taken! Choose another space!\a" << std::endl;
				retryInput = true;
			}
			else board[input] = player + 1; // Accept input

		} while (retryInput);


		// Check for winning board state
		bool win = false;
		for (int i = 0; i < 3; i++) {
			win |= ( // Check row i
				player + 1 == board[i * 3 + 0] &&
				player + 1 == board[i * 3 + 1] &&
				player + 1 == board[i * 3 + 2]
				) || ( // Check column i
				player + 1 == board[0 + i] &&
				player + 1 == board[3 + i] &&
				player + 1 == board[6 + i]
			);
		}

		// Check for both diagonals
		win |= (
			player + 1 == board[0] &&
			player + 1 == board[4] &&
			player + 1 == board[8]
			) || (
			player + 1 == board[2] &&
			player + 1 == board[4] &&
			player + 1 == board[6]
		);

		// Display winning text
		if (win) {
			std::cout << std::endl <<
				t[board[0]] << " " << t[board[1]] << " " << t[board[2]] << std::endl <<
				t[board[3]] << " " << t[board[4]] << " " << t[board[5]] << std::endl <<
				t[board[6]] << " " << t[board[7]] << " " << t[board[8]] << std::endl <<
				"Player " << (player ? 'O' : 'X') << " Wins! Press Enter to Escape!\a";
			while (std::cin.get() != '\n');
			break;
		}


		// Check for draw board state
		if (std::accumulate(board.begin(), board.end(), 0) == 13) {
			std::cout << std::endl <<
				t[board[0]] << " " << t[board[1]] << " " << t[board[2]] << std::endl <<
				t[board[3]] << " " << t[board[4]] << " " << t[board[5]] << std::endl <<
				t[board[6]] << " " << t[board[7]] << " " << t[board[8]] << std::endl <<
				"Draw! Press Enter to Escape!\a";
			while (std::cin.get() != '\n');
			break;
		}


		// Change player before looping
		player = !player;
	}

	return 0;
}
