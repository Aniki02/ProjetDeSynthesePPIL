#include "DessinerSFML.hpp"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Triangle.hpp"
#include "Segment.hpp"
#include "Polygone.hpp"
#include "Cercle.hpp"
#include "Forme.hpp"
#include <vector>
#include "ConstructeurSFML.hpp"

    void ConstructeurSFML::consSFML(const Segment * segment) const{
        sf::Vertex line[] =
    {
    sf::Vertex(sf::Vector2f(segment->getArrive()._x, segment->getArrive()._y)),
    sf::Vertex(sf::Vector2f(segment->getOrigine()._x, segment->getOrigine()._y))
    };
}
	void ConstructeurSFML::consSFML(const Cercle * cercle) const{
	    sf::CircleShape shape(cercle->getRayon());}
	void ConstructeurSFML::consSFML(const Polygone * polygone) const{
	int i=0;
	sf::ConvexShape convex;

    convex.setPointCount(polygone->getPoints().size());
    vector<Vecteur2D>::const_iterator it;
    for (it = polygone->getPoints().begin(); it != polygone->getPoints().end(); it++){
    convex.setPoint(i, sf::Vector2f(it->_x, it->_y));
    i++;
    }
}
	void ConstructeurSFML::consSFML(const Triangle * triangle) const{
	    sf::ConvexShape convex;
    int i=0;
    convex.setPointCount(3);
    for(vector<Vecteur2D>::const_iterator it = triangle->getPoints().begin(); it != triangle->getPoints().end(); it++){
    convex.setPoint(i, sf::Vector2f(it->_x, it->_y));
    i++;
	}
}
   /* void ConstructeurSFML::desSFML(const Segment * segment) const{
        window.draw(line, 2, sf::Lines);
    }
	void ConstructeurSFML::desSFML(const Cercle * cercle) const{
	        window.draw(shape);
}
	void ConstructeurSFML::desSFML(const Polygone * polygone) const{
	    window.draw(convex);

	}
	void ConstructeurSFML::desSFML(const Triangle * triangle) const{
        window.draw(convex);
    }*/
