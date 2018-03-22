#include "global.h"

listeTramways::listeTramways():d_tete{nullptr}
{
    //ctor
}

listeTramways::listeTramways(const listeTramways & liste):d_tete{nullptr}
{
    if(liste.d_tete=nullptr)
    {
        return;
    }
    else
    {
        tramway *c2=liste.d_tete;
        tramway *c1;
        tramway *n= new tramway(c2);
        d_tete=n;
        c1=n;
        c2=c2->suiv;

        while()
        {
            n= new tramway(c2);
            c1->suiv=n;
            c2=c2->suiv;
        }
    }
}

listeTramways::~listeTramways()
{
    tramways *t= d_tete;
    while(t!=0)
    {
        d_tete=t->suiv;
        delete t;
        t=d_tete;
    }
}
