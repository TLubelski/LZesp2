#ifndef BAZATESTU_HH
#define BAZATESTU_HH


#include "WyrazenieZesp.hh"

#include <iostream>
#include <fstream>

enum Poziom_t {Trudny, Latwy};


struct BazaTestu{
  Poziom_t Trudnosc;
  std::fstream plik_wej;
};


bool BazaInit(const char *sNazwaTestu, std::fstream & strm_f);



//std::ostream & operator << (std::ostream & strm, const BazaTestu & BazaT);













/*
struct BazaTestu {
  WyrazenieZesp  *wskTabTestu;   
  unsigned int    IloscPytan;   
  unsigned int    IndeksPytania; 
};



bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char*  sNazwaTestu );

bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu,  WyrazenieZesp *wskWyr );
*/
#endif
