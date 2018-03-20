#ifndef ARRET_H
#define ARRET_H


class arret
{
    friend class listeArrets;
    public:
        arret(const std::string & nom, int dureeArret, const pos & position);
    private:
        std::string d_nom;
        int d_dureeArret;
        pos d_position;
        arret *d_suiv;
};

#endif // ARRET_H
