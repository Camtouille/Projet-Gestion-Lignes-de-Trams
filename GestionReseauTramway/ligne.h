#ifndef LIGNE_H
#define LIGNE_H
class arret;
class listeArrets;
class listeTramways;

class ligne
{
	public:
		ligne();
		ligne(const ligne & l);
		std::vector<pos> GetPosArret();
		void ajouterArret(std::string nom, int dureeArret, pos position);
		void ajouterTram(int numTram, double vitesseMax, bool vitesse, double distanceMiniTram, double tempsArret, double distanceArret, bool sensDeplacement, const std::string nomProchainArret);
		double distance(const arret & a1, const arret & a2);
		double distance(const tramway & t1, const arret & a2);
		double distance(const tramway & t1, const tramway & t2);
	private:
		listeArrets arrets;
		listeTramways tramways;
};

#endif // LIGNE_H
