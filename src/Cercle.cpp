#include "Cercle.hpp"
#include "VisitorDessinerForme.hpp"
#include <sstream>

using namespace std;

    double Cercle::getAir()const{
        return 3.14 * getRayon() * getRayon();
    }
    Forme * Cercle::translation (const Vecteur2D & vecTrans){
        //TODO
        return NULL;
    }
	Forme * Cercle::homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie){
        //TODO
        return NULL;
    }
    Forme * Cercle::rotation (const Vecteur2D & pInvariant, double radiant){
        //TODO
        return NULL;
    }
	void Cercle::accepteDessin(VisitorDessinerForme * v) const {
        v->visite(this);
    }
    Cercle::operator string() const{
    ostringstream os;
	os << "Centre " << _centre <<",  Rayon : " << _rayon << ")";
	return os.str();
    }
