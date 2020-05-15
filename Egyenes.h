#include "Pont.h"
#include "Alakzat.h"

class Egyenes:public Alakzat {
public:
	Egyenes(Pont A, Pont B);
	double getX()const;
	double getY()const;
	double getKonst() const;
	void print();
	
};