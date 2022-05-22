#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "chessWin.h"

void chessWin::FitToHolder()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Squares[i][j].setPosition(sf::Vector2f(Holder.left + (i * Holder.width / 8), Holder.top + (j * Holder.height / 8)));
            Squares[i][j].setSize(sf::Vector2f(Holder.width / 8, Holder.height / 8));
        }
    }
}
void chessWin::DrawSquares()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            win.draw(Squares[i][j]);
        }
    }
}
chessWin::chessWin(int width, int height, const char *name)
{
    bool sColor = 1;
    sColors[0].r = 118;
    sColors[0].g = 150;
    sColors[0].b = 86;
    sColors[1].r = 238;
    sColors[1].g = 238;
    sColors[1].b = 210;
    sX = width;
    sY = height;
    Holder.left = 0;
    Holder.top = 0;
    Holder.width = width;
    Holder.height = height;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Squares[i][j].setFillColor(sColors[sColor]);
            sColor = !sColor;
        }
        sColor = !sColor;
    }
    FitToHolder();
    win.create(sf::VideoMode(width, height), name);
}

bool chessWin::Update()
{
    sf::Event event;
    while (!win.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            win.close();
            return false;
            break;
        }
    }
    win.clear();
    DrawSquares();
    win.display();
    return true;
}