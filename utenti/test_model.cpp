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
int test_model()
{

    Model m;
//    m.aggiungi_utente(new Premium("Pikachu","dioboia","diostronzo","porco","dio"));
//    m.aggiungi_utente(new Gold("Lorenzo","stronzo","diostronzo","porco","dio"));
//    m.aggiungi_utente(new Basic("Elton","diocan","diostronzo","porco","dio"));
//    m.aggiungi_utente(new Gold("Francesca","diobestia","diostronzo","porco","dio"));
//    m.aggiungi_utente(new Premium("Mirko","dioluamaro","diostronzo","porco","dio"));
//    m.aggiungi_utente(DeepPtr<Utente>(new Premium("Giorgia","dioluamaro","diostronzo","porco","dio")));
//    Utente* Pikachu=m.get_utente("Pikachu");
//    Utente* Lorenzo=m.get_utente("Lorenzo");
//    Utente* Elton=m.get_utente("Elton");
//    Utente* Francesca=m.get_utente("Francesca");
//    Utente* Mirko=m.get_utente("Mirko");
//    Utente* Giorgia=m.get_utente("Giorgia");
//    //Pikachu->aggiungi_amico(*Pikachu); funziona
//    Pikachu->aggiungi_amico(*Lorenzo);
//    Pikachu->aggiungi_amico(*Elton);
//    Pikachu->aggiungi_amico(*Mirko);
//    Pikachu->aggiungi_amico(*Giorgia);
//    Giorgia->AggiungiCompetenza("masturbarsi");
//    for(auto it=Pikachu->get_amici().begin();it!=Pikachu->get_amici().end();++it)
//    {
//        (*it)->AggiungiCompetenza("masturbarsi");
//        cout<<**it;
//    }
//    cout<<"conpetenze Giorgia "<<Giorgia->get_profilo().competenze_toString()<<endl;
//    //p->set_profilo("dvjdvndfjvnjvnjd");
//    //cout<<ut->get_profilo().GetNome()<<endl;
//    m.get_utente("Mirko")->set_nome_profilo("ffffffffff");
//    for(auto it=Pikachu->get_amici().begin();it!=Pikachu->get_amici().end();++it)
//        cout<<**it;
//    container<string> l;
//    Pikachu->AggiungiCompetenza("farsi tantissime seghe");
//    Francesca->cerca_utente("Pikachu",m,l,3);
//    cout<<l;
//    for(auto it=Pikachu->get_amici().begin();it!=Pikachu->get_amici().end();++it)
//        cout<<**it;

//    Mirko->fai_domanda(new Domanda("perchè sono stupido",Mirko,1));
//    for(auto it=Mirko->get_domande().begin();it!=Mirko->get_domande().end();++it)
//        cout<<**it<<endl;
//    container<Domanda*>dom= Pikachu->cerca_domanda("stupido perchè",m);
//    cout<<dom.countElements()<<endl;

//    for(auto it=dom.begin();it!=dom.end();++it)
//        Pikachu->scrivi_commento(*it,"dio boia arrangiati");

//    for(auto it=Mirko->get_domande().begin();it!=Mirko->get_domande().end();++it)
//        cout<<**it<<endl;


//    container<Domanda*> d1;
//    container<Domanda*> d2;
//    d1.push_back(new Domanda("gesu bastardo",Mirko,2));
//    d2.push_back(new Domanda("dio bastadro",Elton,3));
//    d2.push_back(new Domanda("madonna bastardo",Mirko,2));
//    container<Domanda*> d3=d1+d2;
//    cout<<d3.countElements()<<d2.countElements()<<d1.countElements()<<endl;
//    for(auto it=d3.begin();it!=d3.end();++it)
//    {
//        cout<<**it<<endl;
//        Mirko->scrivi_commento(*it,"boia la madonna");
//    }
//    cout<<endl;

//    for(auto it=d2.begin();it!=d2.end();++it)
//    {

//        cout<<**it<<endl;
//        Mirko->scrivi_commento(*it,"idsjiijsjisdjisi");


//    }
//    for(auto it=d3.begin();it!=d3.end();++it)
//    {
//        (*it)->RimuoviCommento(Commento("idsjiijsjisdjisi",Mirko));
//        cout<<**it<<endl;
//    }
//    for(auto it=d2.begin();it!=d2.end();++it)
//    {

//        cout<<**it<<endl;
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
//    cout<<Pikachu->get_punti();
//    //Pikachu=m.get_utente("Pikachu");
//    //Pikachu=new Premium("Francesca","diobestia","diostronzo","porco","dio");
//    //cout<<Pikachu->get_punti();
//    DeepPtr<Utente> t=new Gold("dio","dioluamaro","diostronzo","porco","dio");
//    cout<<endl<<t->get_punti();
//    t->fai_domanda(new Domanda("dio boia",&*t,1));
//    t->aggiungi_amico(*Pikachu);
//    Utente* ff=new Gold(Profilo("d","s","s"),Accesso("r","t"),container<Utente*>(),container<Utente*>(),container<Domanda*>(),33,5);
//    cout<<endl<<ff->get_punti()<<endl;
//    ff->fai_domanda(new Domanda("dio boia",ff,1));
//    cout<<" n. domande ff "<<ff->get_domande().countElements()<<endl;
//    m.aggiungi_utente(t);
//    cout<<m.get_utente("dio")->get_domande().countElements()<<" amici di dio "<<m.get_utente("dio")->get_amici().countElements()<<endl;
//    cout<<t->get_punti();
//    cout<<endl<<ff->get_punti();
//    Premium* p=new Premium("zzz","dioluamaro","diostronzo","porco","di");
//    p->fai_domanda(new Domanda("dio boia",p,1));
//    p->fai_domanda(new Domanda("dio boia",p,1));
//    for(auto it=p->get_domande().begin();it!=p->get_domande().end();++it)
//        (*it)->aggiungi_commento(Commento("ciaooo",Elton));
//    Utente* z=new Premium(*p);
//    cout<<endl<<z->get_amici().countElements()<<endl;
//    z->aggiungi_amico(*Elton);
//    cout<<endl<<z->get_amici().countElements()<<endl;
//    cout<<endl<<p->get_amici().countElements()<<endl;
//    p->aggiungi_amico(*Elton);
//    p->fai_domanda(new Domanda("dio boia",p,1));
//    cout<<endl<<z->get_domande().countElements()<<endl;
//    cout<<endl<<p->get_domande().countElements()<<endl;
//    for(auto it=z->get_domande().begin();it!=z->get_domande().end();++it)
//    {
//        (*it)->aggiungi_commento(Commento("dio porco",Francesca));
//        cout<<**it<<endl;
//        (*it)->rimuovi_commento(Commento("dio porco",Francesca));
//    }
//    cout<<"domande di p"<<endl<<endl;
//    for(auto it=p->get_domande().begin();it!=p->get_domande().end();++it)
//    {
//        cout<<**it<<endl;
//    }


    return 0;

}
