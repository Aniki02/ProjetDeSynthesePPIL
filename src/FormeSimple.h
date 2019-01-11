#ifndef FormeSimple_hpp
#define FormeSimple_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Vecteur2D;


class FormeSimple extend Forme{

    Vecteur2D _origine;
public :
    Forme(Vecteur2D v, int c);

    Forme(double x, double y, int c);

    Vecteur2D getOrigine() const;

    void setOrigine(Vecteur2D v);

};
