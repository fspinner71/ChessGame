#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "chessWin.h"

const char *defaultTheme[12] = {"./Assets/Pieces/Default/wp.png",
                                "./Assets/Pieces/Default/wr.png",
                                "./Assets/Pieces/Default/wn.png",
                                "./Assets/Pieces/Default/wb.png",
                                "./Assets/Pieces/Default/wk.png",
                                "./Assets/Pieces/Default/wq.png",
                                "./Assets/Pieces/Default/bp.png",
                                "./Assets/Pieces/Default/br.png",
                                "./Assets/Pieces/Default/bn.png",
                                "./Assets/Pieces/Default/bb.png",
                                "./Assets/Pieces/Default/bk.png",
                                "./Assets/Pieces/Default/bq.png"};

int main()
{
    chessWin window(800, 800, "chess", defaultTheme);
    while (window.Update())
    {
    }
    return 0;
}