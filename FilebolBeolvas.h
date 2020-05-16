#ifndef FILEBOLBEOLVAS_H
#define FILEBOLBEOLVAS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Egyenes.h"
#include "Kor.h"
#include "Parabola.h"

using namespace std;

vector<Egyenes*> egyenes_beolvaso (string file_nev) {
    
    vector<Egyenes*> ret;
    
    ifstream file;
    file.open(file_nev);

    if(file.is_open()) {
        double x1;
        double y1;
        double x2;
        double y2;

        int index = 0;

        while (file >> x1 >> y1 >> x2 >> y2) {
            Pont A(x1, y1);
            Pont B(x2, y2);
            ret[index++] = new Egyenes (A,B);
        }
    }

    file.close();
    return ret;

}
#endif