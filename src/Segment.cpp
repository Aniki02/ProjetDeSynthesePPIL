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

	/*Forme * Segment::clone() const {
	return new Segment(*this);
	}*/
    Forme * Segment::translation (const Vecteur2D & vecTrans){
    	//TODO
    	return NULL;
    }

	Forme * Segment::homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie){
		//TODO
		return NULL;
	}

	Forme * Segment::rotation (const Vecteur2D & pInvariant, double radiant){
		//TODO
		return NULL;
	}

	Segment::operator string() const{
    	ostringstream os;
    	os << "Segment-Couleur:" << this->getCouleur() << "-" << this->getOrigine() << "-"<< this->getArrive();
		return os.str();
	}
