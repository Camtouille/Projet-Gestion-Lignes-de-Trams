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

double ligne::distanceEntreArret(const arret & a1, const arret & a2)
{
    return (sqrt(abs((a1.position.x*a1.position.x)-(a1.position.y*a1.position.y)));
}
