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
    sf::Vertex(sf::Vector2f(segment->getArrive()._x, segment->getArrive()._y),sf::Color((segment->getCouleur()).getCouleur1(),
                                                                                        (segment->getCouleur()).getCouleur2(),
                                                                                        (segment->getCouleur()).getCouleur3())),
    sf::Vertex(sf::Vector2f(segment->getOrigine()._x, segment->getOrigine()._y),sf::Color((segment->getCouleur()).getCouleur1(),
                                                                                      (segment->getCouleur()).getCouleur2(),
                                                                                        (segment->getCouleur()).getCouleur3()))
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
    cout << "entre dans visite cercle" << endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(cercle->getRayon());
    shape.setPosition(cercle->getCentre()._x,cercle->getCentre()._y);
    shape.setFillColor(sf::Color((cercle->getCouleur()).getCouleur1(), (cercle->getCouleur()).getCouleur2(), (cercle->getCouleur()).getCouleur3()));




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
       convex.setFillColor(sf::Color((polygone->getCouleur()).getCouleur1(), (polygone->getCouleur()).getCouleur2(), (polygone->getCouleur()).getCouleur3()));



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
    convex.setFillColor(sf::Color((triangle->getCouleur()).getCouleur1(), (triangle->getCouleur()).getCouleur2(), (triangle->getCouleur()).getCouleur3()));



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
void DessinerSFML::visite(const Groupe * groupe){

    VisitorDessinerForme * visiteuse = new DessinerSFML();
    // for (vector<Forme *>::const_iterator it = groupe->getGroupe().begin(); it != groupe->getGroupe().end(); it++){
    //     cout << " dessin de la forme : " << *it << endl;
    //     (*it)->accepteDessin(visiteuse);
    // }

    for (int i = 0; i < groupe->getGroupe().size(); i++){
        cout << "dessin de la forme :" << groupe->getGroupe()[i] << endl;
        groupe->getGroupe()[i]->accepteDessin(visiteuse);

    }

}












































/*void DessinerSFML::visite(const Segment * segment) const{
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
*/

