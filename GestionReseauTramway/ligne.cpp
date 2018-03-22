#include "global.h"

ligne::ligne():arrets{}, tramways{}
{}

ligne::ligne(const ligne & l):arrets{l.arrets}, tramways{l.tramways}
{}

ligne::std::vector<pos> GetPosArret()
{
    std::vector<pos> V; 
    arrets *c1=arrets.d_tete;
    
}

void ligne::ajouterArret(std::string nom, int dureeArret, pos position)
{
    arrets.ajouter(std::string nom, int dureeArret, pos position);
}

void ligne::ajouterTram(int numTram, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, const std::string nomProchainArret);
{
    tramways.ajouter(int numTram, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, const std::string nomProchainArret);
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
