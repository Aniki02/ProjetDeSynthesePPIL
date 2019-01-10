#include "vecteur.hpp"
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
return u + -v;
}

const Vecteur2D operator *(const double & a, const Vecteur2D & u) { return u*a;}

 //------------ implémentation des fonctions inline ----------------------

Vecteur2D::Vecteur2D(const double & x, const double & y): x(x),y(y){}

const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
return Vecteur2D( x+u.x, y+u.y);
}

const Vecteur2D Vecteur2D::operator * (const double & a) const
{
return Vecteur2D( x*a, y*a);
}

const Vecteur2D Vecteur2D::operator - () const
{
return Vecteur2D(-x,-y);
}

Vecteur2D::operator string() const
{
ostringstream os;
os << "( " << x <<", " << y << ")";
return os.str();
}

ostream & operator << (ostream & os, const Vecteur2D & u)
{
os << (string) u;
return os;
}


