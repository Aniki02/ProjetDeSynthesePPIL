#include "StringEnFormeCOR.hpp"
#include <sstream>

using namespace std;

Forme * StringEnFormeCOR::parse(const string & ligne)const{
	Forme * res;
	res = this->parse1(ligne);

	if(res)
		return res;
	else
		if(this->_suivant)
			return this->_suivant->parse(ligne);
		else
			return NULL;
}

vector<string> StringEnFormeCOR::split(const string & ligne, const char c)const{
	vector<string> ligneSplit; 
	stringstream ss(ligne);
	string sousChaine;

	while (getline(ss, sousChaine, c))
		ligneSplit.push_back(sousChaine);

	return ligneSplit;
}