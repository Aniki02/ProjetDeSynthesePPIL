#ifndef _VISITORMOCK_HPP
#define _VISITORMOCK_HPP

#include "VisitorDessinerForme.hpp"

class VisitorMock : public VisitorDessinerForme{
	void visite(const Segment * segment) const;
	void visite(const Cercle * cercle) const;
	void visite(const Polygone * polygone) const;
	void visite(const Triangle * triangle) const;
	void visite(const Groupe * groupe);

};
#endif
