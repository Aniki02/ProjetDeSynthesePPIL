#ifndef Cercle_hpp
#define Cercle_hpp

#include <stdio.h>
#include "Forme.hpp"
#include "Vecteur2D.hpp"
#include "Couleur.hpp"
#include <iostream>

#define PI 3.14159

class Forme;
class VisitorDessinForme;
class Vecteur2D;

class Cercle : public Forme{
    Vecteur2D _centre;
    double _rayon;

    public :
    Cercle(Couleur couleur, Vecteur2D centre, double r);
    virtual ~Cercle(){}

    Forme * clone() const {return new Cercle(*this);}

    double getAir()const;
    Vecteur2D getCentre()const {return _centre;}
    double getRayon() const {return _rayon;}
    void setCentre(const Vecteur2D &v){_centre = v;}
    void setRayon(double r){_rayon = r;}

    virtual Forme * translation (const Vecteur2D & vecTrans);
	virtual Forme * homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie);
	virtual Forme * rotation (const Vecteur2D & pInvariant, double radiant);
	void accepteDessin(VisitorDessinerForme * v) const;

    virtual operator string() const;
};

#endif
