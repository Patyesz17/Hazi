#ifndef KOR_H
#define KOR_H

#include "Pont.h"
#include "Alakzat.h"

class Kor:public Alakzat {
	double xNegyzet;
	double yNegyzet;
public:
	Kor(Pont A, double);
	double getXnegyzet()const;
	double getYnegyzet()const;
	double getX()const;
	double getY()const;
	double getKonst() const;
	virtual void print() const {
   		std::cout << "KOR" << std::endl;
	}
};
#endif