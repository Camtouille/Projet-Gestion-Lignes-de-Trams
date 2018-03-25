#ifndef LISTETRAMWAYS_H
#define LISTETRAMWAYS_H
#include "tramway.h"

class listeTramways ///liste des tramways triés par numéro de tramway
{
	public:
		listeTramways();
		listeTramways(const listeTramways & liste);
		~listeTramways();
		void ajouter(int numTram, ligne* li, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, arret *arretSuivant, arret *arretPrecedent);
		void supprimer(int num);
		tramway* chercher(int num) const;
		void affiche() const;
		void rafraichir();
	private:
		tramway *d_tete;
};

#endif // LISTETRAMWAYS_H
