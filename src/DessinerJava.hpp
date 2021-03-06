#ifndef _DESSINERJAVA_HPP
#define _DESSINERJAVA_HPP
/**
*	\file DessinerJava.hpp
*	\brief Permet de dessiner a l'aide d'une librairie JAVA
*/
#include "VisitorDessinerForme.hpp"
#include "ClientDessin.hpp"

/**
*	\class DessinerJava
*	\brief Dessiner sur un serveur JAVA
*/
class DessinerJava : public VisitorDessinerForme{

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

};
#endif
