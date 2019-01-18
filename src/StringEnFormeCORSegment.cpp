#include "StringEnFormeCORSegment.hpp"
#include <vector>
#include <string>
#include <regex>
#include "Segment.hpp"
#include "Couleur.hpp"


Forme * StringEnFormeCORSegment::parse1(const string & ligne)const{
	
	regex pattern{"^Segment-Couleur:\\([0-9]{1,3},[0-9]{1,3},[0-9]{1,3}\\)-\\([0-9]+,[0-9]+\\)-\\([0-9]+,[0-9]+\\)+$"};
	if (!regex_match(ligne, pattern))
		return NULL;

	vector<string> ligneSplit = this->split(ligne, '-');
	int a, b, c, xAbcisse, xOrdonne, yAbscisse, yOrdonne;

	sscanf(ligneSplit[1].c_str(), "Couleur:(%d,%d,%d)", &a, &b, &c);
	sscanf(ligneSplit[2].c_str(),"(%d,%d)", &xAbcisse, &xOrdonne);
	sscanf(ligneSplit[3].c_str(), "(%d,%d)", &yAbscisse, &yOrdonne);

	Vecteur2D x (xAbcisse, xOrdonne);
	Vecteur2D y (yAbscisse, yOrdonne);


	return new Segment(Couleur(a,b,c), x, y);
			
}
