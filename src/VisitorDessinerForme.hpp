#ifndef _VISITORDESSINERFORME_HPP
#define _VISITORDESSINERFORME_HPP

#include "Segment.hpp"
#include "Cercle.hpp"
#include "Polygone.hpp"
#include "Triangle.hpp"
#include "Groupe.hpp"


class VisitorDessinerForme{
public:
	virtual void visite(const Segment * segment) = 0;
	virtual void visite(const Cercle * cercle) = 0;
	virtual void visite(const Polygone * polygone) = 0;
	virtual void visite(const Triangle * triangle) = 0;
	virtual void visite(const Groupe * groupe) = 0;

};

#endif
