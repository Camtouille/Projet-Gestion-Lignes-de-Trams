#ifndef TRAMWAY_H
#define TRAMWAY_H


class tramway
{
    friend class listeTramways;
    public:
        tramway(int num, ligne* li, double vitMax, bool vit, double distTram, double tArret, double distArret, bool sens, arret* arretSuivant);
        pos GetPosition() const;
    private:
        int d_numeroTram;
		ligne *d_ligne; ///ligne sur laquelle roule le tramway
		double d_vitesseMax;
		bool d_vitesse;
		double d_distanceMiniTram; ///distance minimale avec le tramway de devant
		double d_tempsRestantArret; ///temps pass� sur l'arr�t, -1.0 si il n'est pas sur un arr�t
		double d_distanceArret; ///distance qui s�pare le tramway du prochain arret
		bool d_sensDeplacement;
		arret *d_arret;///prochain arret (si le tram est sur un arret, cet arret)
		tramway *d_suiv;
};

#endif // TRAMWAY_H
