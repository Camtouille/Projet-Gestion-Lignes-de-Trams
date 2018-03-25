#ifndef ARRET_H
#define ARRET_H
#include <iostream>
#include "global.h"

class arret
{
    friend class listeTramways;
    friend class listeArrets;
    friend class ligne;
    friend class tramway;
    public:
        arret(const std::string & nom, int dureeArret, const pos & position);
        void affiche() const;
        void afficheCoord() const;
    private:
        std::string d_nom;
        int d_dureeArret;
        pos d_position;
        arret *d_suiv;
        arret *d_prec;
};

#endif // ARRET_H
