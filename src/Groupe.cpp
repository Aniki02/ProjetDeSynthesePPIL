#include "Groupe.hpp"
#include <sstream>
#include <vector>



Groupe::Groupe(const Groupe & g): Forme(g.getCouleur()){
	vector<Forme *>::const_iterator it;
	for(it = g.getGroupe().begin(); it != g.getGroupe().end(); it++)
		_groupe.push_back((*it)->clone());


}
Groupe::~Groupe(){
	//TODO
}

/**
Ajoute une forme au groupe si elle est non null.
Lance une excepton si elle est null
*/
void Groupe::addForme(Forme * f){
	if ( f == NULL)
		throw (" la forme donnée en parametre est null");
	_groupe.push_back(f);
}

/**
Renvoi la forme a la position i 
Exception si i plus grand que tableau
*/
const Forme * Groupe::getAt(unsigned int i) const{
	if (i>=_groupe.size())
		throw "Index trop grand";
	return _groupe[i];
}

/**
Renvoi un nouvelle forme qui est la translation de la forme courante 
*/
Forme * Groupe::translation (const Vecteur2D & vecTrans) {
	//TODO
	return NULL;
}

/**
Renvoi un nouvelle forme qui est l'homothetie de la forme courante 
*/
Forme * Groupe::homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie) {
	//TODO
	return NULL;
}

/**
Renvoi un nouvelle forme qui est la rotation de la forme courante
*/
Forme * Groupe::rotation (const Vecteur2D & pInvariant, double radiant){
	//TODO
	return NULL;
}

/**
Renvoie la somme des airs du groupe 
*/
double Groupe::getAir() const{
	vector<Forme *>::const_iterator it;
	double res(0);
	for(it =_groupe.begin(); it != _groupe.end(); it++)
		res += (*it)->getAir();
	return res;
}

/**
Retourne un clone du groupe
*/
Forme * Groupe::clone() const{
	return new Groupe(*this);
}

/**
parse un groupe
*/
Groupe::operator string() const{
	ostringstream os;
	vector<Forme *>::const_iterator it;

	os << "Groupe de forme : " << endl;
	for(it = _groupe.begin(); it != _groupe.end() ; it++)
		os << **it;
	return os.str();
}


void Groupe::accepteDessin(VisitorDessinerForme * v) const{
	//TODO
}