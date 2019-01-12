#include "Segment.hpp"
#include "VisitorDessinerForme.hpp"
#include <sstream>

using namespace std;

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
		os << "Point d'origine : " << _origine <<",  Point d'arrive : " << _arrive << ")";
		return os.str();
	}
