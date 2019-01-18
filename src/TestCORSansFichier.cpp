#include <stdio.h>
#include <iostream>
#include <vector>

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
#include "Couleur.hpp"


using namespace std;

int main()
{
	//------ Test chaine de responsabilite sans fichier -------------//

	cout << "------ Test chaine de responsabilite sans fichier ---------" << endl;


	//Construction de la chaine de responsabilité
	StringEnFormeCOR * sC, *sP, *sT, *sG ,*sS;

	sG = new StringEnFormeCORGroupe(NULL);
	sS = new StringEnFormeCORSegment(sG);
	sP = new StringEnFormeCORPolygone(sS);
	sT = new StringEnFormeCORTriangle(sP);
	sC = new StringEnFormeCORCercle(sT);




	//Construction du tableau de string a envoyer a la chaine de responsabilité
	string s1("Cercle-Couleur:(0,0,0)-Centre(10,10)-Rayon:10"), s2("Segment-Couleur:2-(10,10)-(30,30)"), s3("blablabla"), s4("Polygone-NbPoints:4-Couleur:3-(10,10)-(30,30)-(40,40)-(50,50)");
	string s5("Triangle-Couleur:4-(10,10)-(10,30)-(30,10)"), s6("Groupe-Couleur:(10,10,10)[]");

	vector<string> tab_string;
	vector<string>::const_iterator it;
	Groupe * groupe2 = new Groupe(Couleur(255,255,255));

	tab_string.push_back(s1);
	tab_string.push_back(s2);
	tab_string.push_back(s3);
	tab_string.push_back(s4);
	tab_string.push_back(s5);
	tab_string.push_back(s6);



	for (it = tab_string.begin(); it != tab_string.end(); it++){

		Forme * newForme = sC->parse(*it);
		if (newForme)
			groupe2->addForme(newForme);
	}
	cout << *groupe2 << endl;

	return 0;

}