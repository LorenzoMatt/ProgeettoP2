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
    m.aggiungi_utente(new Basic("p2","password","nome","cogmone","email"));
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
    p2.cambia_piano("Premium");
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
    b.fai_domanda("dio can",4);
    maria.fai_domanda("can dio",5);
    p.fai_domanda("dio can",3);
    dio.fai_domanda("dio can",4);
    p2.fai_domanda("dio can",2);
    gio.fai_domanda("dio can",6);
    gesu.fai_domanda("dio can",3);

    dio.aggiungi_amico(p.get_utente());
    container<Domanda*> d=p.ricerca_domanda("dio can");
    for(auto it=d.begin();it!=d.end();++it)
        cout<<(*it)->get_priorita()<<endl;
//    Domanda s("cazzo",nullptr,2);
//    Domanda f("cazzo",nullptr,1);
    Domanda* d1=new Domanda("s",maria.get_utente(),2);
    Domanda* d2=new Domanda("f",maria.get_utente(),3);
    Domanda* d3=new Domanda("f",maria.get_utente(),5);
    Domanda* d4=new Domanda("f",maria.get_utente(),8);
    Domanda* d5=new Domanda("f",maria.get_utente(),2);
    Domanda* d6=new Domanda("f",maria.get_utente(),7);
    Domanda* d7=new Domanda("f",maria.get_utente(),3);
    Domanda* d8=new Domanda("f",maria.get_utente(),3);
    Domanda* d9=new Domanda("f",maria.get_utente(),9);
    Domanda* d10=new Domanda("f",maria.get_utente(),10);

    container<Domanda*> q;
    q.insertion_sort_pointer(&d1);
    q.insertion_sort_pointer(&d2);
    q.insertion_sort_pointer(&d3);
    q.insertion_sort_pointer(&d4);
    q.insertion_sort_pointer(&d5);
    q.insertion_sort_pointer(&d6);
    q.insertion_sort_pointer(&d7);
    q.insertion_sort_pointer(&d8);
    q.insertion_sort_pointer(&d9);
    q.insertion_sort_pointer(&d10);

//    for(auto it=q.begin();it!=q.end();++it)
//        cout<<**it<<endl;
//    if(s>f)
//        cout<<endl<<"OK"<<endl;
//    else
//        cout<<endl<<"non ok"<<endl;
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
