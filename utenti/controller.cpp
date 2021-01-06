#include "controller.h"

void Controller::salva() const
{
    a->salva();
}

Controller::Controller(const QString& utente,VistaUtente* vista,QObject *parent) :v(vista),QObject(parent)
{
    a=new Account(utente.toStdString());
}

void Controller::setModel(Account * modello)
{
    a=modello;
}

void Controller::setVista(VistaUtente * vista)
{
    v=vista;
}

void Controller::faiDomanda(const QString & testo)
{
    a->fai_domanda(testo.toStdString());

}

Profilo Controller::getProfilo() const
{
    return a->get_profilo();
}

Accesso Controller::getAccesso() const
{
    return a->get_credenziali();
}

container<Domanda *> Controller::getDomandeAmici() const
{
    return a->get_domande_amici();
}

container<Domanda *> Controller::getDomandePersonali() const
{
    return a->get_domande();
}

int Controller::getPunti() const
{
    return a->get_punti();
}

void Controller::modificaNome(const QString& n)
{
    string t=n.toStdString();
    a->get_profilo().set_nome(t);
    a->salva();
}

void Controller::modificaCognome(const QString& c)
{
    string t=c.toStdString();
    a->get_profilo().set_cognome(t);
    a->salva();
}

void Controller::modificaEmail(const QString& e)
{
    string t=e.toStdString();
    a->get_profilo().set_email(t);
    a->salva();
}

void Controller::modificaPassword(const QString& p)
{
    string t=p.toStdString();
    a->modifica_password(t);
    a->salva();
}

void Controller::aggiungiCompetenza(const QString& c)
{
    string t=c.toStdString();
    a->AggiungiCompetenza(t);
    a->salva();
}

void Controller::aggiungiTitoloDiStudio(const QString& t)
{
    string x=t.toStdString();
    a->AggiungiTitoloDiStudio(x);
    a->salva();
}
