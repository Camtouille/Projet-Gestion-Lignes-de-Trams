#ifndef LIGNE_H
#define LIGNE_H
#include <vector>
#include <iostream>
#include "global.h"
#include "listearrets.h"
#include "listetramways.h"

class ligne
{
	friend class listeligne;
	public:
		ligne();
		ligne(const ligne & l);
		std::vector<pos> GetPosArret();
		void ajouterArret(std::string nom, int dureeArret, pos position);
		void ajouterTram(int numTram, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, arret *arretSuivant, arret *arretPrecedent);
		arret* chercherArret(std::string nom);
		tramway* chercherTramway(int num);
		void afficheArrets() const;
		void affiche() const;

	private:
		listeArrets arrets;
		listeTramways tramways;
		ligne *d_suiv;
};

#endif // LIGNE_H
