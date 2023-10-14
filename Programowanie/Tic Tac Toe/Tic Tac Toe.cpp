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

        std::vector<std::vector<char>> board(boardLength, std::vector<char>(boardLength, ' '));
        std::vector<char> player(playersNumber);
        std::vector<Player> playerList;


        for (int i = 0; i < playersNumber; i++) //Przypisuje gracz¹ w³aœciwoœci
        {
            char mark = playerMark(i);
            int playerType = playerTypeF(i, playersNumber);
            Player player(mark, playerType, board);
            playerList.push_back(player);

        }
        while (true) 
        {
            for (int k = 0; k != player.size(); k++) 
            {
                playerList[k].Move(k);
            }
        }
    }

