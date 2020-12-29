#include "log.h"
#include <QApplication>
#include "utente.h"
#include "model.h"
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
int main(int argc ,char** argv)
{

    QApplication a(argc, argv);
    vistaUtente w;
    w.show();
    return a.exec();
//test_deep_ptr();
//test_domande();
//test_model();
//test_profilo();
//test_utenti();
//test_polimorfismo();
//test_account();







}
