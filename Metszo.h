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
	Egyenes* egyenes1;
	Egyenes* egyenes2;
	Kor* kor1;
	Kor* kor2;
	Parabola* parabola1;
	Parabola* parabola2;

  public: 
	  Metszo(Egyenes* egyenes1, Egyenes* egyenes2):egyenes1(egyenes1),egyenes2(egyenes2),kor1(nullptr),kor2(nullptr),parabola1(nullptr),parabola2(nullptr){}
	  Metszo(Egyenes* egyenes1, Kor* kor1) :egyenes1(egyenes1), egyenes2(nullptr), kor1(kor1), kor2(nullptr), parabola1(nullptr), parabola2(nullptr) {}
	  Metszo(Egyenes* egyenes1, Parabola* parabola1) :egyenes1(egyenes1), egyenes2(nullptr), kor1(nullptr), kor2(nullptr), parabola1(parabola1), parabola2(nullptr) {}
	  Metszo(Kor* kor1, Kor* kor2) :egyenes1(nullptr), egyenes2(nullptr), kor1(kor1), kor2(kor2), parabola1(nullptr), parabola2(nullptr) {}
	  Metszo(Parabola* parabola1, Parabola* parabola2) :egyenes1(nullptr), egyenes2(nullptr), kor1(nullptr), kor2(nullptr), parabola1(parabola1), parabola2(parabola2) {}
    
	vector<Pont*> egyenes_egyenes_metszes() {
	vector<Pont*> ret;
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
		ret.push_back(new Pont(metszesX, metszesY));
		return ret;
	}

}
vector<Pont*> egyenes_kor_metszes() {

	vector<Pont*> ret;

	double a = kor1->getXnegyzet() * egyenes1->getX() * egyenes1->getX();
	double b = kor1->getX() + 2 * egyenes1->getX() * egyenes1->getKonst() + kor1->getY() * egyenes1->getX();
	double c = egyenes1->getKonst() * egyenes1->getKonst() + kor1->getY() * egyenes1->getKonst() + kor1->getKonst();
	double metszesX1;
	double metszesY1;
	double metszesX2;
	double metszesY2;

	if ((b * b - 4 * a * c) < 0) {
		return ret;
	}
	else if ((b * b - 4 * a * c) == 0) {
		metszesX1 = (-1 * b) / (2 * a);
		metszesY1 = egyenes1->getX() * metszesX1 + egyenes1->getKonst();
		ret.push_back(new Pont(metszesX1, metszesY1));
		return ret;
	}
	else {
		metszesX1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY1 = egyenes1->getX() * metszesX1 + egyenes1->getKonst();
		metszesX2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY2 = egyenes1->getX() * metszesX2 + egyenes1->getKonst();
		ret.push_back(new Pont(metszesX1, metszesY1));
		ret.push_back(new Pont(metszesX2, metszesY2));
		return ret;
	}
}

vector<Pont*> egyenes_parabola_metszes() {
	vector<Pont*> ret;
	double a=parabola1->getXnegyzet();
	double b=parabola1->getX()-egyenes1->getX();
	double c=parabola1->getKonst()-egyenes1->getKonst();
	double metszesX1;
	double metszesY1;
	double metszesX2;
	double metszesY2;


	if ((b * b - 4 * a * c) < 0) {
		return ret;
	}
	else if ((b * b - 4 * a * c) == 0) {
		metszesX1 = (-1 * b) / (2 * a);
		metszesY1 = egyenes1->getX() * metszesX1 + egyenes1->getKonst();
		ret.push_back(new Pont(metszesX1, metszesY1));
		return ret;
	}
	else {
		metszesX1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY1 = egyenes1->getX() * metszesX1 + egyenes1->getKonst();
		metszesX2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY2 = egyenes1->getX() * metszesX2 + egyenes1->getKonst();
		ret.push_back(new Pont(metszesX1, metszesY1));
		ret.push_back(new Pont(metszesX2, metszesY2));
		return ret;
	}



}

vector<Pont*> kor_kor_metszes() {
	vector<Pont*> ret;
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
		metszesY2 = segedx * metszesX2 + segedkonst;
		ret.push_back(new Pont(metszesX1, metszesY1));
		ret.push_back(new Pont(metszesX2, metszesY2));
		return ret;
	}
}
vector<Pont*> parabola_parabola_metszes() {
	vector<Pont*> ret;
	double a = parabola1->getXnegyzet()-parabola2->getXnegyzet();
	double b = parabola1->getX() - parabola2->getX();
	double c = parabola1->getKonst() - parabola2->getKonst();
	double metszesX1;
	double metszesY1;
	double metszesX2;
	double metszesY2;

	if(parabola1->getXnegyzet()==parabola2->getXnegyzet() && parabola1->getX()==parabola2->getX() && parabola1->getKonst()==parabola2->getKonst()){
		throw false;
	}

	if ((b * b - 4 * a * c) < 0) {
		return ret;
	}
	else if ((b * b - 4 * a * c) == 0) {
		metszesX1 = (-1 * b) / (2 * a);
		metszesY1 = parabola1->getXnegyzet() * metszesX1*metszesX1 + parabola1->getX()*metszesX1+parabola1->getKonst();
		ret.push_back(new Pont(metszesX1, metszesY1));
		return ret;
	}
	else {
		metszesX1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY1 = parabola1->getXnegyzet() * metszesX1 * metszesX1 + parabola1->getX() * metszesX1 + parabola1->getKonst();
		metszesX2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
		metszesY2 = parabola1->getXnegyzet() * metszesX2 * metszesX2 + parabola1->getX() * metszesX2 + parabola1->getKonst();
		ret.push_back(new Pont(metszesX1, metszesY1));
		ret.push_back(new Pont(metszesX2, metszesY2));
		return ret;
	}
}
   

   
    
    ~ Metszo() {}
};


#endif