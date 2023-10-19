class Player
{
public:
    Player(char _mark, int _playerType);

    void Move(int turn);
    char GetMark();

private:
    void MakeMoveAiSimple();
    void makeMovePlayer(int turn);
};
