#include <iostream>
#include <cmath>
#include "bearly.h"

int main()
{
	int doorX, doorY, playerX, playerY, bearX, bearY;
	BearlyGame game;
	
	// Door always starts in the same place and stays fixed
	doorX = game.xDoor();
	doorY = game.yDoor();

	while(!game.isOver())
	{
		// Position of Player Piece, Bear
		playerX = game.xPlayer();
		playerY = game.yPlayer();
		bearX = game.xBear();
		bearY = game.yBear();

		// Take Turn (this should be surrounded by some logic
		//game.turn(/* LEFT, RIGHT, UP, DOWN, NONE */);

		// Determine Manhatten Distance
		int distX = playerX - doorX;
		int distY = playerY - doorY;

		int bearDistX = playerX - bearX;
		int bearDistY = playerY - bearY;
	
		// Run for it
		if(bearDistX < 0)
			game.turn(RIGHT);
		else if(bearDistX > 0)
			game.turn(LEFT);
		else if(bearDistY < 0)
			game.turn(DOWN);
		else if(bearDistY > 0)
			game.turn(UP);

	}



	return 0;
}
