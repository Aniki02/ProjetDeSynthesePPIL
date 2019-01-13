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
#include "StringEnFormeCOR.hpp"
#include "StringEnFormeCORCercle.hpp"
#include "StringEnFormeCORSegment.hpp"
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
	


	//------ Test chaine de responsabilite sans fichier -------------//

	cout << "------ Test chaine de responsabilite sans fichier ---------" << endl;

	
	//Construction de la chaine de responsabilité 
	StringEnFormeCOR * sC, *sS; 

	sS = new StringEnFormeCORSegment(NULL);
	sC = new StringEnFormeCORCercle(sS);
	
	


	//Construction du tableau de string a envoyer a la chaine de responsabilité
	string s1("cercle,1,100,100,4.5"), s2("segment,2,10,10,30,30"), s3("blablabla");

	vector<string> tab_string;
	vector<string>::const_iterator it;

	//vector<Forme *> tab_forme;
	//vector<Forme *>::const_iterator it2;
	Groupe * groupe2 = new Groupe(Forme::RED);

	tab_string.push_back(s1);
	tab_string.push_back(s2);
	tab_string.push_back(s3);
	
	
	/*Forme * seg = sC->parse(s2);
	Forme * cerc = sC->parse(s1);
	Forme * nimpe = sC->parse(s3);*/

	for (it = tab_string.begin(); it != tab_string.end(); it++){

		Forme * newForme = sC->parse(*it);
		if (newForme)
			groupe2->addForme(newForme);
	}
	cout << *groupe2 << endl;

	//for (it2 = tab_forme.begin(); it2 != tab_forme.end(); it2++)
	//	cout << **it2 << endl;

	/*if(cerc == NULL)
		cout << "cerc est null" << endl;
	else 
		cout << *cerc << endl;

	if(seg == NULL)
		cout << "seg est null" << endl;
	else 
		cout << *seg << endl;

	if(nimpe == NULL)
		cout << s3 << " : Format inadapté " << endl;
	else 
		cout << *nimpe << endl;*/



	

	



	

	return 0;

}