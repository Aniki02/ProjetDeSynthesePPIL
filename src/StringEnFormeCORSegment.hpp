#ifndef _STRINGENFORMECORSEGMENT_HPP
#define _STRINGENFORMECORSEGMENT_HPP
/**
*	\file StringEnFormeCORSegment.hpp
*	\brief Permet de parser un string en Segment
*/
#include "StringEnFormeCOR.hpp"
#include "Forme.hpp"

#include <string>

/**
*	\class StringEnFormeCORSegment
*	\brief Permet de parser un string en Segment
*/
class StringEnFormeCORSegment : public StringEnFormeCOR{
public:

	/**
	*	\brief Constructeur
	*	\param suivant : maillon suivant de la chaine de responsabilite 
	*/
	StringEnFormeCORSegment(StringEnFormeCOR * suivant):StringEnFormeCOR(suivant){}

	/**
	*	\brief : parse une ligne en Segment
	*	\param ligne : ligne a parser 
	*/
	Forme * parse1(const string & ligne)const;
};
#endif