#ifndef KOR_H
#define KOR_H
#include <iostream>
#include "Pont.h"
#include "Alakzat.h"

class Kor:public Alakzat {
	double xNegyzet;
	double yNegyzet;
public:
	Kor(Pont A, double sugar):Alakzat(x_kiszamito(A,sugar),y_kiszamito(A,sugar),konstans_kiszamito(A,sugar)),xNegyzet(1.0),yNegyzet(1.0){}
	double x_kiszamito(Pont A, double sugar);
	double y_kiszamito(Pont A, double sugar);
	double konstans_kiszamito(Pont A, double sugar);
	double getXnegyzet()const { return xNegyzet; }
	double getYnegyzet()const { return yNegyzet; }
	virtual void print() const {
   		std::cout << "KOR" << std::endl;
	}
};
#endif