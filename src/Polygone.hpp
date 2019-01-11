#ifndef Polygone_hpp
#define Polygone_hpp

#include <stdio.h>
#include "Forme.hpp"
#include "Vecteur2D.hpp"
#include <iostream>
#include <vector>

class Polygone: public Forme{
	vector<Vecteur2D*> _points;

    public :

    Polygone(){}
    virtual ~Polygone(){}
 //   Forme * clone(){return new Polygone(*this);}
    double getAir()const;
    Vecteur2D getCentre()const {return _centre;}
    double getRayon() const {return _rayon;}
    void addPoint(Vecteur2D*);
    const Vecteur2D * getPointAt(unsigned int index) const;
    virtual Forme * translation (const Vecteur2D & vecTrans) = 0;
	virtual Forme * homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie) = 0;
	virtual Forme * rotation (const Vecteur2D & pInvariant, double radiant) = 0;
	void accepteDessin(VisitorDessinerForme * v) const = 0;
    virtual operator string() const;





};

#endif
