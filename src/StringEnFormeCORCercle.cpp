#include "StringEnFormeCORCercle.hpp"
#include <vector>
#include <regex>
#include <iostream>
#include "Cercle.hpp"
#include "Couleur.hpp"

using namespace std;

Forme * StringEnFormeCORCercle::parse1(const string & ligne)const{
	
	regex pattern{"^Cercle-Couleur:\\([0-9]{1,3},[0-9]{1,3},[0-9]{1,3}\\)-Centre\\([0-9]+,[0-9]+\\)-Rayon:[0-9]+\\.?[0-9]+$"};
	if (!regex_match(ligne, pattern))
		return NULL;

	int a, b, c, xCentre, yCentre;
	double rayon;

	vector<string> ligneSplit = this->split(ligne, '-');

	sscanf(ligneSplit[1].c_str(), "Couleur:(%d,%d,%d)", &a, &b, &c);
	sscanf(ligneSplit[2].c_str(),"Centre(%d,%d)", &xCentre, &yCentre);
	sscanf(ligneSplit[3].c_str(), "Rayon:%lf", &rayon);

	Vecteur2D centre(xCentre, yCentre);
	Couleur couleur(a,b,c);

	return new Cercle(couleur, centre, rayon);
}

