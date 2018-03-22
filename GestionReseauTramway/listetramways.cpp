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

        while(c2!=0)
        {
            n= new tramway(c2);
            c1->suiv=n;
            c2=c2->suiv;
            c1=n;
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

void listeTramways::ajouter(int numTram, ligne* li, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, arret *arretSuivant);
{
    tramway *n= new tramway(numTram,li,vitessMax,vitesse,distanceMiniTram,tempsArrets,distanceArret,sensDeplacement,arretSuivant);
    if(d_tete=nullptr)
    {
        d_tete=n;
    }
    else
    {
        tramway *c=d_tete;
        while(c>suiv!=nullptr && numTram>c->num)
        {
            c=c->suiv;
        }
        if(c==nullptr)
        {
            c->suiv=n;
            n->suiv=nullptr;
        }
        else
        {
            n->suiv=c->suiv;
            c->suiv=n;
        }
    }
}
