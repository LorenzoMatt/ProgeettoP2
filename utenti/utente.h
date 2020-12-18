#ifndef UTENTE_H
#define UTENTE_H
#include "container.h"
#include "profilo.h"
#include "accesso.h"
#include "domanda.h"
#include "model.h"
#include "amico_non_presente.h"
#include "non_autore_domanda.h"
#include <list>
using std::list;
class Domanda;
class Utente
{
    friend std::ostream& operator<<(std::ostream& os,const Utente& u);
private:
    Accesso* credenziali;
    Profilo* pf;
    unsigned int punti=0;
    container<Utente*> amici;
    container<Utente*> seguaci;
    unsigned int risposte_date=0;
    void aggiungi_seguace(Utente& utente);
    container<Domanda*> domande;
    void togli_amico_ausiliario(Utente* utente);
    void togli_seguace_ausiliario(Utente* utente);
public:
    Utente();
    Utente(string username,string password,string nome,string cognome,string email);
    Profilo& get_profilo() const;//OK
    Accesso& get_credenziali() const;//OK
    unsigned int get_punti() const;//OK
    void fai_domanda(Domanda& domanda);
    //void fai_domanda(const string& domanda,unsigned int priorita=0);
    void aggiungi_amico(Utente& utente);
    void togli_amico(Utente* utente);
    void togli_seguace(Utente* utente);
    const container<Utente*>& get_amici() const ;
    const container<Utente*>& get_seguaci() const;
    const container<Domanda*>& get_domande() const;
    void set_profilo(const string&);

};

#endif // UTENTE_H
