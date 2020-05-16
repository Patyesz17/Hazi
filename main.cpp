#include <iostream>
#include "Alakzat.h"
#include "Egyenes.h"
#include "Kor.h"
#include "Parabola.h"
#include "Pont.h"


int main() {
	Pont A(3, 5);
	Pont B(5, 2);
	Pont C(0, 0);
	double sugar = 5;

	Egyenes proba(A, B);
	proba.print();
	std::cout << proba.getX() << " " << proba.getY() << " " << proba.getKonst() << std::endl;

	Parabola teszt(1, -6, 9);
	teszt.print();
	std::cout << teszt.getXnegyzet() << " " << teszt.getX() << " " << teszt.getKonst() << " " << teszt.getY() << std::endl;

	Kor teszteles(C, sugar);
	teszteles.print();
	std::cout << teszteles.getXnegyzet()<<" "<< teszteles.getYnegyzet() << " " << teszteles.getX() << " " << teszteles.getKonst() << " " << teszteles.getY() << std::endl;


}