#ifndef _STRINGENFORMECORTRIANGLE_HPP
#define _STRINGENFORMECORTRIANGLE_HPP

#include "StringEnFormeCOR.hpp"
#include <string>
#include "Forme.hpp"

class StringEnFormeCORTriangle : public StringEnFormeCOR{
public:

	StringEnFormeCORTriangle(StringEnFormeCOR * suivant):StringEnFormeCOR(suivant){}
	Forme * parse1(const string & ligne)const;
};
#endif