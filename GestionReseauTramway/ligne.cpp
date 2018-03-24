#include "ligne.h"
#include "arret.h"

ligne::ligne():arrets{}, tramways{}
{}

ligne::ligne(const ligne & l):arrets{l.arrets}, tramways{l.tramways}
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
