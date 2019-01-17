#ifndef _CHARGEURLISTEFORME_HPP
#define _CHARGEURLISTEFORME_HPP

#include "StringEnForme.hpp"
#include <vector>
#include <fstream>

using namespace std;
class ChargeurListeFormes{
public:
	/*
	Lis un fichier et transforme chaque ligne en Forme *
	le fichier est de la forme suivante : type, attribut1, attribut2, etc..

	donc pour chaque ligne la methode envoi la ligne au parseur qui renvoi un Forme * et l'ajoute au vector .
	si Forme * = NULL alors on l'ignore
	retourne le vetor a la fin 
	*/
	static const vector<Forme *> charge(ifstream & texte, const StringEnForme * stringEnForme);
};

#endif