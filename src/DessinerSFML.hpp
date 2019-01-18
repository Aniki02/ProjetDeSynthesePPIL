#ifndef _DESSINERSFML_HPP
#define _DESSINERSFML_HPP
/**
*	\file DessinerSFML.hpp
*	\brief Permet de Dessiner avec la librairie SFML
*/
#include "VisitorDessinerForme.hpp"
#include <vector>

/**
*	\class DessinerSFML
*	\brief Dessiner grace a SFML
*/
class DessinerSFML : public VisitorDessinerForme{

	/**
	*	\brief Dessine un segment
	*	\param segment : le segment a dessiner 
	*/
	void visite(const Segment * segment) const;

	/**
	*	\brief Dessine un cercle
	*	\param segment : le cercle a dessiner 
	*/
	void visite(const Cercle * cercle) const;

	/**
	*	\brief Dessine un poylgone
	*	\param segment : le polygone a dessiner 
	*/
	void visite(const Polygone * polygone) const;

	/**
	*	\brief Dessine un triangle
	*	\param segment : le triangle a dessiner 
	*/
	void visite(const Triangle * triangle) const;

	/**
	*	\brief Dessine un groupe
	*	\param segment : le groupe a dessiner 
	*/
	void visite(const Groupe * groupe);

};
#endif
