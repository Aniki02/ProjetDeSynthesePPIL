#include "Polygone.hpp"
#include "VisitorDessinerForme.hpp"
#include <sstream>
#include <vector>

using namespace std;

    Polygone::Polygone(int c, const vector<Vecteur2D> points):Forme(c){
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
        //TODO
        return NULL;
    }
	Forme * Polygone::homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie){
        //TODO
        return NULL;
    }
    Forme * Polygone::rotation (const Vecteur2D & pInvariant, double radiant){
        //TODO
        return NULL;
    }

	void Polygone::accepteDessin(VisitorDessinerForme * v) const {
        v->visite(this);
    };

    Polygone::operator string() const
    {
        ostringstream os;
        os << "POLYGONE : " << endl;
        os << "Couleur : " << this->getCouleur();
        vector<Vecteur2D>::const_iterator it;
        int i = 1;
        for( it = _points.begin(); it != _points.end(); it++)
    	   os << ", Point Numero" << i << ":" << *it << "   ";
           i++;
    	return os.str();
	}


