// Tic-tac-toe.h


#pragma once
#include <string>
#include <iostream>


class Tic_tac_toe
{
public:
	Tic_tac_toe(int field_size = 3);
	~Tic_tac_toe();
	void show_field();


private:
	int _field_size;
	char **field;						// values (X's and O's)
	std::string line_separator;
};
