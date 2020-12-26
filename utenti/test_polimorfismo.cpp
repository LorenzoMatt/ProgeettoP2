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

int test_polimorfismo()
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


//    for(auto it=p->get_seguaci().begin();it!=p->get_seguaci().end();++it)
//                 cout<<endl<<**it;

    cout<<A.get_utente()->get_punti()<<endl;
    A.cambia_piano("Premium");
//    if(dynamic_cast<Premium*>(A.get_utente()))
//        cout<<"OK"<<endl;
//    else
//        cout<<"non va bene"<<endl;

    cout<<"amici dopo il cambio piano"<<endl;
    cout<<A.get_utente()->get_punti()<<endl;
//    for(auto it=p->get_seguaci().begin();it!=p->get_seguaci().end();++it)
//            cout<<endl<<**it;

//    cout<<A.ricerca_utente("p2")<<endl;









//    cout<<b->get_punti()<<endl<<g->get_punti()<<endl<<p->get_punti();
//    b->fai_domanda(new Domanda("dio boia",b,1));
//    g->fai_domanda(new Domanda("dio boia",g,1));
//    p->fai_domanda(new Domanda("dio boia",p,1));
//    m.aggiungi_utente(new Premium("l","password","nome","cogmone","email"));
//    Utente* l=m.get_utente("l");
//    l->fai_domanda(new Domanda("dio boia",l,1));
//    p->aggiungi_amico(l);
//    p->aggiungi_amico(p2);
////    for(auto it=l->get_seguaci().begin();it!=l->get_seguaci().end();++it)
////        cout<<**it<<endl;
//    p->aggiungi_amico(g);
//    p->aggiungi_amico(b);
////      cout<<endl<<p->get_amici().countElements();
////      for(auto it=p->get_amici().begin();it!=p->get_amici().end();++it)
////          cout<<endl<<**it;
//    container<Domanda*> domande_b=p->cerca_domanda("dio boia",m);
//    int i=1;
//    for(auto it=domande_b.begin();it!=domande_b.end();++it,i++)
//        cout<<endl<<"domanda "<<i<<**it<<endl;
//    cout<<endl<<endl<<b->get_punti()<<endl<<g->get_punti()<<endl<<p->get_punti();

//    b->get_punti_domanda();
//    g->get_punti_domanda();
//    p->get_punti_domanda();
//    cout<<endl<<endl<<b->get_punti()<<endl<<g->get_punti()<<endl<<p->get_punti();
//    container<string> lu;
//    p->AggiungiCompetenza("fumare");
//    p->AggiungiTitoloDiStudio("prima media");
//    b->cerca_utente("p",m,lu);
//    cout<<lu;
//    container<Domanda*> d1;
//    d1.push_back(new Domanda("dio boia",p,1));
//    d1.push_back(new Domanda("dio boia",p,1));
//    d1.push_back(new Domanda("dio boia",p,1));
//    d1.push_back(new Domanda("dio boia",p,1));
//    d1.push_back(new Domanda("dio boia",p,1));
//    container<Domanda*> d2;
//    d2.push_back(new Domanda("dio boia",p,1));
//    d2.push_back(new Domanda("dio boia",p,1));
//    d2.push_back(new Domanda("dio boia",p,1));
//    d2.push_back(new Domanda("dio boia",p,1));
//    d2.push_back(new Domanda("dio boia",p,1));
//    container<Domanda*> d3=d1+d2;
}
