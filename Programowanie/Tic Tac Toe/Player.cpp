#include <iostream>
#include "Player.h"

#include "BoardObject.h"

char mark;
int playerType;

Player::Player(char _mark, int _playerType)
{
	mark = _mark;
	playerType = _playerType;
}

char Player::GetMark()
{
	return mark;
}

void Player::Move(int turn)
{
	switch (playerType)
	{
	case 1:
		makeMovePlayer(turn);
		break;

	case 2:

		MakeMoveAiSimple();
		break;
	}

	
	  // tu AI trudne
	  //case 3:

}

void Player::MakeMoveAiSimple() {
	std::cout << "---------------------------------------\n";

	std::cout << "ruch AI ( " << mark << " )\n";
	;
	int row, col, boardSize;
	boardSize = BoardObject::GetBoardSize();
	do
	{
		srand(time(NULL));
		row = rand() % boardSize;
		col = rand() % boardSize;
	} while (!BoardObject::ValidMove(row, col));

	BoardObject::SetBoard(row, col, mark);
	BoardObject::PrintBoard();
}

void Player::makeMovePlayer(int turn)
{
	int row, col;
	std::cout << "---------------------------------------\n";

	std::cout << "Teraz gracz " << turn + 1 << " (" << mark << ") Podaj wiersz i kolumnê: \n";
	BoardObject::PrintBoard();

	do
	{
		std::cout << "wiersz = ";
		std::cin >> row;
		std::cout << "kolumna = ";
		std::cin >> col;
		--row;
		--col;
	} while (!BoardObject::ValidMove(row, col));

	BoardObject::SetBoard(row, col, mark);
	BoardObject::PrintBoard();
}