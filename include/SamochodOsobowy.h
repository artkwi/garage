#include "Samochod.h"
#include <iostream>
#include <fstream>

#ifndef SAMOCHODOSOBOWY_H
#define SAMOCHODOSOBOWY_H


class SamochodOsobowy : public Samochod
{
    public:
        SamochodOsobowy();
        virtual ~SamochodOsobowy();

  void zapiszDaneDoPliku();


    private:
};



#endif // SAMOCHODOSOBOWY_H
