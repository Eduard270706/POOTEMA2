#ifndef ECHIPA_H_INCLUDED
#define ECHIPA_H_INCLUDED

#include <vector>
#include <string>
#include <memory>
#include "Jucator.h"
#include <iostream>

class Echipa
{
    std::vector<std::shared_ptr<Jucator>> lot;
    std::string nume;
    int victorii;
    int egaluri;
    int infrangeri;
    int goluri_date;
    int goluri_primite;
    int puncte;
public:
    Echipa(const std::string& nume="");
    Echipa(const Echipa& e);
    Echipa& operator =(Echipa e);

    friend void swap(Echipa& e1,Echipa& e2);

    const std::vector<std::shared_ptr<Jucator>> getlot()const;

    void adaugajucator(const std::shared_ptr<Jucator>&j);

    std::string getnume()const;

    int getvictorii()const;

    int getegaluri()const;

    int getinfrangeri()const;

    int getgoluri_date()const;

    int getgoluri_primite()const;

    int getpuncte()const;

    int getgolaveraj()const;

    int getmeciuri()const;

    double performanta_medie()const;

    static std::shared_ptr<Jucator> celmaibun(const std::vector<std::shared_ptr<Jucator>>& lot);

    int numar_atacanti()const;

    int numar_mijlocasi()const;

    int numar_fundasi()const;

    int numar_portari()const;

    void afisarelot()const;

    void actualizeazastatistici(int goluriinscrise,int goluriluate);

    static Echipa citeste_echipa(std::istream& f);

};

#endif
