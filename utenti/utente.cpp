#include "utente.h"

std::ostream &operator<<(std::ostream &os, const Utente &u) //OK
{
    os<<*(u.pf)<<endl;
    os<<"username: "<<u.credenziali->get_username()<<endl<<"password: "<<u.credenziali->get_password()<<endl;
    return os;
}


Utente::Utente():pf(new Profilo("ciao","ciao","ciao")),credenziali(new Accesso("lorenzo","1111"))
{

}

Utente::Utente(const Utente &u):credenziali(new Accesso(*u.credenziali)),pf(new Profilo(*u.pf))
{

}


Utente::Utente(std::string username, std::string password, std::string nome, std::string cognome, std::string email)
    :credenziali(new Accesso(username,password)),pf(new Profilo(nome,cognome,email)),risposte_date(0){}

Profilo& Utente::get_profilo() const  //OK
{
    return* pf;
}

Accesso& Utente::get_credenziali() const //OK
{
    return *credenziali;
}

unsigned int Utente::get_punti() const
{
    return punti;
}

void Utente::fai_domanda(Domanda& domanda)// il sollevamento dell'eccezione funziona a dovere
{
    try{
        if(this==domanda.get_autore_domanda())
            domande.push_back(&domanda);
        else
            throw non_autore_domanda();
    }catch(non_autore_domanda){
        std::cerr<<"non è l'autore della domanda";
    }
}
void Utente::togli_amico_ausiliario(Utente *utente) // funziona ma il codice commentato non funziona e non so perchè
{
    bool tolto=false;

    for(auto it=amici.begin();it!=amici.end() && !tolto;++it)
        if((*it)==utente)
        {
            amici.remove(it);
            tolto=true;
            cout<<"trovatooooooooooooo!!!!";
        }
/*
    try{
        bool tolto=false;

    for(auto it=amici.begin();it!=amici.end() && !tolto;++it)
        if((*it)==utente)
        {
            amici.remove(it);
            tolto=true;
            cout<<"trovatooooooooooooo!!!!";
        }
    if(!tolto)
        throw amico_non_presente();
    }catch(amico_non_presente){
        std::cerr<<"seguace non trovato";
        return;
    }
    */
}
void Utente::aggiungi_seguace(Utente& utente) //OK
{
    if(this!=&utente)
    {
    seguaci.push_back(&utente);
    }
}
void Utente::aggiungi_amico(Utente& utente) //OK
{
    try
    {
        if(this!=&utente)
        {
            amici.push_back(&utente);
            utente.aggiungi_seguace(*this);
        }else
        {
            throw(amico_non_presente());
        }
    }catch(amico_non_presente)
    {
        std::cerr<<"non ti puoi aggiungere fra gli amici!";
        return;    }
}

void Utente::togli_amico(Utente *utente) // OK, serve a togliere un utente dalla sua lista degli amici se presente e
//l'utente che ha tolto l'amico dalla lista viene rimosso dalla lista dei seguaci dell'ex amico
{
    bool tolto=false;

    try{
        if(this!=utente){
        for(auto it=amici.begin();it!=amici.end() && !tolto;++it)
            if((*it)==utente)
            {
                amici.remove(it);
                tolto=true;
                utente->togli_seguace_ausiliario(this); // tolto dai seguaci di utente
            }
        if(!tolto)
            throw amico_non_presente();
        }else{
             throw togliere_te_stesso_dagli_amici();
        }
    }
    catch(amico_non_presente)
    {
        std::cerr<<"amico non trovato";
        return;
    }
    catch(togliere_te_stesso_dagli_amici) //funziona
    {
        std::cerr<<"non puoi togliere te stesso dagli amici!";
        return;
    }
}
void Utente::togli_seguace_ausiliario(Utente *utente) // È stato testato, ma non so perchè se tolgo il booleano non funziona
// serve a togliere un seguace dalla propria lista. È una funzione utilizzata da togli_amico
{/*
    for(auto it=seguaci.begin();it!=seguaci.end();++it) // non so perchè non funzioni
    if((*it)==utente){
        seguaci.remove(it);
    }*/


    bool tolto=false;

for(auto it=seguaci.begin();it!=seguaci.end() && !tolto;++it)
    if((*it)==utente)
    {
        seguaci.remove(it);
        tolto=true;
        cout<<"trovatooooooooooooo!!!!";
    }
    /*

    try{
        bool tolto=false;

    for(auto it=seguaci.begin();it!=seguaci.end() && !tolto;++it)
        if((*it)==utente)
        {
            seguaci.remove(it);
            tolto=true;
            cout<<"trovatooooooooooooo!!!!";
        }
    if(!tolto)
        throw amico_non_presente();
    }catch(amico_non_presente){
        std::cerr<<"seguace non trovato";
        return;
    }
    */


}
void Utente::togli_seguace(Utente *utente) // OK, toglie un suo seguace dalla coda se è presente e l'utente che ha rimosso il
//seguace viene a sua volta tolto dalla lista degli amici dell'ex seguace
{
    bool tolto=false;
    try{
    for(auto it=seguaci.begin();it!=seguaci.end() && !tolto;++it)
        if((*it)==utente)
        {
            seguaci.remove(it);
            tolto=true;
            utente->togli_amico_ausiliario(this);
        }
    if(!tolto)
        throw amico_non_presente();
    }catch(amico_non_presente){
        std::cerr<<"seguace non trovato";
        return;
    }
}


const container<Utente *>& Utente::get_amici() const //OK
{
    return amici;
}

const container<Utente *>& Utente::get_seguaci() const // OK
{
    return seguaci;
}

const container<Domanda *> &Utente::get_domande() const
{
    return domande;
}

void Utente::set_profilo(const std::string & nome)
{
    pf->SetNome(nome);
}
