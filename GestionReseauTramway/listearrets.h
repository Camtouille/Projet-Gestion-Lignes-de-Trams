#ifndef LISTEARRETS_H
#define LISTEARRETS_H
#include "arret.h"


class listeArrets ///liste des arr�ts tri�s par ordre alphab�tique
{
    friend class ligne;
	public:
		listeArrets();
		listeArrets(const listeArrets & liste);
		~listeArrets();
		void ajouter(std::string nom, int dureeArret, pos position);
		void supprimer(std::string nom);
		arret* chercher(std::string nom) const;
		void afficher() const;
	private:
		arret *d_tete;
};

#endif // LISTEARRETS_H
