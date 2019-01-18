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

	/**
	*	\brief Constructeur 
	*	\param suivant : pointeur sur le suivant de la chaine de reponsabilite
	*/
	StringEnFormeCOR(StringEnFormeCOR * suivant):_suivant(suivant){} 

	/**
	*	\brief parse une ligne et renvoi une forme 
	*	\param ligne : ligne a parser 
	*/
	Forme * parse(const string & ligne)const;
	virtual Forme * parse1(const string & ligne) const = 0;


	/**
	*	\brief split un string par rapport a un caractere 
	* 	Split par un string par rapport a un caractere et le stock dans un tableau qu'il retourne
	*	\param ligne : ligne a spliter
	*	\param c : caractere de separation
	*/
	vector<string> split(const string & ligne, const char c)const;
};
#endif