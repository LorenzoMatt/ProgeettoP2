#include "home.h"
#include <QApplication>
#include "utente.h"
#include "model.h"
#include <list>
#include "deepptr.h"
#include <memory>
#include "prova.h"
int test_domande()
{
    Model m;
    m.aggiungi_utente(new Utente("Pikachu","dioboia","diostronzo","porco","dio"));
    m.aggiungi_utente(new Utente("Lorenzo","stronzo","diostronzo","porco","dio"));
    m.aggiungi_utente(new Utente("Elton","diocan","diostronzo","porco","dio"));
    m.aggiungi_utente(new Utente("Francesca","diobestia","diostronzo","porco","dio"));
    m.aggiungi_utente(new Utente("Mirko","dioluamaro","diostronzo","porco","dio"));
    Utente* Pikachu=m.get_utente("Pikachu");
    Utente* Lorenzo=m.get_utente("Lorenzo");
    Utente* Elton=m.get_utente("Elton");
    Utente* Francesca=m.get_utente("Francesca");
    Utente* Mirko=m.get_utente("Mirko");
    //Pikachu->aggiungi_amico(*Pikachu); funziona
    Pikachu->aggiungi_amico(*Lorenzo);
    Pikachu->aggiungi_amico(*Elton);
    Pikachu->aggiungi_amico(*Mirko);
    for(auto it=Pikachu->get_amici().begin();it!=Pikachu->get_amici().end();++it)
        cout<<**it;
    //p->set_profilo("dvjdvndfjvnjvnjd");
    //cout<<ut->get_profilo().GetNome()<<endl;
    m.get_utente("Mirko")->set_profilo("ffffffffff");
    for(auto it=Pikachu->get_amici().begin();it!=Pikachu->get_amici().end();++it)
        cout<<**it;
    container<string> l;
    Mirko->AggiungiCompetenza("farsi tantissime seghe");
    Francesca->cerca_utente(m,"Pikachu",l,3);
    cout<<l;
    for(auto it=Pikachu->get_amici().begin();it!=Pikachu->get_amici().end();++it)
        cout<<**it;
    return 0;
}
