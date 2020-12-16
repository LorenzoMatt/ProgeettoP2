//#include "mainwindow.h"

//#include <QApplication>
#include "profilo.h"
#include "domanda.h"
#include "utente.h"

int main()
{
    utente u1,u2;
    domanda d("sai dirmi perche non riesco a fare questa operazione?");
    commento c1("secondo me potresti provare a..",&u1);
    commento c2("oppure potresti provare a..",&u2);
    d.AggiungiCommento(c1);
    d.AggiungiCommento(c2);
    cout<<d<<endl;
    profilo p("mirko","stella","sonohadhiugas");
    p.AggiungiCompetenza("hgadi");
    p.AggiungiCompetenza("dagartg");
    p.AggiungiTitoloDiStudio("asgreg");
    cout<<p;




}
