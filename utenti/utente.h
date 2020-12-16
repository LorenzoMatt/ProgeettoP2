#ifndef UTENTE_H
#define UTENTE_H
#include "container.h"
#include "profilo.h"
#include "accesso.h"
#include "domanda.h"
#include "model.h"
#include "amico_non_presente.h"
#include <list>
using std::list;
class Domanda;
class Utente
{
    friend std::ostream& operator<<(std::ostream& os,const Utente& u);
private:
    Accesso credenziali;
    Profilo pf;
    unsigned int punti=0;
    container<Utente*> amici;
    container<Utente*> seguaci;
    unsigned int risposte_date;
    container<Domanda*> domande;
    void aggiungi_seguace(Utente*);
public:
    Utente();
    Utente(string username,string password,string nome,string cognome,string email);
    Profilo get_profilo() const;//OK
    Accesso get_credenziali() const;//OK
    unsigned int get_punti() const;//OK
    void fai_domanda(const string& domanda);
    void aggiungi_amico(Utente* utente);
    void togli_amico(Utente* utente);
    container<Utente *> get_amici() const;
    container<Utente*> get_seguaci() const;

};

#endif // UTENTE_H
