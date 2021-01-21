#include "account.h"

Account::Account(const string & u)
{
    model=new Database();
    model->import();
    utente=model->get_utente(u);
}

Account::Account(Utente *u, Database *m) :model(m)
{
    utente=model->get_utente(u->get_credenziali().get_username());
}

Profilo& Account::get_profilo() const
{
    return utente->get_profilo();
}

Accesso Account::get_credenziali() const
{
    return utente->get_credenziali();
}

const container<Domanda *>& Account::get_domande() const
{
    return utente->get_domande();
}

Utente *Account::get_utente() const
{
    return utente;
}

Utente *Account::cerca_utente_per_nome(const string & utente)
{
    return model->get_utente(utente);
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

void Account::AggiungiCompetenza(const string & competenza)
{
    utente->AggiungiCompetenza(competenza);
}

void Account::AggiungiTitoloDiStudio(const string & titolo)
{
    utente->AggiungiTitoloDiStudio(titolo);
}

void Account::dai_punti(Utente *u) const
{
    utente->dai_punti(u);
}

void Account::dai_punti(const string & username) const
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

void Account::cambia_piano(const string & piano)
{
    utente=model->cambia_piano(utente,piano);
}

void Account::modifica_password(const string & pw)
{
    utente->modifica_password(pw);
}

container<Domanda*> Account::ricerca_domanda(const string & testo)
{
    return utente->cerca_domanda(testo,*model);
}

void Account::fai_domanda (const string & domanda, unsigned int priorita)

{
    utente->fai_domanda(new Domanda(domanda,utente,priorita));
}

void Account::fai_commento(Domanda* domanda, const string & t) const
{
    Commento c(t,utente);
    domanda->aggiungi_commento(c);
}

void Account::salva() const
{
    model->exportdati();
}

container<string> Account::ricerca_contatto(const string & username) const
{
    container<string> aux;
    utente->cerca_amico(username,aux);
    return aux;

}

container<Domanda *> Account::get_domande_amici() const
{
    return utente->get_domande_amici();
}

string Account::get_piano() const
{
    return utente->piano();
}

bool Account::check_presenza_amico(const string & user) const
{
    container<string> l;
    utente->cerca_amico(user,l);
    return !(l.empty()) ? true : false;// se la dimensione è 0 allora l'amico non è presente
}
