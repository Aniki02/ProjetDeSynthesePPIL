#ifndef _GROUPE_HPP
#define _GROUPE_HPP
/**
*	\file Groupe.hpp
*	\brief Represente un groupe de forme
*/
#include <vector>
#include "Forme.hpp"
#include "Couleur.hpp"


/**
*	\class Groupe
*	\brief Represente un groupe de forme
*/
class Groupe : public Forme{
	vector<Forme *> _groupe;
public:

	/**
	*	\brief Constructeur
	*	\param couleur : la couleur du groupe
	*/
	Groupe(Couleur couleur): Forme(couleur){}

	/**
	*	\brief Constructeur par recopie
	*	\param groupe : le groupe a copier
	*/
	Groupe(const Groupe &);

	/**
	*	\brief Destructeur
	*/
	virtual ~Groupe();

	/**
	*	\brief Ajoute une forme au groupe
	*	\param f : la forme a ajouter
	*/
	void addForme(Forme *);

	/**
	*	\brief return la forme a la position de l'index
	*	\param index : position de la forme a retourner
	*/
	const Forme * getAt(unsigned int ) const;

	/**
	*	\brief return le vector<Forme *> du groupe
	*/
	const vector<Forme *> getGroupe() const{return _groupe;}

	/**
    *   \brief effectue une translation sur chaque forme du groupe par rapport a un vecteur 
    *   \param vecTrans : le vecteur de translation
    */
	Forme * translation (const Vecteur2D & vecTrans);

	/**
	*	\brief effectue une homothetie sur chaque forme du groupe
	*   \param pInvariant : point invariant 
    *   \param rapportHomotehie : rapport d'homotethie
	*/
	Forme * homothetie (const Vecteur2D & pInvariant, const double & rapportHomothetie);

	/**
    *   \brief effectue une rotation sur chaque forme du groupe
    *   Effectue une rotation du cercle autour d'un point Invariant 
    *   \param pInvariant : Point invariant autour du quelle le cercle va tourner 
    *   \param radiant : l'angle de rotation
    */
	Forme * rotation (const Vecteur2D & pInvariant, double radiant);

	/**
	*	\brief Return la somme des airs de chaque forme du groupe
	*/
	double getAir() const;

	/**
     *  \brief Return un clone du groupe
     *  Return un pointeur sur un nouveau groupe créer avec le groupe courant 
     */
	Forme * clone() const;

	/**
	*	\brief convertit le groupe en string
	*/
	operator string() const;

	/**
	*	\brief return le vector<Forme *> de l'objet
	*/
	const vector<Forme *> getGroupes()const {return _groupe;}


	/**
    *   \brief Dessine le groupe
    *   param v : Le visiteurDessin de la libairie avec laquelle le cercle doit etre dessiner
    */
	void accepteDessin(VisitorDessinerForme * v) const;
};
#endif
