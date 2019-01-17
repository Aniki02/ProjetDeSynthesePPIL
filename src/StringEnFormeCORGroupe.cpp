#include "StringEnFormeCORGroupe.hpp"
#include "StringEnFormeCORSegment.hpp"
#include "StringEnFormeCORPolygone.hpp"
#include "StringEnFormeCORTriangle.hpp"
#include "StringEnFormeCORCercle.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include "Groupe.hpp"
#include "Vecteur2D.hpp"
#include "Couleur.hpp"



Forme * StringEnFormeCORGroupe::parse1(const string & ligne)const{
	
	regex pattern{"^Groupe-Couleur:[0-9]+\\[.*\\]$"};
	if (!regex_match(ligne, pattern)){
		return NULL;
	}
	int firstPos = ligne.find_first_of("[");
	int lastPos = ligne.find_last_of("]");

	string ligneATraiter = ligne.substr(firstPos + 1, lastPos - firstPos - 1);

	StringEnFormeCOR * sC, *sP, *sT, *sG, *sS;

	sG = new StringEnFormeCORGroupe(NULL);
	sS = new StringEnFormeCORSegment(sG);
	sP = new StringEnFormeCORPolygone(sS);
	sT = new StringEnFormeCORTriangle(sP);
	sC = new StringEnFormeCORCercle(sT);

	Groupe * g = new Groupe(Couleur(0,0,0));
	vector<string> ligneSplit = this->split(ligneATraiter, '|');
	vector<string>::const_iterator it;
	for (it = ligneSplit.begin(); it != ligneSplit.end(); it++){
		if (!it->empty()){
			Forme * newForme = sC->parse(*it);
			if (newForme)
				g->addForme(newForme);
		}
		
	}
	return g;
}