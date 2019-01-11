#ifndef _VECTEUR2D_HPP
#define _VECTEUR2D_HPP

#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
return u + -v;
}

class Vecteur2D{
	
public:
	double _x, _y;

	explicit Vecteur2D(const double & x = 0, const double & y = 0): _x(x), _y(y){}

	const Vecteur2D operator *(const double &) const;
	const Vecteur2D operator - () const{
	return Vecteur2D(-_x,-_y);
	}
	const Vecteur2D operator+(const Vecteur2D & v) const {
	return Vecteur2D(_x + v._x, _y + v._y);
	}
	operator string() const;



};
inline const Vecteur2D Vecteur2D::operator*(const double & a) const{
	return Vecteur2D(a*_x, a*_y);
}

inline const Vecteur2D operator* (const double & a, const Vecteur2D & v){
	return v*a;
}
//extern const Vecteur2D operator +(const Vecteur2D &, const Vecteur2D &);
extern ostream & operator << (ostream &, const Vecteur2D &);


/*const Vecteur2D operator+(const Vecteur2D & u, const Vecteur2D & v){
	return Vecteur2D(u._x + v._x, u._y + v._y);
}*/
#endif