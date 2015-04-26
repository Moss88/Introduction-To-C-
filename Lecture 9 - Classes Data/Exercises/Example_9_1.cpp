#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
	double x;
	double y;
};


int main()
{
	Point p1, p2;
	double dist;

	p1.x = 1;
	p1.y = 4;

	p2.x = 2;
	p2.y = 3;

	dist = sqrt(pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2));
	cout << "Distance: " << dist << endl;

	return 0;
}