#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "vista_utente.h"
#include "account.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    VistaUtente* v;
    Account* a;
public:
    explicit Controller(QObject *parent = nullptr);
    void setModel(Account*);
    void setVista(VistaUtente*);
    void faiDomanda(const QString&);

signals:

};

#endif // CONTROLLER_H
