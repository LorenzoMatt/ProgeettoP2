#include "home.h"
#include <QApplication>
#include "utente.h"
#include <list>
int main()
{
//    QApplication a(argc, argv);
//    Home w;
//    w.show();



//    return a.exec();
    //  ////////////////////////////////////////////////////////////TEST UTENTE ///////////////////////////////////////////////////////////
    cout<<"TEST UTENTI"<<endl<<endl;
    Utente ut("ciao","dioboia","diostronzo","porco","dio");
    cout<<ut.get_profilo()<<endl;
    cout<<ut.get_punti();
    Utente x("Lorenzo","dioboia","diostronzo","porco","dio");
    Utente x2("Mirko","dioboia","diostronzo","porco","dio");
    Utente x3("Mirko","dioboia","diostronzo","porco","dio");
    Utente x4("Mirko","dioboia","diostronzo","porco","dio");
    Utente x5("Mirko","dioboia","diostronzo","porco","dio");
    ut.aggiungi_amico(&x);
    ut.aggiungi_amico(&x2);
    ut.aggiungi_amico(&x3);
    ut.aggiungi_amico(&x4);


    list<Utente*> l;
    l.push_back(&x);
    l.push_back(&x2);
    l.push_back(&x3);
    //for (list<Utente*>::iterator it=l.begin();it!=l.end();++it)
            //cout<<**it;
    //for(container<Utente*>::iterator it=ut.get_amici().begin();it!=ut.get_amici().end();++it)
       // cout<<**it<<endl;
    //container<utente> d;
    //d.insertBack(ut);
    //d.insertBack(utente("non lo so","dioboia","diostronzo","porco","dio"));
    //model c(d);
    //cout<<c.get_utenti();


cout<<endl<<endl<<endl<<"TEST DOMANDE"<<endl<<endl;
    // ///////////////////////////////////////////////////////////TEST DOMANDE ////////////////////////////////////////////////////////////
    Domanda domanda("ho una domanda",&ut,0);
    cout<<*(domanda.get_autore_domanda());// OK
    Commento commento1("vaffanculo",nullptr);
    domanda.AggiungiCommento(Commento("non abbiamo chiesto",nullptr)); //OK
    domanda.AggiungiCommento(Commento("non ho commenti da aggiungere",nullptr)); //OK
    domanda.AggiungiCommento(commento1);//OK
    cout<<domanda; //OK
    domanda.RimuoviCommento(Commento("non ho commenti da aggiungere",nullptr)); //OK
    domanda.RimuoviCommento(commento1);//OK
    cout<<endl<<domanda;


    // /////////////////////////////////////////////////////// TEST PROFILO //////////////////////////////////////////
    cout<<endl<<endl<<endl<<"TEST PROFILO"<<endl<<endl;

    Profilo e("porco","dio","bastardo");
    e.AggiungiCompetenza("farsi le seghe");
    e.AggiungiCompetenza("bestemmiare");
    e.AggiungiCompetenza("pisciare");
    cout<<e.GetCompetenze();
    Profilo e2("porco","dio","bastardo");
    Profilo e3("porco","dio","bastardo");
    Profilo e4("porco","dio","bastardo");
    container<Profilo*> profili;
    profili.push_back(&e);
    profili.push_back(&e2);
    profili.push_back(&e3);
    profili.push_back(&e4);
    for(container<Profilo*>::iterator it=profili.begin();it!=profili.end();++it)
        cout<<**it<<endl;




}
