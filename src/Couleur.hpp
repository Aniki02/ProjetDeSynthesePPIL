#ifndef Couleur_hpp
#define Couleur_hpp
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

class Couleur {

    int _a;
    int _b;
    int _c;

public :

    Couleur(int a, int b, int c):_a(a), _b(b), _c(c){}
    virtual ~Couleur(){}

    int getCouleur1()const{return _a;}
    int getCouleur2()const{return _b;}
    int getCouleur3()const{return _c;}

    void setCouleur1(int a){_a=a;}
    void setCouleur2(int a){_b=a;}
    void setCouleur3(int a){_c=a;}

    Couleur * clone() const {return new Couleur(*this);}

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