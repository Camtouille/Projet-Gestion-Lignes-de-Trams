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

listeArrets::~listeArrets()
{
    arret *a = d_tete;
    while (a != 0)
    {
        d_tete = a->d_suiv;
        delete a;
        a = d_tete;
    }
}

void listeArrets::ajouter(std::string nom, int dureeArret, pos position)
{
    arret *na = new arret(nom, durreArret, position);
    if ( d_tete == 0 )
    {
        d_tete = na;
    }
    else if (strcmp( nom, d_tete->nom) < 0)
    {
        na->suiv = d_tete;
        d_tete = na;
    }
    else
    {
        arret *prec = d_tete;
        arret *a = d_tete->suiv;
        while ( a != 0 && strcmp( a->nom, nom) < 0 )
        {
            prec = a;
            a = a->suiv;
        }
        prec->suiv = na;
        na->suiv = c;
    }
}

void listeArrets::supprimer(std::string nom)
{
    if ( d_tete != 0 )
    {
        if ( strcmp( d_tete->nom, nom) = 0 )
        {
            arret *tmp = d_tete;
            d_tete = d_tete->suiv;
            delete tmp;
        }
        else
        {
            arret *prec = d_tete;
            arret *a = d_tete->suiv;
            while ( a != 0 && strcmp(a->nom, nom) < 0 )
            {
                prec = a;
                a = a->suiv;
            }
            if ( a != 0 )
            {
                prec->suiv = a->suiv;
                delete c;
            }
        }
    }
}

arret* listeArrets::chercher(std::string nom) const;
