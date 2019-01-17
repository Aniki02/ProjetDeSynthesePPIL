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
#include "StringEnFormeCOR.hpp"
#include "StringEnFormeCORCercle.hpp"
#include "StringEnFormeCORSegment.hpp"
#include "StringEnFormeCORPolygone.hpp"
#include "StringEnFormeCORTriangle.hpp"
#include "StringEnFormeCORGroupe.hpp"
#include "StringEnForme.hpp"


using namespace std;

int main()
{

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
	cercle->accepteDessin(visiteur);

	triangle->accepteDessin(visiteur);
	segment->accepteDessin(visiteur);
	g.accepteDessin(visiteur);



    //-----------------------TEST DESSINER FORME SFML------------------------------//*/
 	cout << "-----------------------TEST DESSINER FORME SFML------------------------------"<< endl;
 	Vecteur2D v2(10,20), u10(50,30), i2(40,40),j2(6,4);
    
    vector<Vecteur2D> vecc;
    vecc.push_back(v2);
    vecc.push_back(u10);
    vecc.push_back(i2);
    vecc.push_back(j2);
  	Polygone p(1, vecc);
    Vecteur2D y2(6,8);
    Cercle c(1,y2,150);
    Segment s(1, v2, u10);

    cout << p <<endl;
    VisitorDessinerForme * visiteuse = new DessinerSFML();
    p.accepteDessin(visiteuse);
    c.accepteDessin(visiteuse);



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
	string s1("Cercle-Couleur:1-Centre(10,10)-Rayon:10"), s2("Segment-Couleur:2-(10,10)-(30,30)"), s3("blablabla"), s4("Polygone-NbPoints:4-Couleur:3-(10,10)-(30,30)-(40,40)-(50,50)");
	string s5("Triangle-Couleur:4-(10,10)-(10,30)-(30,10)"), s6("Groupe-Couleur:3[Triangle-Couleur:4-(10,10)-(10,30)-(30,10)|Segment-Couleur:2-(10,10)-(30,30)|Cercle-Couleur:1-Centre(10,10)-Rayon:10|]");

	vector<string> tab_string;
	vector<string>::const_iterator it;
	Groupe * groupe2 = new Groupe(Forme::RED);

	//tab_string.push_back(s1);
	//tab_string.push_back(s2);
	//tab_string.push_back(s3);
	//tab_string.push_back(s4);
	//tab_string.push_back(s5);
	tab_string.push_back(s6);



	for (it = tab_string.begin(); it != tab_string.end(); it++){

		Forme * newForme = sC->parse(*it);
		if (newForme)
			groupe2->addForme(newForme);
	}
	cout << *groupe2 << endl;

	return 0;

}

