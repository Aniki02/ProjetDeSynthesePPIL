#ifndef _STRINGENFORMECORPOLYGONE_HPP
#define _STRINGENFORMECORPOLYGONE_HPP

class StringEnFormeCORPolygone : public StringEnFormeCOR{
public:

	StringEnFormeCORPolygone(StringEnFormeCOR * suivant):StringEnFormeCOR(suivant){}
	Forme * parse1(const string & ligne)const;
};
#endif