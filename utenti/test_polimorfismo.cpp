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

int test_polimorfismo()
{
    Model m;
    Utente* b=new Basic("b","password","nome","cogmone","email");
    m.aggiungi_utente(b);
    m.aggiungi_utente(new Gold("gio","password","nome","cogmone","email"));
    m.aggiungi_utente(new Premium("p","password","nome","cogmone","email"));
    m.aggiungi_utente(new Premium("p2","password","nome","cogmone","email"));

    for(auto it=m.get_utenti().begin();it!=m.get_utenti().end();++it)
        cout<<endl<<**it;
      Utente* c=m.get_utente("b");
      cout<<*c<<endl;
    Utente* g=m.get_utente("gio");
    Utente* p=m.get_utente("p");
    Utente* p2=m.get_utente("p2");
    cout<<b->get_punti()<<endl<<g->get_punti()<<endl<<p->get_punti();
    b->fai_domanda(new Domanda("dio boia",b,1));
    g->fai_domanda(new Domanda("dio boia",g,1));
    p->fai_domanda(new Domanda("dio boia",p,1));
    Utente* l=new Basic("orco","password","nome","cogmone","email");
    p->aggiungi_amico(l);
    for(auto it=l->get_seguaci().begin();it!=l->get_seguaci().end();++it)
        cout<<**it<<endl;
    //p->aggiungi_amico(*(m.get_utente("gio")));
    //p->aggiungi_amico(*(m.get_utente("b")));
    cout<<endl<<p->get_amici().countElements();
    for(auto it=p->get_amici().begin();it!=b->get_amici().end();++it)
        cout<<endl<<**it;
    //container<Domanda*> domande_b=p->cerca_domanda("dio boia",m);
//    for(auto it=domande_b.begin();it!=domande_b.end();++it)
//        cout<<endl<<**it<<endl;
//    cout<<endl<<endl<<b->get_punti()<<endl<<g->get_punti()<<endl<<p->get_punti();
}
