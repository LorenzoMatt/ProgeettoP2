#include "utente.h"

std::ostream &operator<<(std::ostream &os, const Utente &u)
{
    os<<*(u.pf)<<endl;
    os<<"username: "<<u.credenziali->get_username()<<endl<<"password: "<<u.credenziali->get_password()<<endl;
    return os;
}


Utente::Utente():pf(new Profilo("ciao","ciao","ciao")),credenziali(new Accesso("lorenzo","1111"))
{

}

Utente::Utente(std::string username, std::string password, std::string nome, std::string cognome, std::string email)
    :credenziali(new Accesso(username,password)),pf(new Profilo(nome,cognome,email)),risposte_date(0){}

Profilo& Utente::get_profilo() const
{
    return* pf;
}

Accesso& Utente::get_credenziali() const
{
    return *credenziali;
}

unsigned int Utente::get_punti() const
{
    return punti;
}

void Utente::fai_domanda(Domanda& domanda)
{
    domande.push_back(&domanda);
    //domande.push_back(new Domanda(domanda,this,0));
}
void Utente::togli_amico_ausiliario(Utente *utente) // da testare
{
    for(auto it=amici.begin();it!=amici.end();++it)
        if((*it)==utente)
            amici.remove(it);
}
void Utente::aggiungi_seguace(Utente& utente)
{
    if(this!=&utente)
    {
    seguaci.push_back(&utente);
    }
}
void Utente::aggiungi_amico(Utente& utente)
{
    if(this!=&utente)
    {
    amici.push_back(&utente);
    utente.aggiungi_seguace(*this);
    }

}

void Utente::togli_amico(Utente *utente) // da testare
{
    bool tolto=false;

    try{
        for(auto it=amici.begin();it!=amici.end() && !tolto;++it)
            if((*it)==utente)
            {
                amici.remove(it);
                tolto=true;
                cout<<"jkdvfnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnndvfjlnszkjnjnzsklnfjnjdslnfjase"<<endl;
                utente->togli_seguace_ausiliario(this);
            }
        if(!tolto)
            throw amico_non_presente();
        }catch(amico_non_presente)
        {
            std::cerr<<"amico non trovato";
            return;
        }
}
void Utente::togli_seguace_ausiliario(Utente *utente) // È stato testato, ma non so perchè se tolgo il booleano non funziona
{/*
    for(auto it=seguaci.begin();it!=seguaci.end();++it) // non so perchè non funzioni
    if((*it)==utente){
        seguaci.remove(it);
    }*/

/*---------il codice sottostante funziona
    bool tolto=false;

for(auto it=seguaci.begin();it!=seguaci.end() && !tolto;++it)
    if((*it)==utente)
    {
        seguaci.remove(it);
        tolto=true;
        cout<<"trovatooooooooooooo!!!!";
    }
    */
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

}
void Utente::togli_seguace(Utente *utente) // da testare
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


const container<Utente *>& Utente::get_amici() const
{
    return amici;
}

const container<Utente *>& Utente::get_seguaci() const
{
    return seguaci;
}

container<Domanda*> Utente::get_domande() const
{
    return domande;
}

void Utente::set_profilo(const std::string & diocan)
{
    pf->SetNome(diocan);
}
