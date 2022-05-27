#include <vector>
#include "chessBoard.h"
#include <iostream>

move::move(int oldX, int oldY, int newX, int newY)
{
    oX = oldX;
    oY = oldY;
    X = newX;
    Y = newY;
}

void chessBoard::wPawn(std::vector<move> &moves, int x, int y)
{
    if (board[x][y] == 0)
    {
        if (y > 0)
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
}

void chessBoard::bPawn(std::vector<move> &moves, int x, int y)
{
    if (board[x][y] == 6)
    {
        if (y < 7)
        {
            if (board[x][y + 1] == -1)
            {
                moves.push_back(move(x, y, x, y + 1));
                if (board[x][y + 2] == -1 && y == 1)
                {
                    moves.push_back(move(x, y, x, y + 2));
                }
            }
            if (x > 0)
            {
                if (board[x - 1][y + 1] < 6)
                {
                    moves.push_back(move(x, y, x - 1, y + 1));
                }
            }
            if (x < 7)
            {
                if (board[x + 1][y + 1] < 6)
                {
                    moves.push_back(move(x, y, x + 1, y + 1));
                }
            }
        }
    }
}
void chessBoard::King(std::vector<move> &moves, int x, int y)
{
    if (board[x][y] == 4 || board[x][y] == 10)
    {
        bool pThreshold = board[x][y] < 6;
        if (x > 0)
        {
            if ((pThreshold && (board[x - 1][y] > 5 || board[x - 1][y] == -1)) || (!pThreshold && (board[x - 1][y] < 6 || board[x - 1][y] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y));
            }
        }
        if (x > 0 && y > 0)
        {
            if ((pThreshold && (board[x - 1][y - 1] > 5 || board[x - 1][y - 1] == -1)) || (!pThreshold && (board[x - 1][y - 1] < 6 || board[x - 1][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y - 1));
            }
        }
        if (x > 0 && y < 7)
        {
            if ((pThreshold && (board[x - 1][y + 1] > 5 || board[x - 1][y + 1] == -1)) || (!pThreshold && (board[x - 1][y + 1] < 6 || board[x - 1][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y + 1));
            }
        }
        if (y > 0)
        {
            if ((pThreshold && (board[x][y - 1] > 5 || board[x][y - 1] == -1)) || (!pThreshold && (board[x][y - 1] < 6 || board[x][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x, y - 1));
            }
        }
        if (y < 7)
        {
            if ((pThreshold && (board[x][y + 1] > 5 || board[x][y + 1] == -1)) || (!pThreshold && (board[x][y + 1] < 6 || board[x][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x, y + 1));
            }
        }
        if (x < 7)
        {

            if ((pThreshold && (board[x + 1][y] > 5 || board[x + 1][y] == -1)) || (!pThreshold && (board[x + 1][y] < 6 || board[x + 1][y] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y));
            }
        }
        if (x < 7 && y < 7)
        {

            if ((pThreshold && (board[x + 1][y + 1] > 5 || board[x + 1][y + 1] == -1)) || (!pThreshold && (board[x + 1][y + 1] < 6 || board[x + 1][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y + 1));
            }
        }
        if (x < 7 && y > 0)
        {

            if ((pThreshold && (board[x + 1][y - 1] > 5 || board[x + 1][y - 1] == -1)) || (!pThreshold && (board[x + 1][y - 1] < 6 || board[x + 1][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y - 1));
            }
        }
    }
}

void chessBoard::Knight(std::vector<move> &moves, int x, int y)
{
    if (board[x][y] == 2 || board[x][y] == 8)
    {
        bool pThreshold = board[x][y] < 6;
        if (x > 0)
        {
            if ((pThreshold && (board[x - 1][y + 2] > 5 || board[x - 1][y + 2] == -1)) || (!pThreshold && (board[x - 1][y + 2] < 6 || board[x - 1][y + 2] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y + 2));
            }
        }
        if (x > 0 && y > 0)
        {
            if ((pThreshold && (board[x - 1][y - 2] > 5 || board[x - 1][y - 2] == -1)) || (!pThreshold && (board[x - 1][y - 2] < 6 || board[x - 1][y - 2] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y - 2));
            }
        }
        if (x > 0 && y < 7)
        {
            if ((pThreshold && (board[x - 2][y + 1] > 5 || board[x - 2][y + 1] == -1)) || (!pThreshold && (board[x - 2][y + 1] < 6 || board[x - 2][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x - 2, y + 1));
            }
        }
        if (y > 0)
        {
            if ((pThreshold && (board[x - 2][y - 1] > 5 || board[x - 2][y - 1] == -1)) || (!pThreshold && (board[x - 2][y - 1] < 6 || board[x - 2][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x - 2, y - 1));
            }
        }
        if (y < 7)
        {
            if ((pThreshold && (board[x + 1][y + 2] > 5 || board[x + 1][y + 2] == -1)) || (!pThreshold && (board[x + 1][y + 2] < 6 || board[x + 1][y + 2] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y + 2));
            }
        }
        if (x < 7)
        {

            if ((pThreshold && (board[x + 1][y - 2] > 5 || board[x + 1][y - 2] == -1)) || (!pThreshold && (board[x + 1][y - 2] < 6 || board[x + 1][y - 2] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y - 2));
            }
        }
        if (x < 7 && y < 7)
        {

            if ((pThreshold && (board[x + 2][y + 1] > 5 || board[x + 2][y + 1] == -1)) || (!pThreshold && (board[x + 2][y + 1] < 6 || board[x + 2][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x + 2, y + 1));
            }
        }
        if (x < 7 && y > 0)
        {

            if ((pThreshold && (board[x + 2][y - 1] > 5 || board[x + 2][y - 1] == -1)) || (!pThreshold && (board[x + 2][y - 1] < 6 || board[x + 2][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x + 2, y - 1));
            }
        }
    }
}

void chessBoard::Rook(std::vector<move> &moves, int x, int y)
{
    if (board[x][y] == 1 || board[x][y] == 7)
    {
        bool pThreshold = board[x][y] < 6;
        int offX = 0;
        int offY = 0;
        bool stop = false;
        while (!stop)
        {
            ++offX;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offX;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            ++offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
    }
}

void chessBoard::Bishop(std::vector<move> &moves, int x, int y)
{
    if (board[x][y] == 3 || board[x][y] == 9)
    {
        bool pThreshold = board[x][y] < 6;
        int offX = 0;
        int offY = 0;
        bool stop = false;
        while (!stop)
        {
            ++offX;
            ++offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offX;
            --offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offX;
            ++offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            ++offX;
            --offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
    }
}

void chessBoard::Queen(std::vector<move> &moves, int x, int y)
{
    if (board[x][y] == 5 || board[x][y] == 11)
    {
        bool pThreshold = board[x][y] < 6;
        int offX = 0;
        int offY = 0;
        bool stop = false;
        while (!stop)
        {
            ++offX;
            ++offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offX;
            --offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offX;
            ++offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            ++offX;
            --offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            ++offX;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offX;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            ++offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
            }
        }
        offX = 0;
        offY = 0;
        stop = false;
        while (!stop)
        {
            --offY;
            if (x + offX > 7 || x + offX < 0 || y + offY > 7 || y + offY < 0)
            {
                stop = true;
            }
            else
            {
                if (board[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && board[x + offX][y + offY] > 5) || (!pThreshold && board[x + offX][y + offY] < 6))
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                    stop = true;
                }
                else
                {
                    stop = true;
                }
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
            if (turn == 1)
            {
                if (board[i][j] == 0)
                {
                    wPawn(moves, i, j);
                }
                else if (board[i][j] == 4)
                {
                    King(moves, i, j);
                }
                else if (board[i][j] == 2)
                {
                    Knight(moves, i, j);
                }
                else if (board[i][j] == 1)
                {
                    Rook(moves, i, j);
                }
                else if (board[i][j] == 3)
                {
                    Bishop(moves, i, j);
                }
                else if (board[i][j] == 5)
                {
                    Queen(moves, i, j);
                }
            }
            else
            {
                if (board[i][j] == 6)
                {
                    bPawn(moves, i, j);
                }
                else if (board[i][j] == 10)
                {
                    King(moves, i, j);
                }
                else if (board[i][j] == 8)
                {
                    Knight(moves, i, j);
                }
                else if (board[i][j] == 7)
                {
                    Rook(moves, i, j);
                }
                else if (board[i][j] == 9)
                {
                    Bishop(moves, i, j);
                }
                else if (board[i][j] == 11)
                {
                    Queen(moves, i, j);
                }
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
    return false;
}
bool chessBoard::nextTurn()
{
    turn = !turn;
}