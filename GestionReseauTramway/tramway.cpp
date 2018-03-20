#include "global.h"

tramway::tramway(int num, ligne* li, double vitMax, bool vit, double distTram, double tArret, double distArret, bool sens, arret* arretSuivant): d_numeroTram{num}, d_ligne{li}, d_vitesseMax{vitMax}, d_vitesse{vit}, d_distanceMiniTram{distTram}, d_tempsRestantArret{tArret}, d_distanceArret{distArret}, d_sensDeplacement{sens}, d_arret{arretSuivant}
{}
