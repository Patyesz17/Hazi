#ifndef METSZO_H
#define METSZO_H

#include <iostream>
#include <vector>
#include <math.h>
#include "Alakzat.h"
#include "Pont.h"
#include "Kor.h"
#include "Egyenes.h"
#include "Parabola.h"



class Metszo {
	
public:
	static std::vector<Pont> Metszik(Alakzat* alakzat1, Alakzat* alakzat2) {
		
		if (Egyenes* egyenes1 = alakzat1->Caster<Egyenes>()) {
			
				if (Egyenes* egyenes2 = alakzat2->Caster<Egyenes>()) {
						std::cout << "Egyenes-Egyenes:" << std::endl;
						return Egyenes_Egyenes_Metszes(egyenes1, egyenes2);

				} else if (Kor* kor = alakzat2->Caster<Kor>()) {
						std::cout << "Egyenes-Kor:" << std::endl;
						return Egyenes_Kor_Metszes(egyenes1, kor);

				} else if (Parabola* parabola = alakzat2->Caster<Parabola>()) {
						std::cout << "Egyenes-Parabola:" << std::endl;
						return Egyenes_Parabola_Metszes(egyenes1, parabola);

				}

		} else if (Kor* kor1 = alakzat1->Caster<Kor>()) {
			
				if (Kor* kor2 = alakzat2->Caster<Kor>()) {
						std::cout << "Kor-Kor:" << std::endl;
						return Kor_Kor_Metszes(kor1, kor2);

				} else if (Egyenes* egyenes = alakzat2->Caster<Egyenes>()) {
						std::cout << "Kor-Egyenes:" << std::endl;
						return Egyenes_Kor_Metszes(egyenes, kor1);

				} else if (Parabola* parabola1 = alakzat2->Caster<Parabola>()) {
						throw "Kor-Parabola metszesre nincs megoldas.";
				}
				

		} else if (Parabola* parabola1 = alakzat1->Caster<Parabola>()) {

				if (Parabola* parabola2 = alakzat2->Caster<Parabola>()) {
						std::cout << "Parabola-Parabola:" << std::endl;
						return Parabola_Parabola_Metszes(parabola1, parabola2);

				} else if (Egyenes* egyenes = alakzat2->Caster<Egyenes>()) {
						std::cout << "Parabola-Egyenes:" << std::endl;
						return Egyenes_Parabola_Metszes(egyenes, parabola1);

				} else if (Kor* kor = alakzat2->Caster<Kor>())  {
						throw "Parabola-Kor metszesre nincs megoldas.";
				}
		}
		throw "Hiba az elso alakzat Castolasakor.";
}

private:
	static std::vector<Pont> Egyenes_Egyenes_Metszes(Egyenes* egyenes1, Egyenes* egyenes2) {
		/// METSZES
		std::vector<Pont> ret;
		double metszesX;
		double metszesY;

		if (egyenes1->getX() == egyenes2->getX() && egyenes1->getKonst()!= egyenes2->getKonst()) {
			return ret;
		}
		else if (egyenes1->getX() == egyenes2->getX() && egyenes1->getKonst() == egyenes2->getKonst()) {
			throw false;
		}
		else{

			metszesX = ((egyenes2->getKonst()) - (egyenes1->getKonst())) / (egyenes1->getX() - egyenes2->getX());
			metszesY = egyenes1->getX() * metszesX + egyenes1->getKonst();
			ret.push_back(Pont(metszesX, metszesY));
			return ret;
		}

	}

	static std::vector<Pont> Egyenes_Kor_Metszes(Egyenes* egyenes, Kor* kor) {
		/// METSZES
		std::vector<Pont> ret;

		double a = kor->getXnegyzet() * egyenes->getX() * egyenes->getX();
		double b = kor->getX() + 2 * egyenes->getX() * egyenes->getKonst() + kor->getY() * egyenes->getX();
		double c = egyenes->getKonst() * egyenes->getKonst() + kor->getY() * egyenes->getKonst() + kor->getKonst();
		double metszesX1;
		double metszesY1;
		double metszesX2;
		double metszesY2;

		if ((b * b - 4 * a * c) < 0) {
			return ret;
		}
		else if ((b * b - 4 * a * c) == 0) {
			metszesX1 = (-1 * b) / (2 * a);
			metszesY1 = egyenes->getX() * metszesX1 + egyenes->getKonst();
			ret.push_back(Pont(metszesX1, metszesY1));
			return ret;
		}
		else {
			metszesX1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
			metszesY1 = egyenes->getX() * metszesX1 + egyenes->getKonst();
			metszesX2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
			metszesY2 = egyenes->getX() * metszesX2 + egyenes->getKonst();
			ret.push_back(Pont(metszesX1, metszesY1));
			ret.push_back(Pont(metszesX2, metszesY2));
			return ret;
		}
	}

	static std::vector<Pont> Egyenes_Parabola_Metszes(Egyenes* egyenes, Parabola* parabola) {
		/// METSZES
		std::vector<Pont> ret;
		double a=parabola->getXnegyzet();
		double b=parabola->getX()-egyenes->getX();
		double c=parabola->getKonst()-egyenes->getKonst();
		double metszesX1;
		double metszesY1;
		double metszesX2;
		double metszesY2;


		if ((b * b - 4 * a * c) < 0) {
			return ret;
		}
		else if ((b * b - 4 * a * c) == 0) {
			metszesX1 = (-1 * b) / (2 * a);
			metszesY1 = egyenes->getX() * metszesX1 + egyenes->getKonst();
			ret.push_back(Pont(metszesX1, metszesY1));
			return ret;
		}
		else {
			metszesX1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
			metszesY1 = egyenes->getX() * metszesX1 + egyenes->getKonst();
			metszesX2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
			metszesY2 = egyenes->getX() * metszesX2 + egyenes->getKonst();
			ret.push_back(Pont(metszesX1, metszesY1));
			ret.push_back(Pont(metszesX2, metszesY2));
			return ret;
		}
	}

	static std::vector<Pont> Kor_Kor_Metszes(Kor* kor1, Kor* kor2) {
		/// METSZES
		std::vector<Pont> ret;
		double segedx = (-1 * (kor1->getX() - kor2->getX())) / (kor1->getY() - kor2->getY());
		double segedkonst = (-1 * (kor1->getKonst() - kor2->getKonst())) / (kor1->getY() - kor2->getY());
		double a = kor1->getXnegyzet() * segedx * segedx;
		double b = kor1->getX() + 2 * segedx * segedkonst + kor1->getY() * segedx;
		double c = segedkonst * segedkonst + kor1->getY() * segedkonst + kor1->getKonst();
		double metszesX1;
		double metszesY1;
		double metszesX2;
		double metszesY2;

		if (kor1->getX() == kor2->getX() && kor1->getY() == kor2->getY() && kor1->getKonst() == kor2->getKonst()) {
			throw false;
		}

		if ((b * b - 4 * a * c) < 0) {
			return ret;
		} else if ((b * b - 4 * a * c) == 0) {
			metszesX1 = (-1 * b) / (2 * a);
			metszesY1 = segedx * metszesX1 + segedkonst;
			ret.push_back(Pont(metszesX1, metszesY1));
			return ret;
		} else {
			metszesX1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
			metszesY1 = segedx * metszesX1 + segedkonst;
			metszesX2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
			metszesY2 = segedx * metszesX2 + segedkonst;
			ret.push_back(Pont(metszesX1, metszesY1));
			ret.push_back(Pont(metszesX2, metszesY2));
			return ret;
		}
	}

	static std::vector<Pont> Parabola_Parabola_Metszes(Parabola* parabola1, Parabola* parabola2) {
		/// METSZES
		std::vector<Pont> ret;
		double a = parabola1->getXnegyzet()-parabola2->getXnegyzet();
		double b = parabola1->getX() - parabola2->getX();
		double c = parabola1->getKonst() - parabola2->getKonst();
		double metszesX1;
		double metszesY1;
		double metszesX2;
		double metszesY2;

		if   ( parabola1->getXnegyzet() == parabola2->getXnegyzet() 
			&& parabola1->getX() == parabola2->getX() 
			&& parabola1->getKonst()==parabola2->getKonst()) {

			throw false;
		}

		if ((b * b - 4 * a * c) < 0) {
			return ret;
		} else if ((b * b - 4 * a * c) == 0) {
			metszesX1 = (-1 * b) / (2 * a);
			metszesY1 = parabola1->getXnegyzet() * metszesX1*metszesX1 + parabola1->getX()*metszesX1+parabola1->getKonst();
			ret.push_back(Pont(metszesX1, metszesY1));
			return ret;
		} else {
			metszesX1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
			metszesY1 = parabola1->getXnegyzet() * metszesX1 * metszesX1 + parabola1->getX() * metszesX1 + parabola1->getKonst();
			metszesX2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
			metszesY2 = parabola1->getXnegyzet() * metszesX2 * metszesX2 + parabola1->getX() * metszesX2 + parabola1->getKonst();
			ret.push_back(Pont(metszesX1, metszesY1));
			ret.push_back(Pont(metszesX2, metszesY2));
			return ret;
		}
	}


    ~ Metszo() {}
};


#endif