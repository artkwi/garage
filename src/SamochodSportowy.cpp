#include <iostream>

#include "SamochodSportowy.h"

using namespace std;

SamochodSportowy::SamochodSportowy() : Samochod()
{
    _typ_samochodu = "Samochod sportowy";
    this->_czy_nitro = false;

}

SamochodSportowy::~SamochodSportowy()
{

    //dtor
}


//metody

void SamochodSportowy::zamontujNitro()
{
    _czy_nitro = !(_czy_nitro);
}

double SamochodSportowy::podajPredkosc()
{
    if (_czy_nitro)
    {
        return this->_predkosc*1.1;
    }
    else
    {
    return this->_predkosc;}
}

string SamochodSportowy::podajNitro()
{
    if (_czy_nitro) return "TAK";
    else return "NIE";
}
/*double SamochodSportowy::podajWartosc()
{
    return this->SamochodSportowy::_cena_zakupu*0.9;
}*/

void SamochodSportowy::wyswietlDaneSamochodu()
{
    Samochod::wyswietlDaneSamochodu();
    if (_czy_nitro)
            cout << endl << "Nitro:                 TAK";
    else    cout << endl << "Nitro:                 NIE";
}


void SamochodSportowy::zapiszDaneDoPliku()
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
    plik << endl << "Nitro:                 " << this->podajNitro();
    plik << endl;
    plik.close();
}
