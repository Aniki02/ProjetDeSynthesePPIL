#ifndef Polygone_hpp
#define Polygone_hpp
/**
*   \file Polygone.hpp
*   \brief Represente un polygone
*/
#include <stdio.h>
#include "Forme.hpp"
#include "Vecteur2D.hpp"
#include <iostream>
#include <vector>
#include "Couleur.hpp"

class Vecteur2D;


/**
*   \class Polygone
*   \brief represente un polygone definit par un vector<Vecteur2D> de au moin 3 points
*/
class Polygone: public Forme{


    vector<Vecteur2D> _points;
    public :

    /**
    *   \brief Constructeur
    *   \param c : la couleur du polygone
    *   \param points : vector de points du polygone 
    */
    Polygone(Couleur c, const vector<Vecteur2D> points);

    /**
    *   \brief Destructeur
    */
    virtual ~Polygone(){}

    /**
     *  \brief Return un clone du polygone
     *  Return un pointeur sur un nouveau cercle créer avec le cercle courant 
     */
    Forme * clone() const{return new Polygone(*this);}

    /**
    *   \brief Return l'air du polygone
    */
    virtual double getAir()const{return 0;}

    /**
    *   \brief ajoute un points au polygone
    *   \param v : le points a ajouter
    */
    void addPoint(Vecteur2D);

    /**
    *   \brief return le point a la position de l'index
    *   \param index : position de la forme a retourner
    */
    const Vecteur2D getPointAt(unsigned int index) const;

    /**
    *   \brief Deplace le polygone par rapport a un vecteur 
    *   \param vecTrans : le vecteur qui
    */
    virtual Forme * translation (const Vecteur2D & vecTrans);

    /**
    *   \brief Effectue une homotehie sur le polygone
    *   effectue une transformation qui fais correspondre tout point par rapport a un point invariant et un rapport
    *    
    *   \param pInvariant : point invariant 
    *   \param rapportHomotehie : rapport d'homotethie
    */
	virtual Forme * homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie);

      /**
    *   \brief effectue une rotation sur le polygone
    *   Effectue une rotation du polygone autour d'un point Invariant 
    *   \param pInvariant : Point invariant autour du quelle le cercle va tourner 
    *   \param radiant : l'angle de rotation
    */
	virtual Forme * rotation (const Vecteur2D & pInvariant, double radiant);

    /**
    *   \brief Dessine le polygone
    *   \param v : Le visiteurDessin de la libairie avec laquelle le polygone doit etre dessiner
    */
	void accepteDessin(VisitorDessinerForme * v) const;

    /**
    *   \brief return le vector<Vecteur2D> de l'objet
    */
    const vector<Vecteur2D> getPoints() const{return _points;}

    /**
    *   \brief convertit un polygone en string
    */
    operator string() const;

};

#endif
