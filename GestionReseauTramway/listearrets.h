#ifndef LISTEARRETS_H
#define LISTEARRETS_H
#include "arret.h"
#include <vector>


class listeArrets
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
		std::vector<pos> CoordsArrets() const;
		void afficherNomArrets() const;
	private:
		arret *d_tete;
};

#endif // LISTEARRETS_H
