#ifndef ALAKZAT_H
#define ALAKZAT_H

#include <iostream>

class Alakzat {
	double x;
	double y;
	double konstans;
	

public:
	Alakzat(double x = 0, double y = 0, double konstans = 0) : x(x), y(y), konstans(konstans) {}
	
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

	virtual void print() const {
   		std::cout << "ALAKZAT" << std::endl;
	}

	template<typename T>
	T* Caster() {
		return dynamic_cast<T*>(this);
	}

	virtual ~Alakzat() {}
	
};

#endif

