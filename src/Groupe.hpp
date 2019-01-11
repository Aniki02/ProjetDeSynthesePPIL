#ifndef _GROUPE_HPP
#define _GROUPE_HPP

#include <vector>
#include "Forme.hpp"
class Groupe : public Forme{
	vector<Forme *> _groupe;
public:
	Groupe(int couleur): Forme(couleur){}
	Groupe(const Groupe &);
	virtual ~Groupe();

	void addForme(Forme *);
	const Forme * getAt(unsigned int ) const;

	const vector<Forme *> getGroupe() const{return _groupe;}

	Forme * translation (const Vecteur2D & vecTrans);
	Forme * homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie);
	Forme * rotation (const Vecteur2D & pInvariant, double radiant);

	double getAir() const;
	Forme * clone() const;
	operator string() const;

	void accepteDessin(VisitorDessinerForme * v) const;
};
#endif