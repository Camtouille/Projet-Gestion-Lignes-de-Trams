#ifndef ARRET_H
#define ARRET_H
#include <iostream>
#include "global.h"

class arret
{
    friend class listeArrets;
    friend class ligne;
    friend class tramway;
    public:
        arret(const std::string & nom, int dureeArret, const pos & position);
        void affiche() const;
    private:
        std::string d_nom;
        int d_dureeArret;
        pos d_position;
        arret *d_suiv;
};

#endif // ARRET_H
