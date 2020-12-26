#include "account.h"

void Account::sistema_amici_seguaci()
{
    for(auto it=utente->seguaci.begin();it!=utente->seguaci.end();++it)
    {
        (*it)->togli_amico_ausiliario(utente);
    }
    for(auto it=utente->amici.begin();it!=utente->amici.end();++it)
    {
        (*it)->togli_seguace_ausiliario(utente);
    }
}

void Account::reverse_seguaci_amici()
{
    for(auto it=utente->seguaci.begin();it!=utente->seguaci.end();++it)
    {
        (*it)->amici.push_back(utente);
    }
    for(auto it=utente->amici.begin();it!=utente->amici.end();++it)
    {
        (*it)->seguaci.push_back(utente);
    }
}

Account::Account()
{

}

Account::Account(Utente *u, Model *m) : utente(u),model(m)
{

}

Profilo Account::get_profilo() const
{
    return utente->get_profilo();
}

Accesso Account::get_credenziali() const
{
    return utente->get_credenziali();
}

container<Domanda *> &Account::get_domande() const
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

container<string> Account::ricerca_utente(const string & u)
{
    container<string> lista_attributi;
    utente->cerca_utente(u,*model,lista_attributi);
    return lista_attributi;
}

void Account::cambia_piano(const std::string & piano)
{
    sistema_amici_seguaci();
    utente=model->cambia_piano(utente,piano);
    reverse_seguaci_amici();
}


