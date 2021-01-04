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

public slots:
    void vediCommenti();


};

#endif // BOTTONEVEDICOMMENTO_H
