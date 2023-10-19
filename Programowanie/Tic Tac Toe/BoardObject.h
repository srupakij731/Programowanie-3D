#pragma once
#include <vector>

static class BoardObject
{

public:
	static void CreateBoard(int boardLength);

	static bool ValidMove(int row, int col);
	static bool CheckWin(char mark);
	static bool CheckDraw();

	static void PrintBoard();


	static std::vector<std::vector<char>> GetBoard();
	static void SetBoard(int row, int col, char mark);

	static int GetBoardSize();
private:
	char mark;
	int playerType;
};




