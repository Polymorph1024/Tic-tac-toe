// Tic-tac-toe.h

#pragma once
#include "ConsoleFunctions.h"


class Tic_tac_toe
{
public:
	Tic_tac_toe(int);
	~Tic_tac_toe();
	bool isOver;
	bool process_input();
	void origin_draw();
	void redraw();

private:
	int vIndent;
	int hIndent;
	int curX;
	int old_curX;
	int curY;
	int old_curY;
	char player;
	void draw_cell(int, int);
	void check(int);
	string _winner;
	int _field_size;
	char **field;						// values (X's and O's)
	string line_separator;
};
