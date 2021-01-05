#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "account.h"
#include "vista_utente.h"


class Controller : public QObject
{
    Q_OBJECT
private:
    VistaUtente* v;
    Account* a;
public:
    explicit Controller(const QString& ,VistaUtente*,QObject *parent = nullptr);
    void setModel(Account*);
    void setVista(VistaUtente*);
    void faiDomanda(const QString&);
    Profilo getProfilo() const;
    Accesso getAccesso() const;
    container<Domanda *> getDomandeAmici() const;//OK
    container<std::string> cercaUtente(const QString&) const;
    bool check_presenza_amico(const QString &) const;
    container<Domanda *> getDomandePersonali() const;
    int getPunti() const;

public slots:
    void aggiungi_amico(const QString&);
    void togli_amico(const QString&);
    void modificaNome(const string&);
    void modificaCognome(const string&);
    void modificaEmail(const string&);
    void modificaPassword(const string&);
    void aggiungiCompetenza(const string&);
    void aggiungiTitoloDiStudio(const string&);




signals:

};

#endif // CONTROLLER_H
