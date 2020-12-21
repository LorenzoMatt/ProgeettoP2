#ifndef BASIC_H
#define BASIC_H
#include "utente.h"

class basic : public Utente
{
private:
    static unsigned int limitePerAverePuntiBonus;
    static unsigned int puntiPerDomandaData;
    static unsigned int puntiDetrattiDomandaFatta;
    static unsigned int limiteDomandeVisualizzate;
    static unsigned int puntiBonus;
public:
    basic(string username,string password,string nome,string cognome,string email,unsigned int punti=puntiBonus);
    void cerca_utente(const Model&, const string&, container<string>&,int) const;
};
#endif // BASIC_H
