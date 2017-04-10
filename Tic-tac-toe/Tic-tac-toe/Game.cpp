// Game.cpp


#include "Tic-tac-toe.h"
#include "stdio.h"


const int FIELD_SIZE = 15;


int main()
{
	// set the console size
	system("mode con cols=96 lines=36");
	
	Tic_tac_toe Ttt = Tic_tac_toe(FIELD_SIZE);
	Ttt.show_field();

	getchar();
	return 0;
}