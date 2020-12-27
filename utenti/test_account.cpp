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
    m.aggiungi_utente(new Basic("dio","password","nome","cogmone","email"));
    m.aggiungi_utente(new Premium("gesu","password","nome","cogmone","email"));
    m.aggiungi_utente(new Premium("maria","password","nome","cogmone","email"));


//    for(auto it=m.get_utenti().begin();it!=m.get_utenti().end();++it)
//        cout<<endl<<**it;
    Account p(m.get_utente("p"),&m);
    Account b(m.get_utente("b"),&m);
    Account dio(m.get_utente("dio"),&m);
    Account maria(m.get_utente("maria"),&m);
    Account gio(m.get_utente("gio"),&m);
    Account p2(m.get_utente("p2"),&m);
    Account gesu(m.get_utente("gesu"),&m);
    p.AggiungiCompetenza("dio porco");
    p.AggiungiTitoloDiStudio("bauuu");
    p.aggiungi_amico(p2.get_utente());
    p.aggiungi_amico(b.get_utente());
    p.aggiungi_amico(dio.get_utente());
    p.aggiungi_amico(maria.get_utente());
    p.aggiungi_amico(gesu.get_utente());
    p.aggiungi_amico(gio.get_utente());
    p2.AggiungiCompetenza("dioboia");
    p2.AggiungiTitoloDiStudio("diocan");
    cout<<"amici di p"<<endl;
    cout<<p.get_utente()->get_amici().countElements()<<endl;
    //m.togli_utente("gesu");
    cout<<p.get_utente()->get_amici().countElements()<<endl;
    cout<<"seguaci di maria"<<maria.get_utente()->get_seguaci()<<endl;
    cout<<"seguaci di maria"<<maria.get_utente()->get_seguaci()<<endl;
    cout<<"punti di maria "<<maria.get_punti()<<endl;
    p.dai_punti("maria");
    cout<<"punti di maria "<<maria.get_punti()<<endl;
//    cout<<A.ricerca_utente("p2")<<endl;
    p.modifica_password("dio boia");
    cout<<p.get_credenziali().get_password();


//    for(auto it=p->get_amici().begin();it!=p->get_amici().end();++it)
//                 cout<<endl<<**it;

//    cout<<A.get_utente()->get_punti()<<endl;
    p.cambia_piano("Premium");
//    if(dynamic_cast<Premium*>(A.get_utente()))
//        cout<<"OK"<<endl;
//    else
//        cout<<"non va bene"<<endl;
//    A.AggiungiCompetenza("dio stracane");

//    cout<<"amici dopo il cambio piano"<<endl<<endl<<endl;
//    cout<<A.get_utente()->get_punti()<<endl;
//    for(auto it=p->get_amici().begin();it!=p->get_amici().end();++it)
//            cout<<endl<<**it;

//    m.togli_utente(g);
    maria.fai_domanda("can dio");
    p.fai_domanda("dio can");
    b.fai_domanda("dio can");
    dio.fai_domanda("dio can");
    p2.fai_domanda("dio can");
    gio.fai_domanda("dio can");
    gesu.fai_domanda("dio can");
    dio.aggiungi_amico(p.get_utente());
    cout<<*p.get_domanda(p.get_domande_amici(),2);
//    cout<<dio.ricerca_contatto("p");
//    dio.togli_amico(p.get_utente());
//    cout<<dio.ricerca_contatto("p");
    //cout<<*gesu.get_utente();
    //domande+=domande2;
//    cout<<domande.countElements();
//    for(int i=0;i<10;++i)
//        domande+=domande2;
//    cout<<domande.countElements();
//    Domanda* ho= A.get_domanda(k,0);
    //cout<<A.get_utente()->get_amici();

//    for(auto it=k.begin();it!=k.end();++it)
//    {
//        (*it)->aggiungi_commento(Commento("dio boia",dio));
//    }
//    for(auto it=dio->get_domande().begin();it!=dio->get_domande().end();++it)
//    {
//        cout<<**it<<endl;
//    }
//    for(auto it=A.get_utente()->get_amici().begin();it!=A.get_utente()->get_amici().end();++it){
//       domande+=(*it)->get_domande();
//    }
    cout<<endl<<endl<<"ciaoooooooooo"<<endl;
//    for(auto it=A.get_utente()->get_amici().begin();it!=A.get_utente()->get_amici().end();++it)
//        cout<<endl<<**it;

//    cout<<A.ricerca_utente("p2")<<endl;

return 0;

}
