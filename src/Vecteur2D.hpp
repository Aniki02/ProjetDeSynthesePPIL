#ifndef _VECTEUR2D_HPP
#define _VECTEUR2D_HPP

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cmath>

#define PI 3.14159

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

	const double getX() const{return _x;}
	const double getY() const{return _y;}

	void setX(const double x){_x = x;}
	void setY(const double y){_y = y;}

	// void translation(const Vecteur2D &vecteur){*this = *this + vecteur;}
	// void homothetie(const double nombre){_x *= nombre; _y *= nombre;}
	// void rotation(const double degre, const Vecteur2D &vecteur_centre){
	// 	double	x = _x - vecteur_centre.getX(),
	// 			y = _y - vecteur_centre.getY(),
	// 			r = degre * PI / 180.0;
	
	// 	_x = vecteur_centre.getX() + x * cos(r) - y * sin(r);
	// 	_y = vecteur_centre.getY() + x * sin(r) + y * cos(r);
	// }

	const Vecteur2D operator *(const double &) const;
	const Vecteur2D operator - () const{return Vecteur2D(-_x,-_y);}
	const Vecteur2D operator+(const Vecteur2D & v) const {return Vecteur2D(_x + v._x, _y + v._y);}
	operator string() const;

};


inline const Vecteur2D Vecteur2D::operator*(const double & a) const{
	return Vecteur2D(a*_x, a*_y);
}

inline const Vecteur2D operator* (const double & a, const Vecteur2D & v){
	return v*a;
}
//extern const Vecteur2D operator +(const Vecteur2D &, const Vecteur2D &);
//extern ostream & operator << (ostream &, const Vecteur2D &);


/*const Vecteur2D operator+(const Vecteur2D & u, const Vecteur2D & v){
	return Vecteur2D(u._x + v._x, u._y + v._y);
}*/

inline Vecteur2D::operator string() const{
	ostringstream os;
	os << "(" << _x <<"," << _y << ")";
	return os.str();
}


inline ostream & operator<< (ostream & os, const Vecteur2D & v){
	os << (string) v;
	return os;
}
#endif