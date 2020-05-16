#ifndef ALAKZAT_H
#define ALAKZAT_H

class Alakzat {
	double x;
	double y;
	double konstans;

public:
	Alakzat(double x, double y, double konstans) : x(x), y(y), konstans(konstans) {}
	
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

	virtual void print() const {
   		std::cout << "ALAKZAT" << std::endl;
	}

	virtual ~Alakzat() {}

	
};

#endif

