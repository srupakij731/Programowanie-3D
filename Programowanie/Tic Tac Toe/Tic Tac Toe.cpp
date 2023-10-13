#include <iostream>
#include <vector>

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

void printBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            std::cout << board[i][j];
            if (j < board[i].size() - 1)
                std::cout << "|";
        }
        std::cout << "\n";
        if (i < board.size() - 1)
            for (int j = 0; j < board[i].size() * 2 - 1; j++) {
                std::cout << "-";
            }

        std::cout << "\n";
    }
    std::cout << "\n";
}

bool move(std::vector<std::vector<char>>& board, int row, int col, char player, int k) {
    if (row >= 0 && row < board.size() && col >= 0 && col < board.size() && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

int main() {
    setlocale(LC_CTYPE, "Polish");


    int ascii = 62;
    int boardLength, playerNumber;
    std::cout << "Podaj wielkoœæ planszy\n";
    std::cin >> boardLength;
    std::cout << "Podaj iloœæ graczy\n";
    std::cin >> playerNumber;

    std::vector<std::vector<char>> board(boardLength, std::vector<char>(boardLength, ' '));
    std::vector<char> player(playerNumber);

    for (int i = 0; i < player.size(); i++) {
        player[i] = playerMark(i);
    }
    while (true) {
        for (int k = 0; k != player.size(); k++) {
            int col, row;
            std::cout << "Teraz gracz " << k + 1 << " (" << player[k] << ") Podaj wiersz i kolumnê: \n";
            printBoard(board);

            std::cin >> row >> col;
            if (move(board, row - 1, col - 1, player[k], k)) {
                // tu dodaj sprawdzanie czy gracz wygra
            }
            else {
                std::cout << "Nieprawid³owy ruch. Spróbuj jeszcze raz.\n";
                k--;
            }
        }
    }
}
