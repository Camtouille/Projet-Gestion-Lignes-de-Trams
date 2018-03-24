#include "ligne.h"
#include <fstream>
#include "graphics.h"

void chargerLigne(ligne & l, const std::string & nomFichier)
{
    std::ifstream fin(nomFichier);
    int nbLignes, nbTram, nbArret, numTram;
    double vitesseMax, distMinTram, tempsRestantArret, distanceArret;
    bool vitesse, sensDeplacement;
    std::string nomArret, nomProchainArret, nomArretPrecedent;
    int dureeArret;
    pos positionArret;
    fin >> nbLignes;
    for(int i = 0 ; i<nbLignes ; ++i)
    {
        fin >> nbArret;
        for(int j = 0 ; j<nbArret ; ++j)
        {
            fin >> nomArret >> dureeArret >> positionArret.x >> positionArret.y;
            l.ajouterArret(nomArret, dureeArret, positionArret);
        }
        fin >> nbTram;
        for(int j = 0 ; j<nbTram ; ++j)
        {
            fin >> numTram >> vitesseMax >> vitesse >> distMinTram >> tempsRestantArret >> distanceArret >> sensDeplacement >> nomProchainArret >> nomArretPrecedent;
            l.ajouterTram(numTram, vitesseMax, vitesse, distMinTram, tempsRestantArret, distanceArret, sensDeplacement, l.chercherArret(nomProchainArret), l.chercherArret(nomArretPrecedent));
        }
    }
}

int main()
{
    ligne l;
    chargerLigne(l, "fichiertest.txt");
    opengraphsize(1000, 500);
    setbkcolor(WHITE);
    cleardevice();
    l.afficheArrets();
    getch();
}
