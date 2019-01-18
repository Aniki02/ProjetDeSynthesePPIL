#include <stdio.h>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

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
    //creation fentetre
    DessinerSFML * visiteur = new DessinerSFML("ma Fenetre", 800, 800);
    //creation des forme
    Forme * s = new Segment(Couleur(0,255,0), Vecteur2D(10,10), Vecteur2D(700,700));
    Forme * s1 = new Segment(Couleur(0,255,0), Vecteur2D(700,200), Vecteur2D(10,100));
    Forme * s2 = new Segment(Couleur(255,0,0), Vecteur2D(300,200), Vecteur2D(800,100));
    Forme * c = new Cercle(Couleur(0,0,255), Vecteur2D(400,200), 100);
    Forme * p = new Polygone(Couleur(0,255,255), {Vecteur2D(20,20), Vecteur2D(20,100), Vecteur2D(100,100), Vecteur2D(100,20)});
    Forme * t = new Triangle(Couleur(100,100,100), {Vecteur2D(200,200), Vecteur2D(200,500), Vecteur2D(500,500)});
    
    Groupe * g = new Groupe(Couleur(100,200,0));
    g->addForme(s);
    g->addForme(s1);
    g->addForme(s2);
    g->addForme(c);
    g->addForme(p);
    g->addForme(t);

    g->accepteDessin(visiteur);

    // s->accepteDessin(visiteur);
    // s1->accepteDessin(visiteur);
    // s2->accepteDessin(visiteur);
    //c->accepteDessin(visiteur);
    // Forme * c2 = c->homothetie(Vecteur2D(100,100), 2);
    // c2->accepteDessin(visiteur);
    // p->accepteDessin(visiteur);
    // t->accepteDessin(visiteur);

    visiteur->run();

    

    return 0;

}