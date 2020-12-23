#ifndef PAGAMENTO_H
#define PAGAMENTO_H
#include "utente.h"

class Pagamento : public Utente
{
public:
    Pagamento();
    // virtual void get_punti_bonus()=0; //dovrà essere virtuale
    // virtual void cerca_utente(const string&,const Model&, container<string>&,int) const=0;//OK quando implementeremo le classi polimorfe dovrà andare tolto l'ultimo intero da passare alla funzione
    //virtual void get_punti_domanda()=0;
    container<Domanda*> cerca_domanda(const string&,const Model&);//OK per adesso contiene un container di domande, in utente basic la domanda viene cercata solo negli amici mentre negli account a pagamento nel modello
    //void fai_domanda(Domanda* domanda);
    //virtual Pagamento* clone() const;
};

#endif // PAGAMENTO_H
