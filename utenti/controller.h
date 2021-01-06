#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "account.h"
#include "vista_utente.h"

class VistaUtente;

class Controller : public QObject
{
    Q_OBJECT
private:
    Account* a;
    VistaUtente* v;
    void salva() const;
public:
    explicit Controller(const QString& ,VistaUtente*,QObject *parent = nullptr);
    ~Controller();
    void setModel(Account*);
    void setVista(VistaUtente*);
    Profilo getProfilo() const;
    Accesso getAccesso() const;
    container<Domanda *> getDomandeAmici() const;//OK
    container<std::string> cercaUtente(const QString&) const;
    bool check_presenza_amico(const QString &) const;
    container<Domanda *> getDomandePersonali() const;
    int getPunti() const;
    container<Domanda *> cercaDomanda(const QString&);


private slots:
    void aggiungi_amico(const QString&);
    void togli_amico(const QString&);
    void modificaNome(const QString&);
    void modificaCognome(const QString&);
    void modificaEmail(const QString&);
    void modificaPassword(const QString&);
    void aggiungiCompetenza(const QString&);
    void aggiungiTitoloDiStudio(const QString&);
    void faiDomanda(const QString&, int priorita);
    void scrivi_commento(const QString&,Domanda*);
    void dai_like(int,Domanda*);
    void rimuovi_commento(int,Domanda*);
signals:

};

#endif // CONTROLLER_H
