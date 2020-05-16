#ifndef ALAKZAT_H
#define ALAKZAT_H
#include <iostream>

enum AlakzatNev {egyenes, kor, parabola};

class Alakzat {
	double x;
	double y;
	double konstans;
	AlakzatNev nev;

public:
	Alakzat(double x, double y, double konstans, AlakzatNev nev) : x(x), y(y), konstans(konstans), nev(nev) {}
	
	Alakzat(const Alakzat& masik) {
		x = masik.x;
		y = masik.y;
		konstans = masik.konstans;
	}

	Alakzat& operator=(const Alakzat& masik) {
		if (this != &masik) {
			x = masik.x;
			y = masik.y;
			konstans = masik.konstans;
		}
		return *this;
	}
	double getX()const { return x; }
	double getY()const { return y; }
	double getKonst() const { return konstans; };
	AlakzatNev getAlakzatNev()  { return nev; }

	virtual void print() const {
   		std::cout << "ALAKZAT" << std::endl;
	}

	virtual ~Alakzat() {}

	
};

#endif

