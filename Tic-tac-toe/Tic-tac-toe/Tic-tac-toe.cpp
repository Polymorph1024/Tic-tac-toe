// Tic-tac-toe.cpp


#include "Tic-tac-toe.h"


Tic_tac_toe::Tic_tac_toe(int field_size)
{
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
Tic_tac_toe::show_field()
{
	std::cout << "\n\n";
	for (int i = 0; i < _field_size; i++)
	{
		std::cout << "   ";
		for (int j = 0; j < _field_size; j++)
		{
			std::cout << ' ' << field[i][j] << ' ';
			if (j < _field_size - 1)
			{
				std::cout << '|';
			}
		}
		if (i < _field_size - 1)
		{
			std::cout << std::endl << "   " << line_separator << std::endl;
		}
	}
	std::cout << "\n\n\n";
}