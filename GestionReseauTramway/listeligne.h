#ifndef LISTELIGNE_H
#define LISTELIGNE_H


class listeligne
{
    public:
        listeligne();
        ~listeligne();
        listeligne(const listeligne & liste);
        void ajouter( listearrets &la, listetramways &lt);
        void supprimer( listearrets &la, listetramways &lt);

    private:
        ligne *d_tete;
};

#endif // LISTELIGNE_H
