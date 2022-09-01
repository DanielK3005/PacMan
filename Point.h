#pragma once
#include <iostream>
using namespace std;
enum dimensions { LENGTH = 20, DEPTH = 60 };

class Point 
{
	int x = 1, y = 1 ;
public:
	Point() {}
	Point(const Point& other) { x = other.x; y = other.y; }
	Point(int x, int y) : x(x), y(y) {}
	void setXY(int x, int y) { this->x = x; this->y = y; }
	int GetX() const { return this->x; }
	int GetY() const { return this->y; }
	void draw(char ch) const;
	void moveWIthDirection(int direction);
};