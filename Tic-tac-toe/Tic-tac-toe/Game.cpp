// Game.cpp

#include "Tic-tac-toe.h"


const int FIELD_SIZE = 3;


void name()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightRed));
	cout << "\n\n";
	cout << "    _|_|_|_|_|  _|x|_|    _|_|_|      _|_|o|_|_|    _|_|      _|x|x|      _|x|x|_|_|    _|_|    _|x|_|_|  \n";
	cout << "        x|        _|    _|                o|      _|    _|  _|                _|      x|    _|  _|        \n";
	cout << "        x|        _|    o|    _|x|x|x|_|  o|      _|o|x|_|  _|    _|o|o|x|_|  _|      _|    _|  _|o|_|    \n";
	cout << "        o|        _|    _|                _|      _|    _|  _|                o|      _|    o|  _|        \n";
	cout << "        _|      _|_|o|    _|_|_|          _|      _|    _|    _|o|_|          o|        _|_|    _|_|_|x|  \n";
	cout << "\n\n";
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightGray));
}

void intro()
{
	int  height = 11;
	for (int i = 0; i < height; i++)
	{
		system("cls");
		for (int j = 0; j < i; j++)
		{
			cout << endl;
		}
		name();
		Sleep(16);
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	_getch();
}

int main()
{
	system("mode con cols=110 lines=36");
	
	intro();
	
	Tic_tac_toe Ttt = Tic_tac_toe(FIELD_SIZE);
	
	while (!Ttt.isOver)
	{
		Ttt.redraw();
		Ttt.isOver = Ttt.process_input();
	}

	_getch();
	return 0;
}