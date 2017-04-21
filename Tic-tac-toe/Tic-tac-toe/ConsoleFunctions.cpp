// ConsoleFunctions.cpp

#include "ConsoleFunctions.h"


void
color_cout(string str, int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | color));
	cout << str;
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightGray));

}


void
set_cursor(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void
clear_lines(int lines_count)
{
	for (int i = 0; i < lines_count; i++)
	{
		cout << "                                                                                                          \n";
	}
}
