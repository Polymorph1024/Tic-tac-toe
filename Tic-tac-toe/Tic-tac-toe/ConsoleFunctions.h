// ConsoleColor.h

#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

enum ConsoleColor
{
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


void color_cout(string str, int color);
void set_cursor(int x, int y);
void clear_lines(int lines_count);
