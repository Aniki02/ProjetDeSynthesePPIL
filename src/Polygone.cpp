#include "Polygone.hpp"
#include "VisitorDessinerForme.hpp"
#include <sstream>
#include <vector>

using namespace std;

    Polygone::Polygone(Couleur c, const vector<Vecteur2D> points):Forme(c){
        vector<Vecteur2D>::const_iterator it;
        if (points.size() < 3)
            throw ("Un polygone doit etre compose de au moins 3 points");
        for(it = points.begin(); it != points.end(); it++)
            _points.push_back(*it);

    }
    void Polygone::addPoint(Vecteur2D v){
		_points.push_back(v);
    }

    const Vecteur2D Polygone::getPointAt(unsigned int index) const{
        if (index >= _points.size())
			throw ("Index plus grand que le tableau");
        return _points[index];
	}

    Forme * Polygone::translation (const Vecteur2D & vecTrans){
        vector<Vecteur2D> vecteur;
        vector<Vecteur2D>::const_iterator it;
        for(it = _points.begin(); it != _points.end(); it++){
            Vecteur2D v = (*it)+vecTrans;
            vecteur.push_back(v);
        }
        return new Polygone(getCouleur(),vecteur);
    }

	Forme * Polygone::homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie){
        vector<Vecteur2D> vecteur;
        vector<Vecteur2D>::iterator it;
        for(it = _points.begin(); it != _points.end(); it++){
            Vecteur2D v = ((*it) - pInvariant) * rapportHomothetie;
            vecteur.push_back(v);
        }
        return new Polygone(getCouleur(),vecteur);
    }

    Forme * Polygone::rotation (const Vecteur2D & pInvariant, double radiant){
        vector<Vecteur2D> vecteur;
        vector<Vecteur2D>::iterator it;
        for(it = _points.begin(); it != _points.end(); it++){
           Vecteur2D v = (*it).rotation(pInvariant, radiant);
           vecteur.push_back(v);
        }
        return new Polygone(getCouleur(),vecteur);
    }

	void Polygone::accepteDessin(VisitorDessinerForme * v) const {
        v->visite(this);
    };

    Polygone::operator string() const{
        int i = 1;
        ostringstream os;
        os << "Polygone-NbPoint:" << this->getPoints().size() << "-Couleur:" << this->getCouleur();
        vector<Vecteur2D>::const_iterator it;
        for( it = _points.begin(); it != _points.end(); it++){
            os << "-" << *it;
            i++;
        }

    	return os.str();
	}


