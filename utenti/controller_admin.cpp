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

void controller_admin::aggiungi_utente(const QString &username, const QString &password, const QString&nome,
                                       const QString&cognome, const QString&email, const QString&piano)
{
    try
    {
        string u=username.toStdString(),pw=password.toStdString(),n=nome.toStdString(),co=cognome.toStdString(),em=email.toStdString(),pi=piano.toStdString();
        if(piano=="Gold")
            db->aggiungi_utente(new Gold(u,pw,n,co,em));
        if(piano=="Basic")
            db->aggiungi_utente(new Basic(u,pw,n,co,em));
        if(piano=="Premium")
            db->aggiungi_utente(new Premium(u,pw,n,co,em));
        QMessageBox* messaggio=new QMessageBox(vista);
        messaggio->setWindowTitle("utente aggiunto");
        messaggio->setText("utente "+username+" aggiunto con successo!");
        messaggio->exec();
        vista->aggiorna_tabella();
    }
        catch(utente_gia_presente)
    {
        QErrorMessage* messaggio=new QErrorMessage(vista);
        messaggio->setWindowTitle("Utente non inserito");
        messaggio->showMessage("l'utente "+username+" è già presente");
    }
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
