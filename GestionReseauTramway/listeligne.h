#ifndef LISTELIGNE_H
#define LISTELIGNE_H


class listeligne
{
    public:
        listeligne();
        ~listeligne();
        listeligne(const listeligne & liste);
        void ajouter();

    private:
        ligne *d_tete;
};

#endif // LISTELIGNE_H
