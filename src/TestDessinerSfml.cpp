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
    Couleur Rouge(255,0,0);
    Couleur Vert(0, 250, 0);
    Couleur Blanc(0,0,0);
    Couleur Bleu(0,0,255);
    Couleur Noir(255,255,255);

    //-----------------------TEST DESSINER FORME SFML------------------------------//*/

    //Création des vecteurs
    Vecteur2D v2(10,20), u10(50,30), i2(40,40),j2(6,4);
    Vecteur2D  u(5,3), i(4,4),j(6,4);
    Vecteur2D y2(60,80);
    
    // Création des vectors pour triangle et polygone
    vector<Vecteur2D> vecP;
    vecP.push_back(v2);
    vecP.push_back(u10);
    vecP.push_back(i2);
    vecP.push_back(j2);
    vecP.push_back(u);

    vector<Vecteur2D> vecT;
    vecT.push_back(v2);
    vecT.push_back(u10);
    vecT.push_back(i2);


   // Initialisation des formes simples
    Forme * p = new Polygone(Rouge,vecP);
    Forme * s = new Segment(Vert,u,u10);
    Forme * t = new Triangle(Rouge,vecT);
    Forme * c = new Cercle(Vert,y2,5);

    // Initialisation du groupe de forme
    Forme * tG = new Triangle(Rouge, vecT);
    Forme * cG = new Cercle(Vert,y2,50);
    Forme * sG = new Segment(Rouge, v2, u10);
    Forme * pG = new Polygone(Vert,vecP);
    Groupe * g = new Groupe(Rouge);


    g->addForme(tG);
    g->addForme(cG);
    g->addForme(sG);
    g->addForme(pG);
    
    
    // Lancement du dessin

    VisitorDessinerForme * visiteuse = new DessinerSFML();
    t->accepteDessin(visiteuse);
    s->accepteDessin(visiteuse);
    p->accepteDessin(visiteuse);
    c->accepteDessin(visiteuse);

    g->accepteDessin(visiteuse);
    

    // }
    return 0;

}