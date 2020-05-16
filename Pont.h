#ifndef PONT_H
#define PONT_H

class Pont{
	double x;
	double y;

public:
	Pont(double, double);
	void setX(double);
	void setY(double);
	double getX()const;
	double getY()const;
	void kiirat();
};
#endif