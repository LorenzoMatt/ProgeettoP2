#include "controller_admin.h"
#include "basic.h"
#include "gold.h"
#include "premium.h"
#include <QErrorMessage>
controller_admin::controller_admin(vista_amministratore* v) :vista(v), db(new Database())
{
    db->import();
//    vista=new vista_amministratore(this)
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

void controller_admin::cambia_piano(const QString & utente,const QString& piano)
{
    Utente* u=db->get_utente(utente.toStdString());
    if(u)
    {
        string p=piano.toStdString();
        if((p=="Basic" && dynamic_cast<Basic*>(u)) || (p=="Gold" && dynamic_cast<Gold*>(u))
                || (p=="Premium" && dynamic_cast<Premium*>(u)))
        {
            QErrorMessage* messaggio=new QErrorMessage(vista);
            messaggio->setWindowTitle("Piano non cambiato");
            messaggio->showMessage("l'utente "+utente+" ha già un piano "+piano);
        }
        else
        {
            db->cambia_piano(u,p);
            QMessageBox* messaggio=new QMessageBox(vista);
            messaggio->setWindowTitle("Cambio piano completato");
            messaggio->setText("cambio piano andato a buon fine!");
            messaggio->exec();
            vista->aggiorna_tabella();
        }
    }
    else
    {
        QErrorMessage * messaggio=new QErrorMessage(vista);
        messaggio->setWindowTitle("Utente non presente");
        messaggio->showMessage("Utente "+utente+" non presente");
    }

}

void controller_admin::set_vista(vista_amministratore *v)
{
    vista=v;
}

