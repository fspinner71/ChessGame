#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "chessWin.h"

int main()
{
    chessWin window(800, 800, "chess");
    while (window.Update())
    {
    }
    return 0;
}