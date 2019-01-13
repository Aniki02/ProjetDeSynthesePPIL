#include "Triangle.hpp"
#include <sstream>
#include "VisitorDessinerForme.hpp"

using namespace std;

   void Triangle::accepteDessin(VisitorDessinerForme * v) const{
        v->visite(this);
    }

    Triangle::operator string() const{
    	ostringstream os;
    	os << "TRIANGLE : " << endl;
    	os << Polygone::operator string();

    	return os.str();
    }
