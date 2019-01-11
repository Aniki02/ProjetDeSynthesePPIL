#include "Cercle.hpp"
#include <sstream>

using namespace std;

    double Cercle::getAir()const{return 3,14 * Cercle::getRayon() * Cercle::getRayon();}
    Forme * Cercle::translation (const Vecteur2D & vecTrans){return NULL;}
	Forme * Cercle::homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie){return NULL;}
    Forme * Cercle::rotation (const Vecteur2D & pInvariant, double radiant){return NULL;}
	void Cercle::accepteDessin(VisitorDessinerForme * v) const {}
    Cercle::operator string() const{
    ostringstream os;
	os << "Centre " << _centre <<",  Rayon : " << _rayon << ")";
	return os.str();
    }
