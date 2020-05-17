#ifndef PARABOLA_H
#define PARABOLA_H

#include "Alakzat.h"
#include <iostream>

class Parabola:public Alakzat {
	double xNegyzet;
	
public:
	Parabola(double xNegyzet, double x, double konstans) :Alakzat(x, 1.0, konstans), xNegyzet(xNegyzet){}
	double getXnegyzet()const { return xNegyzet; }
	virtual void print() const {
		std::cout << "Itt jon egy Parabola: ";
		std::cout << "y = " << getXnegyzet() << " * x^2 + " << getX() << " * x + " << getKonst() << std::endl;
	}
	~Parabola() {}
};
#endif