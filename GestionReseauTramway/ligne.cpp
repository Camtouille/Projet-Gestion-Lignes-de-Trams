#include "global.h"

ligne::ligne():arrets{}, tramways{}
{
    //ctor
}

ligne::ligne(const ligne & l):arrets{l.arrets}, tramways{l.tramways}
{
    ///bonjour
}

/// listeArrets et ListeTramways s'occupe de la destruction?  -juj
ligne::~ligne()
{
    //dtor
}

double ligne::distance(const arret & a1, const arret & a2)
{
    return (sqrt(abs((a1.position.x*a2.position.x)-(a1.position.y*a2.position.y)));
}

double ligne::distance(const tramway & t1, const arret & a2)
{
    return (sqrt(abs((t1.position.x*a2.position.x)-(t1.position.y*a2.position.y)));
}

double ligne::distance(const tramway & a1, const tramway & a2)
{
    return (sqrt(abs((t1.position.x*t2.position.x)-(t1.position.y*t2.position.y)));
}
