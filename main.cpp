#include <iostream>
#include "Alakzat.h"
#include "Egyenes.h"
#include "Kor.h"
#include "Parabola.h"
#include "Pont.h"
#include "FilebolBeolvas.h"
#include "Metszo.h"

int main() {
	

		vector<Egyenes*> egyenesek = egyenes_beolvaso("egyenes.txt");

		vector<Kor*> korok = kor_beolvaso("kor.txt");

		vector<Parabola*> parabolak = parabola_beolvaso("parabola.txt");

		Metszo metszi1(egyenesek[0], egyenesek[1]);
		vector<Pont*>metszespont1 = metszi1.egyenes_egyenes_metszes();
		if (metszespont1.size() == 0) {
			std::cout << "Nem metszi egymást a két alakzat" << std::endl;
		}
		else {
			for (int i = 0; i < metszespont1.size(); i++) {
				metszespont1[i]->kiirat();
			}
		}

		Metszo metszi2(egyenesek[0], korok[2]);
		vector<Pont*>metszespont2 = metszi2.egyenes_kor_metszes();
		if (metszespont2.size() == 0) {
			std::cout << "Nem metszi egymást a két alakzat" << std::endl;
		}
		else {
			for (int i = 0; i < metszespont2.size(); i++) {
				metszespont2[i]->kiirat();
			}
		}


		Metszo metszi3(egyenesek[2], parabolak[1]);
		vector<Pont*>metszespont3 = metszi3.egyenes_parabola_metszes();
		if (metszespont3.size() == 0) {
			std::cout << "Nem metszi egymást a két alakzat" << std::endl;
		}
		else {
			for (int i = 0; i < metszespont3.size(); i++) {
				metszespont3[i]->kiirat();
			}
		}

		/*Metszo metszi4(korok[0], korok[1]);
		vector<Pont*>metszespont4 = metszi4.kor_kor_metszes();
		if (metszespont4.size() < 1) {
			std::cout << "Nem metszi egymást a két alakzat" << std::endl;
		}
		else if(metszespont4.size()>=1) {
			for (int i = 0; i < metszespont4.size(); i++) {
				metszespont4[i]->kiirat();
				std::cout << "hibakereses" << std::endl;
			}
		}*/

		/*Metszo metszi5(parabolak[0], parabolak[1]);
		vector<Pont*>metszespont5 = metszi5.parabola_parabola_metszes();
		if (metszespont5.size() < 1) {
			std::cout << "Nem metszi egymást a két alakzat" << std::endl;
		}
		else {
			for (int i = 0; i < metszespont5.size(); i++) {
				metszespont5[i]->kiirat();
				std::cout << "hibakereses" << std::endl;
			}
		}*/

	
	
	
	}
	

	
	
	