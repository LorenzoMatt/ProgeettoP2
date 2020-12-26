#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "utente.h"
#include "model.h"
class Model;
class Account
{
    friend class Utente;
private:
    Utente* utente;
    Model* model;
    void sistema_amici_seguaci();
    void reverse_seguaci_amici();
public:
    Account();
    Account(Utente *, Model *);
           /* getter*/
    Profilo get_profilo() const;
    Accesso get_credenziali() const;
    container<Domanda*>& get_domande() const;
    Utente *get_utente() const;
    unsigned int get_punti() const;

    void aggiungi_amico(Utente *);
    void togli_amico(Utente*);
    void togli_seguace(Utente*);
    void AggiungiCompetenza(const string&); //OK
    void AggiungiTitoloDiStudio (const string&); //OK
    void dai_punti(Utente*) const;
    container<string> ricerca_utente(const string&);
    void cambia_piano(const string&);
    void fai_domanda(Domanda*);
    void modifica_credenziali(const string& username,const string& pw);
    void ricerca_domanda(const string&,container<Domanda*>);
    void fai_domanda(const string&,unsigned int);
    void fai_commento(Domanda* domanda,const string&) const;
    container<Domanda*> cerca_domanda(const string &) const;
    Utente* ricerca_contatto(const string&) const;
    container<Domanda*> visualizza_domande_amici() const;
};
#endif // ACCOUNT_H
