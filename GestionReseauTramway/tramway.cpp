#include "global.h"

tramway::tramway(int num, ligne* li, double vitMax, bool vit, double distTram, double tArret, double distArret, bool sens, arret* arretSuivant, arret* arretPrecedent): d_numeroTram{num}, d_ligne{li}, d_vitesseMax{vitMax}, d_vitesse{vit}, d_distanceMiniTram{distTram}, d_tempsRestantArret{tArret}, d_distanceArret{distArret}, d_sensDeplacement{sens}, d_arretSuiv{arretSuivant},d_arretPrec{arretPrecedent}
{}
double tramway::distance(const arret & a1, const arret & a2)
{
    return (sqrt(abs((a1.position.x*a2.position.x)-(a1.position.y*a2.position.y)));
}

double tramway::distance(const tramway & t1, const arret & a2)
{
    pos p=t1.GetPosition();
    return (sqrt(abs((p.x*a2.position.x)-(p.y*a2.position.y)));
}

double tramway::distance(const tramway & a1, const tramway & a2)
{
    pos p1=a1.GetPosition();
    pos p2=a2.GetPosition();
    return (sqrt(abs((p1.x*p2.x)-(p1.y*p2.y)));
}

pos tramway::GetPosition() const
{
    pos p;
    double d=d_distanceArret/distance(d_arretSuiv,d_arretPrec);
    p.x=d_arretSuiv->pos.x*d+d_arretPrec->pos.x*(1-d);
    p.y=d_arretSuiv->pos.y*d+d_arretPrec->pos.y*(1-d);
}
