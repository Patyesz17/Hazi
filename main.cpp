#include <iostream>
#include "Alakzat.h"
#include "Egyenes.h"
#include "Kor.h"
#include "Parabola.h"
#include "Pont.h"
#include "FilebolBeolvas.h"
#include "Metszo.h"

int main() {
	Pont A(3, 5);
	Pont B(5, 2);
	Pont C(0, 0);
	double sugar = 5;

	Egyenes proba(3, 5, 5, 2, egyenes);
	proba.print();
	std::cout << proba.getX() << " " << proba.getY() << " " << proba.getKonst() << std::endl;

	Parabola teszt(1, -6, 9, parabola);
	teszt.print();
	std::cout << teszt.getXnegyzet() << " " << teszt.getX() << " " << teszt.getKonst() << " " << teszt.getY() << std::endl;

	Kor teszteles(0, 0, sugar, kor);
	teszteles.print();
	std::cout << teszteles.getXnegyzet()<<" "<< teszteles.getYnegyzet() << " " << teszteles.getX() << " " << teszteles.getKonst() << " " << teszteles.getY() << std::endl;

	vector<Egyenes*> egyenesek = egyenes_beolvaso("egyenes.txt");
	for (int i = 0; i < egyenesek.size(); i++) {
		egyenesek[i]->print();
	}

	vector<Kor*> korok = kor_beolvaso("kor.txt");
	for (int i = 0; i < korok.size(); i++) {
		korok[i]->print();
	}

	vector<Parabola*> parabolak = parabola_beolvaso("parabola.txt");
	for (int i = 0; i < parabolak.size(); i++) {
		parabolak[i]->print();
	}
}	