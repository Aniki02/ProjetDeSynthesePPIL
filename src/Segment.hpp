#ifndef Segment_hpp
#define Segment_hpp

#include <stdio.h>
#include "Forme.hpp"
#include "Vecteur2D.hpp"
#include <iostream>
class Forme;
class VisitorDessinerForme;
class Vecteur2D;

class Segment : public Forme{
Vecteur2D _origine;
Vecteur2D _arrive;

public :
    Segment(const Vecteur2D &x, const Vecteur2D &y, int couleur):Forme(couleur), _origine(x), _arrive(y){}
    virtual ~Segment(){}
    Forme * clone() const;
    double getAir() const {return 0;}
    Vecteur2D getArrive()const {return _arrive; }
    Vecteur2D getOrigine()const {return _origine;}
    void setArrive(const Vecteur2D &v){_arrive = v;}
    void setOrigine(const Vecteur2D &v){_origine = v;}
    void accepteDessin(VisitorDessinerForme *visiteur) const;

	virtual Forme * translation (const Vecteur2D & vecTrans);
	virtual Forme * homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie);
	virtual Forme * rotation (const Vecteur2D & pInvariant, double radiant);
	virtual operator string() const;


};

#endif
