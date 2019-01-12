#include "Forme.hpp"
#include <iostream>
#include <string>

using namespace std;

Forme::Forme(int c){
	this->setCouleur(c);
}

Forme::~Forme(){}

const string Forme::getCouleur() const{
	switch (_couleur) {
		case 1 : return "Black";
			break;
		case 2 : return "Blue";
			break;
		case 3 : return "Red";
			break;
		case 4 : return "Green";
			break;
		case 5 : return "Yellow";
			break;
		case 6 : return "Cyan";
			break;
		default : return "Couleur Inconnu";
			break;
	}
}

void Forme::setCouleur(int c){
	if (c < 1 || c > 5)
		throw ("La couleur dois etre entre 1 et 5");
	_couleur = c;
}

extern ostream & operator << (ostream & os, const Forme & f){
	os << (string) f;
	return os;
}