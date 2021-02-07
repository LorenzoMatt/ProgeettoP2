#ifndef UTENTE_H
#define UTENTE_H
#include "container.h"
#include "profilo.h"
#include "accesso.h"
#include "domanda.h"
#include "database.h"
#include "amicononpresente.h"
#include "nonautoredomanda.h"
#include "puntinonsufficienti.h"
#include <algorithm>
class Domanda;
class Database;
class Utente
{
    friend class Database;
    friend std::ostream& operator<<(std::ostream& os,const Utente& u);
private:
    Profilo pf;
    Accesso credenziali;
    container<Utente*> amici;
    container<Utente*> seguaci;
    container<Domanda*> domande;
    void aggiungi_seguace(Utente &utente);
    void togli_amico_ausiliario(const Utente* utente);
    void togli_seguace_ausiliario(const Utente* utente);
public:
            /*costruttori e distruttori*/
    Utente() =delete;
    virtual ~Utente();
    Utente(const Utente& u);
    Utente(string username,string password,string nome,string cognome,string email,unsigned int,unsigned int =0);
    Utente(Profilo p,Accesso c,container<Utente*> a,container<Utente*> s,unsigned int punti,unsigned int risposte);

                     /*getter vari*/

    const Profilo &get_profilo() const;
    Profilo &get_profilo();
    Accesso get_credenziali() const;
    container<Utente*>& get_amici();
    const container<Utente *> &get_seguaci() const;
    const container<Domanda *>& get_domande() const;
    container<Domanda *>& get_domande_rif();//ho bisogno di ritornarlo per riferimento non costante perchè possono essere modificate aggiungendovi nuove domande
    container<Domanda *> get_domande_amici() const;
    const container<Utente* > & get_amici() const;
    unsigned int get_punti() const;
    unsigned int get_risposte_date() const; //serve per ottenere un bonus per gli utenti gold e premium
    string get_username_amici() const; //serve per la creazione del file xml
    string get_username_seguaci() const; //serve per la creazione del file xml


    //caricamento da file
    void carica_competenze(const container<string> &);
    void carica_titoli(const container<string> &);

    void modifica_password(const string &);
    void aggiungi_amico(Utente *);
    void togli_amico(Utente*);
    void cerca_amico(const string&,container<string>&) const;
    void togli_seguace(Utente*);
    void AggiungiCompetenza(const string&);
    void AggiungiTitoloDiStudio (const string&);
    void dai_punti(Utente*) const;
    void scrivi_commento(Domanda* d, string risposta);
    void fai_domanda(const string&, unsigned int);
    void set_domande(const container<Domanda *> &);
    static container<string> split(const string&,const string&);

                /*virtual*/
    virtual void cerca_utente(const string&,const Database&, container<string>&) const =0;// quando implementeremo le classi polimorfe dovrà andare tolto l'ultimo intero da passare alla funzione
    virtual void get_punti_domanda() =0;
    virtual container<Domanda*> cerca_domanda(const string&,const Database&) const =0;//in utente basic la domanda viene cercata solo negli amici mentre negli account a pagamento nel modello
    virtual void fai_domanda(Domanda* domanda)=0;
    virtual Utente* clone() const=0;
    virtual string piano() const=0;

protected:
    unsigned int punti; // punti presenti nell'account
    unsigned int risposte_date; //serve per ottenere un bonus
    bool check_presenza_amico(const string&) const;
    static bool case_insensitive_match(string s1, string s2);
    //Classe Funtore utilizzata per la ricerca polimorfa dell'utente
    class Funtore
    {
    public:
        int search;//parametro per effetturare la ricerca
        Funtore(int x=1);
        void operator() (const Utente* ut, container<string>& l) const;
    };

};
#endif // UTENTE_H
