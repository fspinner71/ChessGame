#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class chessWin
{
private:
    sf::RenderWindow win;
    sf::RectangleShape Squares[8][8];
    sf::IntRect Holder;
    sf::Color sColors[2];
    int sX, sY;

    void FitToHolder();
    void DrawSquares();

public:
    chessWin(int width, int height, const char *name);
    bool Update();
};
#endif