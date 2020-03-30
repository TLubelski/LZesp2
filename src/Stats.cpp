#include "Stats.hh"

using std::cout;
using std::endl;


Stats stats_init()
{
    Stats temp;
    temp.odp_dobre = 0;
    temp.odp_wsz = 0;
    return temp;
}


void dodaj_dobra(Stats & stat)
{
    stat.odp_dobre++;
    stat.odp_wsz++;
}


void dodaj_zla(Stats & stat)
{
    stat.odp_wsz++;
}


std::ostream & operator << (std::ostream & strm, const Stats & stat)
{
    strm << "--Statystyki--" << endl;
    strm << "*Dobrych: " << stat.odp_dobre << endl; 
    strm << "*Zlych: " << stat.odp_wsz-stat.odp_dobre << endl;
    strm << "*Wynik: " << ((stat.odp_dobre/stat.odp_wsz)*100) << "%" << endl; 
    return strm;
}

int getWsz(Stats stat)
{
    return stat.odp_wsz;
}