#include "global.h"

ligne::ligne():arrets{}, tramways{}
{}

ligne::ligne(const ligne & l):arrets{l.arrets}, tramways{l.tramways}
{}

ligne::std::vector<pos> GetPosArret()
{
    std::vector<pos> V; 
    arrets *c1=arrets.d_tete;
    while(c1 != 0)
    {
        V.push_back(c1-> arrets.d_position);
    }
    
}

void ligne::ajouterArret(std::string nom, int dureeArret, pos position)
{
    arrets.ajouter(std::string nom, int dureeArret, pos position);
}

void ligne::ajouterTram(int numTram, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, const std::string nomProchainArret);
{
    tramways.ajouter(int numTram, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, const std::string nomProchainArret);
}

