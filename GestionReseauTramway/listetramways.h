#ifndef LISTETRAMWAYS_H
#define LISTETRAMWAYS_H


class listeTramways ///liste des tramways triés par numéro de tramway
{
	public:
		listeTramways();
		listeTramways(const listeTramways & liste);
		~listeTramways();
		void ajouter(int numTram, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, const std::string nomProchainArret);
		void supprimer(int num);
		tramway* chercher(int num) const;
	private:
		tramway *tete;
};

#endif // LISTETRAMWAYS_H
