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

void listeligne::ajouter( listeArrets &la, listetramways &lt);
