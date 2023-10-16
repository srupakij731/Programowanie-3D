#include <iostream>
#include <vector>
#include "Player.h"

int playerTypeF(int number, int playersNumber)
{
        int type;

        std::cout << "\nPodaj typ " << number+1 << " gracza \n 1--- Cz³owiek"
            "\n 2--- AI Proste"
            "\n 3--- AI trude\n";
        std::cin >> type;
        return type; 
}

int ascii = 62;
char playerMark(int playerNumber) {
    char mark;

    if (playerNumber == 0) {
        mark = 'O';
    }
    else if (playerNumber == 1) {
        mark = 'X';
    }
    else {
        if (ascii + playerNumber == 88 || ascii + playerNumber == 79) {
            ascii += 1;
        }
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

        std::vector<std::vector<char>> board(boardLength, std::vector<char>(boardLength, ' '));// vektor tworz¹cy planesze
        std::vector<Player> playerList;


        for (int i = 0; i < playersNumber; i++) //Przypisuje gracz¹ w³aœciwoœci
        {
            Player player(playerMark(i), playerTypeF(i, playersNumber), board);
            playerList.push_back(player);
        }
        while (true) //Powtarzanie dopóki ktoœ nie wygra
        {
            for (int k = 0; k != playersNumber; k++) //Faktyczna gra
            {
                playerList[k].Move(k);
                if (playerList[k].checkWin())
                {

                    std::cout << "gracz " << k + 1 << "( " << playerList[k].mark << " ) wygral!!!!!\n";
                    playerList[k].printBoard();
                    return 0;
                }
                else if (playerList[k].isBoardFull())
                {
                    std::cout << "plansza jest pelna. remis!!";
                    return 0;
                }
            }
        }
    }

