#include "Player.h"
#include "BoardObject.h"
#include <iostream>
class Player
{
public:
	Player(char mark, int playerType) : mark(mark), playerType(playerType) {}

	void Move(int turn)
	{
		switch (playerType)
		{
		case 1:
			makeMovePlayer(turn);
			break;

		case 2:

			MakeMoveAiSimple();
			break;
			//case 3:
				/// tu AI trudne
		}
	}
	char GetMark()
	{
		return mark;
	}
		
private:
	void MakeMoveAiSimple()
	{
		std::cout << "---------------------------------------\n";

		std::cout << "ruch AI ( " << mark << " )\n";
		;
		int row, col, boardSize;
		boardSize = BoardObject::GetBoardSize();
		do {
			srand(time(NULL));
			row = rand() % boardSize;
			col = rand() % boardSize;
		} while (!BoardObject::ValidMove(row, col));

		BoardObject::SetBoard(row, col, mark);
		BoardObject::PrintBoard();
	}
	void makeMovePlayer(int turn)
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
			--row; --col;
		} while (!BoardObject::ValidMove(row, col));

		BoardObject::SetBoard(row, col, mark);
		BoardObject::PrintBoard();
	}

	char mark;
	int playerType;

};
