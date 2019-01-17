#ifndef _SAUVERFORME_HPP
#define _SAUVERFORME_HPP
#include <fstream>
#include "Forme.hpp"

using namespace std;

class SauverForme{
public:
	static void sauver(ofstream & o, const Forme * f);
};


#endif