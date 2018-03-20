#include "arret.h"

arret::arret(const std::string & nom, int dureeArret, const pos & position): d_nom{nom}, d_dureeArret{dureeArret}, d_position{position}, d_suiv{nullptr}
{}
