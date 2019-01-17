#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>

#include "Vecteur2D.hpp"
#include "Forme.hpp"
#include "Groupe.hpp"
#include "Polygone.hpp"
#include "Triangle.hpp"
#include "Segment.hpp"
#include "Cercle.hpp"
#include "StringEnFormeCOR.hpp"
#include "StringEnFormeCORCercle.hpp"
#include "StringEnFormeCORSegment.hpp"
#include "StringEnFormeCORPolygone.hpp"
#include "StringEnFormeCORTriangle.hpp"
#include "StringEnFormeCORGroupe.hpp"
#include "StringEnForme.hpp"
#include "ChargeurListeFormes.hpp"


using namespace std;

int main()
{
	//------ Test chaine de responsabilite Avec fichier -------------//

	cout << "------ Test chaine de responsabilite Avec fichier ---------" << endl;



	ifstream monFichier("test.txt", ios::in);
	if (monFichier){

		//Construction de la chaine de responsabilité
		StringEnFormeCOR * sC, *sP, *sT, *sG ,*sS;

		sG = new StringEnFormeCORGroupe(NULL);
		sS = new StringEnFormeCORSegment(sG);
		sP = new StringEnFormeCORPolygone(sS);
		sT = new StringEnFormeCORTriangle(sP);
		sC = new StringEnFormeCORCercle(sT);

		vector<Forme *> formes = ChargeurListeFormes::charge(monFichier, sC);
		monFichier.close();

		vector<Forme *>::const_iterator it;
		for (it = formes.begin(); it != formes.end(); it++)
			cout << *it << endl;

	}
	else 
		cerr << "Erreur lors de l'ouverture du fichier" << endl;

	return 0;

}

