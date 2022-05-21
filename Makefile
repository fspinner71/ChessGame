output: main.cpp chessWin.cpp chessWin.h
	g++ chessWin.cpp -o output.exe main.cpp -Isrc/include -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system