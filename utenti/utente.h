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
#include <list>
using std::list;
class Domanda;
class Model;
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
    Utente(const Utente& u);
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
    string get_username_amici() const; //OK
    void cerca_utente(const Model&, const string&, container<string>&,int) const;// quando implementeremo le classi polimorfe dovrà andare tolto l'ultimo intero da passare alla funzione
    //virtual Utente* clone(return new Utente(t));

protected:
    //Classe Funtore utilizzata per la ricerca polimorfa dell'utente
    class Funtore
    {
    public:
        int search;
        Funtore(int x=0) : search(x) {}
        void operator() (const Utente* ut, container<string>& l) const
        {
            switch(search)
            {
                case 1:
                    l.push_back(ut->credenziali->get_username());
                    l.push_back(ut->pf->GetNome());
                    l.push_back(ut->pf->GetCognome());
                    l.push_back(ut->pf->GetEmail());
                    break;

                case 2:
                    l.push_back(ut->credenziali->get_username());
                    l.push_back(ut->pf->GetNome());
                    l.push_back(ut->pf->GetCognome());
                    l.push_back(ut->pf->GetEmail());
                    l.push_back(ut->pf->competenze_toString());
                    break;

                case 3:
                    l.push_back(ut->credenziali->get_username());
                    l.push_back(ut->pf->GetNome());
                    l.push_back(ut->pf->GetCognome());
                    l.push_back(ut->pf->GetEmail());
                    l.push_back(ut->pf->competenze_toString());
                    l.push_back(ut->get_username_amici());
                    break;
            }
        }
    };

};

#endif // UTENTE_H
