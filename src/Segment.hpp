#ifndef Segment_hpp
#define Segment_hpp
/**
*   \file Segment.hpp
*   \brief represente un segment
*/
#include <stdio.h>
#include "Forme.hpp"
#include "Vecteur2D.hpp"
#include <iostream>
#include "Couleur.hpp"

class Forme;
class VisitorDessinerForme;
class Vecteur2D;

/**
*   \class Forme
*   \brief represente une forme 
*/
class Segment : public Forme{
Vecteur2D _origine;
Vecteur2D _arrive;

public :

    /**
    *   \brief Constructeur
    *   \param couleur : la couleur du segment 
    *   \param x : le point de depart du segment
    *   \param y : le point d'arrive du segment
    */
    Segment( Couleur couleur, const Vecteur2D &x, const Vecteur2D &y);

    /**
    *   \brief Destructeur
    */
    virtual ~Segment(){}

    /**
     *  \brief Return un clone du cercle 
     *  Return un pointeur sur un nouveau cercle créer avec le cercle courant 
     */
    Forme * clone() const{return new Segment(*this);}

    /**
     *  \brief Return l'air du cercle
     */
    double getAir() const {return 0;}

    /**
    *   \brief Return le points d'Arrive du segment
    */
    Vecteur2D getArrive()const {return _arrive; }

    /**
     *  \brief Return le point de depart du segment 
     */
    Vecteur2D getOrigine()const {return _origine;}

    /**
    *   \brief Change le point d'arrive
    *   \param v : nouveau point d'arrive
    */
    void setArrive(const Vecteur2D &v){_arrive = v;}

    /**
    *   \brief Change le point de depart
    *   \param v : nouveau point de depart
    */
    void setOrigine(const Vecteur2D &v){_origine = v;}

    /**
    *   \brief Dessine le segment
    *   \param v : Le visiteurDessin de la libairie avec laquelle le cercle doit etre dessiner
    */
    void accepteDessin(VisitorDessinerForme *visiteur) const;

    /**
    *   \brief Deplace le cercle par rapport a un vecteur 
    *   \param vecTrans : le vecteur qui
    */
	virtual Forme * translation (const Vecteur2D & vecTrans);

    /**
    *   \brief Effectue une homotehie sur le cercle
    *   effectue une transformation qui fais correspondre tout point par rapport a un point invariant et un rapport
    *    
    *   \param pInvariant : point invariant 
    *   \param rapportHomotehie : rapport d'homotethie
    */
	virtual Forme * homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie);

    /**
    *   \brief effectue une rotation sur le cercle
    *   Effectue une rotation du cercle autour d'un point Invariant 
    *   \param pInvariant : Point invariant autour du quelle le cercle va tourner 
    *   \param radiant : l'angle de rotation
    */
	virtual Forme * rotation (const Vecteur2D & pInvariant, double radiant);

    /**
    *   \brief Convertit la forme en string
    */
	virtual operator string() const;


};

#endif
