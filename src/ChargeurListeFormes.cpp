#include "ChargeurListeFormes.hpp"
#include "Forme.hpp"
#include <fstream>
#include <vector>

using namespace std;

const vector<Forme *> ChargeurListeFormes::charge(ifstream texte, const StringEnForme * stringEnForme){
	vector<Forme *> resultat;

	if (!texte) return resultat;	// retourne une liste vide car le fichier n'est pas ouvert

	string ligne;

	while(getline(texte, ligne)){

		Forme * forme = stringEnForme->parse(ligne);
		if (forme) resultat.push_back(forme);
	}
	return resultat;	
}

