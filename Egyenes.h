#ifndef EGYENES_H
#define EGYENES_H

#include <iostream>
#include "Pont.h"
#include "Alakzat.h"


class Egyenes : public Alakzat {
	
public:
	Egyenes(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0): Alakzat(x_kiszamito(x1, y1,  x2, y2), 1.0, konstans_kiszamito(x1, y1,  x2, y2)) {}
	double x_kiszamito(double x1, double y1, double x2, double y2);
	double konstans_kiszamito(double x1, double y1, double x2, double y2);
	virtual void print() const;

	
	~Egyenes() {}
	
};
#endif