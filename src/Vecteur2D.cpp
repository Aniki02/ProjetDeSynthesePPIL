#include "Vecteur2D.hpp"




Vecteur2D::operator string() const{
	ostringstream os;
	os << "( " << _x <<", " << _y << ")";
	return os.str();
}







ostream & operator<< (ostream & os, const Vecteur2D & v){
	os << (string) v;
	return os;
}