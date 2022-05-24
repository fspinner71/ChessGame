#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
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
void chessWin::DrawPieces()
{
    for (int i = 0; i < 64; ++i)
    {
        if (pieces[i].draw == 1)
        {
            win.draw(pieces[i].Sprite);
        }
    }
}
void chessWin::MapPieces()
{
    for (int i = 0; i < 64; ++i)
    {
        if (pieces[i].draw == 1)
        {
            pieces[i].Sprite.setPosition(sf::Vector2f(Holder.left + (pieces[i].x * Holder.width / 8), Holder.top + (pieces[i].y * Holder.height / 8)));
            pieces[i].Sprite.setScale(Holder.width / 1600.f, Holder.height / 1600.f);
        }
    }
}
void chessWin::MapPieces(move curr)
{
    for (int i = 0; i < 64; ++i)
    {
        if (pieces[i].draw == 1)
        {
            if (pieces[i].x == curr.oX && pieces[i].y == curr.oY)
            {
                pieces[i].x = curr.X;
                pieces[i].y = curr.Y;
            }
            pieces[i].Sprite.setPosition(sf::Vector2f(Holder.left + (pieces[i].x * Holder.width / 8), Holder.top + (pieces[i].y * Holder.height / 8)));
            pieces[i].Sprite.setScale(Holder.width / 1600.f, Holder.height / 1600.f);
        }
    }
}
chessWin::chessWin(int width, int height, const char *name, const char *imgPath[12])
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
    sf::IntRect blank;
    for (int i = 0; i < 12; ++i)
    {
        pieceTex[i].loadFromFile(imgPath[i], blank);
    }
    int index = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            pieces[index].pieceID = cBoard.board[i][j];
            pieces[index].x = i;
            pieces[index].y = j;
            if (pieces[index].pieceID != -1)
            {
                pieces[index].Sprite.setTexture(pieceTex[pieces[index].pieceID], true);
                pieces[index].draw = 1;
            }
            ++index;
        }
    }
    MapPieces();
    win.create(sf::VideoMode(width, height), name);
}

bool chessWin::Update()
{
    sf::Event event;
    while (win.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Resized:
            sX = win.getSize().x;
            sY = win.getSize().y;
            win.setView(sf::View(sf::FloatRect(0, 0, sX, sY)));
            if (sX > sY)
            {
                Holder.width = sY;
                Holder.height = sY;
                Holder.left = sX / 2 - Holder.width / 2;
                Holder.top = 0;
            }
            else
            {
                Holder.width = sX;
                Holder.height = sX;
                Holder.top = sY / 2 - Holder.height / 2;
                Holder.left = 0;
            }
            MapPieces();
            FitToHolder();
            break;
        case sf::Event::Closed:
            win.close();
            return false;
            break;
        }
    }
    win.clear();
    DrawSquares();
    DrawPieces();
    win.display();
    return true;
}