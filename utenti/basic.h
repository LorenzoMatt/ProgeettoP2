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
    Basic(string username,string password,string nome,string cognome,string email,unsigned int punti=puntiBonus);
    Basic(Profilo p,Accesso c,container<Utente*> a,container<Utente*> s,container<Domanda*> d);
    void cerca_utente(const Model&, const string&, container<string>&) const;
    void fai_domanda(Domanda*);
    container<Domanda*> cerca_domanda(const string&,const Model&);//OK per adesso contiene un container di domande, in utente basic la domanda viene cercata solo negli amici mentre negli account a pagamento nel modello
    void get_punti_domanda(); //virtual
    Basic* clone() const;
};
#endif // BASIC_H
