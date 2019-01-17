#include "ChargeurListeFormes.hpp"
#include "Forme.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>

using namespace std;

const vector<Forme *> ChargeurListeFormes::charge(ifstream & texte, const StringEnForme * stringEnForme){
	vector<Forme *> resultat;

	if (!texte) return resultat;	// retourne une liste vide car le fichier n'est pas ouvert
	
	ifstream monFichier ("test.txt", ios::in);
	string ligne;
	
	while(getline(texte, ligne)){

	Forme * forme = stringEnForme->parse(ligne);
	if (forme) resultat.push_back(forme);
	}
	return resultat;
	
}

