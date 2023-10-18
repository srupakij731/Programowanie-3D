#include <iostream>
#include <vector>
#include "Player.h"
#include "BoardObject.h"

int playerType(int number, int playersNumber)
{
	int type;

	std::cout << "\nPodaj typ " << number + 1 << " gracza \n 1--- Cz³owiek"
		"\n 2--- AI Proste"
		"\n 3--- AI trude\n";
	std::cin >> type;
	return type;
}


char playerMark(int playerNumber)
{
	char mark;

	int ascii = 62;
	if (playerNumber == 0)
		mark = 'O';
	else if (playerNumber == 1)
		mark = 'X';
	else
	{
		if (ascii + playerNumber == 88 || ascii + playerNumber == 79)
			ascii += 1;

		mark = static_cast<char>(ascii + playerNumber);
	}

	return mark;
}

int main() {
	setlocale(LC_CTYPE, "Polish");

	int boardLength, playersNumber;
	std::cout << "Podaj wielkoœæ planszy\n";
	std::cin >> boardLength;
	std::cout << "Podaj iloœæ graczy\n";
	std::cin >> playersNumber;


	BoardObject::CreateBoard(boardLength);

	std::vector<Player> playerList;

	;
	for (int i = 0; i < playersNumber; i++) //Przypisuje gracz¹ w³aœciwoœci
	{
		Player player(playerMark(i), playerType(i, playersNumber));
		playerList.push_back(player);
	}
	int playerTurnNumber = -1;
	while (true) //Powtarzanie dopóki ktoœ nie wygra
	{
		playerTurnNumber = (playerTurnNumber + 1) % playersNumber;
		playerList[playerTurnNumber].Move(playerTurnNumber);
		if (BoardObject::CheckWin(playerList[playerTurnNumber].GetMark()))
		{
			std::cout << "gracz " << playerTurnNumber + 1 << "( " << playerList[playerTurnNumber].GetMark() << " ) wygral!!!!!\n";
			BoardObject::PrintBoard();
			return 0;
		}
		else if (BoardObject::CheckDraw())
		{
			std::cout << "plansza jest pelna. remis!!";
			return 0;
		}
	}
}

