#ifndef KOR_H
#define KOR_H

#include <iostream>
#include "Pont.h"
#include "Alakzat.h"


class Kor:public Alakzat {
	double xNegyzet;
	double yNegyzet;
	
public:
	Kor(double x,double y ,  double sugar):Alakzat(x_kiszamito(x,y,sugar),y_kiszamito(x,y,sugar),konstans_kiszamito(x,y,sugar)),xNegyzet(1.0),yNegyzet(1.0){
	}
	double x_kiszamito(double x, double y, double sugar);
	double y_kiszamito(double x, double y, double sugar);
	double konstans_kiszamito(double x, double y, double sugar);
	double getXnegyzet() const { return xNegyzet; }
	double getYnegyzet() const { return yNegyzet; }
	virtual void print() const;

	
	~Kor() {}
};
#endif