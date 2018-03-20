#ifndef LISTEARRETS_H
#define LISTEARRETS_H


class listeArrets ///liste des arrêts triés par ordre alphabétique
{
	public:
		listeArrets();
		listeArrets(const listeArrets & liste);
		~listeArrets();
		void ajouter(std::string nom, int dureeArret, pos position);
		void supprimer(std::string nom);
		arret* chercher(std::string nom) const;
	private:
		arret *d_tete;
};

#endif // LISTEARRETS_H
