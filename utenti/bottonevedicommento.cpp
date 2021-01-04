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

}
