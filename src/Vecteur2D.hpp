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

	Vecteur2D(const double & , const double & );
	Vecteur2D(const double &);
	~Vecteur2D();

	const Vecteur2D operator *(const double &) const;
	const Vecteur2D operator - () const;

	operator string() const;



};

extern const Vecteur2D operator * (const double &, const Vecteur2D &);
extern const Vecteur2D operator +(const Vecteur2D &, const Vecteur2D &);
extern ostream & operator << (ostream &, const Vecteur2D &);

#endif