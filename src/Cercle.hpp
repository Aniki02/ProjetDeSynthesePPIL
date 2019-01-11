#ifndef Cercle_hpp
#define Cercle_hpp

#include <stdio.h>
#include "Forme.hpp"
#include "Vecteur2D.hpp"
#include <iostream>

class Forme;
class VisitorDessinForme;
class Vecteur2D;

class Cercle : public Forme{
    Vecteur2D _centre;
    double _rayon;

    public :
    Cercle(Vecteur2D v, double r, int c):Forme(c),_rayon(r), _centre(v){}
    virtual ~Cercle(){}
 //   Forme * clone(){return new Cercle(*this);}
    double getAir()const;
    Vecteur2D getCentre()const {return _centre;}
    double getRayon() const {return _rayon;}
    void setCentre(const Vecteur2D &v){_centre = v;}
    void setRayon(double r){_rayon = r;}
    virtual Forme * translation (const Vecteur2D & vecTrans) = 0;
	virtual Forme * homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie) = 0;
	virtual Forme * rotation (const Vecteur2D & pInvariant, double radiant) = 0;
	void accepteDessin(VisitorDessinerForme * v) const = 0;
    virtual operator string() const;
};

#endif
