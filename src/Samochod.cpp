#include <fstream>
#include <string>
#include <iostream>
#include "Samochod.h"
using namespace std;




Samochod::Samochod()
{

    cout << endl << "Podaj marke samochodu: ";
    cin >> this->_marka;
    cout << endl << "Podaj model samochodu: ";
    cin >> this->_model;
    cout << endl << "Podaj rok produkcji: ";
    cin >> this->_rok_produkcji;
    cout << endl << "Podaj cene zakupu(zl): ";
    cin >> this->_cena_zakupu;
    cout << endl << "Podaj przebieg (km): ";
    cin >> this->_przebieg;
    cout << endl << "Podaj predkosc maksymalna: ";
    cin >> this->_predkosc;
}

Samochod::~Samochod()
{
    //dtor
}


//metody


void Samochod::wyswietlDaneSamochodu()
{
    cout << endl << "Typ pojazdu:           " << _typ_samochodu;
    cout << endl << "Marka:                 " << _marka;
    cout << endl << "Model:                 " << _model;
    cout << endl << "Rok produkcji:         " << _rok_produkcji;
    cout << endl << "Przebieg:              " << _przebieg;
    cout << endl << "Predkosc maksymalna:   " << this->podajPredkosc();
    cout << endl << "Wartosc:               " << this->podajWartosc();

}

void Samochod::zapiszDaneDoPliku()
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
    plik.close();
}

double Samochod::podajWartosc()
{
    if (this->_przebieg<100)
    {
        return _cena_zakupu*0.9;
    }else if(this->_przebieg<50000)
    {
        return _cena_zakupu*0.8;
    }else if(this->_przebieg<200000)
    {
        return _cena_zakupu*0.7;
    }else return _cena_zakupu*0.5;
}



