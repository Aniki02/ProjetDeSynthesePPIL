#include "Triangle.hpp"
#include <sstream>
#include "VisitorDessinerForme.hpp"

using namespace std;

    void Triangle::accepteDessin(VisitorDessinerForme * v) const{
        v->visite(this);
    }

