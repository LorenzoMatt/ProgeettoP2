#include "home.h"
#include <QApplication>
#include "utente.h"
int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    Home w;
//    w.show();

//    return a.exec();

    utente ut("ciao","dioboia","diostronzo","porco","dio");
    //cout<<ut.get_profilo()<<endl;
    //cout<<ut.get_punti();
    container<utente> d;
    d.insertBack(ut);
    d.insertBack(utente("non lo so","dioboia","diostronzo","porco","dio"));
    model c(d);
    cout<<c.get_utenti();


}
