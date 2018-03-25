#ifndef LISTELIGNE_H
#define LISTELIGNE_H
#include "ligne.h"

class listeligne
{
    public:
        listeligne();
        ~listeligne();
        listeligne(const listeligne & liste);
        ligne* ajouter();
        void affiche() const;
        void rafraichir();
        void afficherNomArrets() const;

    private:
        ligne *d_tete;
};

#endif // LISTELIGNE_H
