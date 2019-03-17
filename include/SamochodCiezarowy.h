#include "Samochod.h"
#include <iostream>
#include <fstream>

#ifndef SAMOCHODCIEZAROWY_H
#define SAMOCHODCIEZAROWY_H


class SamochodCiezarowy : public Samochod
{
    public:
        SamochodCiezarowy();
        virtual ~SamochodCiezarowy();

        //metody

        void zamontujNaczepa();
        double podajPredkosc();
        void wyswietlDaneSamochodu();
        void zapiszDaneDoPliku();
        string podajNaczepa();

    private:
        bool _czy_naczepa;
};

#endif // SAMOCHODCIEZAROWY_H
