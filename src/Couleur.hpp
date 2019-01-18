#ifndef Couleur_hpp
#define Couleur_hpp
/**
 * \file Couleur.hpp
 * \brief représente une couleur
 * \author zitoun-diallo-sid
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

/** \class Couleur
* \brief classe representant une couleur
*
*  La classe Couleur represente une couleur sous le format rgb
*/
class Couleur {

    int _a;
    int _b;
    int _c;

public :

    /**
    *   \brief Constructeur
    *   \param a : quantite de rouge
    *   \param b : quantite de vert
    *   \param c : quantite de bleu
    */
    Couleur(int a, int b, int c):_a(a), _b(b), _c(c){}

    /**
    *   \brief Destructeur
    */
    virtual ~Couleur(){}

    /**
    *   \brief Return la quantite de rouge
    */
    int getCouleur1()const{return _a;}

    /**
    *   \brief Return la quantite de vert
    */
    int getCouleur2()const{return _b;}

    /**
    *   \brief Return la quantite de bleu
    */
    int getCouleur3()const{return _c;}

    /**
    *   \brief Change la quantite de rouge
    */
    void setCouleur1(int a){_a=a;}

    /**
    *   \brief Change la quantite de vert
    */
    void setCouleur2(int a){_b=a;}

    /**
    *   \brief Change la quantite de bleu
    */
    void setCouleur3(int a){_c=a;}

    /**
     *  \brief Return un clone de couleur 
     *  Return un pointeur sur une nouvelle couleur créer avec la couleur courante 
     */
    Couleur * clone() const {return new Couleur(*this);}

    /**
    *   \brief Convertit la couleur en string
    */
    operator string() const{
        ostringstream os;
        os <<"("<<_a<< ","<<_b <<","<<_c << ")";
        return os.str();
    }
    
};

inline ostream & operator << (ostream & o , const Couleur & c){
    return o << (string)c;
}

inline ostream & operator << (ostream & o , const Couleur * c){
    return o << *c;
}

#endif