#include "listearrets.h"

listeArrets::listeArrets(): d_tete{nullptr}
{}

listeArrets::listeArrets(const listeArrets & l): d_tete{nullptr}
{
    if(l.d_tete != 0)
    {
        arret *c1, *c2 = l.d_tete;
        arret *n = new arret(c2->d_nom, c2->d_dureeArret, c2->d_position);
        d_tete = n;
        c1 = n;
        c2 = c2->d_suiv;
        while(c2 != 0)
        {
            n = new arret(c2->d_nom, c2->d_dureeArret, c2->d_position);
            c1->d_suiv = n;
            c1 = n;
            c2 = c2->d_suiv;
        }
    }
}

listeArrets::~listeArrets();
void listeArrets::ajouter(std::string nom, int dureeArret, pos position);
void listeArrets::supprimer(std::string nom);
arret* listeArrets::chercher(std::string nom) const;
