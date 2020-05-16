#ifndef EGYENES_H
#define EGYENES_H
#include <iostream>
#include "Pont.h"
#include "Alakzat.h"

class Egyenes:public Alakzat {

public:
	Egyenes(Pont A, Pont B):Alakzat(x_kiszamito(A, B), 1.0, konstans_kiszamito(A, B)) {}
	double x_kiszamito(Pont A, Pont B);
	double konstans_kiszamito(Pont A, Pont B);
	virtual void print() const {
   		std::cout << "EGYENES" << std::endl;
	}
	
};
#endif