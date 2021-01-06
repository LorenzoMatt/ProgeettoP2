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

    void salva() const;
public:
    explicit Controller(const QString& ,VistaUtente*,QObject *parent = nullptr);
    void setModel(Account*);
    void setVista(VistaUtente*);
    void faiDomanda(const QString&);
    Profilo getProfilo() const;
    Accesso getAccesso() const;
    container<Domanda *> getDomandeAmici() const;
    container<Domanda *> getDomandePersonali() const;
    int getPunti() const;




public slots:
    void modificaNome(const QString&);
    void modificaCognome(const QString&);
    void modificaEmail(const QString&);
    void modificaPassword(const QString&);

    void aggiungiCompetenza(const QString&);
    void aggiungiTitoloDiStudio(const QString&);

};

#endif // CONTROLLER_H
