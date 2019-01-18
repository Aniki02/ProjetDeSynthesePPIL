#ifndef _VISITORMOCK_HPP
#define _VISITORMOCK_HPP

#include "VisitorDessinerForme.hpp"

class VisitorMock : public VisitorDessinerForme{
	void visite(const Segment * segment);
	void visite(const Cercle * cercle);
	void visite(const Polygone * polygone);
	void visite(const Triangle * triangle);
	void visite(const Groupe * groupe);

};
#endif
