#ifndef PARABOLA_H
#define PARABOLA_H

#include "Alakzat.h"

class Parabola:public Alakzat {
	double xNegyzet;
public:
	Parabola(double, double, double);
	double getXnegyzet()const;
	double getX()const;
	double getY()const;
	double getKonst() const;
	virtual void print() const {
   		std::cout << "PARABOLA" << std::endl;
	}
};
#endif