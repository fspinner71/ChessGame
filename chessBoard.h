#include <vector>
struct move
{
    int oX, oY, X, Y;
    move() {}
    move(int oldX, int oldY, int newX, int newY);
};
class chessBoard
{
private:
    bool turn = 1;
    const char *notation(int x, int y);

    void wPawn(std::vector<move> &moves, int x, int y);
    void bPawn(std::vector<move> &moves, int x, int y);
    void King(std::vector<move> &moves, int x, int y);
    void Queen(std::vector<move> &moves, int x, int y);
    void Rook(std::vector<move> &moves, int x, int y);
    void Bishop(std::vector<move> &moves, int x, int y);
    void Knight(std::vector<move> &moves, int x, int y);
    std::vector<move> getLegalMoves();

public:
    int board[8][8] = {
        {7, 6, -1, -1, -1, -1, 0, 1},
        {8, 6, -1, -1, -1, -1, 0, 2},
        {9, 6, -1, -1, -1, -1, 0, 3},
        {11, 6, -1, -1, -1, -1, 0, 5},
        {10, 6, -1, -1, -1, -1, 0, 4},
        {9, 6, -1, -1, -1, -1, 0, 3},
        {8, 6, -1, -1, -1, -1, 0, 2},
        {7, 6, -1, -1, -1, -1, 0, 1},
    };
    bool playMove(move req);
    bool nextTurn();
};