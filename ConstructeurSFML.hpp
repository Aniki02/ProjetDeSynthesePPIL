#ifndef _ConstructeurSFML_HPP
#define _ConstructeurSFML_HPP

#include <vector>


class ConstructeurSFML{
    public :
	void consSFML(const Segment * segment) const;
	void consSFML(const Cercle * cercle) const;
	void consSFML(const Polygone * polygone) const;
	void consSFML(const Triangle * triangle) const;
	void desSFML(const Segment * segment) const;
	void desSFML(const Cercle * cercle) const;
	void desSFML(const Polygone * polygone) const;
	void desSFML(const Triangle * triangle) const;
};
#endif
