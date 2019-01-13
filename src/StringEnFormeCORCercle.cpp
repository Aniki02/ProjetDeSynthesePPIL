#include "StringEnFormeCORCercle.hpp"
#include <vector>
#include "Cercle.hpp"

using namespace std;

Forme * StringEnFormeCORCercle::parse1(const string & ligne)const{
	
	vector<string> ligneSplit = this->split(ligne);

	if (ligneSplit[0] != "cercle")
		return NULL;
	if (ligneSplit.size() != 5)
		return NULL;
	int couleur = atoi(ligneSplit[1].c_str());
	Vecteur2D centre(atof(ligneSplit[2].c_str()), atof(ligneSplit[3].c_str()));
	double diametre (atof(ligneSplit[4].c_str()));

	return new Cercle(couleur, centre, diametre); 
			
}

