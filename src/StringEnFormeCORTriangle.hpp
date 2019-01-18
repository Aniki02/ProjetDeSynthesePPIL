#ifndef _STRINGENFORMECORTRIANGLE_HPP
#define _STRINGENFORMECORTRIANGLE_HPP
/**
*	\file StringEnFormeCORTriangle.hpp
*	\brief Permet de parser un string en Triangle
*/
#include "StringEnFormeCOR.hpp"
#include <string>
#include "Forme.hpp"

/**
*	\class StringEnFormeCORTriangle
*	\brief Permet de parser un string en Triangle
*/
class StringEnFormeCORTriangle : public StringEnFormeCOR{
public:

	/**
	*	\brief Constructeur
	*	\param suivant : maillon suivant de la chaine de responsabilite
	*/
	StringEnFormeCORTriangle(StringEnFormeCOR * suivant):StringEnFormeCOR(suivant){}

	/**
	*	\brief : parse une ligne en Triangle
	*	\param ligne : ligne a parser 
	*/
	Forme * parse1(const string & ligne)const;
};
#endif