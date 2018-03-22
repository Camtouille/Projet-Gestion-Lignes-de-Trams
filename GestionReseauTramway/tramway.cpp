#include "global.h"

tramway::tramway(int num, ligne* li, double vitMax, bool vit, double distTram, double tArret, double distArret, bool sens, arret* arretSuivant, arret* arretPrecedent): d_numeroTram{num}, d_ligne{li}, d_vitesseMax{vitMax}, d_vitesse{vit}, d_distanceMiniTram{distTram}, d_tempsRestantArret{tArret}, d_distanceArret{distArret}, d_sensDeplacement{sens}, d_arretSuiv{arretSuivant},d_arretPrec{arretPrecedent}
{}
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

pos tramway::GetPosition() const
{

}
