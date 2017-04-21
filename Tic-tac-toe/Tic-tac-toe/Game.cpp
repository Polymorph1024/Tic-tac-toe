// Game.cpp

#include "Intro.h"
#include "Tic-tac-toe.h"


const int FIELD_SIZE = 3;


int main()
{	
	system("mode con cols=110 lines=40");

	
	Intro intro = Intro();
	intro.show();
	Sleep(1200);
	
	
	Tic_tac_toe Ttt = Tic_tac_toe(FIELD_SIZE);
	Ttt.origin_draw();
	while (!Ttt.isOver)
	{
		Ttt.isOver = Ttt.process_input();
		Ttt.redraw();
	}

	return 0;
}
