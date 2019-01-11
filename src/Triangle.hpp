#ifndef Triangle_hpp
#define Triangle_hpp
#include <stdio.h>
#include "Forme.hpp"
#include "Vecteur2D.hpp"
#include <iostream>

class VisitorDessinForme;
class Vecteur2D;

class Triangle: public Polygone{

Vecteur2D _un;
Vecteur2D _deux;
Vecteur2D _trois;

public :
    Triangle(Vecteur2D u, Vecteur2D d, Vecteur2D t):Polygone(){
        _un = u;
        _deux = d;
        _trois = t;
        _points.add(_un);
        _points.add(_deux);
        _points.add(_trois);
    }

    virtual ~Segment(){}
    Forme * clone() const;
    double getAir() const {return 0;}
    Vecteur2D getUn()const {return _un;}
    Vecteur2D getDeux()const {return _deux;}
    Vecteur2D getDeux()const {return _trois;}

    void setUn(const Vecteur2D &v){_un = v;}
    void setDeux(const Vecteur2D &v){_deux = v;}
    void setTrois(const Vecteur2D &v){_deux = v;}

    void accepteDessin(VisitorDessinForme *visiteur) const;

	virtual Forme * translation (const Vecteur2D & vecTrans);
	virtual Forme * homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie);
	virtual Forme * rotation (const Vecteur2D & pInvariant, double radiant);
	virtual operator string() const;



};

#endif
