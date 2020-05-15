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
	void print();
};