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
		int bearDoorX = bearX - doorX;
		int bearDoorY = bearY - doorY;		
		// Test for Bear, if the bear distance is positive it is likely we can beat the bear to the door			
		if((abs(bearDistX) <= 5 && abs(bearDistY) <= 5) && 
			((abs(bearDoorX) + abs(bearDoorY)) < (abs(distX) + abs(distY))))
		{
			cout << "Attempted Bear Evasion" << endl;
			// Bear Evasion
			if(abs(bearDistX) < abs(bearDistY))
			{
				if(bearX > playerX)
					game.turn(LEFT);
				else if(bearX < playerX)
					game.turn(RIGHT);	
				else
				{
					if(bearY > playerY)	
						game.turn(UP);
					else
						game.turn(DOWN);
				}					
			}			
			else
			{		
				if(bearY > playerY)	
					game.turn(UP);
				else if(bearY < playerY)
					game.turn(DOWN);
				else
				{
					if(bearX > playerX)
						game.turn(LEFT);
					else
						game.turn(RIGHT);
				}
			}		
		}
		else
		{
			// Run for it
			if(distX < 0)
				game.turn(RIGHT);
			else if(distX > 0)
				game.turn(LEFT);
			else if(distY < 0)
				game.turn(DOWN);
			else if(distY > 0)
				game.turn(UP);
		}

	}



	return 0;
}
