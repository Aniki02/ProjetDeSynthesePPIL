#include "Forme.hpp"
#include <iostream>

using namespace std;

Forme::Forme(int couleur){
	if (couleur < 1 || couleur > 5)
		throw ("La couleur dois etre entre 1 et 5");
	_couleur = couleur;
}

Forme::~Forme(){}

int Forme::getCouleur() const{return _couleur;}

extern ostream & operator << (ostream & os, const Forme & f){
	os << (string) f;
	return os;
}