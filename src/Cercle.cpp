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
        //return new Cercle(this->getNumeroCouleur(), _centre.translation(vecTrans), _rayon);
        return NULL;
    }
	Forme * Cercle::homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie){
        //return new Cercle (this->getNumeroCouleur(), _centre, _rayon *= rapportHomothetie );
        return NULL;
    }
    Forme * Cercle::rotation (const Vecteur2D & pInvariant, double radiant){
        //return new Cercle(this->getNumeroCouleur(), _centre.rotation(pInvariant, radiant), _rayon);
        return NULL;
    }
	void Cercle::accepteDessin(VisitorDessinerForme * v) const {
        v->visite(this);
    }
    Cercle::operator string() const{
    ostringstream os;
    os << "Cercle-Couleur:" << this->getCouleur() << "-Centre" << this->getCentre() <<"-Rayon:" << this->getRayon();
	return os.str();
    }
