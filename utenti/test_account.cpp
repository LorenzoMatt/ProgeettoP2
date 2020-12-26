#include "test_account.h"
#include "test_polimorfismo.h"
#include "home.h"
#include <QApplication>
#include "model.h"
#include <list>
#include "deepptr.h"
#include <memory>
#include "prova.h"
#include "premium.h"
#include "gold.h"
#include "basic.h"
#include "account.h"


int test_account()
{
    Model m;
    m.aggiungi_utente(new Basic("b","password","nome","cogmone","email"));
    m.aggiungi_utente(new Gold("gio","password","nome","cogmone","email"));
    m.aggiungi_utente(new Premium("p","password","nome","cogmone","email"));
    m.aggiungi_utente(new Premium("p2","password","nome","cogmone","email"));

//    for(auto it=m.get_utenti().begin();it!=m.get_utenti().end();++it)
//        cout<<endl<<**it;
    Utente* g=m.get_utente("gio");
    Utente* p=m.get_utente("p");
    Utente* p2=m.get_utente("p2");
    Utente* b=m.get_utente("b");
    Account A(g,&m);
    A.AggiungiCompetenza("dio porco");
    A.AggiungiTitoloDiStudio("bauuu");
    A.aggiungi_amico(p);
    A.aggiungi_amico(p2);
    A.aggiungi_amico(b);
    p->aggiungi_amico(g);
    p->aggiungi_amico(p2);
    p->aggiungi_amico(b);

//    for(auto it=A.get_utente()->get_amici().begin();it!=A.get_utente()->get_amici().end();++it)
//             cout<<endl<<**it;
    p2->AggiungiCompetenza("dioboia");
    p2->AggiungiTitoloDiStudio("diocan");
    p2->aggiungi_amico(b);
    p2->aggiungi_amico(p);
//    cout<<A.ricerca_utente("p2")<<endl;


    for(auto it=p->get_amici().begin();it!=p->get_amici().end();++it)
                 cout<<endl<<**it;

//    cout<<A.get_utente()->get_punti()<<endl;
    A.cambia_piano("Premium");
    if(dynamic_cast<Premium*>(A.get_utente()))
        cout<<"OK"<<endl;
    else
        cout<<"non va bene"<<endl;
    A.AggiungiCompetenza("dio stracane");

    cout<<"amici dopo il cambio piano"<<endl<<endl<<endl;
//    cout<<A.get_utente()->get_punti()<<endl;
    for(auto it=p->get_amici().begin();it!=p->get_amici().end();++it)
            cout<<endl<<**it;

//    cout<<A.ricerca_utente("p2")<<endl;

return 0;

}
