#include "BoardObject.h"
#include <vector>
#include<iostream>
#include "Player.h"
static class BoardObject
{
public:
	void CreateBoard(int boardLength) {
		board = std::vector<std::vector<char>>(boardLength, std::vector<char>(boardLength, ' '));
	}


	static bool CheckWin(char mark)
	{
		int N = board.size();

		for (int i = 0; i < N; i++)
		{
			bool rowWin = true;
			bool colWin = true;
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] != mark)
					rowWin = false;
				if (board[j][i] != mark)
					colWin = false;
			}
			if (rowWin || colWin)

				return true;


			bool diagonal1Win = true;
			bool diagonal2Win = true;
			for (int i = 0; i < N; i++)
			{
				if (board[i][i] != mark)
					diagonal1Win = false;
				if (board[i][N - i - 1] != mark)
					diagonal2Win = false;
			}
			if (diagonal1Win || diagonal2Win)
				return true;
		}

		return false;
	}

	bool CheckDraw()
	{
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board.size(); j++)
			{
				if (board[i][j] == ' ')
					return false;
			}
		}
		return true;
	}

	static void PrintBoard() {
		std::cout << "\n";
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				std::cout << board[i][j];
				if (j < board[i].size() - 1)
					std::cout << "|";
			}
			std::cout << "\n";
			if (i < board.size() - 1) {
				for (int j = 0; j < board[i].size() * 2 - 1; j++) {
					std::cout << "-";
				}
				std::cout << "\n";

			}
		}
		std::cout << "\n";
	}

	bool ValidMove(int row, int col) {
		if (row >= 0 && row < board.size() && col >= 0 && col < board.size() && board[row][col] == ' ')
			return true;
		else
			return false;
	}

	std::vector<std::vector<char>> GetBoard()
	{
		return board;
	}
	int GetBoardSize()
	{
		return board.size();
	}
	static void SetBoard(int row, int col, char mark)
	{
		board[row][col] = mark;
	}

private:
	static std::vector<std::vector<char>> board;

};

