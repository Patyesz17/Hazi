#ifndef EGYENES_H
#define EGYENES_H

#include "Pont.h"
#include "Alakzat.h"

class Egyenes:public Alakzat {

public:
	Egyenes(Pont A, Pont B);
	double getX()const;
	double getY()const;
	double getKonst() const;
	virtual void print() const {
   		std::cout << "EGYENES" << std::endl;
	}
	
};
#endif