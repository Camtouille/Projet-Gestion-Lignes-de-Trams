#include "tramway.h"
#include <cmath>
#include "graphics.h"

tramway::tramway(int num, ligne* li, double vitMax, bool vit, double distTram, double tArret, double distArret, bool sens, arret* arretSuivant, arret* arretPrecedent): d_numeroTram{num}, d_ligne{li}, d_vitesseMax{vitMax}, d_vitesse{vit}, d_distanceMiniTram{distTram}, d_tempsRestantArret{tArret}, d_distanceArret{distArret}, d_sensDeplacement{sens}, d_arretSuiv{arretSuivant},d_arretPrec{arretPrecedent},d_suiv{0},d_prec{0},d_cmpt{d_arretSuiv->d_dureeArret},d_inPause{false},d_change{false}
{}
double tramway::distance(const arret & a1, const arret & a2) const
{
    return (sqrt(pow((a1.d_position.x - a2.d_position.x),2.0) + pow((a1.d_position.y - a2.d_position.y),2.0)));
}

double tramway::distance(const tramway & t1, const arret & a2) const
{
    pos p;
    GetPosition(p);
    return (sqrt(pow((p.x - a2.d_position.x),2.0) + pow((p.y - a2.d_position.y),2.0)));
}

double tramway::distance(const tramway & a1, const tramway & a2) const
{
    pos p1;
    a1.GetPosition(p1);
    pos p2;
    a2.GetPosition(p2);
    return (sqrt(pow((p1.x - p2.x),2.0) + pow((p1.y - p2.y),2.0)));
}

void tramway::GetPosition(pos & p) const
{
    double d=d_distanceArret/distance(*d_arretSuiv, *d_arretPrec);
    p.x=d_arretSuiv->d_position.x*(1-d)+d_arretPrec->d_position.x*(d);
    p.y=d_arretSuiv->d_position.y*(1-d)+d_arretPrec->d_position.y*(d);
}

void tramway::affiche() const
{
    pos p;
    GetPosition(p);
    setcolor(YELLOW);
    bar(p.x-8, p.y-3, p.x+8, p.y+3);
    setcolor(BLUE);
    rectangle(p.x-8, p.y-3, p.x+8, p.y+3);
}

void tramway::avancer()
{
    if(d_prec!=0)
    {
        if(distance(*this,*d_prec)<d_distanceMiniTram && d_sensDeplacement==d_prec->d_sensDeplacement)
        {
            return;
        }
    }
    d_distanceArret-=d_vitesseMax;
    if(d_distanceArret<=0)
    {
        d_arretSuiv->d_dureeArret;
        d_change=false;
        if(d_arretSuiv->d_suiv==0 && d_change==false)
        {
            arret* tmp=d_arretSuiv;
            d_arretSuiv=d_arretPrec;
            d_arretPrec=tmp;
            d_sensDeplacement=false;
            d_change=true;
            d_distanceArret=distance(*d_arretPrec, *d_arretSuiv);
        }
        if(d_change!=true && d_sensDeplacement==true)
        {

            d_arretSuiv=d_arretSuiv->d_suiv;
            d_arretPrec=d_arretPrec->d_suiv;
            d_distanceArret=distance(*d_arretPrec, *d_arretSuiv);
        }
        if(d_arretSuiv->d_prec==0)
        {

            arret* tmp=d_arretSuiv;
            d_arretSuiv=d_arretPrec;
            d_arretPrec=tmp;
            d_sensDeplacement=true;
            d_change=true;
            d_distanceArret=distance(*d_arretPrec, *d_arretSuiv);
        }
        if(d_change!=true && d_sensDeplacement==false)
        {
            d_arretSuiv=d_arretSuiv->d_prec;
            d_arretPrec=d_arretPrec->d_prec;
            d_distanceArret=distance(*d_arretPrec, *d_arretSuiv);

        }
        d_change=false;
    }
}






