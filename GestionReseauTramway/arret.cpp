#include "arret.h"
#include "graphics.h"

arret::arret(const std::string & nom, int dureeArret, const pos & position): d_nom{nom}, d_dureeArret{dureeArret}, d_position{}, d_suiv{nullptr}
{
    d_position.x = position.x;
    d_position.y = position.y;
}

void arret::affiche() const
{
    setcolor(BLACK);
    rectangle(d_position.x-2, d_position.y-2, d_position.x+2, d_position.y+2);
}
