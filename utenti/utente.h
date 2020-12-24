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
    static unsigned int punti_domanda_fatta_utente; //dovrà essere cancellata
public:

            /*costruttori e distruttori*/
    Utente();//dovra essere =delete;
    virtual ~Utente();
    Utente(const Utente& u);
    Utente(string username,string password,string nome,string cognome,string email,unsigned int=0);

                     /*getter*/
    Profilo get_profilo() const;//OK
    Accesso get_credenziali() const;//OK
    const container<Utente*>& get_amici() const ;
    const container<Utente*>& get_seguaci() const;
    container<Domanda*> &get_domande();
    unsigned int get_punti() const;//OK


    //void fai_domanda(const string& domanda,unsigned int priorita=0);
    void aggiungi_amico(Utente& utente);
    void togli_amico(Utente* utente);
    void togli_seguace(Utente* utente);
    void AggiungiCompetenza(const string&); //OK
    void AggiungiTitoloDiStudio (const string&); //OK
    void set_nome_profilo(const string&);
    void dai_punti(Utente*) const;
    string get_username_amici() const; //OK
    void scrivi_commento(Domanda* d, string risposta);


                /*virtual*/
    void cerca_utente(const string&,const Model&, container<string>&,int) const;//OK quando implementeremo le classi polimorfe dovrà andare tolto l'ultimo intero da passare alla funzione
    void get_punti_domanda(); //virtual
    container<Domanda*> cerca_domanda(const string&,const Model&);//OK per adesso contiene un container di domande, in utente basic la domanda viene cercata solo negli amici mentre negli account a pagamento nel modello
    void fai_domanda(Domanda* domanda);
    Utente* clone();

protected:
    unsigned int punti=0; // punti presenti nell'account
    unsigned int risposte_date=0; //serve per ottenere un bonus
    static container<string> split(const string&,const string&); //OK
    bool check_presenza_amico(const string&) const;
    //Classe Funtore utilizzata per la ricerca polimorfa dell'utente
    class Funtore
    {
    public:
        int search;
        Funtore(int x=0);
        void operator() (const Utente* ut, container<string>& l) const;

    };

};
#endif // UTENTE_H
