#include <string>

#ifndef SAMOCHOD_H
#define SAMOCHOD_H

using namespace std;

class Samochod
{

    public:
        //metody


        Samochod();

        void DodajSamochod();
        virtual ~Samochod();


        //metody

        string podajTyp()   {return this->_typ_samochodu;}
        string podajMarka() {return this->_marka;}
        string podajModel() {return this->_model;}
        int podajRokProdukcji() {return this->_rok_produkcji;}
        double podajCenaZakupu() {return this->_cena_zakupu;}
        //int podajId() {return this->_id;}
        double podajPrzebieg() {return this->_przebieg;}


        //metody wirtualne

        virtual double podajWartosc();
        virtual double podajPredkosc()      {return this->_predkosc;}
        virtual void wyswietlDaneSamochodu();
        virtual void zapiszDaneDoPliku();

    protected:

        // atrybuty

        string _typ_samochodu;
        string _marka;
        string _model;
        int _rok_produkcji;
        double _cena_zakupu;
        //int _id;
        int _przebieg;
        double _predkosc;

};





#endif // SAMOCHOD_H
