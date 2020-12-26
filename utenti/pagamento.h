#ifndef PAGAMENTO_H
#define PAGAMENTO_H
#include "utente.h"
class Model;
class Pagamento : public Utente
{
public:
    Pagamento()=delete;
    //Pagamento(const Pagamento&);
    Pagamento(string username,string password,string nome,string cognome,string email,unsigned int punti);
    Pagamento(Profilo p,Accesso c,container<Utente*> a,container<Utente*> s,container<Domanda*> d,unsigned int punti,unsigned int risposte);
    virtual Pagamento* clone() const=0;// va dichiarata altrimenti potremmo incorrere in errori di compilazione
    virtual void get_punti_bonus()=0;
    container<Domanda*> cerca_domanda(const string&,const Model&) const override;//OK per adesso contiene un container di domande, in utente basic la domanda viene cercata solo negli amici mentre negli account a pagamento nel modello
};

#endif // PAGAMENTO_H
