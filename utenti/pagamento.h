#ifndef PAGAMENTO_H
#define PAGAMENTO_H
#include "utente.h"

class Pagamento : public Utente
{
public:
    Pagamento();
    void get_punti_bonus(); //dovrà essere virtuale
    void cerca_utente(const string&,const Model&, container<string>&,int) const;//OK quando implementeremo le classi polimorfe dovrà andare tolto l'ultimo intero da passare alla funzione
    void get_punti_domanda(); //virtual
    container<Domanda*> cerca_domanda(const string&,const Model&);//OK per adesso contiene un container di domande, in utente basic la domanda viene cercata solo negli amici mentre negli account a pagamento nel modello
    void fai_domanda(Domanda* domanda);
    //virtual Pagamento* clone() const;
};

#endif // PAGAMENTO_H
