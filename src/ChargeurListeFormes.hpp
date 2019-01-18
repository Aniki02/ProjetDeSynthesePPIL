#ifndef _CHARGEURLISTEFORME_HPP
#define _CHARGEURLISTEFORME_HPP

/**
 * \file ChargeurListeFormes.hpp
 * \brief Chargeur de fichier 
 * \author zitoun-diallo-sid
 */
#include "StringEnForme.hpp"
#include <vector>
#include <fstream>

using namespace std;

	/** \class ChargeurListesFormes
  	* \brief classe représentant le chargeur de fichier 
   	*/
class ChargeurListeFormes{
public:
	/**
	*	\brief Lis un fichier et transforme chaque ligne en Forme *
	*
	*
	*	donc pour chaque ligne la methode envoi la ligne au parseur qui renvoi un Forme * et l'ajoute au vector .
	*	si Forme * = NULL alors on l'ignore
	*	retourne le vetor a la fin 
	*
	*	\param stringEnForme : la chaine de responsabilité qui tranforme un string en Forme
	*	\param texte : fichier ouvert en lecture 
	*/
	static const vector<Forme *> charge(ifstream & texte, const StringEnForme * stringEnForme);
};

#endif