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
#include "VisitorMock.hpp"



using namespace std;

int main()
{

	//--------------------- TEST DP VISITOR A L'AIDE D'UN MOCK ------------------- //

	Forme * triangle = new Triangle (Forme::BLUE, {Vecteur2D(10,10), Vecteur2D(100, 50), Vecteur2D(20, 50)});
	Forme * cercle = new Cercle (Forme::RED, Vecteur2D(150,150), 10.5);
	Forme * segment = new Segment(Forme::BLACK, Vecteur2D(300, 300), Vecteur2D(400, 400));
	VisitorDessinerForme * visiteur = new VisitorMock();
	cout << endl<< endl << "--------------- TEST DP VISITOR A L'AIDE D'UN MOCK -------------------" << endl << endl << endl;

	cout << "[+] Appel VisiteurMock pour triangle" << endl;
	triangle->accepteDessin(visiteur);
	cout << endl << "[+] Appel VisiteurMock pour cercle" << endl;
	cercle->accepteDessin(visiteur);
	cout << endl << "[+] Appel VisiteurMock pour segment" << endl;
	segment->accepteDessin(visiteur);

	return 0;

}
