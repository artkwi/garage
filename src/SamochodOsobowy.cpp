#include "SamochodOsobowy.h"
#include <iostream>
SamochodOsobowy::SamochodOsobowy() : Samochod()
{
    _typ_samochodu = "Samochod osobowy";
    //ctor
}

SamochodOsobowy::~SamochodOsobowy()
{
    //dtor
}

void SamochodOsobowy::zapiszDaneDoPliku()
{
    fstream plik;
    plik.open("garaz.txt",ios::out | ios::app);
    plik << endl << "Typ pojazdu:           " << _typ_samochodu;
    plik << endl << "Marka:                 " << _marka;
    plik << endl << "Model:                 " << _model;
    plik << endl << "Rok produkcji:         " << _rok_produkcji;
    plik << endl << "Przebieg:              " << _przebieg;
    plik << endl << "Predkosc maksymalna:   " << this->podajPredkosc();
    plik << endl << "Wartosc:               " << this->podajWartosc();
    plik << endl;
    plik.close();
}
