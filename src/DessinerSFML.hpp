#ifndef _DESSINERSFML_HPP
#define _DESSINERSFML_HPP
/**
*	\file DessinerSFML.hpp
*	\brief Permet de Dessiner avec la librairie SFML
*/
#include "VisitorDessinerForme.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

/**
*	\class DessinerSFML
*	\brief Dessiner grace a SFML
*/
class DessinerSFML : public VisitorDessinerForme{
	
public:
	sf::RenderWindow window;

	DessinerSFML(const string & nomFenetre, int hauteur, int largeur){
		window.create(sf::VideoMode(hauteur, largeur), nomFenetre);
	}

	//sf::RenderWindow  getWindow() {return window;}
	/**
	*	\brief Dessine un segment
	*	\param segment : le segment a dessiner 
	*/
	void visite(const Segment * segment);

	/**
	*	\brief Dessine un cercle
	*	\param segment : le cercle a dessiner 
	*/
	void visite(const Cercle * cercle);

	/**
	*	\brief Dessine un poylgone
	*	\param segment : le polygone a dessiner 
	*/
	void visite(const Polygone * polygone);

	/**
	*	\brief Dessine un triangle
	*	\param segment : le triangle a dessiner 
	*/
	void visite(const Triangle * triangle);

	/**
	*	\brief Dessine un groupe
	*	\param segment : le groupe a dessiner 
	*/
	void visite(const Groupe * groupe);

	/**
	*	\brief lance l'affichage de la fenetre
	*/
	void run();

};
#endif
