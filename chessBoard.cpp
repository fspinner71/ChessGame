#include <vector>
#include "chessBoard.h"

move::move(int oldX, int oldY, int newX, int newY)
{
    oX = oldX;
    oY = oldY;
    X = newX;
    Y = newY;
}

void chessBoard::wPawn(std::vector<move> &moves, int x, int y, bool clr)
{
    if (board[x][y] == 0)
    {
        if (board[x][y - 1] == -1)
        {
            moves.push_back(move(x, y, x, y - 1));
            if (board[x][y - 2] == -1 && y == 6)
            {
                moves.push_back(move(x, y, x, y - 2));
            }
        }
        if (x > 0)
        {
            if (board[x - 1][y - 1] >= 6)
            {
                moves.push_back(move(x, y, x - 1, y - 1));
            }
        }
        if (x < 7)
        {
            if (board[x + 1][y - 1] >= 6)
            {
                moves.push_back(move(x, y, x + 1, y - 1));
            }
        }
    }
}

std::vector<move> chessBoard::getLegalMoves()
{
    std::vector<move> moves;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == 0)
            {
                wPawn(moves, i, j, turn);
            }
        }
    }
    // for (int i = 0; i < moves.size(); ++i)
    // {
    //     std::cout << moves[i].oX << " " << moves[i].oY << " " << moves[i].X << " " << moves[i].Y << "\n";
    // }
    return moves;
}
bool chessBoard::playMove(move req)
{
    std::vector<move> moves = getLegalMoves();
    move temp;
    for (int i = 0; i < moves.size(); ++i)
    {
        temp = moves[i];
        if (temp.oX == req.oX && temp.oY == req.oY && temp.X == req.X && temp.Y == req.Y)
        {
            board[req.X][req.Y] = board[req.oX][req.oY];
            board[req.oX][req.oY] = -1;
            return true;
        }
    }
}