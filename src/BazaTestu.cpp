#include <cstring>
#include <cassert>
#include "BazaTestu.hh"

using namespace std;

bool BazaInit(const char *sNazwaTestu, fstream &strm_f)
{
  string sciezkaPliku = sNazwaTestu;
  sciezkaPliku = "pliki_testow/" + sciezkaPliku + ".dat";

  strm_f.open(sciezkaPliku, ios::in);

  if (strm_f.good())
    return true;
  else
    return false;
}

/*
static WyrazenieZesp  TestLatwy[] =
  { {{2,1}, Op_Dodaj, {1,2}},
    {{1,0}, Op_Odejmij, {0,1}},
    {{3,0}, Op_Mnoz, {0,3}},
    {{4,8}, Op_Dziel, {1,0}},
  };


static WyrazenieZesp  TestTrudny[] =
  { {{12,11}, Op_Dodaj, {19,22}},
    {{31,10}, Op_Odejmij, {15,9}},
    {{7,8}, Op_Mnoz, {3,2}},
    {{10,11}, Op_Dziel, {12,5}},
  };



void UstawTest( BazaTestu *wskBazaTestu, WyrazenieZesp *wskTabTestu, unsigned int IloscPytan )
{
  wskBazaTestu->wskTabTestu = wskTabTestu;
  wskBazaTestu->IloscPytan = IloscPytan;
  wskBazaTestu->IndeksPytania = 0;
}




bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char *sNazwaTestu )
{
  if (!strcmp(sNazwaTestu,"latwy")) {
    UstawTest(wskBazaTestu,TestLatwy,sizeof(TestLatwy)/sizeof(WyrazenieZesp));
    return true;
  }
  else if (!strcmp(sNazwaTestu,"trudny")) {
    UstawTest(wskBazaTestu,TestTrudny,sizeof(TestTrudny)/sizeof(WyrazenieZesp));
    return true;
  }

  cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
  return false;
}

bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu, WyrazenieZesp *wskWyrazenie )
{
  if (wskBazaTestu->IndeksPytania >= wskBazaTestu->IloscPytan) return false;

  *wskWyrazenie = wskBazaTestu->wskTabTestu[wskBazaTestu->IndeksPytania];
  ++wskBazaTestu->IndeksPytania;
  return true;
}
*/