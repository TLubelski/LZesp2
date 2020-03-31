#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Stats.hh"

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
  string trash;

  if (argc < 2) //Sprawdzenie czy podano argument
  {
    cerr << "[!]Blad: Podaj trudnosc: latwe/trudne" << endl;
    return 1;
  }

  fstream Plik_We; //strumien pliku wejsciowego

  if (BazaInit(argv[1], Plik_We) == false) //otwarcie pliku i sprawdzenie poprawnosci
  {
    cerr << "[!]Blad: Nie udalo sie otworzyc pliku z wybranym poziomem trudnosci" << endl;
    return 2;
  }

  //INFO
  cout << endl
       << "---- Start testu arytmetyki zespolonej ----" << endl;
  cout << "#Format odp: (a+-bi)" << endl;
  cout << "#Poziom: " << argv[1] << endl;

  WyrazenieZesp WyrZ_PytanieTestowe; // obiekty testowe
  LZespolona Odpowiedz;
  Stats Statyskyka = stats_init();

  while (!Plik_We.eof())
  { // Do konca pliku pobieraj pytania
    Plik_We >> WyrZ_PytanieTestowe;

    while (Plik_We.fail() && !Plik_We.eof())
    {
      cerr << endl
           << "[!]Niepoprawne wyrażenie w bazie, pomijam" << endl;
      Plik_We.clear();
      getline(Plik_We, trash);
      Plik_We >> WyrZ_PytanieTestowe;
    }

    if (!Plik_We.eof())
    {
      cout << endl
           << "-- Pytanie " << getWsz(Statyskyka) + 1 << " --" << endl; //wysw pytania
      cout << WyrZ_PytanieTestowe << endl;

      cout << "Odp.: "; // wczytanie odpowiedzi
      cin >> Odpowiedz;

      while (cin.fail()) //sprawdzenie poprawnosci odpowiedzi i ew ponowne wczytanie
      {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "!Zla forma, napisz jeszcze raz!\nOdp.: ";
        cin >> Odpowiedz;
      }

      if (Odpowiedz == Oblicz(WyrZ_PytanieTestowe)) //ocena odpowiedzi i zanotowanie statystyk
      {
        cout << "***Odp. DOBRA***" << endl;
        dodaj_dobra(Statyskyka);
      }
      else
      {
        cout << "***Odp. ZLA*** Poprawna to:  " << Oblicz(WyrZ_PytanieTestowe) << endl;
        dodaj_zla(Statyskyka);
      }
    }
  }

  Plik_We.close(); //zamkniecie pliku po pomyslnym tescie

  cout << endl
       << " Koniec testu" << endl; //zakonczenie testu i wysw statystyk
  cout << endl
       << Statyskyka << endl;
}
