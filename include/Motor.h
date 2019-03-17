#include "Samochod.h"
#include <iostream>
#include <fstream>

#ifndef MOTOR_H
#define MOTOR_H


class Motor : public Samochod
{
    public:
        Motor();
        virtual ~Motor();

        // metody
        double podajPredkosc();
        void zamontujOwiewka();
        void wyswietlDaneSamochodu();
        void zapiszDaneDoPliku();
        string podajOwiewka();

    private:
        bool _czy_owiewka;
};

#endif // MOTOR_H
