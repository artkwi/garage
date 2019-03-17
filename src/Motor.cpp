#include "Motor.h"

Motor::Motor():Samochod()
{
    _typ_samochodu = "Motor";

    char owiewka;
    cout << endl << "Czy posiada owiewke (T/N): ";
    cin >> owiewka;
    if ((owiewka=='t')||(owiewka=='T')) this->_czy_owiewka = true;//cout << "Jest naczepa";
    else this->_czy_owiewka = false;
    //ctor
}

Motor::~Motor()
{
    //dtor
}


double Motor::podajPredkosc()
{
    if(this->_czy_owiewka) return this->_predkosc*1.1;
    else return this->_predkosc;
}

void Motor::zamontujOwiewka()
{
    _czy_owiewka = !_czy_owiewka;
}

void Motor::wyswietlDaneSamochodu()
{
    Samochod::wyswietlDaneSamochodu();
    if (_czy_owiewka)
    cout << endl << "Owiewka:               TAK";
    else cout << endl << "Owiewka:               NIE";
}

string Motor::podajOwiewka()
{
    if(_czy_owiewka) return "TAK";
    else return "NIE";
}

void Motor::zapiszDaneDoPliku()
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
    plik << endl << "Owiewka:               " << this->podajOwiewka();
    plik << endl;
    plik.close();
}

