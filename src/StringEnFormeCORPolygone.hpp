#ifndef _STRINGENFORMECORPOLYGONE_HPP
#define _STRINGENFORMECORPOLYGONE_HPP
/**
*	\file StringEnFormeCORPolygone.hpp
*	\brief Permet de parser un string en polygone 
*/
#include "StringEnFormeCOR.hpp"
#include <string>
#include "Forme.hpp"

/**
*	\class StringEnFormeCORPolygone
*	\brief Permet de parser un string en Polygone
*/
class StringEnFormeCORPolygone : public StringEnFormeCOR{
public:

	/**
	*	\brief Constructeur
	*	\param suivant : maillon suivant de la chaine de responsabilite 
	*/
	StringEnFormeCORPolygone(StringEnFormeCOR * suivant):StringEnFormeCOR(suivant){}

	/**
	*	\brief : parse une ligne en Polygone
	*	\param ligne : ligne a parser 
	*/
	Forme * parse1(const string & ligne)const;
};
#endif