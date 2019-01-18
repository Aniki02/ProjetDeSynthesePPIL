#include "Segment.hpp"
#include "VisitorDessinerForme.hpp"
#include <sstream>

using namespace std;


	Segment::Segment( Couleur couleur, const Vecteur2D &x, const Vecteur2D &y):Forme(couleur){
		/*if (x == y)
			throw ("Les 2 points doivent etre different"); */
		_origine = x;
		_arrive = y;
	}
    void Segment::accepteDessin(VisitorDessinerForme * v) const{
    	v->visite(this);
    }

    Forme * Segment::translation (const Vecteur2D & vecTrans){
    	Vecteur2D ori = getOrigine() + vecTrans;
    	Vecteur2D ari = getArrive() + vecTrans;
        return new Segment(getCouleur(),ori, ari);
    }

	Forme * Segment::homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie){
		Vecteur2D ori = (getOrigine() - pInvariant) * rapportHomothetie;
		Vecteur2D ar = (getArrive() - pInvariant) * rapportHomothetie;
        return new Segment(getCouleur(), ori, ar);
	}

	Forme * Segment::rotation (const Vecteur2D & pInvariant, double radiant){
		Vecteur2D ori = getOrigine().rotation(pInvariant, radiant);
		Vecteur2D ar = getArrive().rotation(pInvariant, radiant);
        return new Segment(getCouleur(),ori,ar);
	}

	Segment::operator string() const{
    	ostringstream os;
    	os << "Segment-Couleur:" << this->getCouleur() << "-" << this->getOrigine() << "-"<< this->getArrive();
		return os.str();
	}
