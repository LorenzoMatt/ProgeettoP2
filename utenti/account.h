#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "utente.h"
#include "model.h"
class Model;
class Account
{
private:
    Utente* utente;
    Model* model;
public:
    Account();
    Account(Utente *, Model *);
           /* getter*/
    Profilo get_profilo() const;
    Accesso get_credenziali() const;
    container<Domanda*>& get_domande() const;
    Utente *get_utente() const;
    unsigned int get_punti() const;
            /*funzioni*/
    void aggiungi_amico(Utente *);
    void togli_amico(Utente*);
    void togli_seguace(Utente*);
    void AggiungiCompetenza(const string&); //OK
    void AggiungiTitoloDiStudio (const string&); //OK
    void dai_punti(Utente*) const;
    container<string> ricerca_utente(const string&); //OK
    void cambia_piano(const string&); //OK
    void modifica_password(const string&);
    container<Domanda *> ricerca_domanda(const string&);
    void fai_domanda(const string&,unsigned int);
    void fai_commento(Domanda* domanda,const string&) const;
    container<std::string> ricerca_contatto(const string&) const;
    container<Domanda*> get_domande_amici() const;
};
#endif // ACCOUNT_H
