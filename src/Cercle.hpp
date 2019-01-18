#ifndef Cercle_hpp
#define Cercle_hpp
/**
 * \file Cercle.hpp
 * \brief représente un cercle
 * \author zitoun-diallo-sid
 */
#include <stdio.h>
#include "Forme.hpp"
#include "Vecteur2D.hpp"
#include "Couleur.hpp"
#include <iostream>

#define PI 3.14159

class Forme;
class VisitorDessinForme;
class Vecteur2D;




/** \class Cercle
* \brief classe representant un cercle
*
*  La classe Cercle represente un cercle et possede des methode pour transformer le cercle 
*/
class Cercle : public Forme{
    Vecteur2D _centre;
    double _rayon;

    public :
    /**
     *  \brief Constructeur
     *
     *  Constructeur de la classe Cercle
     *
     *  \param couleur : couleur de la forme
     *  \param centre : Vecteur2D qui represente le centre du cercle
     *  \param r : le rayon du cercle
     */
    Cercle(Couleur couleur, Vecteur2D centre, double r);

    /**
     *  \brief Destructeur
     */
    virtual ~Cercle(){}

    /**
     *  \brief Return un clone du cercle 
     *  Return un pointeur sur un nouveau cercle créer avec le cercle courant 
     */
    Forme * clone() const {return new Cercle(*this);}

    /**
     *  \brief Return l'air du cercle
     */
    double getAir()const;

    /**
     *  \brief Return le centre du cercle
     */
    Vecteur2D getCentre()const {return _centre;}

    /**
     *  \brief Return le rayon du cercle
     */
    double getRayon() const {return _rayon;}

    /**
     *  \brief Change le centre du cercle
     *  \param v : vecteur du nouveau centre 
     */
    void setCentre(const Vecteur2D &v){_centre = v;}

    /**
     *  \brief Change le rayon du cercle
     *  \param r: nouveau rayon
     */
    void setRayon(double r){_rayon = r;}

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
    *   \brief Dessine le cercle
    *   \param v : Le visiteurDessin de la libairie avec laquelle le cercle doit etre dessiner
    */
	void accepteDessin(VisitorDessinerForme * v) const;

    /**
    *   \brief Convertit la forme en string
    */
    virtual operator string() const;
};

#endif
