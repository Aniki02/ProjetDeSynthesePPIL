#ifndef _VISITORDESSINERFORME_HPP
#define _VISITORDESSINERFORME_HPP

#include "Segment.hpp"
#include "Cercle.hpp"
#include "Polygone.hpp"
#include "Triangle.hpp"
#include "Groupe.hpp"


class VisitorDessinerForme{
public:
	virtual void visite(const Segment * segment) const = 0;
	virtual void visite(const Cercle * cercle) const = 0;
	virtual void visite(const Polygone * polygone) const = 0;
	virtual void visite(const Triangle * triangle) const = 0;
	virtual void visite(const Groupe * groupe) const = 0;
};

#endif
