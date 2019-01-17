#include <stdio.h>
#include <iostream>
#include <vector>

#include "Vecteur2D.hpp"


using namespace std;

int main()
{

	//-----TEST DE LA CLASSE VECTEUR2D ------//
	cout << "-----TEST des vecteurs 2D------- \n";

	Vecteur2D u1(2,3), u2(2,3), v(5), v1(35,-63), u3(3,4), u4(3,-4);

	cout << " u1 = " <<  u1 << endl;
	cout << " u2 = " <<  u2 << endl;
	cout << " u1 + u2 = " <<  u1+u2 << endl;
	cout << " 5.8*u1 = " <<  5.8*u1 << endl;

	return 0;

}

