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
#include "Couleur.hpp"
#include "DessinerJava.hpp"
#include "ClientDessin.hpp"

using namespace std;

int main()
{
    /*const ClientDessin * client =  ClientDessin::getClient();

    client->envoiRequete("drawLine, diallo, 20, 30");
    client->envoiRequete("sid, diallo, 20, 30");
    client->envoiRequete("zitoun, diallo, 20, 30");*/
	//--------------------- TEST DP VISITOR A L'AIDE D'UN MOCK ------------------- //

	//--------------------- TEST DP VISITOR A L'AIDE D'UN MOCK ------------------- //
    ClientDessin::getClient()->ouvertureFenetre("Ouverture c++", 50, 50, 400, 300);
	Forme * triangle = new Triangle (Couleur(0,0,255), {Vecteur2D(50,70), Vecteur2D(100, 50), Vecteur2D(100, 50)});
	Forme * cercle = new Cercle (Couleur(0,255, 0), Vecteur2D(150,150), 50.10);
	Forme * segment = new Segment(Couleur(255, 0, 0), Vecteur2D(100, 100), Vecteur2D(100, 100));
	//DessinerJava * visiteur = new DessinerJava();
	cout << endl<< endl << "--------------- TEST DP VISITOR A L'AIDE D'UN MOCK -------------------" << endl << endl << endl;

    /*
        un groupe de forme
    */
   DessinerJava * visiteur = new DessinerJava();

    Forme * triangles = new Triangle (Couleur(50,10,203), {Vecteur2D(50,80), Vecteur2D(100, 50), Vecteur2D(100, 50)});
	Forme * cercles = new Cercle (Couleur(120,255, 70), Vecteur2D(150,150), 10.5);
	Forme * segments = new Segment(Couleur(80, 100, 70), Vecteur2D(80, 80), Vecteur2D(120, 120));
   
    Groupe *groupe =new Groupe(Couleur(20,30, 50));
    groupe->addForme(triangles);
    groupe->addForme(cercles);
    groupe->addForme(segments);
     cout<<endl<<"les infos sur les formes du groupe :"<<endl;
    groupe->accepteDessin(visiteur);
    
    cout<<"----------------------------------------------------"<<endl;
	cout << "[+] Appel VisiteurDessineJava pour triangle" << endl;
	triangle->accepteDessin(visiteur);
    cout << endl << "[+] Appel VisiteurDessineJava pour segment" << endl;
	segment->accepteDessin(visiteur);
    cout << endl << "[+] Appel VisiteurDessineJava pour cercle" << endl;
	cercle->accepteDessin(visiteur);

   
    
    
	
	

	return 0;

}
