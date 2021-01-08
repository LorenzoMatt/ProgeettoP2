#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "utente.h"
#include "database.h"
class Database;
class Account
{
private:
    Utente* utente;
    Database* model;
public:
    Account();
    ~Account();
    Account(const string&);
    Account(Utente *, Database *);
           /* getter*/
    Profilo &get_profilo() const;//OK
    Accesso get_credenziali() const;//OK
    container<Domanda *>& get_domande();//OK
    Utente *get_utente() const;//OK
     unsigned int get_punti() const;//OK
     container<Domanda *> get_domande_amici() const;//OK
     Domanda* get_domanda(const container<Domanda *> &d, unsigned int i) const;//OK



    //aggiungi
    void aggiungi_amico(Utente *);//OK
    void AggiungiCompetenza(const string&); //OK
    void AggiungiTitoloDiStudio (const string&); //OK

    void fai_domanda(const string&,unsigned int =1);//OK
    void fai_commento(Domanda* domanda,const string&) const;

    //togli
    void togli_amico(Utente*);//OK
    void togli_seguace(Utente*);//OK

    //dai
    void dai_punti(Utente*) const;//OK
    void dai_punti(const string &) const;//OK

    //modifica
    void cambia_piano(const string&); //OK
    void modifica_password(const string&);//OK

    void salva() const;

    //cerca
    Utente* cerca_utente_per_nome(const string&);
    container<Domanda *> ricerca_domanda(const string&);//OK
    container<string> ricerca_utente(const string&); //OK
    container<std::string> ricerca_contatto(const string&) const;//OK

   bool check_presenza_amico(const string &) const;
};
#endif // ACCOUNT_H
