#ifndef _STRINGENFRACTIONCOR_HPP
#define _STRINGENFRACTIONCOR_HPP
#include "StringEnForme.hpp"
#include <vector>
#include <string>


class StringEnFormeCOR : public StringEnForme{
	StringEnFormeCOR * _suivant;
public: 
	StringEnFormeCOR(StringEnFormeCOR * suivant):_suivant(suivant){} 
	Forme * parse(const string & ligne)const;
	virtual Forme * parse1(const string & ligne) const = 0;

	vector<string> split(const string & ligne)const;
};
#endif