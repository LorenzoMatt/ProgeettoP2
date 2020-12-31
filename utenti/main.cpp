#include "log.h"
#include <QApplication>
#include "utente.h"
#include "database.h"
#include <list>
#include "deepptr.h"
#include <memory>
#include "test_utenti.h"
#include "test_deep_ptr.h"
#include "test_domande.h"
#include "test_model.h"
#include "test_profilo.h"
#include "test_polimorfismo.h"
#include "test_account.h"
#include "QPushButton"
#include "vista_utente.h"
#include "vista_domanda.h"
#include "controller.h"
#include "account.h"
#include "basic.h"
#include "vista_amministratore.h"
int main(int argc ,char** argv)
{

    QApplication x(argc, argv);
//    Database d;
//    Account a(new Basic("pippo","1234","mirko","stella","ing_mirko@genioincompreso.com"),&d);
//    cout<<*a.get_utente();
//    cout<<endl<<d.get_utenti().countElements()<<endl;
    vista_amministratore w;

//    c.setModel(&a);
//    c.setVista(&w);
//    w.setController(&c);

    w.show();
    return x.exec();
//test_deep_ptr();
//test_domande();
//test_model();
//test_profilo();
//test_utenti();
//test_polimorfismo();
//test_account();







}
