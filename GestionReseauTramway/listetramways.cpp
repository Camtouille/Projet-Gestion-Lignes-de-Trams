#include "listetramways.h"
#include "tramway.h"

listeTramways::listeTramways():d_tete{nullptr}
{
    //ctor
}

listeTramways::listeTramways(const listeTramways & liste):d_tete{nullptr}
{
    if(liste.d_tete == nullptr)
    {
        return;
    }
    else
    {
        tramway *c2=liste.d_tete;
        tramway *c1;
        tramway *n= new tramway(*c2);
        d_tete=n;
        c1=n;
        c2=c2->d_suiv;

        while(c2!=0)
        {
            n= new tramway(*c2);
            c1->d_suiv=n;
            c1=n;
            c2=c2->d_suiv;
        }
    }
}

listeTramways::~listeTramways()
{
    tramway *t= d_tete;
    while(t!=0)
    {
        d_tete=t->d_suiv;
        delete t;
        t=d_tete;
    }
}

void listeTramways::ajouter(int numTram, ligne* li, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, arret *arretSuivant, arret *arretPrecedent)
{
    tramway *n= new tramway(numTram,li,vitesseMax,vitesse,distanceMiniTram,tempsArret,distanceArret,sensDeplacement,arretSuivant,arretPrecedent);
    if(d_tete==nullptr)
    {
        d_tete=n;
    }
    else
    {
        tramway *c=d_tete;
        if(c->d_numeroTram>numTram)
        {
            n->d_suiv=c;
            d_tete=n;
            return;
        }
        while(c->d_suiv!=nullptr && numTram>c->d_suiv->d_numeroTram)
        {
            c=c->d_suiv;
        }
        if(c->d_suiv==nullptr)
        {
            c->d_suiv=n;
        }
        else
        {
            n->d_suiv=c->d_suiv;
            c->d_suiv=n;
        }
    }
}

void listeTramways::supprimer(int numTram)
{
    if(d_tete==nullptr)
    {
        return;
    }
    else
    {
        tramway *c=d_tete;
        if(c->d_numeroTram==numTram)
        {
            tramway *d=d_tete;
            d_tete=d_tete->d_suiv;
            delete d;
        }
        while(c->d_suiv!=nullptr && numTram!=c->d_suiv->d_numeroTram)
        {
            c=c->d_suiv;
        }
        if(c->d_suiv!=nullptr)
        {
            tramway *d=c->d_suiv;
            c->d_suiv=d->d_suiv;
            delete d;
        }
    }
}

tramway* listeTramways::chercher(int num) const
{
    if(d_tete == 0)
    {
        return nullptr;
    }
    tramway *c = d_tete;
    while(c != 0 && c->d_numeroTram < num)
    {
        c = c->d_suiv;
    }
    if(c == 0)
    {
        return nullptr;
    }
    if(c->d_numeroTram == num)
    {
        return c;
    }
    return nullptr;
}

void listeTramways::affiche() const
{
    if(d_tete != 0)
    {
        tramway *c = d_tete;
        while(c != 0)
        {
            c->affiche();
            c = c->d_suiv;
        }
    }
}
