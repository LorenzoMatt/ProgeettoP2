#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "utente.h"
class Account
{
private:
    Utente* utente;
    Database* model;
public:
    ~Account();
    Account()=delete;
    Account(const string&);
    Account(Utente *, Database *);
           /* getter*/
    Profilo &get_profilo() const;
    Accesso get_credenziali() const;
    const container<Domanda *> &get_domande() const;
    Utente *get_utente() const;
    unsigned int get_punti() const;
    container<Domanda *> get_domande_amici() const;
    string get_piano() const;



    //aggiungi
    void aggiungi_amico(Utente *);
    void AggiungiCompetenza(const string&);
    void AggiungiTitoloDiStudio (const string&);

    void fai_domanda(const string&,unsigned int =1);
    void fai_commento(Domanda* domanda,const string&);

    //togli
    void togli_amico(Utente*);

    //dai
    void dai_punti(const string &) const;

    //modifica
    void cambia_piano(const string&);
    void modifica_password(const string&);

    void salva() const;

    //cerca
    Utente* cerca_utente_per_nome(const string&) const;
    container<Domanda *> ricerca_domanda(const string&) const;
    container<string> ricerca_utente(const string&) const;
    container<string> ricerca_contatto(const string&) const;

   bool check_presenza_amico(const string &) const;
};
#endif // ACCOUNT_H
