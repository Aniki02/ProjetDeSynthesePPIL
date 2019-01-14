#ifndef _STRINGENFORMECORSEGMENT_HPP
#define _STRINGENFORMECORSEGMENT_HPP

#include "StringEnFormeCOR.hpp"
#include "Forme.hpp"

#include <string>

class StringEnFormeCORSegment : public StringEnFormeCOR{
public:

	StringEnFormeCORSegment(StringEnFormeCOR * suivant):StringEnFormeCOR(suivant){}
	Forme * parse1(const string & ligne)const;
};
#endif