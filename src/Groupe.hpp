#ifndef _GROUPE_HPP
#define _GROUPE_HPP

#include
#include <Forme.hpp>
class Groupe : public Forme{
	vector<Forme *> _groupes;
public:
	virtual void translation (const Vecteur2D & vecTrans) = 0;
	virtual void homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie) = 0;
	virtual void rotation (const Vecteur2D & pInvariant, double radiant) = 0;

	virtual Forme * translation (const Vecteur2D & vecTrans) = 0;
	virtual Forme * homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie) = 0;
	virtual Forme * rotation (const Vecteur2D & pInvariant, double radiant) = 0;

	virtual double getAir() const = 0;
	virtual Forme * clone() const = 0;
	virtual operator string() const = 0;

	virtual void accepteDessin(VisitorDessinerForme * v) const = 0;
};
#endif