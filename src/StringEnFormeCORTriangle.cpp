#include "StringEnFormeCORTriangle.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include "Triangle.hpp"
#include "Vecteur2D.hpp"
#include "Couleur.hpp"



Forme * StringEnFormeCORTriangle::parse1(const string & ligne)const{
	
	regex pattern{"^Triangle-Couleur:\\([0-9]{1,3},[0-9]{1,3},[0-9]{1,3}\\)(-\\([0-9]+,[0-9]+\\)){3}$"};
	if (!regex_match(ligne, pattern))
		return NULL;

	vector<string> ligneSplit = this->split(ligne, '-');

	int a, b, c, n(3);
	vector<Vecteur2D> points;

	sscanf(ligneSplit[1].c_str(), "Couleur:(%d,%d,%d)", &a, &b, &c);
	int i;
	
	for (i = 0; i < n; i++) {
		int abscisse, ordonne;
		sscanf(ligneSplit[i+2].c_str(),"(%d,%d)", &abscisse, &ordonne);
		points.push_back(Vecteur2D (abscisse, ordonne));
	}

	return new Triangle(Couleur(a,b,c),points);	
}