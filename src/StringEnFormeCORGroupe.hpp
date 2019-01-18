#ifndef _STRINGENFORMECORGROUPE_HPP
#define _STRINGENFORMECORGROUPE_HPP

#include "StringEnFormeCOR.hpp"
#include "Forme.hpp"
#include <string>

class StringEnFormeCORGroupe : public StringEnFormeCOR{
public:

	StringEnFormeCORGroupe(StringEnFormeCOR * suivant):StringEnFormeCOR(suivant){}
	Forme * parse1(const string & ligne)const;
};
#endif