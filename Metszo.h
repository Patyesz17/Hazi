#ifndef METSZO_H
#define METSZO_H
#include <iostream>
#include <vector>
#include "Alakzat.h"
#include "Pont.h"
#include "Kor.h"
#include "Egyenes.h"
#include "Parabola.h"
#include <math.h>

using namespace std;

class Metszo {
    Alakzat* egyik_alakzat;
    Alakzat* masik_alakzat;

  public: 
    Metszo (Alakzat* egyik, Alakzat* masik): egyik_alakzat(egyik), masik_alakzat(masik) {}
    
    vector<Pont*> metszespontok ()  {
        vector<Pont*> ret;

        switch (egyik_alakzat->getAlakzatNev()) {
        
            case egyenes:
                switch (masik_alakzat->getAlakzatNev()) {
                    case egyenes:
                        ret = egyenes_egyenes_metszes((Egyenes&)egyik_alakzat,(Egyenes&)masik_alakzat);
                    break;

                    case kor:
                        ret = egyenes_kor_metszes((Egyenes&)egyik_alakzat, (Kor&)masik_alakzat);
                    break;

                    case parabola:
                        ret = egyenes_parabola_metszes((Egyenes&)egyik_alakzat, (Parabola&)masik_alakzat);
                    break;
                } 
            break;

            case kor:
                switch(masik_alakzat->getAlakzatNev()) {
                    case egyenes:
                        ret = egyenes_kor_metszes((Egyenes&)masik_alakzat, (Kor&)egyik_alakzat);
                    break;

                    case kor:
                        ret = kor_kor_metszes((Kor&)egyik_alakzat, (Kor&)masik_alakzat);
                    break;
                }
            break;
            
            case parabola:
                switch(masik_alakzat->getAlakzatNev()) {
                    case egyenes:
                        ret = egyenes_parabola_metszes((Egyenes&)masik_alakzat, (Parabola&)egyik_alakzat);
                    break;

                    case parabola:
                        ret = parabola_parabola_metszes((Parabola&)egyik_alakzat, (Parabola&)masik_alakzat);
                    break;
                }
            break; 

            default:
                break;
        }

        return ret;
    }

   
    
    ~ Metszo() {
        delete egyik_alakzat;
        delete masik_alakzat;
    }
};
vector<Pont*> egyenes_egyenes_metszes(const Egyenes& egyik, const Egyenes& masik) {
	vector<Pont*> ret;
	double metszesX;
	double metszesY;

	if (egyik.getX() == masik.getX()) {
		return ret;
	}
	else {

		metszesX = ((masik.getKonst()) - (egyik.getKonst())) / (egyik.getX() - masik.getX());
		metszesY = egyik.getX() * metszesX + egyik.getKonst();
		ret.push_back(new Pont(metszesX, metszesY));
		return ret;
	}

}
vector<Pont*> egyenes_kor_metszes(const Egyenes& egyenes, const Kor& kor) {

	vector<Pont*> ret;

	double a = kor.getXnegyzet() * egyenes.getX() * egyenes.getX();
	double b = kor.getX() + 2 * egyenes.getX() * egyenes.getKonst() + kor.getY() * egyenes.getX();
	double c = egyenes.getKonst() * egyenes.getKonst() + kor.getY() * egyenes.getKonst() + kor.getKonst();
	double metszesX1;
	double metszesY1;
	double metszesX2;
	double metszesY2;

	if ((b * b - 4 * a * c) < 0) {
		return ret;
	}
	else if ((b * b - 4 * a * c) == 0) {
		metszesX1 = (-1 * b) / (2 * a);
		metszesY1 = egyenes.getX() * metszesX1 + egyenes.getKonst();
		ret.push_back(new Pont(metszesX1, metszesY1));
		return ret;
	}
	else {
		metszesX1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY1 = egyenes.getX() * metszesX1 + egyenes.getKonst();
		metszesX2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY2 = egyenes.getX() * metszesX2 + egyenes.getKonst();
		ret.push_back(new Pont(metszesX1, metszesY1));
		ret.push_back(new Pont(metszesX2, metszesY2));
		return ret;
	}
}

vector<Pont*> egyenes_parabola_metszes(const Egyenes& egyenes, const Parabola& parabola) {
	vector<Pont*> ret;
	double a=parabola.getXnegyzet();
	double b=parabola.getX()-egyenes.getX();
	double c=parabola.getKonst()-egyenes.getKonst();
	double metszesX1;
	double metszesY1;
	double metszesX2;
	double metszesY2;


	if ((b * b - 4 * a * c) < 0) {
		return ret;
	}
	else if ((b * b - 4 * a * c) == 0) {
		metszesX1 = (-1 * b) / (2 * a);
		metszesY1 = egyenes.getX() * metszesX1 + egyenes.getKonst();
		ret.push_back(new Pont(metszesX1, metszesY1));
		return ret;
	}
	else {
		metszesX1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY1 = egyenes.getX() * metszesX1 + egyenes.getKonst();
		metszesX2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY2 = egyenes.getX() * metszesX2 + egyenes.getKonst();
		ret.push_back(new Pont(metszesX1, metszesY1));
		ret.push_back(new Pont(metszesX2, metszesY2));
		return ret;
	}



}

vector<Pont*> kor_kor_metszes(const Kor& kor1, const Kor& kor2) {
	vector<Pont*> ret;
	double segedx = (-1 * (kor1.getX() - kor2.getX())) / (kor1.getY() - kor2.getY());
	double segedkonst = (-1 * (kor1.getKonst() - kor2.getKonst())) / (kor1.getY() - kor2.getY());
	double a = kor1.getXnegyzet() * segedx * segedx;
	double b = kor1.getX() + 2 * segedx * segedkonst + kor1.getY() * segedx;
	double c = segedkonst * segedkonst + kor1.getY() * segedkonst + kor1.getKonst();
	double metszesX1;
	double metszesY1;
	double metszesX2;
	double metszesY2;

	if ((b * b - 4 * a * c) < 0) {
		return ret;
	}
	else if ((b * b - 4 * a * c) == 0) {
		metszesX1 = (-1 * b) / (2 * a);
		metszesY1 = segedx * metszesX1 + segedkonst;
		ret.push_back(new Pont(metszesX1, metszesY1));
		return ret;
	}
	else {
		metszesX1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY1 = segedx * metszesX1 + segedkonst;
		metszesX2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY1 = segedx * metszesX2 + segedkonst;
		ret.push_back(new Pont(metszesX1, metszesY1));
		ret.push_back(new Pont(metszesX2, metszesY2));
		return ret;
	}
}
vector<Pont*> parabola_parabola_metszes(const Parabola& parabola1, const Parabola& parabola2) {
	vector<Pont*> ret;
	double a = parabola1.getXnegyzet()-parabola2.getXnegyzet();
	double b = parabola1.getX() - parabola2.getX();
	double c = parabola1.getKonst() - parabola2.getKonst();
	double metszesX1;
	double metszesY1;
	double metszesX2;
	double metszesY2;

	if(parabola1.getXnegyzet()==parabola2.getXnegyzet() && parabola1.getX()==parabola2.getX()){
		return ret;
	}

	if ((b * b - 4 * a * c) < 0) {
		return ret;
	}
	else if ((b * b - 4 * a * c) == 0) {
		metszesX1 = (-1 * b) / (2 * a);
		metszesY1 = parabola1.getXnegyzet() * metszesX1*metszesX1 + parabola1.getX()*metszesX1+parabola1.getKonst();
		ret.push_back(new Pont(metszesX1, metszesY1));
		return ret;
	}
	else {
		metszesX1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY1 = parabola1.getXnegyzet() * metszesX1 * metszesX1 + parabola1.getX() * metszesX1 + parabola1.getKonst();
		metszesX2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY2 = parabola1.getXnegyzet() * metszesX2 * metszesX2 + parabola1.getX() * metszesX2 + parabola1.getKonst();
		ret.push_back(new Pont(metszesX1, metszesY1));
		ret.push_back(new Pont(metszesX2, metszesY2));
		return ret;
	}
}

#endif