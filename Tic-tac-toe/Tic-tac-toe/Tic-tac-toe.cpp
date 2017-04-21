// Tic-tac-toe.cpp

#include "Tic-tac-toe.h"


Tic_tac_toe::Tic_tac_toe(int field_size)
{
	isOver = false;
	player = 'x';
	_winner = "";
	curX = 0;
	curY = 0;
	old_curX = 0;
	old_curY = 0;
	_field_size = field_size;
	vIndent = 17 - _field_size;
	hIndent = 55 - _field_size * 2;
	field = new char*[_field_size];
	for (int i = 0; i < _field_size; i++)
	{
		field[i] = new char[_field_size];
		for (int j = 0; j < _field_size; j++)
		{
			field[i][j] = ' ';
		}
	}
	line_separator = "---";
	for (int i = 0; i < field_size - 1; i++)
	{
		line_separator += "+---";
	}
}


Tic_tac_toe::~Tic_tac_toe()
{
}


void
Tic_tac_toe::draw_cell(int i, int j)
{
	if (i == curY && j == curX)
	{
		color_cout(">", Cyan);
		cout << field[i][j];
		color_cout("<", Cyan);
	}
	else
	{
		cout << ' ' << field[i][j] << ' ';
	}
}


void
Tic_tac_toe::origin_draw()
{
	string sIndent(hIndent, ' ');
	system("cls");
	set_cursor(0, vIndent);
	for (int i = 0; i < _field_size; i++)
	{
		cout << sIndent;
		for (int j = 0; j < _field_size; j++)
		{
			draw_cell(i, j);
			if (j < _field_size - 1)
			{
				cout << '|';
			}
		}
		if (i < _field_size - 1)
		{
			cout << "\n" << sIndent << line_separator << endl;
		}
	}

	set_cursor(3, 37);
	cout << "New game [";
	color_cout("N", LightGreen);
	cout << "]\n   Exit     [";
	color_cout("Esc", LightGreen);
	cout << "]";
	set_cursor(7, 38);
}


void
Tic_tac_toe::redraw()
{
	set_cursor(old_curX * 4 + hIndent, old_curY * 2 + vIndent);
	draw_cell(old_curY, old_curX);
	set_cursor(curX * 4 + hIndent, curY * 2 + vIndent);
	draw_cell(curY, curX);
	set_cursor(7, 38);

	if (_winner != "")
	{
		set_cursor(45, _field_size * 2 + vIndent + 1);
		cout << "Player \"" << _winner << "\" has won!\n";
		set_cursor(7, 38);
	}
}


bool
Tic_tac_toe::process_input()
{
	int c = _getch();

	if (c == 27)
	{
		return true;
	}

	else if (c == 224)
	{
		c = _getch();
		if (c == 75 && curX > 0)
		{
			old_curX = curX;
			old_curY = curY;
			curX--;
			redraw();
			Beep(150, 200);
		}
		else if (c == 77 && curX < _field_size - 1)
		{
			old_curX = curX;
			old_curY = curY;
			curX++;
			redraw();
			Beep(150, 200);
		}
		else if (c == 72 && curY > 0)
		{
			old_curX = curX;
			old_curY = curY;
			curY--;
			redraw();
			Beep(150, 200);
		}
		else if (c == 80 && curY < _field_size - 1)
		{
			old_curX = curX;
			old_curY = curY;
			curY++;
			redraw();
			Beep(150, 200);
		}
	}

	else if (c == 32)
	{
		if (field[curY][curX] == ' ')
		{
			field[curY][curX] = player;
			check(_field_size);
			player = (player == 'x') ? 'o' : 'x';
			Beep(500, 200);
		}
	}

	else if (c == 110)
	{
		system("cls");
		for (int i = 0; i < _field_size; i++)
		{
			for (int j = 0; j < _field_size; j++)
			{
				field[i][j] = ' ';
			}
		}
		_winner = "";
		curY = 0;
		curX = 0;
		old_curX = 0;
		old_curY = 0;
		origin_draw();
	}

	return false;
}


void
Tic_tac_toe::check(int field_size)
{
	bool horizontal = false;
	bool vertical = false;
	bool diagonal = false;

	for (int i = 0; i < field_size; i++)
	{
		if (field[i][0] == player)
		{
			horizontal = true;
			for (int j = 1; j < field_size; j++)
			{
				if (field[i][j] != player)
				{
					horizontal = false;
					break;
				}
			}
		}

		if (field[0][i] == player)
		{
			vertical = true;
			for (int j = 1; j < field_size; j++)
			{
				if (field[j][i] != player)
				{
					vertical = false;
					break;
				}
			}
		}
	}
	
	if (field[0][0] == player)
	{
		diagonal = true;
		for (int i = 1; i < field_size; i++)
		{
			if (field[i][i] != player)
			{
				diagonal = false;
				break;
			}
		}
	}

	if (diagonal == false && field[0][_field_size - 1] == player)
	{
		diagonal = true;
		for (int i = 1; i < field_size; i++)
		{
			if (field[i][_field_size - 1 - i] != player)
			{
				diagonal = false;
				break;
			}
		}
	}

	if (horizontal || vertical || diagonal)
	{
		_winner = player;
	}
}
