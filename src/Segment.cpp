#include "Segment.hpp"
#include <sstream>

using namespace std;

    void Segment::accepteDessin(VisitorDessinForme *visiteur) const{}
//     Forme * Segment::clone() const {return new Segment(this);}
     Forme * Segment::translation (const Vecteur2D & vecTrans){return NULL;}
	 Forme * Segment::homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie){return NULL;}
	 Forme * Segment::rotation (const Vecteur2D & pInvariant, double radiant){return NULL;}
	 Segment::operator string() const{
    ostringstream os;
	os << "Point d'origine : " << _origine <<",  Point d'arrivé : " << _arrive << ")";
	return os.str();
	}
