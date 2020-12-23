#ifndef GOLD_H
#define GOLD_H
#include "pagamento.h"

class Gold : public Pagamento
{
private:
    static unsigned int puntiPerDomandaData;
    static unsigned int puntiDetrattiDomandaFatta;
    static unsigned int limiteDomandeVisualizzate;
    static unsigned int puntiBonus;
    static unsigned int supplementoDomandaPriorita;
    static unsigned int limitePerAverePuntiBonus;
public:
    Gold();// =delete
    Gold(string username,string password,string nome,string cognome,string email,unsigned int punti=puntiBonus);
    void cerca_utente(const string&,const Model&, container<string>&) const;//OK quando implementeremo le classi polimorfe dovrà andare tolto l'ultimo intero da passare alla funzione
    void get_punti_domanda(); //virtual
    void fai_domanda(Domanda* domanda);
    void get_punti_bonus();
    Gold* clone();
};

#endif // GOLD_H
