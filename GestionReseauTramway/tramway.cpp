#include "tramway.h"
#include <cmath>

tramway::tramway(int num, ligne* li, double vitMax, bool vit, double distTram, double tArret, double distArret, bool sens, arret* arretSuivant, arret* arretPrecedent): d_numeroTram{num}, d_ligne{li}, d_vitesseMax{vitMax}, d_vitesse{vit}, d_distanceMiniTram{distTram}, d_tempsRestantArret{tArret}, d_distanceArret{distArret}, d_sensDeplacement{sens}, d_arretSuiv{arretSuivant},d_arretPrec{arretPrecedent}
{}
double tramway::distance(const arret & a1, const arret & a2) const
{
    return (sqrt(pow((a1.d_position.x - a2.d_position.x),2.0) + pow((a1.d_position.y - a2.d_position.y),2.0)));
}

double tramway::distance(const tramway & t1, const arret & a2) const
{
    pos p=t1.GetPosition();
    return (sqrt(pow((p.x - a2.d_position.x),2.0) + pow((p.y - a2.d_position.y),2.0)));
}

double tramway::distance(const tramway & a1, const tramway & a2) const
{
    pos p1=a1.GetPosition();
    pos p2=a2.GetPosition();
    return (sqrt(pow((p1.x - p2.x),2.0) + pow((p1.y - p2.y),2.0)));
}

pos tramway::GetPosition() const
{
    pos p;
    double d=d_distanceArret/distance(*d_arretSuiv, *d_arretPrec);
    p.x=d_arretSuiv->d_position.x*d+d_arretPrec->d_position.x*(1-d);
    p.y=d_arretSuiv->d_position.y*d+d_arretPrec->d_position.y*(1-d);
}
