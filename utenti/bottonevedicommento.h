#ifndef BOTTONEVEDICOMMENTO_H
#define BOTTONEVEDICOMMENTO_H

#include <QPushButton>
#include "vista_domanda.h"
class Domanda;

class bottoneVediCommento:public QPushButton
{
    Q_OBJECT
    Domanda* dom;
public:
    bottoneVediCommento(Domanda*,const QString&);
//    void setDom(Domanda*);

private slots:
    void vediCommenti();
signals:
    void like(int,Domanda*);
    void commento(const QString&,Domanda*);
    void rimuovi(int,Domanda*);
};

#endif // BOTTONEVEDICOMMENTO_H
