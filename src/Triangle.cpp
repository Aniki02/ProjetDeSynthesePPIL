#include "Triangle.hpp"
#include <sstream>

using namespace std;

    /*Forme * Triangle::clone() const{
        return new Triangle(*this);
    }*/
    void Triangle::accepteDessin(VisitorDessinerForme * v) const{
        //TODO
    }

    Triangle::operator string() const{
        ostringstream os;
    	os << "Point 1: " << _un <<",  Point 2 : " << _deux << "Point 2 :" << _deux << ")";
    	return os.str();
	}
