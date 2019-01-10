#include "Vecteur2D.hpp"


Vecteur2D::Vecteur2D(const double & x, const double & y):_x(x), _y(y){}
Vecteur2D::Vecteur2D(const double & a): _x(a), _y(a){}
Vecteur2D::~Vecteur2D(){}

const Vecteur2D Vecteur2D::operator*(const double & a) const{
	return Vecteur2D(a*_x, a*_y);
}

Vecteur2D::operator string() const{
	ostringstream os;
	os << "( " << _x <<", " << _y << ")";
	return os.str();
}

const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-_x,-_y);
}



const Vecteur2D operator* (const double & a, const Vecteur2D & v){
	return v*a;
}
const Vecteur2D operator+(const Vecteur2D & u, const Vecteur2D & v){
	return Vecteur2D(u._x + v._x, u._y + v._y);
}
ostream & operator<< (ostream & os, const Vecteur2D & v){
	os << (string) v;
	return os;
}