#pragma once
#include <iostream>



class Point
{
	int x;
	int y;
public:
	Point() {
		x = y = 0;
	}
	Point(int x, int y) : x(x), y(y) {

	}

	void setX(int x) {
		this->x = x;
	}
	int getX() const {
		return x;
	}

	void setY(int y) {
		this->y = y;
	}
	int getY() const {
		return y;
	}

	Point* operator ->() {
		return this;
	}

	friend std::ostream& operator << (std::ostream& os, const Point& p);
};

