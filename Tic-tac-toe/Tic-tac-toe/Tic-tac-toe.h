// Tic-tac-toe.h

#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <conio.h>

enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

using namespace std;

class Tic_tac_toe
{
public:
	Tic_tac_toe(int);
	~Tic_tac_toe();
	bool isOver;
	int curX;
	int curY;
	char player;
	bool process_input();
	void redraw();
	void draw_cell(int, int);
	void check(int);
	string winner;

private:
	int _field_size;
	char **field;						// values (X's and O's)
	string line_separator;
};
