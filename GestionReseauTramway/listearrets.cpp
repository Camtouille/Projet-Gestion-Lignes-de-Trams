#include "listearrets.h"
#include <string.h>

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
            n->d_prec=c1;
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

void listeArrets::ajouter(const std::string nom, int dureeArret, pos position)
{
    arret *na = new arret(nom, dureeArret, position);
    if ( d_tete == 0 )
    {
        d_tete = na;
    }
    else
    {
        arret *c = d_tete;
        while(c->d_suiv != 0)
        {
            c = c->d_suiv;
        }
        c->d_suiv = na;
        na->d_prec = c;
    }
}

void listeArrets::supprimer(std::string nom)
{
    if ( d_tete != 0 )
    {
        if ( strcmp( d_tete->d_nom.c_str(), nom.c_str()) == 0 )
        {
            arret *tmp = d_tete;
            d_tete = d_tete->d_suiv;
            d_tete->d_suiv->d_prec=0;
            delete tmp;
        }
        else
        {
            arret *prec = d_tete;
            arret *a = d_tete->d_suiv;
            while ( a != 0 && strcmp(a->d_nom.c_str(), nom.c_str()) != 0 )
            {
                prec = a;
                a = a->d_suiv;
            }
            if ( a != 0 )
            {
                prec->d_suiv = a->d_suiv;
                a->d_suiv->d_prec=prec;
                delete a;
            }
        }
    }
}

arret* listeArrets::chercher(std::string nom) const
{
    if(d_tete == 0)
    {
        return nullptr;
    }
    arret *c = d_tete;
    while(c!=0 && strcmp(c->d_nom.c_str(), nom.c_str()) != 0)
    {
        c = c->d_suiv;
    }
    if(c == 0)
    {
        return nullptr;
    }
    if(strcmp(c->d_nom.c_str(), nom.c_str()) == 0)
    {
        return c;
    }
    return nullptr; ///Si on a pas trouvé l'arret
}

void listeArrets::afficher() const
{
    if(d_tete != 0)
    {
        arret *c = d_tete;
        while(c != 0)
        {
            c->affiche();
            c = c->d_suiv;
        }
    }
}

std::vector<pos> listeArrets::CoordsArrets() const
{
    std::vector<pos> vect;
    if(d_tete != 0)
    {
        arret *c = d_tete;
        while(c != 0)
        {
            vect.push_back(c->d_position);
            c = c->d_suiv;
        }
    }
    return vect;
}

void listeArrets::afficherNomArrets() const
{
    if(d_tete!=0)
    {
        arret *c = d_tete;
        while (c!=0)
        {
            std::cout<<c->d_nom<<" ";
            c=c->d_suiv;
        }
    }
}






