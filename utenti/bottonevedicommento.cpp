#include "bottonevedicommento.h"

bottoneVediCommento::bottoneVediCommento(Domanda* d,const QString& t):QPushButton(t),dom(d)
{

}

void bottoneVediCommento::vediCommenti()
{
    Domanda* d=dom;
    vista_domanda* dettagli=new vista_domanda(d);
    dettagli->setWindowTitle("dettagli domanda");
    dettagli->show();
    connect(dettagli,SIGNAL(commento(const QString&)),this,SIGNAL(commento(const QString&,d)));
    connect(dettagli,SIGNAL(like(int)),this,SIGNAL(like(int,d)));
    connect(dettagli,SIGNAL(rimuovi(int)),this,SIGNAL(rimuovi(int,d)));
}
