#ifndef _FORME_HPP
#define _FORME_HPP

#include <stdio.h>
#include <iostream>

using namespace std;

class Vecteur2D;
class VisitorDessinerForme;
/**
Une forme geometrique est caracterise par un couleur
un int défini par les constantes static
*/
class Forme{
	int _couleur;
public:
	static const int BLACK = 1, BLUE = 2, RED = 3, GREEN = 4, YELLOW = 5, CYAN = 6;
	Forme(int couleur);
	virtual ~Forme();

	int getCouleur() const ;

	virtual Forme * translation (const Vecteur2D & vecTrans) = 0;
	virtual Forme * homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie) = 0;
	virtual Forme * rotation (const Vecteur2D & pInvariant, double radiant) = 0;

	virtual double getAir() const = 0;
	virtual Forme * clone() const = 0;
	virtual operator string() const = 0;

	virtual void accepteDessin(VisitorDessinerForme * v) const = 0;

};

extern ostream & operator << (ostream & , const Forme &);






#endif
