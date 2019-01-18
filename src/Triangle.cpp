#include "Triangle.hpp"
#include <sstream>
#include "VisitorDessinerForme.hpp"

using namespace std;

   void Triangle::accepteDessin(VisitorDessinerForme * v) const{
        v->visite(this);
    }

    Triangle::operator string() const{
    	ostringstream os;
    	os << "Triangle-Couleur:"<<this->getCouleur()<<"-"<< this->getPointAt(0) << "-" << this->getPointAt(1)<<"-" << this->getPointAt(2);

    	return os.str();
    }
