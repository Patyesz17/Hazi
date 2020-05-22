#include <iostream>
#include <iomanip>
#include "Alakzat.h"
#include "Egyenes.h"
#include "Kor.h"
#include "Parabola.h"
#include "Pont.h"
#include "FilebolBeolvas.h"
#include "Metszo.h"

void eredmeny_kiir(const std::vector<Pont>& metszespontok) {
	if (metszespontok.empty()) {
			std::cout << "Nem metszik egymast." << std::endl << std::endl;
		}
		for (const auto& v : metszespontok ) {
			std::cout << "Metszespont X koord.: "<< v.getX() << std::endl <<  "Metszespont Y koord.: "<< v.getY() << std::endl << std::endl;
		}
}


int main() {
	
	std::cout << std::setprecision(3);
	try {
		std::vector<Alakzat*> alakzatok = alakzat_beolvaso("alakzatok.txt");

		//e-e		
		auto w = Metszo::Metszik(alakzatok[0], alakzatok[1]);
		eredmeny_kiir(w);
		
		//e-k
		auto x = Metszo::Metszik(alakzatok[1], alakzatok[7]);
		eredmeny_kiir(x);
		
		//e-p
		auto y = Metszo::Metszik(alakzatok[3], alakzatok[9]);
		eredmeny_kiir(y);

		//k-k
		auto z = Metszo::Metszik(alakzatok[7], alakzatok[8]);
		eredmeny_kiir(z);

		//p-p
		auto j = Metszo::Metszik(alakzatok[10], alakzatok[9]);
		eredmeny_kiir(j);

		//k-p
		auto q = Metszo::Metszik(alakzatok[7], alakzatok[9]);
		eredmeny_kiir(q);
		
		
		for (size_t i = 0; i < alakzatok.size(); i++) {
			delete alakzatok[i];
		}
		
	} catch (char const* e) {
		std::cout<< e << std::endl;
	}
	
}