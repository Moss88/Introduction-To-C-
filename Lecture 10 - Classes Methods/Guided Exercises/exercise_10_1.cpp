#include <iostream>
#include <cmath>

using namespace std;

class GamePiece {
	public:
	GamePiece();
	GamePiece(int X, int Y);
	int getX();
	int getY();
	void up();
	void down();
	void right();
	void left();
	float dist(GamePiece p);

	private:
	int x, y;

};


GamePiece::GamePiece() {
	x = 0;
	y = 0;
}


GamePiece::GamePiece(int X, int Y) {
	x = X;
	y = Y;
}

int GamePiece::getX() {
	return x;
}

int GamePiece::getY() {
	return y;
}

void GamePiece::up() {
	y++;
}

void GamePiece::down() {
	y--;
}

void GamePiece::right() {
	x++;
}

void GamePiece::left() {
	x--;
}

float GamePiece::dist(GamePiece p) {
	return sqrt(pow(p.getX() - x, 2) + pow(p.getY() - y, 2));
}


int main() {
	GamePiece shoe, dog(6, 4);

	cout << "Shoe Location: " << shoe.getX() << "," << shoe.getY() << endl;
	cout << "Dog Location: " << dog.getX() << "," << dog.getY() << endl;
	cout << "Distance: " << shoe.dist(dog) << endl;
	shoe.up();
	cout << "Shoe Location: " << shoe.getX() << "," << shoe.getY() << endl; 

	return 0;
}
