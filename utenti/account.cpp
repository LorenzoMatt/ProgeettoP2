#include "account.h"

Account::Account()
{

}

Account::Account(const std::string & u)
{
    model=new Database();
    model->import();
    utente=model->get_utente(u);
}

Account::Account(Utente *u, Database *m) :model(m)
{
    m->aggiungi_utente(u);
    utente=model->get_utente(u->get_credenziali().get_username());
}

Profilo Account::get_profilo() const
{
    return utente->get_profilo();
}

Accesso Account::get_credenziali() const
{
    return utente->get_credenziali();
}

container<Domanda *>& Account::get_domande()
{
    return utente->get_domande();
}

Utente *Account::get_utente() const
{
    return utente;
}

unsigned int Account::get_punti() const
{
    return utente->get_punti();
}

void Account::aggiungi_amico(Utente *u)
{
    utente->aggiungi_amico(u);
}

void Account::togli_amico(Utente *u)
{
    utente->togli_amico(u);
}

void Account::togli_seguace(Utente *u)
{
    utente->togli_seguace(u);
}

void Account::AggiungiCompetenza(const std::string & competenza)
{
    utente->AggiungiCompetenza(competenza);
}

void Account::AggiungiTitoloDiStudio(const std::string & titolo)
{
    utente->AggiungiTitoloDiStudio(titolo);
}

void Account::dai_punti(Utente *u) const
{
    utente->dai_punti(u);
}

void Account::dai_punti(const std::string & username) const
{
    try
    {
        Utente* u=model->get_utente(username);
        u->get_punti_domanda();
    }catch(amico_non_presente)
    {
        std::cerr<<"amico non presente";
    }

}

container<string> Account::ricerca_utente(const string & u)
{
    container<string> lista_attributi;
    utente->cerca_utente(u,*model,lista_attributi);
    return lista_attributi;
}

void Account::cambia_piano(const std::string & piano)
{
    utente=model->cambia_piano(utente,piano);
}

void Account::modifica_password(const std::string & pw)
{
    utente->modifica_password(pw);
}

container<Domanda*> Account::ricerca_domanda(const std::string & testo)
{
    utente->cerca_domanda(testo,*model);
    return utente->cerca_domanda(testo,*model);
}

void Account::fai_domanda(const std::string & domanda, unsigned int priorita)
{
    utente->fai_domanda(new Domanda(domanda,utente,priorita));
}

void Account::fai_commento(Domanda* domanda, const std::string & t) const
{
    Commento c(t,utente);
    domanda->aggiungi_commento(c);
}

container<string> Account::ricerca_contatto(const std::string & username) const
{
    container<string> aux;
    utente->cerca_amico(username,aux);
    return aux;
}

container<Domanda *> Account::get_domande_amici() const
{
    return utente->get_domande_amici();
}

Domanda *Account::get_domanda(const container<Domanda *>& d, unsigned int i) const
{
    if(i>d.size())
        throw std::runtime_error("domanda non presente");
    else
    {
        container<Domanda*>::const_iterator it=d.begin();
        for(;it!=d.end() && i>0;++it,i--)
        {}//corpo vuoto
        return *it;
    }
}
