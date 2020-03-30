#include "WyrazenieZesp.hh"

/* I/O */

std::istream & operator >> (std::istream & strm, WyrazenieZesp & WyrZ)
{
  char temp;

  strm >> WyrZ.Arg1; //Wczytanie 1 arg
  
  strm >> temp;    //Wczytanie znaku 
  switch (temp)
  {
    case '+':
      WyrZ.Op = Op_Dodaj;
      break;
    
    case '-':
      WyrZ.Op = Op_Odejmij;
      break;

    case '*':
      WyrZ.Op = Op_Mnoz;
      break;

    case '/':
      WyrZ.Op = Op_Dziel;
      break;

    default:
      strm.setstate(std::ios::failbit);
      break;
  }

  strm >> WyrZ.Arg2; //Wczytanie 2 arg

  return strm;
}


std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & WyrZ)
{
  strm << WyrZ.Arg1;
  
  switch ( WyrZ.Op )
  {
  case Op_Dodaj:
    strm << " + ";
    break;
  
  case Op_Odejmij:
    strm << " - ";
    break;

  case Op_Mnoz:
    strm << " * ";
    break;

  case Op_Dziel:
    strm << " / ";
    break;
  }

  strm << WyrZ.Arg2;

  return strm;
}
  

/* Praca */

LZespolona Oblicz(WyrazenieZesp  WyrZ){
  
  switch(WyrZ.Op)
    {
    case Op_Dodaj:
      return WyrZ.Arg1 + WyrZ.Arg2;
      break;

    case Op_Odejmij:
      return WyrZ.Arg1 - WyrZ.Arg2;
      break;

    case Op_Mnoz:
      return WyrZ.Arg1 * WyrZ.Arg2;
      break;

    case Op_Dziel:
      return WyrZ.Arg1 / WyrZ.Arg2;
      break;
    
    default:
      return utworzLZ(0,0);
      break;
    }

}
