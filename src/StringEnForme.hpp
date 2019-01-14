#ifndef _STRINGENFORME_HPP
#define _STRINGENFORME_HPP
#include <string>
#include "Forme.hpp"

using namespace std;
class StringEnForme{

public: 
	virtual Forme * parse(const string & ligne)const = 0;
};

#endif