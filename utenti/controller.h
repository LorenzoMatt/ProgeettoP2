#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "account.h"
#include "vistautente.h"
#include "basic.h"
#include "gold.h"
#include "premium.h"
class vistaUtente;

class Controller : public QObject
{
    Q_OBJECT
private:
    Account* a;
    vistaUtente* v;
    void aggiorna_vista();
public:
    explicit Controller(const QString& ,vistaUtente*,QObject *parent = nullptr);
    ~Controller();
    Profilo getProfilo() const;
    Accesso getAccesso() const;
    container<Domanda *> getDomandeAmici() const;
    const container<Domanda *>& getDomandePersonali() const;
    int getPunti() const;
    Utente* getUtente() const;
    const container<Utente *> &getAmici() const;
    const container<Utente *> &getSeguaci() const;

    container<string> cercaUtente(const QString&) const;
    container<Domanda *> cercaDomanda(const QString&) const;

    bool check_presenza_amico(const QString &) const;
    bool cambiaPiano(const QString&);

private slots:
    void aggiungi_amico(const QString&);
    void aggiungiCompetenza(const QString&);
    void aggiungiTitoloDiStudio(const QString&);
    void faiDomanda(const QString&, int priorita);
    void scrivi_commento(const QString&,Domanda*);

    void togli_amico(const QString&);
    void rimuovi_commento(int,Domanda*);

    void modificaNome(const QString&);
    void modificaCognome(const QString&);
    void modificaEmail(const QString&);
    void modificaPassword(const QString&);



    void dai_like(int,Domanda*);

signals:

};

#endif // CONTROLLER_H
