#ifndef METSZO_H
#define METSZO_H
#include <iostream>
#include <vector>
#include "Alakzat.h"
#include "Pont.h"
#include "Kor.h"

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
                        ret = egyenes_egyenes_metszes();
                    break;

                    case kor:
                        ret = egyenes_kor_metszes();
                    break;

                    case parabola:
                        ret = egyenes_parabola_metszes();
                    break;
                } 
            break;

            case kor:
                switch(masik_alakzat->getAlakzatNev()) {
                    case egyenes:
                        ret = egyenes_kor_metszes();
                    break;

                    case kor:
                        ret = kor_kor_metszes();
                    break;
                }
            break;
            
            case parabola:
                switch(masik_alakzat->getAlakzatNev()) {
                    case egyenes:
                        ret = egyenes_parabola_metszes();
                    break;

                    case parabola:
                        ret = parabola_parabola_metszes();
                    break;
                }
            break;

            default:
                break;
        }

        return ret;
    }

    vector<Pont*> egyenes_egyenes_metszes () {


    }
    vector<Pont*> egyenes_kor_metszes () {
      
        
    }
    vector<Pont*> kor_egyenes_metszes () {
      
        
    }
    vector<Pont*> egyenes_parabola_metszes () {

    }
    vector<Pont*> parabola_egyenes_metszes () {

    }
    vector<Pont*> kor_kor_metszes () {

    }
    vector<Pont*> parabola_parabola_metszes () {

    }
    
    ~ Metszo() {
        delete egyik_alakzat;
        delete masik_alakzat;
    }
};
#endif