#ifndef Vecteur2D_hpp
#define Vecteur2D_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Vecteur2D
{
public:
double x,y;

Vecteur2D(const double & x = 0, const double & y = 0);

Vecteur2D(const char * s);
const Vecteur2D operator + (const Vecteur2D & u) const;
const Vecteur2D operator * (const double & a) const;
const Vecteur2D operator - () const;

operator string() const;
};

extern ostream & operator << (ostream &,const Vecteur2D &);

#endif
