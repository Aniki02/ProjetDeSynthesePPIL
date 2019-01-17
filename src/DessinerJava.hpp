#ifndef _DESSINERJAVA_HPP
#define _DESSINERJAVA_HPP

#include "VisitorDessinerForme.hpp"

class DessinerJava : public VisitorDessinerForme{
	void visite(const Segment * segment) const;
	void visite(const Cercle * cercle) const;
	void visite(const Polygone * polygone) const;
	void visite(const Triangle * triangle) const;
	

};
#endif
