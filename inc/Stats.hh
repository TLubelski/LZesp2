#ifndef STATS_HH
#define STATS_HH

#include <iostream>


struct Stats
{
    int odp_dobre; 
    int odp_wsz;
};

Stats stats_init();

void dodaj_dobra(Stats & stat);

void dodaj_zla(Stats & stat);

void wysw_stat(Stats stat);

std::ostream & operator << (std::ostream & strm, const Stats & stat);

int getWsz(Stats stat);

#endif