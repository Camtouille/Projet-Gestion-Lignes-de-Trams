#include "global.h"

listeTramways::listeTramways()
{
    //ctor
}
listeTramways(const listeTramways & liste);

listeTramways::~listeTramways()
{
    //dtor
}
void ajouter(int numTram, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, const std::string nomProchainArret);
void supprimer(int num);
tramway* chercher(int num) const;
