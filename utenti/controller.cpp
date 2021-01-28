#include "controller.h"
#include "funzioniutili.h"

Controller::Controller(const QString& utente,vistaUtente* vista,QObject *parent) :QObject(parent),v(vista)
{
    a=new Account(utente.toStdString());
}

Controller::~Controller()// viene invocato dalla delete della classe vista_utente
{
    a->salva();
    delete a;
}

void Controller::faiDomanda(const QString & testo,int priorita)
{
    try
    {
        a->fai_domanda(testo.toStdString(),priorita);
        v->aggiungiAreaDomandePersonali();//aggiorno la vista
        messaggio_informativo("Domanda effettuata correttamente","Domanda effettuata, ti restano in tutto "+QString::fromStdString(std::to_string(a->get_punti()))+" punti",v);
    }
    catch(punti_non_sufficienti)
    {
        messaggio_errore("Domanda non inserita","Non hai punti sufficienti per fare una domanda,"
                                                "prova a rispondere domande di altri utenti oppure a cambiare piano",v);
    }
}

void Controller::scrivi_commento(const QString & testo, Domanda *d)
{
    a->fai_commento(d,testo.toStdString());
}

void Controller::dai_like(int i, Domanda * d)
{
    Commento& c=(d->get_commenti()[i]);
    Utente* u=a->cerca_utente_per_nome(c.get_autore());
    if(u)
        a->dai_punti(c.get_autore());
    c.set_like(true);
}

void Controller::rimuovi_commento(int i, Domanda * d)
{
    d->rimuovi_commento(i);
}

container<Domanda*> Controller::cercaDomanda(const QString & d) const
{
    return a->ricerca_domanda(d.toStdString());
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

container<string> Controller::cercaUtente(const QString & utente) const
{
    container<string> parametri;
        parametri=a->ricerca_contatto(utente.toStdString());
        if(parametri.empty())
        {
            parametri=a->ricerca_utente(utente.toStdString());
        }
        return parametri;
}

bool Controller::check_presenza_amico(const QString& user) const
{
    return a->check_presenza_amico(user.toStdString());
}

void Controller::aggiungi_amico(const QString & user)
{
    try
    {
        Utente* u=a->cerca_utente_per_nome(user.toStdString());
        a->aggiungi_amico(u);
        v->aggiungiAreaDomandaAmici();
    }
    catch(amico_non_presente)
    {
        messaggio_errore("utente non presente","l'utente "+user+" non è presente!",v);
    }
}

void Controller::togli_amico(const QString & user)
{
    Utente* u=a->cerca_utente_per_nome(user.toStdString());
    a->togli_amico(u);
    aggiorna_vista();
}
const container<Domanda *> &Controller::getDomandePersonali() const
{
    return a->get_domande();
}

int Controller::getPunti() const
{
    return a->get_punti();
}

Utente *Controller::getUtente() const
{
    return a->get_utente();
}

const container<Utente *> &Controller::getAmici() const
{
    return a->get_utente()->get_amici();
}

const container<Utente *> &Controller::getSeguaci() const
{
    return a->get_utente()->get_seguaci();
}

bool Controller::cambiaPiano(const QString & piano)
{
    string p=piano.toStdString();
    if(p==a->get_utente()->piano()){
        return false;
    }
    else
    {
        string stringaPiano=piano.toStdString();
        a->cambia_piano(stringaPiano);
        aggiorna_vista();
    }
    return true;
}
void Controller::aggiorna_vista()
{
    v->aggiungiAreaDomandaAmici();
    v->aggiungiAreaDomandePersonali();
}
void Controller::modificaNome(const QString& n)
{
    string t=n.toStdString();
    a->get_profilo().set_nome(t);
}

void Controller::modificaCognome(const QString& c)
{
    string t=c.toStdString();
    a->get_profilo().set_cognome(t);
}

void Controller::modificaEmail(const QString& e)
{
    string t=e.toStdString();
    a->get_profilo().set_email(t);
}

void Controller::modificaPassword(const QString& p)
{
    string t=p.toStdString();
    a->modifica_password(t);
}

void Controller::aggiungiCompetenza(const QString& c)
{
    string t=c.toStdString();
    a->AggiungiCompetenza(t);
}

void Controller::aggiungiTitoloDiStudio(const QString& t)
{
    string x=t.toStdString();
    a->AggiungiTitoloDiStudio(x);
}
