#include <stdio.h>
#include <iostream>
#include <vector>

#include "Vecteur2D.hpp"
#include "Forme.hpp"
#include "Groupe.hpp"
#include "Polygone.hpp"
#include "Triangle.hpp"
#include "Segment.hpp"
#include "Cercle.hpp"
#include "DessinerSFML.hpp"



using namespace std;

int main()
{
    //-----------------------TEST DESSINER FORME SFML------------------------------//*/
    cout << "-----------------------TEST DESSINER FORME SFML------------------------------"<< endl;
    Vecteur2D v2(10,20), u10(50,30), i2(40,40),j2(6,4);
    
    vector<Vecteur2D> vecc;
    vecc.push_back(v2);
    vecc.push_back(u10);
    vecc.push_back(i2);
    vecc.push_back(j2);
    Polygone p(1, vecc);
    Vecteur2D y2(6,8);
    Cercle c(1,y2,150);
    Segment s(1, v2, u10);

    cout << p <<endl;
    VisitorDessinerForme * visiteuse = new DessinerSFML();
    p.accepteDessin(visiteuse);
    c.accepteDessin(visiteuse);


    return 0;

}