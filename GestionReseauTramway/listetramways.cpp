#include "global.h"

listeTramways::listeTramways()
{
    //ctor
}
listeTramways::listeTramways(const listeTramways & liste);

listeTramways::~listeTramways()
{
    //dtor
}
void listeTramways::ajouter(int numTram, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, const std::string nomProchainArret);
void listeTramways::supprimer(int num);
tramway* listeTramways::chercher(int num) const;
