#ifndef PREMIUM_H
#define PREMIUM_H

#include "pagamento.h"
class Premium : public Pagamento
{
private:
    static unsigned int puntiPerDomandaData;
    static unsigned int puntiDetrattiDomandaFatta;
    static unsigned int puntiBonus;
    static unsigned int limitePerAverePuntiBonus;
    static unsigned int supplementoDomandaPriorita;
public:
    Premium()=delete;
    Premium(string username,string password,string nome,string cognome,string email, unsigned int=puntiBonus, unsigned int = 0);
    Premium(Profilo p,Accesso c,container<Utente*> a,container<Utente*> s,unsigned int punti,unsigned int risposte);
    void cerca_utente(const string&,const Database&, container<string>&) const override; //quando implementeremo le classi polimorfe dovrà andare tolto l'ultimo intero da passare alla funzione
    void get_punti_domanda() override; 
    void fai_domanda(Domanda* domanda) override;
    void get_punti_bonus() override;
    Premium* clone() const override;
    string piano() const override;

};

#endif // PREMIUM_H
