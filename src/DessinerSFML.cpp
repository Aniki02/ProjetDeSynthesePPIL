#include "DessinerSFML.hpp"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Triangle.hpp"
#include "Segment.hpp"
#include "Polygone.hpp"
#include "Cercle.hpp"
#include "Forme.hpp"
#include <vector>








void DessinerSFML::visite(const Segment * segment) const{
	 sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::Vertex line[] =
    {
    sf::Vertex(sf::Vector2f(segment->getArrive()._x, segment->getArrive()._y)),
    sf::Vertex(sf::Vector2f(segment->getOrigine()._x, segment->getOrigine()._y))
    };




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(line, 2, sf::Lines);
        window.display();
    }


}
void DessinerSFML::visite(const Cercle * cercle) const{

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
   sf::CircleShape shape(cercle->getRayon());



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }


}
void DessinerSFML::visite(const Polygone * polygone) const{
	int i=0;
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::ConvexShape convex;

    convex.setPointCount(polygone->getPoints().size());
    vector<Vecteur2D>::const_iterator it;
    for (it = polygone->getPoints().begin(); it != polygone->getPoints().end(); it++){
    convex.setPoint(i, sf::Vector2f(it->_x, it->_y));
    i++;
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(convex);
        window.display();
    }
}
void DessinerSFML::visite(const Triangle * triangle) const{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::ConvexShape convex;
    int i=0;
    convex.setPointCount(3);
    for(vector<Vecteur2D>::const_iterator it = triangle->getPoints().begin(); it != triangle->getPoints().end(); it++){
    convex.setPoint(i, sf::Vector2f(it->_x, it->_y));
    i++;
    }



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(convex);
        window.display();
    }

}


