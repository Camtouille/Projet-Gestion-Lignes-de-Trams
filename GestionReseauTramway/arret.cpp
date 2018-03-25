#include "arret.h"
#include "graphics.h"

arret::arret(const std::string & nom, int dureeArret, const pos & position): d_nom{nom}, d_dureeArret{dureeArret}, d_position{}, d_suiv{nullptr}
{
    d_position.x = position.x;
    d_position.y = position.y;
}

void arret::affiche() const
{
    ///std::cout << "J'affiche l'arret :)\n";
    setcolor(BLUE);
    bar(d_position.x-4, d_position.y-4, d_position.x+4, d_position.y+4);
}

void arret::afficheCoord() const
{
    std::cout << d_position.x << ", " << d_position.y << std::endl;
}
