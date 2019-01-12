#include <stdio.h>
#include "VisitorMock.hpp"
#include <iostream>


void VisitorMock::visite(const Segment * segment) const{
	cout << "VisitorMock : Dessin d'un segment" << endl;
	cout << *segment << endl;
}
void VisitorMock::visite(const Cercle * cercle) const{
	cout << "VisitorMock : Dessin d'un cercle" << endl;
	cout << *cercle << endl;
}
void VisitorMock::visite(const Polygone * polygone) const{
	cout << "VisitorMock : Dessin d'un polygone" << endl;
	cout << *polygone << endl;
}
void VisitorMock::visite(const Triangle * triangle) const{
	cout << "VisitorMock : Dessin d'un triangle" << endl;
	cout << *triangle << endl;
}
void VisitorMock::visite(const Groupe * groupe) const{
	cout << "VisitorMock : Dessin d'un groupe" << endl;
	cout << *groupe << endl;
}