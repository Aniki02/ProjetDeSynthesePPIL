#ifndef _STRINGENFORMECORGROUPE_HPP
#define _STRINGENFORMECORGROUPE_HPP
/**
*	\file StringEnFormeCORGroupe.hpp
*	\brief Permet de parser un string en groupe
*/

#include "StringEnFormeCOR.hpp"
#include "Forme.hpp"
#include <string>

/**
*	\class StringEnFormeCORGroupe
*	\brief Permet de parser un string en Groupe
*/
class StringEnFormeCORGroupe : public StringEnFormeCOR{
public:

	/**
	*	\brief Constructeur
	*	\param suivant : maillon suivant de la chaine de responsabilite 
	*/
	StringEnFormeCORGroupe(StringEnFormeCOR * suivant):StringEnFormeCOR(suivant){}

	/**
	*	\brief : parse une ligne en Groupe
	*	\param ligne : ligne a parser 
	*/
	Forme * parse1(const string & ligne)const;
};
#endif