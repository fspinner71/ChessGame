output: main.cpp chessWin.cpp
	g++ main.cpp chessWin.cpp -o output -Isrc/include -Lsrc/lib -lsfml-system -lsfml-graphics -lsfml-window