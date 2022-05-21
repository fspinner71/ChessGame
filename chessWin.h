#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class chessWin
{
private:
    sf::RenderWindow win;
    sf::RectangleShape Squares[8][8];

public:
    chessWin();
};