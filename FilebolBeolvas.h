#ifndef FILEBOLBEOLVAS_H
#define FILEBOLBEOLVAS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Egyenes.h"
#include "Kor.h"
#include "Parabola.h"


Egyenes* egyenes_beolvaso(std::istream& is) {

		double x1, x2, y1, y2;
		is >> x1 >> y1 >> x2 >> y2;
		
		return new Egyenes(x1, y1, x2, y2);
}

Kor* kor_beolvaso(std::istream& is) {

		double x, y, sugar;
		is >> x >> y >> sugar;

		return new Kor(x, y, sugar);
}

Parabola* parabola_beolvaso(std::istream& is) {
        
        double xNegyzet, x, konstans;
		is >> xNegyzet >> x >> konstans;

		return new Parabola(xNegyzet, x, konstans);
}

std::vector<Alakzat*> alakzat_beolvaso (const std::string& file_nev) {
    
    std::vector<Alakzat*> ret;
    
    std::ifstream input_filestream;
    input_filestream.open(file_nev);

    std::string temp;

    while(!input_filestream.eof()) {
        
        input_filestream >> temp;
        if (temp == "egyenes") {
            
            ret.push_back(egyenes_beolvaso(input_filestream));
       
        } else if (temp == "kor") {
       
            ret.push_back(kor_beolvaso(input_filestream));
       
        } else if (temp == "parabola") {

            ret.push_back(parabola_beolvaso(input_filestream));

        }
    }
    
    input_filestream.close();
    return ret;

}
#endif
