#ifndef PONT_H
#define PONT_H
#include <iostream>

class Pont{
	double x;
	double y;

public:
	Pont(double x, double y):x(x),y(y){}
	double getX()const { return x; }
	double getY()const { return y; }
	void print() {
		std::cout << x << " " << y << std::endl;
	}
	~Pont() {}
};
#endif