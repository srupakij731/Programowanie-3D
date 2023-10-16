#include <iostream>
#include <vector>

class Player {
public:
    Player(char mark, int isAI, std::vector<std::vector<char>>& board) : mark(mark), isAI(isAI), board(board) {}

    char mark;
    int isAI;

    void Move(int turn) 
    {
        switch (isAI)
        {
        case 1:
            makeMovePlayer(turn);
            break;

        case 2:

            makeMoveAiSimple();
            break;
            //case 3:
                /// tu AI trudne
        }
    }

    bool checkWin() 
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
    bool isBoardFull()
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

    void printBoard() {
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
    
private:
    std::vector<std::vector<char>>& board;
    bool validMove(int row, int col) {
        if (row >= 0 && row < board.size() && col >= 0 && col < board.size() && board[row][col] == ' ')
            return true;
        else
            return false;
    }

    void makeMoveAiSimple() {
        std::cout << "---------------------------------------\n";

        std::cout << "ruch AI ( "<<mark<<" )\n";
        ;
        int row, col;
        do {
            srand(time(NULL));
            row = rand() % board.size();
            col = rand() % board.size();
        } while (!validMove(row, col));
        board[row][col] = mark;
        printBoard();
    }

    void makeMovePlayer(int turn) {
        int row, col;
        std::cout << "---------------------------------------\n";

        std::cout << "Teraz gracz " << turn + 1 << " (" << mark << ") Podaj wiersz i kolumnê: \n";
        printBoard();

        do 
        {
            std::cout << "wiersz = ";
            std::cin >> row;
            std::cout << "kolumna = ";
            std::cin >> col;
            --row;--col;
        } while (!validMove(row, col));

        board[row][col] = mark;
        printBoard();
    }
};
 