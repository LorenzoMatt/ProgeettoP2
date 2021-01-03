#include "controller_admin.h"
#include "basic.h"
#include "gold.h"
#include "premium.h"
controller_admin::controller_admin(vista_amministratore* v,Database* d) :vista(v), db(d)
{
    db->import();
    /*vista=new vista_amministratore(this)*/
//    vista->show();
}

controller_admin::~controller_admin()
{
//    delete db;
}

Database *controller_admin::get_db() const
{
    return db;
}

void controller_admin::togli_utente(const std::string & utente)
{
    db->togli_utente(utente);
    vista->aggiorna_tabella();
}

void controller_admin::salva() const
{
    db->exportdati();
}

Utente *controller_admin::get_utente(const std::string & utente) const
{
    Utente* ut=db->get_utente(utente);
    return ut;
}

void controller_admin::aggiungi_utente(const std::string &username, const std::string &password, const std::string &nome,
                                       const std::string &cognome, const std::string &email, const std::string &piano)
{
    if(piano=="Gold")
        db->aggiungi_utente(new Gold(username,password,nome,cognome,email));
    if(piano=="Basic")
        db->aggiungi_utente(new Basic(username,password,nome,cognome,email));
    if(piano=="Premium")
        db->aggiungi_utente(new Premium(username,password,nome,cognome,email));
    vista->aggiorna_tabella();
}

