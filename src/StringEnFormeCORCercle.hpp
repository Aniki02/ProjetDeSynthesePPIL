#ifndef _STRINGENFORMECORCERCLE_HPP
#define _STRINGENFORMECORCERCLE_HPP

#include "StringEnFormeCOR.hpp"
#include "Forme.hpp"
#include <string>

class StringEnFormeCORCercle : public StringEnFormeCOR{
public:

	StringEnFormeCORCercle(StringEnFormeCOR * suivant):StringEnFormeCOR(suivant){}
	Forme * parse1(const string & ligne)const;
};
#endif