// Intro.cpp

#include "Intro.h"


Intro::Intro()
{
	float _E[25], _A[25], _D[25], _G[25], _B[25], _e[25];
	_E[0] = 329.63f;
	_A[0] = 440.0f;
	_D[0] = 587.32f;
	_G[0] = 784.0f;
	_B[0] = 987.75f;
	_e[0] = 1318.5f;
	for (int i = 1; i < 25; i++)
	{
		_E[i] = _E[i - 1] * 1.0595f;
		_A[i] = _A[i - 1] * 1.0595f;
		_D[i] = _D[i - 1] * 1.0595f;
		_G[i] = _G[i - 1] * 1.0595f;
		_B[i] = _B[i - 1] * 1.0595f;
		_e[i] = _e[i - 1] * 1.0595f;
	}
	for (int i = 1; i < 25; i++)
	{
		E[i] = int(_E[i]);
		A[i] = int(_A[i]);
		D[i] = int(_D[i]);
		G[i] = int(_G[i]);
		B[i] = int(_B[i]);
		e[i] = int(_e[i]);
	}
}


Intro::~Intro()
{
}


void
Intro::name()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightRed));
	cout << "    _|_|_|_|_|  _|x|_|    _|_|_|      _|_|o|_|_|    _|_|      _|x|x|      _|x|x|_|_|    _|_|    _|x|_|_|  \n";
	cout << "        x|        _|    _|                o|      _|    _|  _|                _|      x|    _|  _|        \n";
	cout << "        x|        _|    o|    _|x|x|x|_|  o|      _|o|x|_|  _|    _|o|o|x|_|  _|      _|    _|  _|o|_|    \n";
	cout << "        o|        _|    _|                _|      _|    _|  _|                o|      _|    o|  _|        \n";
	cout << "        _|      _|_|o|    _|_|_|          _|      _|    _|    _|o|_|          o|        _|_|    _|_|_|x|  \n";
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightGray));
	
}


void
Intro::show()
{
	Beep(150, 1000);
	Beep(A[12], 100);

	set_cursor(0, 10);
	name();

	Beep(A[14], 400);

	set_cursor(0, 10);
	clear_lines(1);
	name();

	Beep(A[12], 100);

	set_cursor(0, 15);
	clear_lines(1);
	set_cursor(0, 10);
	name();

	Beep(A[14], 400);

	set_cursor(0, 10);
	clear_lines(1);
	name();

	Beep(A[12], 100);

	set_cursor(0, 15);
	clear_lines(1);
	set_cursor(0, 10);
	name();

	Beep(A[14], 400);

	set_cursor(0, 10);
	clear_lines(1);
	name();

	Beep(A[12], 200);

	set_cursor(0, 11);
	clear_lines(1);
	name();

	Beep(A[14], 200);

	set_cursor(0, 12);
	clear_lines(1);
	name();

	Beep(D[12], 200);

	set_cursor(0, 13);
	clear_lines(1);
	name();

	Beep(D[14], 200);

	set_cursor(0, 14);
	clear_lines(1);
	name();

	Beep(A[12], 200);

	set_cursor(0, 15);
	clear_lines(1);
	name();

	Beep(A[14], 200);

	set_cursor(0, 16);
	clear_lines(1);
	name();

	Beep(D[12], 200);

	set_cursor(0, 21);
	clear_lines(1);
	set_cursor(0, 16);
	name();

	Beep(A[14], 200);

	set_cursor(109, 39);
}
