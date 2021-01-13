#ifndef PAGAMENTO_H
#define PAGAMENTO_H
#include "utente.h"
class Database;
class Pagamento : public Utente
{
public:
    Pagamento()=delete;
    Pagamento(string username,string password,string nome,string cognome,string email,unsigned int punti,unsigned int risposte);
    Pagamento(Profilo p,Accesso c,container<Utente*> a,container<Utente*> s,unsigned int punti,unsigned int risposte);
    virtual Pagamento* clone() const override=0;// va dichiarata altrimenti potremmo incorrere in errori di compilazione
    virtual void get_punti_bonus()=0;
    container<Domanda*> cerca_domanda(const string&,const Database&) const override;
};

#endif // PAGAMENTO_H
