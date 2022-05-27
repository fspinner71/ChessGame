#include <vector>
#include "chessBoard.h"

move::move(int oldX, int oldY, int newX, int newY)
{
    oX = oldX;
    oY = oldY;
    X = newX;
    Y = newY;
}

void chessBoard::wPawn(std::vector<move> &moves, int x, int y)
{
    if (mBoard.arr[x][y] == 0)
    {
        if (y > 0)
        {
            if (mBoard.arr[x][y - 1] == -1)
            {
                moves.push_back(move(x, y, x, y - 1));
                if (mBoard.arr[x][y - 2] == -1 && y == 6)
                {
                    moves.push_back(move(x, y, x, y - 2));
                }
            }
            if (x > 0)
            {
                if (mBoard.arr[x - 1][y - 1] >= 6)
                {
                    moves.push_back(move(x, y, x - 1, y - 1));
                }
            }
            if (x < 7)
            {
                if (mBoard.arr[x + 1][y - 1] >= 6)
                {
                    moves.push_back(move(x, y, x + 1, y - 1));
                }
            }
        }
    }
}

void chessBoard::bPawn(std::vector<move> &moves, int x, int y)
{
    if (mBoard.arr[x][y] == 6)
    {
        if (y < 7)
        {
            if (mBoard.arr[x][y + 1] == -1)
            {
                moves.push_back(move(x, y, x, y + 1));
                if (mBoard.arr[x][y + 2] == -1 && y == 1)
                {
                    moves.push_back(move(x, y, x, y + 2));
                }
            }
            if (x > 0)
            {
                if (mBoard.arr[x - 1][y + 1] < 6 && mBoard.arr[x - 1][y + 1] != -1)
                {
                    moves.push_back(move(x, y, x - 1, y + 1));
                }
            }
            if (x < 7)
            {
                if (mBoard.arr[x + 1][y + 1] < 6 && mBoard.arr[x + 1][y + 1] != -1)
                {
                    moves.push_back(move(x, y, x + 1, y + 1));
                }
            }
        }
    }
}
void chessBoard::King(std::vector<move> &moves, int x, int y)
{
    if (mBoard.arr[x][y] == 4 || mBoard.arr[x][y] == 10)
    {
        bool pThreshold = mBoard.arr[x][y] < 6;
        if (x > 0)
        {
            if ((pThreshold && (mBoard.arr[x - 1][y] > 5 || mBoard.arr[x - 1][y] == -1)) || (!pThreshold && (mBoard.arr[x - 1][y] < 6 || mBoard.arr[x - 1][y] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y));
            }
        }
        if (x > 0 && y > 0)
        {
            if ((pThreshold && (mBoard.arr[x - 1][y - 1] > 5 || mBoard.arr[x - 1][y - 1] == -1)) || (!pThreshold && (mBoard.arr[x - 1][y - 1] < 6 || mBoard.arr[x - 1][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y - 1));
            }
        }
        if (x > 0 && y < 7)
        {
            if ((pThreshold && (mBoard.arr[x - 1][y + 1] > 5 || mBoard.arr[x - 1][y + 1] == -1)) || (!pThreshold && (mBoard.arr[x - 1][y + 1] < 6 || mBoard.arr[x - 1][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y + 1));
            }
        }
        if (y > 0)
        {
            if ((pThreshold && (mBoard.arr[x][y - 1] > 5 || mBoard.arr[x][y - 1] == -1)) || (!pThreshold && (mBoard.arr[x][y - 1] < 6 || mBoard.arr[x][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x, y - 1));
            }
        }
        if (y < 7)
        {
            if ((pThreshold && (mBoard.arr[x][y + 1] > 5 || mBoard.arr[x][y + 1] == -1)) || (!pThreshold && (mBoard.arr[x][y + 1] < 6 || mBoard.arr[x][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x, y + 1));
            }
        }
        if (x < 7)
        {

            if ((pThreshold && (mBoard.arr[x + 1][y] > 5 || mBoard.arr[x + 1][y] == -1)) || (!pThreshold && (mBoard.arr[x + 1][y] < 6 || mBoard.arr[x + 1][y] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y));
            }
        }
        if (x < 7 && y < 7)
        {

            if ((pThreshold && (mBoard.arr[x + 1][y + 1] > 5 || mBoard.arr[x + 1][y + 1] == -1)) || (!pThreshold && (mBoard.arr[x + 1][y + 1] < 6 || mBoard.arr[x + 1][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y + 1));
            }
        }
        if (x < 7 && y > 0)
        {

            if ((pThreshold && (mBoard.arr[x + 1][y - 1] > 5 || mBoard.arr[x + 1][y - 1] == -1)) || (!pThreshold && (mBoard.arr[x + 1][y - 1] < 6 || mBoard.arr[x + 1][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y - 1));
            }
        }
    }
}

void chessBoard::Knight(std::vector<move> &moves, int x, int y)
{
    if (mBoard.arr[x][y] == 2 || mBoard.arr[x][y] == 8)
    {
        bool pThreshold = mBoard.arr[x][y] < 6;
        if (x > 0 && y < 6)
        {
            if ((pThreshold && (mBoard.arr[x - 1][y + 2] > 5 || mBoard.arr[x - 1][y + 2] == -1)) || (!pThreshold && (mBoard.arr[x - 1][y + 2] < 6 || mBoard.arr[x - 1][y + 2] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y + 2));
            }
        }
        if (x > 0 && y > 1)
        {
            if ((pThreshold && (mBoard.arr[x - 1][y - 2] > 5 || mBoard.arr[x - 1][y - 2] == -1)) || (!pThreshold && (mBoard.arr[x - 1][y - 2] < 6 || mBoard.arr[x - 1][y - 2] == -1)))
            {
                moves.push_back(move(x, y, x - 1, y - 2));
            }
        }
        if (x > 1 && y < 7)
        {
            if ((pThreshold && (mBoard.arr[x - 2][y + 1] > 5 || mBoard.arr[x - 2][y + 1] == -1)) || (!pThreshold && (mBoard.arr[x - 2][y + 1] < 6 || mBoard.arr[x - 2][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x - 2, y + 1));
            }
        }
        if (y > 0 && x > 1)
        {
            if ((pThreshold && (mBoard.arr[x - 2][y - 1] > 5 || mBoard.arr[x - 2][y - 1] == -1)) || (!pThreshold && (mBoard.arr[x - 2][y - 1] < 6 || mBoard.arr[x - 2][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x - 2, y - 1));
            }
        }
        if (y < 6 && x < 7)
        {
            if ((pThreshold && (mBoard.arr[x + 1][y + 2] > 5 || mBoard.arr[x + 1][y + 2] == -1)) || (!pThreshold && (mBoard.arr[x + 1][y + 2] < 6 || mBoard.arr[x + 1][y + 2] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y + 2));
            }
        }
        if (x < 7 && y > 1)
        {

            if ((pThreshold && (mBoard.arr[x + 1][y - 2] > 5 || mBoard.arr[x + 1][y - 2] == -1)) || (!pThreshold && (mBoard.arr[x + 1][y - 2] < 6 || mBoard.arr[x + 1][y - 2] == -1)))
            {
                moves.push_back(move(x, y, x + 1, y - 2));
            }
        }
        if (x < 6 && y < 7)
        {

            if ((pThreshold && (mBoard.arr[x + 2][y + 1] > 5 || mBoard.arr[x + 2][y + 1] == -1)) || (!pThreshold && (mBoard.arr[x + 2][y + 1] < 6 || mBoard.arr[x + 2][y + 1] == -1)))
            {
                moves.push_back(move(x, y, x + 2, y + 1));
            }
        }
        if (x < 6 && y > 0)
        {

            if ((pThreshold && (mBoard.arr[x + 2][y - 1] > 5 || mBoard.arr[x + 2][y - 1] == -1)) || (!pThreshold && (mBoard.arr[x + 2][y - 1] < 6 || mBoard.arr[x + 2][y - 1] == -1)))
            {
                moves.push_back(move(x, y, x + 2, y - 1));
            }
        }
    }
}

void chessBoard::Rook(std::vector<move> &moves, int x, int y)
{
    if (mBoard.arr[x][y] == 1 || mBoard.arr[x][y] == 7)
    {
        bool pThreshold = mBoard.arr[x][y] < 6;
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
    if (mBoard.arr[x][y] == 3 || mBoard.arr[x][y] == 9)
    {
        bool pThreshold = mBoard.arr[x][y] < 6;
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
    if (mBoard.arr[x][y] == 5 || mBoard.arr[x][y] == 11)
    {
        bool pThreshold = mBoard.arr[x][y] < 6;
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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
                if (mBoard.arr[x + offX][y + offY] == -1)
                {
                    moves.push_back(move(x, y, x + offX, y + offY));
                }
                else if ((pThreshold && mBoard.arr[x + offX][y + offY] > 5) || (!pThreshold && mBoard.arr[x + offX][y + offY] < 6))
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

std::vector<move> chessBoard::getLegalMoves(board b, bool color)
{
    std::vector<move> moves;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (color == 1)
            {
                if (b.arr[i][j] == 0)
                {
                    wPawn(moves, i, j);
                }
                else if (b.arr[i][j] == 4)
                {
                    King(moves, i, j);
                }
                else if (b.arr[i][j] == 2)
                {
                    Knight(moves, i, j);
                }
                else if (b.arr[i][j] == 1)
                {
                    Rook(moves, i, j);
                }
                else if (b.arr[i][j] == 3)
                {
                    Bishop(moves, i, j);
                }
                else if (b.arr[i][j] == 5)
                {
                    Queen(moves, i, j);
                }
            }
            else
            {
                if (b.arr[i][j] == 6)
                {
                    bPawn(moves, i, j);
                }
                else if (b.arr[i][j] == 10)
                {
                    King(moves, i, j);
                }
                else if (b.arr[i][j] == 8)
                {
                    Knight(moves, i, j);
                }
                else if (b.arr[i][j] == 7)
                {
                    Rook(moves, i, j);
                }
                else if (b.arr[i][j] == 9)
                {
                    Bishop(moves, i, j);
                }
                else if (b.arr[i][j] == 11)
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
    std::vector<move> moves = getLegalMoves(mBoard, turn);
    move temp;
    for (int i = 0; i < moves.size(); ++i)
    {
        temp = moves[i];
        if (temp.oX == req.oX && temp.oY == req.oY && temp.X == req.X && temp.Y == req.Y)
        {
            mBoard.arr[req.X][req.Y] = mBoard.arr[req.oX][req.oY];
            mBoard.arr[req.oX][req.oY] = -1;
            std::vector<move> tempMoves = getLegalMoves(mBoard, !turn);
            bool check = false;
            for (int j = 0; j < tempMoves.size(); ++j)
            {
                if (mBoard.arr[tempMoves[j].X][tempMoves[j].Y] == 4 || mBoard.arr[tempMoves[j].X][tempMoves[j].Y] == 10)
                {
                    mBoard = history[history.size() - 1];
                    check = true;
                    break;
                }
            }
            if (!check)
            {
                history.push_back(mBoard);
                return true;
            }
        }
    }
    return false;
}
bool chessBoard::nextTurn()
{
    turn = !turn;
}