#include "home.h"
#include <QApplication>
#include "utente.h"
#include "model.h"
#include <list>
#include "deepptr.h"
#include <memory>
#include "prova.h"
int test_model()
{

    Model m;
    m.aggiungi_utente(new Utente("Pikachu","dioboia","diostronzo","porco","dio"));
    m.aggiungi_utente(new Utente("Lorenzo","stronzo","diostronzo","porco","dio"));
    m.aggiungi_utente(new Utente("Elton","diocan","diostronzo","porco","dio"));
    m.aggiungi_utente(new Utente("Francesca","diobestia","diostronzo","porco","dio"));
    m.aggiungi_utente(new Utente("Mirko","dioluamaro","diostronzo","porco","dio"));
    m.aggiungi_utente(DeepPtr<Utente>(new Utente("Giorgia","dioluamaro","diostronzo","porco","dio")));
    Utente* Pikachu=m.get_utente("Pikachu");
    Utente* Lorenzo=m.get_utente("Lorenzo");
    Utente* Elton=m.get_utente("Elton");
    Utente* Francesca=m.get_utente("Francesca");
    Utente* Mirko=m.get_utente("Mirko");
    Utente* Giorgia=m.get_utente("Giorgia");
    //Pikachu->aggiungi_amico(*Pikachu); funziona
    Pikachu->aggiungi_amico(*Lorenzo);
    Pikachu->aggiungi_amico(*Elton);
    Pikachu->aggiungi_amico(*Mirko);
    Pikachu->aggiungi_amico(*Giorgia);
    Giorgia->AggiungiCompetenza("masturbarsi");
    for(auto it=Pikachu->get_amici().begin();it!=Pikachu->get_amici().end();++it)
    {
        (*it)->AggiungiCompetenza("masturbarsi");
        cout<<**it;
    }
    cout<<"conpetenze Giorgia "<<Giorgia->get_profilo().competenze_toString()<<endl;
    //p->set_profilo("dvjdvndfjvnjvnjd");
    //cout<<ut->get_profilo().GetNome()<<endl;
    m.get_utente("Mirko")->set_nome_profilo("ffffffffff");
    for(auto it=Pikachu->get_amici().begin();it!=Pikachu->get_amici().end();++it)
        cout<<**it;
    container<string> l;
    Pikachu->AggiungiCompetenza("farsi tantissime seghe");
    Francesca->cerca_utente("Pikachu",m,l,3);
    cout<<l;
//    for(auto it=Pikachu->get_amici().begin();it!=Pikachu->get_amici().end();++it)
//        cout<<**it;

    Mirko->fai_domanda(new Domanda("perchè sono stupido",Mirko,1));
//    for(auto it=Mirko->get_domande().begin();it!=Mirko->get_domande().end();++it)
//        cout<<**it<<endl;
    container<Domanda*>dom= Pikachu->cerca_domanda("stupido perchè",m);
    cout<<dom.countElements()<<endl;

//    for(auto it=dom.begin();it!=dom.end();++it)
//        Pikachu->scrivi_commento(*it,"dio boia arrangiati");

//    for(auto it=Mirko->get_domande().begin();it!=Mirko->get_domande().end();++it)
//        cout<<**it<<endl;


        return 0;

}
