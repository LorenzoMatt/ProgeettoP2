#ifndef PREMIUM_H
#define PREMIUM_H

#include "pagamento.h"
class Premium : public Pagamento
{
private:
    static unsigned int puntiPerDomandaData;
    static unsigned int puntiDetrattiDomandaFatta;
    static unsigned int limiteDomandeVisualizzate;
    static unsigned int puntiBonus;
    static unsigned int limitePerAverePuntiBonus;
    static unsigned int supplementoDomandaPriorita;
public:
    Premium()=delete;
    //Premium(const Premium &);
    Premium(string username,string password,string nome,string cognome,string email, unsigned int=puntiBonus, unsigned int = 0);
    Premium(Profilo p,Accesso c,container<Utente*> a,container<Utente*> s,container<Domanda*> d,unsigned int punti,unsigned int risposte);
    void cerca_utente(const string&,const Database&, container<string>&) const override;//OK quando implementeremo le classi polimorfe dovrà andare tolto l'ultimo intero da passare alla funzione
    void get_punti_domanda() override; //OK
    void fai_domanda(Domanda* domanda) override;//OK
    void get_punti_bonus() override;//OK
    Premium* clone() const override;//OK
};

#endif // PREMIUM_H
