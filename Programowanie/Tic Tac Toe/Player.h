#include <iostream>
#include <vector>

class Player {
public:
    Player(char mark, int isAI, std::vector<std::vector<char>>& board) : mark(mark), isAI(isAI), board(board) {}

    char mark;
    int isAI;


    void Move(int turn) {
        switch (isAI)
        {
        case 1:
            makeMovePlayer(board, mark, turn);
            break;

        case 2:
            makeMoveAiSimple(board, mark);
            break;
            //case 3:
                /// tu AI trudne
        }

    }

private:
    std::vector<std::vector<char>>& board;

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

    bool validMove(int row, int col, std::vector<std::vector<char>>& board)
    {
        if (row >= 0 && row < board.size() && col >= 0 && col < board.size() && board[row][col] == ' ')
            return true;
        else
            return false;
    }

    void makeMoveAiSimple(std::vector<std::vector<char>>& board, char player)
    {
        int row, col;
    backAI:
        row = rand() % board.size();
        col = rand() % board.size();
        if (validMove(row, col, board))
            board[row][col] = player;
        else
            goto backAI;

    }

    void makeMovePlayer(std::vector<std::vector<char>>& board, char player, int turn)
    {
        int row, col;
        std::cout << "Teraz gracz " << turn + 1 << " (" << mark << ") Podaj wiersz i kolumnê: \n";
        printBoard(board);
    backPlayer:
        std::cin >> row >> col;
        --row; --col;

        if (validMove(row, col, board))
        {
            board[row][col] = player;
            printBoard(board);
        }
        else
        {
            std::cout << "ruch niepoprawny spróbuj jeszcze raz";
            goto backPlayer;
        }

    }
};