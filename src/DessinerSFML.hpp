#ifndef _DESSINERSFML_HPP
#define _DESSINERSFML_HPP

#include "VisitorDessinerForme.hpp"
#include <vector>


class DessinerSFML : public VisitorDessinerForme{

	void visite(const Segment * segment) const;
	void visite(const Cercle * cercle) const;
	void visite(const Polygone * polygone) const;
	void visite(const Triangle * triangle) const;
	void visite(const Groupe * groupe);

};
#endif
