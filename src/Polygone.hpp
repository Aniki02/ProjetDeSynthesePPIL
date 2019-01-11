#ifndef Polygone_hpp
#define Polygone_hpp

#include <stdio.h>
#include "Forme.hpp"
#include "Vecteur2D.hpp"
#include <iostream>
#include <vector>

class Vecteur2D;

class Polygone: public Forme{
	vector<Vecteur2D> _points;

    public :

    Polygone(int c, const vector<Vecteur2D> points);
    virtual ~Polygone(){}
 //   Forme * clone(){return new Polygone(*this);}
    virtual double getAir()const=0;
    void addPoint(Vecteur2D);
    const Vecteur2D getPointAt(unsigned int index) const;
    virtual Forme * translation (const Vecteur2D & vecTrans);
	virtual Forme * homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie);
	virtual Forme * rotation (const Vecteur2D & pInvariant, double radiant);
	void accepteDessin(VisitorDessinerForme * v) const;
    virtual operator string() const;





};

#endif
