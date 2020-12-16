#include "utente.h"

std::ostream &operator<<(std::ostream &os, const Utente &u)
{
    os<<u.pf<<endl;
    os<<"username: "<<u.credenziali.get_username()<<endl<<"password: "<<u.credenziali.get_password()<<endl;
    return os;
}


void Utente::aggiungi_seguace(Utente* utente)
{
    seguaci.push_back(utente);
}

Utente::Utente():pf(Profilo("ciao","ciao","ciao")),credenziali(Accesso("lorenzo","1111"))
{

}

Utente::Utente(std::string username, std::string password, std::string nome, std::string cognome, std::string email)
    :credenziali(Accesso(username,password)),pf(Profilo(nome,cognome,email)){}

Profilo Utente::get_profilo() const
{
    return pf;
}

Accesso Utente::get_credenziali() const
{
    return credenziali;
}

unsigned int Utente::get_punti() const
{
    return punti;
}

void Utente::fai_domanda(const std::string &domanda)
{
    domande.push_back(new Domanda(domanda,this,0));
}

void Utente::aggiungi_amico(Utente *utente)
{
    amici.push_back(utente);
    utente->aggiungi_seguace(utente);

}

void Utente::togli_amico(Utente *utente)
{
    bool tolto=false;
    try{
    for(auto it=amici.begin();it!=amici.end() && !tolto;++it)
        if((*it)==utente)
        {
            amici.remove(it);
            tolto=true;
        }
    if(!tolto)
        throw amico_non_presente();
    }catch(amico_non_presente)
    {
        std::cerr<<"amico non trovato";
    }
}

container<Utente *> Utente::get_amici() const
{
    return amici;
}

container<Utente*> Utente::get_seguaci() const
{
    return seguaci;
}
