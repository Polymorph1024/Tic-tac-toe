// Tic-tac-toe.cpp

#include "Tic-tac-toe.h"


void color_cout(string str, int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | color));
	cout << str;
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightGray));

}


Tic_tac_toe::Tic_tac_toe(int field_size)
{
	isOver = false;
	player = 'x';
	winner = "";
	curX = 0;
	curY = 0;
	_field_size = field_size;
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
Tic_tac_toe::redraw()
{
	system("cls");
	cout << "\n\n";
	for (int i = 0; i < _field_size; i++)
	{
		cout << "   ";
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
			cout << "\n   " << line_separator << endl;
		}
	}

	if (winner != "")
	{
		cout << "\n\n   Player \"" << winner << "\" has won!\n";
	}

	cout << "\n\n\n   New game [";
	color_cout("N", LightGreen);
	cout << "]\n   Exit     [";
	color_cout("Esc", LightGreen);
	cout << "]\n\n";	
}


bool
Tic_tac_toe::process_input()
{
	int c = getch();

	if (c == 27)
	{
		return true;
	}

	else if (c == 224)
	{
		c = _getch();
		if (c == 75 && curX > 0)
		{
			curX--;
			redraw();
		}
		else if (c == 77 && curX < _field_size - 1)
		{
			curX++;
			redraw();
		}
		else if (c == 72 && curY > 0)
		{
			curY--;
			redraw();
		}
		else if (c == 80 && curY < _field_size - 1)
		{
			curY++;
			redraw();
		}
	}

	else if (c == 32)
	{
		if (field[curY][curX] == ' ')
		{
			field[curY][curX] = player;
			check(_field_size);
			player = (player == 'x') ? 'o' : 'x';
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
			curY = 0;
			curX = 0;
		}
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

	if (diagonal == false && field[0][_field_size] == player)
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
		winner = player;
	}

}