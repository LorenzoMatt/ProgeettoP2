#ifndef BASIC_H
#define BASIC_H
#include "utente.h"
class Model;
class Basic : public Utente
{
private:
    static unsigned int puntiPerDomandaData;
    static unsigned int puntiDetrattiDomandaFatta;
    static unsigned int supplementoDomandaPriorita;
    static unsigned int puntiBonus;
public:
    ~Basic();
    Basic() =delete;
    Basic(string username,string password,string nome,string cognome,string email);
    Basic(Profilo p,Accesso c,container<Utente*> a,container<Utente*> s,container<Domanda*> d,unsigned int punti,unsigned int risposte);
    void cerca_utente(const string&,const Model&, container<string>&) const override;//OK
    void fai_domanda(Domanda*);//OK
    container<Domanda*> cerca_domanda(const string&,const Model&) override;//OK per adesso contiene un container di domande, in utente basic la domanda viene cercata solo negli amici mentre negli account a pagamento nel modello
    void get_punti_domanda() override; //OK
    Basic* clone() const override;//OK
};
#endif // BASIC_H
