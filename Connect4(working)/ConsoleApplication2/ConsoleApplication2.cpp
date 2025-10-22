#include <iostream>

char board[6][7] = {
		{'-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-'}
};

void printboard()
{
	for (size_t row = 0; row < 6; row++)
	{
		for (size_t column = 0; column < 7; column++)
		{
			std::cout << board[row][column];
		}
		std::cout << std::endl;
	}
}

// input player movement
// insert the move into the board

// player : 0 or 1 for players 1 and 2
void move(int player)
{
	if (player == 0)
	{
		char x = 'X';
		int moveto;
		std::cout << "Player X, Choose a column 1 - 7: ";
		std::cin >> moveto;
		moveto--;
		for (int row = 5; row >= 0; row--)
		{
			if (board[row][moveto] == '-')
			{
				board[row][moveto] = x;
				return;
				player = 1;
			}
		}
	}

	if (player == 1)
	{
		char o = 'O';
		int moveto;
		std::cout << "Player O, Choose a column 1 - 7: ";
		std::cin >> moveto;
		moveto--;
		//int randomNum = rand() % 8;
		//randomNum--;
		for (int row = 5; row >= 0; row--)
		{
			if (board[row][moveto] == '-')
			{
				board[row][moveto] = o;
				return;
				player = 0;
			}
		}
	}
}

bool Result()
{
	// Horizontal victory
	for (size_t row = 0; row < 6; row++)
	{
		for (size_t column = 0; column < 4; column++)
		{
			char c = board[row][column];
			if (c != '-' && c == board[row][column + 1] && c == board[row][column + 2] && c == board[row][column + 3])
			{
				printboard();
				return true;
			}
		}
	}
	// Vertical victory
	for (size_t column = 0; column < 7; column++)
	{
		for (size_t row = 0; row < 3; row++)
		{
			char c = board[row][column];
			if (c != '-' && c == board[row + 1][column] && c == board[row + 2][column] && c == board[row + 3][column])
			{
				printboard();
				return true;
			}
		}
	}
	// Diagonal \ victory
	for (size_t column = 0; column < 4; column++)
	{
		for (size_t row = 0; row < 3; row++)
		{
			char c = board[row][column];
			if (c != '-' && c == board[row + 1][column + 1] && c == board[row + 2][column + 2] && c == board[row + 3][column + 3])
			{
				printboard();
				return true;
			}
		}
	}
	// Diagonal / victory
	for (size_t column = 0; column < 4; column++)
	{
		for (size_t row = 3; row < 6; row++)
		{
			char c = board[row][column];
			if (c != '-' && c == board[row - 1][column + 1] && c == board[row - 2][column + 2] && c == board[row - 3][column + 3])
			{
				printboard();
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int player = 0;
	while (!Result())
	{
		printboard();
		move(player);
		player++;
		if (player == 2)
		{
			player = 0;
		}
	}
}