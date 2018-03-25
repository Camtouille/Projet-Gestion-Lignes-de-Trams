#include "listeligne.h"

listeligne::listeligne(): d_tete{nullptr}
{}

listeligne::~listeligne()
{
    ligne *l = d_tete;
    while ( l != 0 )
    {
        d_tete = l->d_suiv;
        delete l;
        l = d_tete;
    }
}

listeligne::listeligne(const listeligne & liste)
{
    if(liste.d_tete == nullptr)
    {
        return;
    }
    else
    {
        ligne *c2=liste.d_tete;
        ligne *c1;
        ligne *n= new ligne(*c2);
        d_tete=n;
        c1=n;
        c2=c2->d_suiv;
        while(c2!=0)
        {
            n= new ligne(*c2);
            c1->d_suiv=n;
            c1=n;
            c2=c2->d_suiv;
        }
    }
}

ligne* listeligne::ajouter()
{
    ligne* l= new ligne{};
    if(d_tete==0)
    {
        d_tete=l;
    }
    else
    {
        ligne *prec = d_tete;
        ligne *l2 = d_tete->d_suiv;
        while ( l2 != 0)
        {
            prec = l2;
            l2 = l2->d_suiv;
        }
        prec->d_suiv = l;
        l->d_suiv = l2;
    }
    return l;
}

void listeligne::affiche() const
{
    if(d_tete != 0)
    {
        ligne *c = d_tete;
        while(c != 0)
        {
            c->affiche();
            c = c->d_suiv;
        }
    }
}
