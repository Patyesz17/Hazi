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
           // cout << "BEOLVASOK" << endl;
            ret.push_back(new  Egyenes(x1, y1, x2, y2));
        }
    }

    file.close();
    return ret;

}

vector<Kor*> kor_beolvaso (string file_nev) {
    
    vector<Kor*> ret;
    
    ifstream file;
    file.open(file_nev);

    if(file.is_open()) {
        double x1;
        double y1;
        double sugar;

        int index = 0;

        while (file >> x1 >> y1 >> sugar) {
            cout << "BEOLVASOK" << endl;
            ret.push_back(new  Kor(x1, y1, sugar));
        }
    }

    file.close();
    return ret;

}

vector<Parabola*> parabola_beolvaso (string file_nev) {
    
    vector<Parabola*> ret;
    
    ifstream file;
    file.open(file_nev);

    if(file.is_open()) {
        double x1;
        double y1;
        double sugar;

        int index = 0;

        while (file >> x1 >> y1 >> sugar) {
            cout << "BEOLVASOK" << endl;
            ret.push_back(new Parabola(x1, y1, sugar));
        }
    }

    file.close();
    return ret;

}
#endif
