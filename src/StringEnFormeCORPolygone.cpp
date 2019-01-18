#include "StringEnFormeCORPolygone.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include "Polygone.hpp"
#include "Vecteur2D.hpp"
#include "Couleur.hpp"



Forme * StringEnFormeCORPolygone::parse1(const string & ligne)const{
	
	regex pattern{"^Polygone-NbPoints:[0-9]+-Couleur:\\([0-9]{1,3},[0-9]{1,3},[0-9]{1,3}\\)(-\\([0-9]+,[0-9]+\\)){3,}$"};
	if (!regex_match(ligne, pattern)){
		return NULL;
	}

	vector<string> ligneSplit = this->split(ligne, '-');

	int a, b, c, n;
	vector<Vecteur2D> points;

	sscanf(ligneSplit[1].c_str(), "NbPoints:%d", &n);
	sscanf(ligneSplit[2].c_str(), "Couleur:(%d,%d,%d)", &a, &b, &c);
	int i = 0;
	while(i < n){
		int abscisse, ordonne;
		sscanf(ligneSplit[i+3].c_str(),"(%d,%d)", &abscisse, &ordonne);
		points.push_back(Vecteur2D (abscisse, ordonne));
		i++;
	}

	return new Polygone(Couleur(a,b,c),points);
			
}
