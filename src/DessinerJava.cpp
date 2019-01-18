#include <stdio.h>
#include "DessinerJava.hpp"


void DessinerJava::visite(const Segment * segment) {
	//TODO
	ClientDessin::getClient()->dessineSegment("drawLine",segment->getCouleur(),
												 segment->getOrigine(), 
												segment->getArrive());
}
void DessinerJava::visite(const Cercle * cercle){
	//TODO
	ClientDessin::getClient()->dessineCercle("drawOval", cercle->getCouleur(),
											 cercle->getCentre(), 
											 cercle->getRayon());
}
void DessinerJava::visite(const Polygone * polygone){
	//TODO
	ClientDessin::getClient()->dessinePolygone("drawPolygon", 
												polygone->getCouleur(), 
												polygone->getPoints());
}
void DessinerJava::visite(const Triangle * triangle){
	//TODO
	ClientDessin::getClient()->dessinePolygone("drawPolygon", 
												triangle->getCouleur(),
												 triangle->getPoints());
}
void DessinerJava::visite(const Groupe * groupe) {
	//TODO
	VisitorDessinerForme *G = new DessinerJava();
	cout<<"visite groupe"<<endl;
	//vector <Forme *>::const_iterator it;
	for(int i=0; i<groupe->getGroupe().size(); i++){
		cout << "dessin de la forme :" << groupe->getGroupe()[i] << endl;
        groupe->getGroupe()[i]->accepteDessin(G);
	}
}
