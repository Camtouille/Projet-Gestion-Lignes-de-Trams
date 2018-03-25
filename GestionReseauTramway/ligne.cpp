#include "ligne.h"
#include "arret.h"
#include <iostream>
#include <vector>
#include "graphics.h"

ligne::ligne():arrets{}, tramways{}, d_suiv{0}
{}

ligne::ligne(const ligne & l):arrets{l.arrets}, tramways{l.tramways}, d_suiv{0}
{}

std::vector<pos> ligne::GetPosArret()
{
    std::vector<pos> V;
    arret *c1 = arrets.d_tete;
    while(c1 != 0)
    {
        V.push_back(c1->d_position);
    }

}

void ligne::ajouterArret(std::string nom, int dureeArret, pos position)
{
    arrets.ajouter(nom, dureeArret, position);
}

void ligne::ajouterTram(int numTram, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, arret *arretSuivant, arret *arretPrecedent)
{
    tramways.ajouter(numTram, this, vitesseMax, vitesse, distanceMiniTram, tempsArret, distanceArret, sensDeplacement, arretSuivant, arretPrecedent);
}

arret* ligne::chercherArret(std::string nom)
{
    return arrets.chercher(nom);
}

tramway* ligne::chercherTramway(int num)
{
    return tramways.chercher(num);
}

void ligne::afficheArrets() const
{
    arrets.afficher();
}

void ligne::affiche() const
{
    afficheArrets();
    std::vector<pos> p = arrets.CoordsArrets();
    for(int i = 1 ; i<p.size() ; i++)
    {
        setcolor(BLUE);
        line(p[i-1].x, p[i-1].y, p[i].x, p[i].y);
    }
}
