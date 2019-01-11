#include "Triangle.hpp"
#include <sstream>

using namespace std;

    //Forme * Triangle::clone() const;
    void Triangle::accepteDessin(VisitorDessinForme *visiteur) const{}

    Forme * Triangle::translation (const Vecteur2D & vecTrans){return NULL;}

    Forme * Triangle::homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie){return NULL;}

    Forme * Triangle::rotation (const Vecteur2D & pInvariant, double radiant){return NULL;}

    Triangle::operator string() const{
    ostringstream os;
	os << "Point 1: " << _un <<",  Point 2 : " << _deux << "Point 2 :" << _deux ")";
	return os.str();
	}
