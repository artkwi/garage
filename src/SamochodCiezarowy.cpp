#include "SamochodCiezarowy.h"

SamochodCiezarowy::SamochodCiezarowy():Samochod()
{
    _typ_samochodu = "Samochod ciezarowy";

    char naczepa;
    cout << endl << "Czy posiada naczepe (T/N): ";
    cin >> naczepa;
    if ((naczepa=='t')||(naczepa=='T')) this->_czy_naczepa = true;//cout << "Jest naczepa";
    else this->_czy_naczepa = false;//cout << "Nie ma naczepy";
}


SamochodCiezarowy::~SamochodCiezarowy()
{
    //dtor
}


//  metody

void SamochodCiezarowy::zamontujNaczepa()
{
    _czy_naczepa = !_czy_naczepa;
}


string SamochodCiezarowy::podajNaczepa()
{
    if (_czy_naczepa) return "TAK";
    else return "NIE";
}

double SamochodCiezarowy::podajPredkosc()
{
    if(this->_czy_naczepa) return this->_predkosc*0.6;
    else return this->_predkosc;
}

void SamochodCiezarowy::wyswietlDaneSamochodu()
{
    Samochod::wyswietlDaneSamochodu();
    if (_czy_naczepa)
    cout << endl << "Naczepa:               TAK";
    else cout << endl << "Naczepa:               NIE";
}

void SamochodCiezarowy::zapiszDaneDoPliku()
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
    plik << endl << "Naczepa:               " << this->podajNaczepa();
    plik << endl;
    plik.close();
}
