#ifndef _STRINGENFORMECORCERCLE_HPP
#define _STRINGENFORMECORCERCLE_HPP
/**
*	\file StringEnFormeCORCercle.hpp
*	\brief Permet de parser un string en Cercle 
*/
#include "StringEnFormeCOR.hpp"
#include "Forme.hpp"
#include <string>

/**
*	\class StringEnFormeCORCercle
*	\brief Permet de parser un string en Cercle
*/
class StringEnFormeCORCercle : public StringEnFormeCOR{
public:

	/**
	*	\brief Constructeur
	*	\param suivant : maillon suivant de la chaine de responsabilite 
	*/
	StringEnFormeCORCercle(StringEnFormeCOR * suivant):StringEnFormeCOR(suivant){}

	/**
	*	\brief : parse une ligne en Cercle
	*	\param ligne : ligne a parser 
	*/
	Forme * parse1(const string & ligne)const;
};
#endif