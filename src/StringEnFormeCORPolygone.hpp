#ifndef _STRINGENFORMECORPOLYGONE_HPP
#define _STRINGENFORMECORPOLYGONE_HPP

#include "StringEnFormeCOR.hpp"
#include <string>
#include "Forme.hpp"

class StringEnFormeCORPolygone : public StringEnFormeCOR{
public:

	StringEnFormeCORPolygone(StringEnFormeCOR * suivant):StringEnFormeCOR(suivant){}
	Forme * parse1(const string & ligne)const;
};
#endif