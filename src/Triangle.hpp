#ifndef Triangle_hpp
#define Triangle_hpp
#include <stdio.h>
#include "Forme.hpp"
#include "Vecteur2D.hpp"
#include "Polygone.hpp"
#include <iostream>

class VisitorDessinForme;
class Vecteur2D;


class Triangle: public Polygone{

public :
    Triangle(int couleur, vector<Vecteur2D> points):Polygone(couleur, points){}

    virtual ~Triangle(){}
    Forme * clone() const{return new Triangle(*this);}
    double getAir() const {return 0;}

    void accepteDessin(VisitorDessinerForme * v) const;
};

#endif
