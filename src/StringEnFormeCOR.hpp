#ifndef _STRINGENFRACTIONCOR_HPP
#define _STRINGENFRACTIONCOR_HPP
/**
*	\file StringEnFormeCOR.hpp
*	\brief Permet de creer une chaine de responsabilité pour parser un string en forme
*/
#include "StringEnForme.hpp"
#include <vector>
#include <string>


/**
*	\class StringEnFormeCOR
*	\brief Permet de creer une chaine de responsabilité pour parser un string en forme
*/
class StringEnFormeCOR : public StringEnForme{
	StringEnFormeCOR * _suivant;
public: 
	StringEnFormeCOR(StringEnFormeCOR * suivant):_suivant(suivant){} 
	Forme * parse(const string & ligne)const;
	virtual Forme * parse1(const string & ligne) const = 0;

	vector<string> split(const string & ligne, const char c)const;
};
#endif