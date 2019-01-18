#include "Cercle.hpp"
#include "VisitorDessinerForme.hpp"
#include <sstream>

using namespace std;


    Cercle::Cercle(Couleur couleur, Vecteur2D centre, double r):Forme(couleur), _centre(centre){
        if (r <= 0)
            throw ("Le rayon doit etre superieur a 0");
        _rayon = r;
    }
    double Cercle::getAir()const{
        return 3.14 * getRayon() * getRayon();
    }
    Forme * Cercle::translation (const Vecteur2D & vecTrans){
        Vecteur2D centre = getCentre() + vecTrans;
        return new Cercle(getCouleur(),centre,getRayon());
    }
	Forme * Cercle::homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie){
        double rayon = getRayon() * rapportHomothetie;
        Vecteur2D v = (getCentre() - pInvariant) * rapportHomothetie;
        return new Cercle(getCouleur(), v, rayon);
    }
    Forme * Cercle::rotation (const Vecteur2D & pInvariant, double radiant){
        Vecteur2D v = getCentre().rotation(pInvariant, radiant);
        return new Cercle(getCouleur(),v,getRayon());
    }
	void Cercle::accepteDessin(VisitorDessinerForme * v) const {
        v->visite(this);
    }
    Cercle::operator string() const{
    ostringstream os;
    os << "Cercle-Couleur:" << this->getCouleur() << "-Centre" << this->getCentre() <<"-Rayon:" << this->getRayon();
	return os.str();
    }
