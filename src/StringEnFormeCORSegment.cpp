#include "StringEnFormeCORSegment.hpp"
#include <vector>
#include <string>
#include "Segment.hpp"


Forme * StringEnFormeCORSegment::parse1(const string & ligne)const{
	
	vector<string> ligneSplit = this->split(ligne);

	if (ligneSplit[0] != "segment")
		return NULL;
	if (ligneSplit.size() != 6)
		return NULL;
	int couleur = atoi(ligneSplit[1].c_str());
	Vecteur2D x(atof(ligneSplit[2].c_str()), atof(ligneSplit[3].c_str()));
	Vecteur2D y(atof(ligneSplit[4].c_str()), atof(ligneSplit[5].c_str()));


	return new Segment(couleur, x, y);
			
}
