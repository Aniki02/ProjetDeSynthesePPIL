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
#include "DessinerSFML.hpp"

using namespace std;

int main()
{
/*
	//-----TEST DE LA CLASSE VECTEUR2D ------//
	cout << "-----TEST des vecteurs 2D------- \n";

	Vecteur2D u1(2,3), u2(2,3), v(5), v1(35,-63), u3(3,4), u4(3,-4);

	cout << " u1 = " <<  u1 << endl;
	cout << " u2 = " <<  u2 << endl;
	cout << " u1 + u2 = " <<  u1+u2 << endl;
	cout << " 5.8*u1 = " <<  5.8*u1 << endl;


	//------Test HIERARCHIE DES FORMES------//

	cout << "------TEST HIERARCHIE DES FORME-------" << endl;

	// ---------SEGMENT-----------//
	Vecteur2D x (1, 2), y(10, 14), Atriangle(10, 10), Btriangle(10, 20), Ctriangle(20, 20), centreCercle(40, 40);
	vector<Vecteur2D> pointsTriangle;
	Forme * segment = new Segment(Forme::BLACK, x, y);

	cout << *segment << endl;

	//-------Triangle --------//

	pointsTriangle.push_back(Atriangle);
	pointsTriangle.push_back(Btriangle);
	pointsTriangle.push_back(Ctriangle);

	Polygone * triangle = new Triangle(Forme::BLUE, pointsTriangle);

	cout << *triangle << endl;

	// ------- Cercle ---------//
	Cercle * cercle = new Cercle(Forme::RED, centreCercle, 10.5);
	cout << *cercle << endl;


	//------- Groupe -------//
	Groupe g(Forme::YELLOW);

	g.addForme(segment);
	g.addForme(triangle);
	g.addForme(cercle);
	cout << g << endl;


	//--------------------- TEST DP VISITOR A L'AIDE D'UN MOCK ------------------- //

	VisitorDessinerForme * visiteur = new VisitorMock();
	cout << "--------------- TEST DP VISITOR A L'AIDE D'UN MOCK -------------------" << endl << endl << endl;

	vector<Forme *>::const_iterator it;
	for (it = g.getGroupe().begin(); it != g.getGroupe().end(); it++)
		(*it)->accepteDessin(visiteur);

    //-----------------------TEST DESSINER FORME SFML------------------------------//*/
  Vecteur2D v(10,20), u(50,30), i(40,40),j(6,4);
    /* vector<Vecteur2D> vec;
    Vecteur2D v(1,2), u(5,3), i(4,4),j(6,4);
    Polygone p(1, vec);
    p.addPoint(v);
    p.addPoint(u);
    p.addPoint(i);
    p.addPoint(j); */
    vector<Vecteur2D> vecc;
    vecc.push_back(v);
    vecc.push_back(u);
    vecc.push_back(i);
    vecc.push_back(j);
  //  Triangle t(1, vecc);
  Polygone p(1, vecc);
    Vecteur2D y(6,8);
    Cercle c(1,y,5);
    Segment s(1, v, u);
    VisitorDessinerForme * visiteuse = new DessinerSFML();
    p.accepteDessin(visiteuse);
    c.accepteDessin(visiteuse);
}
