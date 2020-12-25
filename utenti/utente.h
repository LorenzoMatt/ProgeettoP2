#ifndef UTENTE_H
#define UTENTE_H
#include "container.h"
#include "profilo.h"
#include "accesso.h"
#include "domanda.h"
#include "model.h"
#include "amico_non_presente.h"
#include "non_autore_domanda.h"
#include "togliere_te_stesso_dagli_amici.h"
#include "punti_non_sufficienti.h"
class Domanda;
class Model;
class Utente
{
    friend std::ostream& operator<<(std::ostream& os,const Utente& u);
private:
    Profilo pf;
    Accesso credenziali;
    container<Utente*> amici;
    container<Utente*> seguaci;
    container<Domanda*> domande;
    void aggiungi_seguace(Utente& utente); //OK
    void togli_amico_ausiliario(Utente* utente); //OK
    void togli_seguace_ausiliario(Utente* utente); //OK
public:


            /*costruttori e distruttori*/
    Utente() =delete;
    virtual ~Utente();
    Utente(const Utente& u);
    Utente(string username,string password,string nome,string cognome,string email,unsigned int);
    Utente(Profilo p,Accesso c,container<Utente*> a,container<Utente*> s,container<Domanda*> d,unsigned int punti,unsigned int risposte);

                     /*getter*/
    Profilo get_profilo() const;//OK
    Accesso get_credenziali() const;//OK
    container<Utente*> get_amici() const ;
    container<Utente*> get_seguaci() const;
    container<Domanda *> &get_domande();
    unsigned int get_punti() const;//OK
    unsigned int get_risposte_date() const; //serve per ottenere un bonus



    //void fai_domanda(const string& domanda,unsigned int priorita=0);
    void aggiungi_amico(Utente*);
    void togli_amico(Utente*);
    void togli_seguace(Utente*);
    void AggiungiCompetenza(const string&); //OK
    void AggiungiTitoloDiStudio (const string&); //OK
    void set_nome_profilo(const string&);
    void dai_punti(Utente*) const;
    string get_username_amici() const; //OK
    void scrivi_commento(Domanda* d, string risposta);


                /*virtual*/
    virtual void cerca_utente(const string&,const Model&, container<string>&) const =0;//OK quando implementeremo le classi polimorfe dovrà andare tolto l'ultimo intero da passare alla funzione
    virtual void get_punti_domanda() =0; //virtual
    virtual container<Domanda*> cerca_domanda(const string&,const Model&) const=0;//OK per adesso contiene un container di domande, in utente basic la domanda viene cercata solo negli amici mentre negli account a pagamento nel modello
    virtual void fai_domanda(Domanda* domanda)=0;
    virtual Utente* clone() const=0;

protected:
    unsigned int punti; // punti presenti nell'account
    unsigned int risposte_date; //serve per ottenere un bonus
    static container<string> split(const string&,const string&); //OK
    bool check_presenza_amico(const string&) const;
    //Classe Funtore utilizzata per la ricerca polimorfa dell'utente
    class Funtore
    {
    public:
        int search;
        Funtore(int x=1);
        void operator() (const Utente* ut, container<string>& l) const;
    };

};
#endif // UTENTE_H
