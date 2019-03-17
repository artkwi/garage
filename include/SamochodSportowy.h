#include "Samochod.h"
#include <iostream>
#include <fstream>
#ifndef SAMOCHODSPORTOWY_H
#define SAMOCHODSPORTOWY_H


class SamochodSportowy : public Samochod
{
    public:
        SamochodSportowy();
        virtual ~SamochodSportowy();

        //metody wirtualne

        //double podajWartosc();
        string podajNitro();
        void zamontujNitro();
        double podajPredkosc();
        bool czyNitro() {return this->_czy_nitro;}
        void wyswietlDaneSamochodu();
        void zapiszDaneDoPliku();

    private:
        bool _czy_nitro;
};

#endif // SAMOCHODSPORTOWY_H
