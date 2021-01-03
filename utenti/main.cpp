#include "log.h"
#include <QApplication>
#include "utente.h"
#include "database.h"
#include <list>
#include "deepptr.h"
#include <memory>
//#include "test_utenti.h"
//#include "test_deep_ptr.h"
//#include "test_domande.h"
//#include "test_model.h"
//#include "test_profilo.h"
//#include "test_polimorfismo.h"
//#include "test_account.h"
//#include "QPushButton"
//#include "vista_utente.h"
//#include "vista_domanda.h"
//#include "controller.h"
#include "account.h"
#include "basic.h"
#include "gold.h"
#include "premium.h"
#include "vista_amministratore.h"
int main(int argc ,char** argv)
{

//    QApplication x(argc, argv);
////    Database d;
////    Account a(new Basic("pippo","1234","mirko","stella","ing_mirko@genioincompreso.com"),&d);
////    cout<<*a.get_utente();
////    cout<<endl<<d.get_utenti().countElements()<<endl;
//    vista_amministratore w;

////    c.setModel(&a);
////    c.setVista(&w);
////    w.setController(&c);

//    w.show();
//    return x.exec();
//test_deep_ptr();
//test_domande();
//test_model();
//test_profilo();
//test_utenti();
//test_polimorfismo();
//test_account();
//    Database m;
//    m.aggiungi_utente(new Basic("b","password","nome","cogmone","email"));
//    m.aggiungi_utente(new Gold("gio","password","nome","cogmone","email"));
//    m.aggiungi_utente(new Basic("p","password","nome","cogmone","email"));
//    m.aggiungi_utente(new Basic("p2","password","nome","cogmone","email"));
//    m.aggiungi_utente(new Basic("dio","password","nome","cogmone","email"));
//    m.aggiungi_utente(new Premium("gesu","password","nome","cogmone","email"));
//    m.aggiungi_utente(new Premium("maria","password","nome","cogmone","email"));

    Database m;
//    m.aggiungi_utente(new Premium("Pikachu","dioboia","diostronzo","porco","dio"));
//    m.aggiungi_utente(new Gold("Lorenzo","stronzo","diostronzo","porco","dio"));
//    m.aggiungi_utente(new Basic("Elton","diocan","diostronzo","porco","dio"));
//    m.aggiungi_utente(new Gold("Francesca","diobestia","diostronzo","porco","dio"));
//    m.aggiungi_utente(new Premium("Mirko","dioluamaro","diostronzo","porco","dio"));
//    m.aggiungi_utente(DeepPtr<Utente>(new Basic("Giorgia","dioluamaro","diostronzo","porco","dio")));
//    Utente* Pikachu=m.get_utente("Pikachu");
//    Utente* Lorenzo=m.get_utente("Lorenzo");
//    Utente* Elton=m.get_utente("Elton");
//    Utente* Francesca=m.get_utente("Francesca");
//    Utente* Mirko=m.get_utente("Mirko");
//    Utente* Giorgia=m.get_utente("Giorgia");
//    //Pikachu->aggiungi_amico(*Pikachu); funziona
//    Pikachu->aggiungi_amico(Lorenzo);
//    Pikachu->aggiungi_amico(Elton);
//    Pikachu->aggiungi_amico(Mirko);
//    Pikachu->aggiungi_amico(Giorgia);
//    Giorgia->AggiungiCompetenza("masturbarsi");
//    Giorgia->AggiungiCompetenza("masturbarsi");
//    Giorgia->AggiungiTitoloDiStudio("studiare");

//    Giorgia->AggiungiTitoloDiStudio("mangiare");
//    Giorgia->aggiungi_amico(Lorenzo);
//    Giorgia->aggiungi_amico(Elton);
//    Giorgia->aggiungi_amico(Mirko);
//    Giorgia->aggiungi_amico(Pikachu);
//    Francesca->AggiungiCompetenza("masturbarsi");
//    Francesca->AggiungiCompetenza("masturbarsi");
//    Francesca->aggiungi_amico(Lorenzo);
//    Francesca->aggiungi_amico(Elton);
//    Francesca->aggiungi_amico(Mirko);
//    Francesca->aggiungi_amico(Pikachu);


//    Domanda* domanda1=new Domanda("prova a fare una domanda",Pikachu,2);
//    Domanda* domanda2=new Domanda("prova a fare una domanda",Pikachu,2);
//    Domanda* domanda3=new Domanda("prova a fare una domanda",Pikachu,2);
//    Domanda* domanda4=new Domanda("prova a fare una domanda",Pikachu,2);
//    Domanda* domanda5=new Domanda("prova a fare una domanda",Pikachu,2);

//    Pikachu->fai_domanda(domanda1);
//    Pikachu->fai_domanda(domanda2);
//    Pikachu->fai_domanda(domanda3);
//    Pikachu->fai_domanda(domanda4);
//    Pikachu->fai_domanda(domanda5);
//    Pikachu->fai_domanda(new Domanda("prova a fare una domanda",Pikachu,2));
//    Pikachu->fai_domanda(new Domanda("prova a fare una domanda",Pikachu,2));
//    Giorgia->fai_domanda(new Domanda("prova a fare una domanda",Giorgia,1));
//    Giorgia->fai_domanda(new Domanda("prova a fare una domanda",Giorgia,1));
//    Giorgia->fai_domanda(new Domanda("prova a fare una domanda",Giorgia,1));

//    Giorgia->scrivi_commento(domanda1,"prova per un commento");
//    Giorgia->scrivi_commento(domanda1,"prova per un commento");
//    Giorgia->scrivi_commento(domanda1,"prova per un commento");
//    Giorgia->scrivi_commento(domanda2,"prova per un commento");
//    Giorgia->scrivi_commento(domanda3,"prova per un commento");
//    Giorgia->scrivi_commento(domanda2,"prova per un commento");

//    m.exportdati();
////    m.aggiungi_utente(new Gold("dioo","password","nome","cogmone","email"));
    m.importa_dati_utenti();
//    m.importa_amici_utenti();
//    m.importa_amici();
//    cout<<m.get_utenti();

//    cout<<"ciaoooo"<<endl;
//    cout<<m.get_utenti()<<endl;
//    cout<<m.get_utente("Giorgia")->get_profilo().competenze_toString();
//    m.funzione_prova("Pikachu");
//    cout<<Pikachu->get_punti();
//    cout<<m.get_utenti().size();
//    cout<<endl<<m.get_utenti().size()<<endl;

    cout<<m.get_utente("Pikachu")->get_domande_amici();
//    for(auto it=m.get_utenti().begin();it!=m.get_utenti().end();++it)
//    {
//        cout<<endl<<(*it)->get_domande()<<endl;
//    }


//    m.aggiungi_utente(new Premium("Pikachu","dioboia","diostronzo","porco","dio"));
//    m.aggiungi_utente(new Basic("Lorenzo","stronzo","diostronzo","porco","dio"));
//    m.aggiungi_utente(new Premium("Elton","diocan","diostronzo","porco","dio"));
//    m.aggiungi_utente(new Basic("Francesca","diobestia","diostronzo","porco","dio"));
//    m.aggiungi_utente(new Gold("Mirko","dioluamaro","diostronzo","porco","dio"));
//    m.aggiungi_utente(DeepPtr<Utente>(new Premium("Giorgia","dioluamaro","diostronzo","porco","dio")));
//    Utente* Lorenzo=m.get_utente("Lorenzo");
//    Utente* Elton=m.get_utente("Elton");
//    Utente* Mirko=m.get_utente("Mirko");
//    Utente* Pikachu=m.get_utente("Pikachu");
//    Utente* Francesca=m.get_utente("Francesca");
//    cout<<"punti "<<m.get_utente("Pikachu")->get_punti()<<endl;
//    Pikachu->fai_domanda(new Domanda("ciao",Pikachu,1));
//    Pikachu->fai_domanda(new Domanda("dio",Pikachu,1));
//    cout<<"punti "<<m.get_utente("Pikachu")->get_punti()<<endl;

//    cout<<Pikachu->get_domande().countElements()<<endl;
//    cout<<m.get_utenti().countElements()<<endl;
//    m.cambia_piano(m.get_utente("Pikachu"),"Premium");
//    cout<<m.get_utenti().countElements()<<endl;
//    //Utente* Pikachu=m.get_utente("Pikachu");
//    Pikachu=m.get_utente("Pikachu");
//    m.aggiungi_utente(new Premium("rrr","dioluamaro","diostronzo","porco","dio"));
//    for(auto it=m.get_utenti().begin();it!=m.get_utenti().end();++it)
//    {
//        if(dynamic_cast<Pagamento*> (&**it))
//            cout<<"OK,tipo Pagamento"<<endl;
//        else
//            cout<<"conversione non avvenuta"<<endl;
//    }






}
