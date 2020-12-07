#ifndef USER_H
#define USER_H

#include "profilo.h"

#include <iostream>

class user
{
private:
    profilo p;
    //rete* r;
    //username u;
public:
   // virtual rete* RicercaUtente() const=0;
    void SetLingue(int*,int);
    void StampaUtente(){p.StampaProfilo();}

};

#endif // USER_H
