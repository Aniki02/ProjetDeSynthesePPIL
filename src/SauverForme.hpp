#ifndef _SAUVERFORME_HPP
#define _SAUVERFORME_HPP

/**
*	\file SauverForme.hpp
*	\brief Permet de sauvegarder une forme sur un fichier
*/
#include <fstream>
#include "Forme.hpp"

using namespace std;

/**
*	\class SauverForme
*	\brief Permet de sauvegarder une forme sur un fichier
*/
class SauverForme{
public:
	
	/**
	*	\brief	sauve une forme sur un fichier ouvert en ecriture
	*	\param o : le flux du fichier ouvert en ecriture
	*	\param f : la forme a sauvegarder 
	*/
	static void sauver(ofstream & o, const Forme * f);
};


#endif