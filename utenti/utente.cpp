#include "utente.h"




std::ostream &operator<<(std::ostream &os, const Utente &u)
{
    os<<u.pf<<endl;
    os<<"username: "<<u.credenziali.get_username()<<endl<<"password: "<<u.credenziali.get_password()<<endl;
    return os;
}

Utente::~Utente()// vanno distrutte solo le domande, ovviamente per gli amici ed i seguaci è sufficiente deallocare i puntatori
{
     for(auto it=domande.begin();it!=domande.end();++it)
        delete *it;
}

Utente::Utente(const Utente &u):pf(u.pf),credenziali(u.credenziali),amici(u.amici),seguaci(u.seguaci),punti(u.punti),risposte_date(u.risposte_date)
{//le domande sono riferite al nuovo utente
    for(auto it=u.domande.begin();it!=u.domande.end();++it)
    {
        string testo=(*it)->get_testo();
        container<Commento> commenti=(*it)->get_commenti();
        unsigned int priorita=(*it)->get_priorita();
        domande.push_back(new Domanda(testo,this,priorita,commenti));
    }
}


Utente::Utente(string username, string password, string nome, string cognome, string email, unsigned int punti, unsigned int risposte)
    :pf(Profilo(nome,cognome,email)),credenziali(Accesso(username,password)),punti(punti),risposte_date(risposte){
}

Utente::Utente(Profilo p, Accesso c, container<Utente *> a, container<Utente *> s, unsigned int punti, unsigned int risposte)
    :pf(p),credenziali(c),amici(a),seguaci(s),punti(punti),risposte_date(risposte)
{

}

Profilo& Utente::get_profilo()
{
    return pf;
}

Accesso Utente::get_credenziali()
{
    return credenziali;
}

unsigned int Utente::get_punti() const
{
    return punti;
}

unsigned int Utente::get_risposte_date() const
{
    return risposte_date;
}


void Utente::carica_titoli(const container<string>& titoli)
{
    pf.set_titoli_di_studio(titoli);
}

void Utente::carica_competenze(const container<string>& competenze)
{
    pf.set_competenze(competenze);
}


void Utente::modifica_password(const string & pw)
{
    credenziali.set_password(pw);
}

void Utente::togli_amico_ausiliario(const Utente *utente) // serve a rimuovere dall'elenco degli amici utente
{
    bool tolto=false;

    for(auto it=amici.begin();it!=amici.end() && !tolto;++it)
        if((*it)==utente)
        {
            amici.erase(it);
            tolto=true;
        }
}
void Utente::aggiungi_seguace(Utente& utente)
{
    if(this!=&utente)
    {
    seguaci.push_back(&utente);
    }
}
void Utente::aggiungi_amico(Utente *utente)
{
        if(this!=utente)
        {
            amici.push_back(utente);
            utente->aggiungi_seguace(*this);//aggiunge this alla lista dei seguaci di utente
        }else
        {
            throw(amico_non_presente());
        }

}

void Utente::togli_amico(Utente *utente) //serve a togliere un utente dalla sua lista degli amici se presente e
//l'utente che ha tolto l'amico dalla lista viene rimosso dalla lista dei seguaci dell'ex amico
{
    bool tolto=false;

        for(auto it=amici.begin();it!=amici.end() && !tolto;++it)
            if((*it)==utente)
            {
                tolto=true;
                utente->togli_seguace_ausiliario(this); // tolgo dai seguaci di utente
                amici.erase(it);
            }
        if(!tolto)
            throw amico_non_presente();
}

void Utente::cerca_amico(const string & username, container<string>& lista_di_elementi) const{

            Utente* utente;
            bool trovato=false;
            for(auto it=amici.begin();it!=amici.end() && !trovato;++it)
                if((*it)->get_credenziali().get_username()==username){
                    trovato=true;
                    utente=*it;
                }
            if(trovato){
                Utente::Funtore f(3);
                f(utente, lista_di_elementi);
            }
}

container<Domanda *> Utente::get_domande_amici() const
{
    container<Domanda *> d;
    for(auto it=amici.begin();it!=amici.end();++it){
       for(auto ut=(*it)->domande.begin();ut!=(*it)->domande.end();++ut)
       {
           d.insertion_sort(&*ut);//inserisco le domande degli amici in ordine di priorità
       }
    }
    return d;
}

void Utente::togli_seguace_ausiliario(const Utente *utente)
// serve a togliere un seguace dalla propria lista. È una funzione utilizzata da togli_amico
{
    bool tolto=false;

for(auto it=seguaci.begin();it!=seguaci.end() && !tolto;++it)
    if((*it)==utente)
    {
        seguaci.erase(it);
        tolto=true;
    }

}

bool Utente::check_presenza_amico(const string & username) const
{
    bool trovato=false;
    for(auto it=amici.begin();it!=amici.end() && !trovato;++it)
    {
        if((*it)->get_credenziali().get_username()==username)
            trovato=true;
    }
    return trovato;

}

container<string> Utente::split(const string & text, const string & delim)
//divide una stringa in base alle occorrenze di delim
{
       container<string> parole;
        std::size_t start = text.find_first_not_of(delim), end = 0;

        while((end = text.find_first_of(delim, start)) != string::npos)
        {
            parole.push_back(text.substr(start, end - start));
            start = text.find_first_not_of(delim, end);
        }
        if(start != string::npos)
            parole.push_back(text.substr(start));

        return parole;
}


void Utente::togli_seguace(Utente *utente) // OK, toglie un suo seguace dalla coda se è presente e l'utente che ha rimosso il
//seguace viene a sua volta tolto dalla lista degli amici dell'ex seguace
{
    bool tolto=false;
    for(auto it=seguaci.begin();it!=seguaci.end() && !tolto;++it)
        if((*it)==utente)
        {
            seguaci.erase(it);
            tolto=true;
            utente->togli_amico_ausiliario(this);
        }
    if(!tolto){
        throw amico_non_presente();
    }
}


container<Utente *> &Utente::get_amici()
{
    return amici;
}

const container<Utente *> &Utente::get_seguaci() const // OK
{
    return seguaci;
}

const container<Domanda *> &Utente::get_domande() const
{
    return domande;
}

container<Domanda *> &Utente::get_domande_rif()
{
    return domande;
}

const container<Utente *> &Utente::get_amici() const
{
    return amici;
}

void Utente::scrivi_commento(Domanda *d,string risposta)
{
    d->aggiungi_commento(Commento(risposta,this));
}

void Utente::fai_domanda(const string & testo, unsigned int priorita)
{
    domande.push_back(new Domanda(testo,this,priorita));
}

void Utente::set_domande(const container<Domanda *>& d)
{
    domande=d;
}

void Utente::dai_punti(Utente* utente) const
{
    utente->get_punti_domanda();
}

string Utente::get_username_amici() const
{
    string username;
    for(auto it=amici.begin();it!=amici.end();++it)
    {
        if(username.size()==0)
            username=(*it)->get_credenziali().get_username();
        else
            username=username+" "+(*it)->get_credenziali().get_username();
    }
    return username;
}

string Utente::get_username_seguaci() const
{
    string username;
    for(auto it=seguaci.begin();it!=seguaci.end();++it)
    {
        if(username.size()==0)
            username=(*it)->get_credenziali().get_username();
        else
            username=username+" "+(*it)->get_credenziali().get_username();
    }
    return username;
}

void Utente::AggiungiCompetenza(const string & competenza)
{
    pf.aggiungi_competenza(competenza);
}

void Utente::AggiungiTitoloDiStudio(const string & titolo)
{
    pf.aggiungi_titolo_di_studio(titolo);
}


Utente::Funtore::Funtore(int x) : search(x)
{

}

void Utente::Funtore::operator()(const Utente *ut, container<string> &l) const//in base a search inserisco nel container le informazioni necessarie
{
    {
        switch(search)
        {
            case 1:
                l.push_back(ut->credenziali.get_username());
                l.push_back(ut->pf.get_nome());
                l.push_back(ut->pf.get_cognome());
                l.push_back(ut->pf.get_email());
                break;
            case 2:
                l.push_back(ut->credenziali.get_username());
                l.push_back(ut->pf.get_nome());
                l.push_back(ut->pf.get_cognome());
                l.push_back(ut->pf.get_email());
                l.push_back(ut->pf.titoli_di_studio_toString());
                l.push_back(ut->pf.competenze_toString());
                break;
            case 3:
                l.push_back(ut->credenziali.get_username());
                l.push_back(ut->pf.get_nome());
                l.push_back(ut->pf.get_cognome());
                l.push_back(ut->pf.get_email());
                l.push_back(ut->pf.titoli_di_studio_toString());
                l.push_back(ut->pf.competenze_toString());
                l.push_back(ut->get_username_amici());
                l.push_back(ut->get_username_seguaci());
                break;
        }
    }
}
