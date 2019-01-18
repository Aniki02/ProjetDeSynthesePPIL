#ifndef _STRINGENFORME_HPP
#define _STRINGENFORME_HPP
/**
*	\file StringEnForme.hpp
*	\brief change un string en Forme
*/
#include <string>
#include "Forme.hpp"

using namespace std;

/**
*	\class StringEnForme
*	\brief Permet de changer un string en Forme
*/
class StringEnForme{

public: 

	/**
	*	\brief return un Forme * construit a l'aide d'un string
	*	\param ligne : ligne a partir de laquelle on construit la forme
	*/
	virtual Forme * parse(const string & ligne)const = 0;
};

#endif