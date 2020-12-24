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
public:
    Premium();// =delete
    Premium(string username,string password,string nome,string cognome,string email,unsigned int punti=puntiBonus);
    Premium(Profilo p,Accesso c,container<Utente*> a,container<Utente*> s,container<Domanda*> d);
    void cerca_utente(const string&,const Model&, container<string>&) const;//OK quando implementeremo le classi polimorfe dovrà andare tolto l'ultimo intero da passare alla funzione
    void get_punti_domanda(); //virtual
    void fai_domanda(Domanda* domanda);
    void get_punti_bonus();
    Premium* clone() const;
};

#endif // PREMIUM_H
