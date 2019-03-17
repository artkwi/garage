#include <iostream>
#include <cstdlib>
#include <fstream>
#include <exception>

#include "Samochod.h"
#include "SamochodSportowy.h"
#include "SamochodCiezarowy.h"
#include "Motor.h"
#include "SamochodOsobowy.h"



using namespace std;


int wole_id=1;
Samochod * tablicaSamochod[50];

void dodajSamochodOsobowy()
{
    Samochod *s1 = new SamochodOsobowy();
    tablicaSamochod[wole_id++] = s1;
}

void dodajSamochodSportowy()
{
    Samochod *s1 = new SamochodSportowy();
    tablicaSamochod[wole_id++] = s1;
}

void dodajSamochodCiezarowy()
{
    Samochod *s1 = new SamochodCiezarowy();
    tablicaSamochod[wole_id++] = s1;
}

void dodajMotor()
{
    Samochod *s1 = new Motor();
    tablicaSamochod[wole_id++] = s1;
}

// Przegladanie garazu ************************************

void zobaczGaraz()
{
    for (int i=1;i<wole_id;i++)
    {
        cout << endl << endl << "Nr " << i ;
        tablicaSamochod[i]->wyswietlDaneSamochodu();
    }
}

// Usuwanie samochodu ****************************************

void usunSamochod()
{
    int ktory_usunac;
    zobaczGaraz();
    cout << endl << "Ktory samochod usunac? Podaj nr: ";
    cin >> ktory_usunac;
    for (int i=ktory_usunac;i<wole_id-1;i++)
    {
        tablicaSamochod[i]=tablicaSamochod[i+1];
    }
    delete tablicaSamochod[wole_id--];
}
int main()
{



    while(1)
    {
        int wybor_menu, wybor_pojazdu;
        cout << endl << "1 - dodaj pojazd do garazu";
        cout << endl << "2 - wyswietl pojazdy";
        cout << endl << "3 - usun pojazd";
        cout << endl << "4 - wybierz pojazd";
        cout << endl << "5 - zapisz stan garazu do pliku";
        cout << endl;
        cin >> wybor_menu;
        system("cls");
        switch (wybor_menu)
        {
        case 1:

            {
                cout << endl << "Dodaj: ";
                cout << endl << "1 - samochod osobowy";
                cout << endl << "2 - samochod sportowy";
                cout << endl << "3 - samochod ciezarowy";
                cout << endl << "4 - motor";
                cout << endl;
                cin >> wybor_pojazdu;
                system("cls");
                switch(wybor_pojazdu)
                {
                    case 1:
                        dodajSamochodOsobowy();
                        break;

                    case 2:
                        dodajSamochodSportowy();
                        break;

                    case 3:
                        dodajSamochodCiezarowy();
                        break;
                    case 4:
                        dodajMotor();
                        break;
                }
            }
            break;
        case 2:
            {
                cout << endl << "Stan garazu: ";
                zobaczGaraz();
            }
            break;
        case 3:
            {
                usunSamochod();
            }
            break;
        case 4:
            {


                zobaczGaraz();

                cout << endl << "Wybierz samochod: ";
                int ktory_wybrac,montaz;
                cin >> ktory_wybrac;
                cout << endl;
                system("cls");

                tablicaSamochod[ktory_wybrac]->wyswietlDaneSamochodu();
                cout << endl << "Dostepne modyfikacje:";

                if (tablicaSamochod[ktory_wybrac]->podajTyp()=="Samochod sportowy")
                {
                    cout << endl << "1 - montaz/demontaz nitro" << endl;
                    cin >> montaz;
                    if (montaz==1) dynamic_cast<SamochodSportowy*>(tablicaSamochod[ktory_wybrac])->zamontujNitro();
                } else if (tablicaSamochod[ktory_wybrac]->podajTyp()=="Samochod ciezarowy")
                {
                    cout << endl << "1 - zaczep/odczep naczepe" << endl;
                    cin >> montaz;
                    if (montaz==1) dynamic_cast<SamochodCiezarowy*>(tablicaSamochod[ktory_wybrac])->zamontujNaczepa();
                } else if (tablicaSamochod[ktory_wybrac]->podajTyp()=="Motor")
                {
                   cout << endl << "1 - zamontuj/zdemontuj owiewke" << endl;
                    cin >> montaz;
                    if (montaz==1) dynamic_cast<Motor*>(tablicaSamochod[ktory_wybrac])->zamontujOwiewka();
                }
                else cout << endl << "Brak";


            }
            break;
        case 5:
            {
                fstream plik;
                plik.open("garaz.txt", ios::out);

                plik.close();

                    for (int i=1;i<wole_id;i++)
                    {
                        //dynamic_cast <SamochodOsobowy*>(tablicaSamochod[i])->zapiszDaneDoPliku();
                        //tablicaSamochod[i]->zapiszDaneDoPliku();


                        if (tablicaSamochod[i]->podajTyp()=="Samochod sportowy")
                        {
                            dynamic_cast<SamochodSportowy*>(tablicaSamochod[i])->zapiszDaneDoPliku();
                        } else if (tablicaSamochod[i]->podajTyp()=="Samochod ciezarowy")
                        {
                        dynamic_cast<SamochodCiezarowy*>(tablicaSamochod[i])->zapiszDaneDoPliku();
                        } else if (tablicaSamochod[i]->podajTyp()=="Motor")
                        {
                        dynamic_cast<Motor*>(tablicaSamochod[i])->zapiszDaneDoPliku();
                        }else
                            dynamic_cast<SamochodOsobowy*>(tablicaSamochod[i])->zapiszDaneDoPliku();


                    }


                    cout << "Zapisano!";

            }
            break;
        }
    }


    //SamochodCiezarowy s2;


    //cout << endl << s2.podajPredkosc();


    /*catch(logic_error obj)
    {
        cout << "Zly typ danych!";
    }
          //koniec try
*/
    return 0;
}
