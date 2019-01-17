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
#include "Couleur.hpp"


using namespace std;

int main()
{



	//------Test HIERARCHIE DES FORMES------//

	cout << "------TEST HIERARCHIE DES FORME-------" << endl;

	// ---------SEGMENT-----------//
	Vecteur2D x (1, 2), y(10, 14), Atriangle(10, 10), Btriangle(10, 20), Ctriangle(20, 20), centreCercle(40, 40);
	vector<Vecteur2D> pointsTriangle;
	Forme * segment = new Segment(Couleur(255,255,255), x, y);

	cout << *segment << endl;

	//-------Triangle --------//

	pointsTriangle.push_back(Atriangle);
	pointsTriangle.push_back(Btriangle);
	pointsTriangle.push_back(Ctriangle);

	Polygone * triangle = new Triangle(Couleur(100,100,100), pointsTriangle);

	cout << *triangle << endl;

	// ------- Cercle ---------//
	Cercle * cercle = new Cercle(Couleur(200,200,200), centreCercle, 10.5);
	cout << *cercle << endl;


	//------- Groupe -------//
	Groupe * g = new Groupe(Couleur(0,100,80));

	g->addForme(segment);
	g->addForme(triangle);
	g->addForme(cercle);
	cout << g << endl;

	return 0;

}

