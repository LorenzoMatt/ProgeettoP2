#include "home.h"
#include <QApplication>
#include "utente.h"
#include "model.h"
#include <list>
#include "deepptr.h"
#include <memory>
#include "prova.h"

int test_deep_ptr()
{
    // /////////////////////////////////////////////////////// TEST DEEPPTR //////////////////////////////////////////
    cout<<endl<<endl<<endl<<"TEST DEEPPTR"<<endl<<endl;

    Utente* u=new Utente("Giorgio","0000","Giorgio","Armani","giorgioamrmani");
    DeepPtr<Utente> ptr=DeepPtr<Utente>(u);
    cout<<*ptr;
    container<DeepPtr<Utente>> utente;
    utente.push_back(DeepPtr<Utente>(new Utente("Giorgio","0000","Giorgio","Armani","giorgioamrmani")));
    return 0;
}
