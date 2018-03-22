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
    if(liste.d_tete=nullptr)
    {
        return;
    }
    else
    {
        ligne *c2=liste.d_tete;
        ligne *c1;
        ligne *n= new ligne(c2);
        d_tete=n;
        c1=n;
        c2=c2->suiv;
        while(c2!=0)
        {
            n= new ligne(c2);
            c1->suiv=n;
            c1=n;
            c2=c2->suiv;
        }
    }
}

void listeligne::ajouter( listeArrets &la, listetramways &lt);
void listeligne::supprimer( listearrets &la, listetramways &lt);
