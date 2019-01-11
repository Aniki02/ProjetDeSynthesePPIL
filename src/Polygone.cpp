#include "Polygone.hpp"
#include <sstream>

using namespace std;

    void Polygone::addPoint(Vecteur2D* o){
    if(o != NULL)
			_points.push_back(o);
    }

    const Vecteur2D * Polygone::getPointAt(unsigned int index) const{
        if (index < _points.size())
			return _points[index];
            return NULL;
		}

    Forme * Polygone::translation (const Vecteur2D & vecTrans){return NULL;}
	Forme * Polygone::homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie){return NULL;}
    Forme * Polygone::rotation (const Vecteur2D & pInvariant, double radiant){return NULL;}

	void Polygone::accepteDessin(VisitorDessinerForme * v) const {};

    Polygone::operator string() const
    { ostringstream os;
    for(vector<Vecteur2D*>::const_iterator it = _points.begin(); it != _points.end(); it++){
	os << "Point";
	return os.str();
    }
	};


