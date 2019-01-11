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

Vecteur2D _un;
Vecteur2D _deux;
Vecteur2D _trois;

public :
    Triangle(int couleur, vector<Vecteur2D> points):Polygone(couleur, points){}

    virtual ~Triangle(){}
    //Forme * clone() const;
    double getAir() const {return 0;}
    Vecteur2D getUn()const {return _un;}
    Vecteur2D getDeux()const {return _deux;}
    Vecteur2D getTrois()const {return _trois;}

    void setUn(const Vecteur2D &v){_un = v;}
    void setDeux(const Vecteur2D &v){_deux = v;}
    void setTrois(const Vecteur2D &v){_deux = v;}

    void accepteDessin(VisitorDessinerForme * v) const;

	virtual operator string() const;
};

#endif
