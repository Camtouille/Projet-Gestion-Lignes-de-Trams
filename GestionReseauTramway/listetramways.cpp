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
            c1=n;
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

void listeTramways::ajouter(int numTram, ligne* li, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, arret *arretSuivant, arret *arretPrecedent);
{
    tramway *n= new tramway(numTram,li,vitessMax,vitesse,distanceMiniTram,tempsArrets,distanceArret,sensDeplacement,arretSuivant,arretPrecedent);
    if(d_tete=nullptr)
    {
        d_tete=n;
    }
    else
    {
        tramway *c=d_tete;
        if(c->num>numTram)
        {
            n->suiv=c;
            d_tete=n;
            return;
        }
        while(c->suiv!=nullptr && numTram>c->suiv->num)
        {
            c=c->suiv;
        }
        if(c->suiv==nullptr)
        {
            c->suiv=n;
        }
        else
        {
            n->suiv=c->suiv;
            c->suiv=n;
        }
    }
}

void listeTramways::supprimer(int numTram);
{
    if(d_tete=nullptr)
    {
        return;
    }
    else
    {
        tramway *c=d_tete;
        if(c->num=numTram)
        {
            tramway *d=d_tete;
            d_tete=d_tete->suiv;
            delete d;
        }
        while(c->suiv!=nullptr && numTram>c->suiv->num)
        {
            c=c->suiv;
        }
        if(c->suiv!=nullptr)
        {
            tramway *d=c->suiv;
            c->suiv=d->suiv;
            delete d;
        }
    }
}
