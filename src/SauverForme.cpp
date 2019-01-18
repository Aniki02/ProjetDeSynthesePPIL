#include "SauverForme.hpp"

using namespace std;

void SauverForme::sauver(ofstream & o, const Forme * f){
	o << f << endl;
}
