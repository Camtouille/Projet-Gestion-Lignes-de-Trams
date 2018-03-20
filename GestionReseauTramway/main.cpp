#include "global.h"

void chargerLigne(ligne & l, const std::string & nomFichier)
{
    std::ifstream fin(nomFichier);
    int nbLignes, nbTram, nbArret, numTram;
    double vitesseMax, distMinTram, tempsRestantArret, distanceArret;
    bool vitesse, sensDeplacement;
    std::string nomArret, nomProchainArret;
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
            fin >> numTram >> vitesseMax >> vitesse >> distMinTram >> tempsRestantArret >> distanceArret >> sensDeplacement >> nomProchainArret;
            l.ajouterTram(numTram, vitesseMax, vitesse, distMinTram, tempsRestantArret, distanceArret, sensDeplacement, nomProchainArret);
        }
    }
}

int main()
{
    opengraphsize(200, 200);
}
