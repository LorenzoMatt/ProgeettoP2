#include "home.h"
#include <QApplication>
#include "utente.h"
#include "model.h"
#include <list>
#include "deepptr.h"
#include <memory>

int main()
{

//    QApplication a(argc, argv);
//    Home w;
//    w.show();



//    return a.exec();
    //  ////////////////////////////////////////////////////////////TEST UTENTE ///////////////////////////////////////////////////////////
    cout<<"TEST UTENTI"<<endl<<endl;
    Utente ut("Pikachu","dioboia","diostronzo","porco","dio");
    ut.get_profilo().AggiungiCompetenza("stare a letto");
    ut.get_profilo().AggiungiCompetenza("stare a letto");
    cout<<ut.get_profilo();
    Utente x("Lorenzo","dioboia","diostronzo","porco","dio");
    Utente x2("Elisa","dioboia","diostronzo","porco","dio");
    Utente x3("Mirko","dioboia","diostronzo","porco","dio");
    Utente x4("Francesca","dioboia","diostronzo","porco","dio");
    Utente x5("Elton","dioboia","diostronzo","porco","dio");
    ut.aggiungi_amico(x);
    ut.aggiungi_amico(x2);
    ut.aggiungi_amico(x3);
    ut.aggiungi_amico(x4);
    x2.aggiungi_amico(x);
    x3.aggiungi_amico(x);
    x4.aggiungi_amico(x);
    // x4.togli_amico(&x4);
    int i=1;

    Utente j("ciao","dd","t","g","w");


    cout<<"amici di ut ------------------------"<<endl;
    for(container<Utente*>::const_iterator it=ut.get_amici().begin();it!=ut.get_amici().end();++it,i++){
       cout<<"amico n. "<<i<<endl<<**it<<endl;
    }
    i=1;
    cout<<endl<<"seguaci di x--------------------------------------------"<<endl;
    for(container<Utente*>::const_iterator it=x.get_seguaci().begin();it!=x.get_seguaci().end();++it,i++){
        cout<<"seguace n. "<<i<<endl<<endl<<**it;
    }
    i=1;
    cout<<"fine seguaci di x--------------------------------------------"<<endl;
    ut.togli_amico(&x);
    cout<<"tolto x dagli amici di ut"<<endl;
    //ut.togli_amico(&j);
    cout<<"controllo seguaci di x--------------------------------------------"<<endl;
    for(container<Utente*>::const_iterator it=x.get_seguaci().begin();it!=x.get_seguaci().end();++it,i++){
        cout<<"seguace n. "<<i<<endl<<endl<<**it;
    }
    i=1;
    cout<<"fine del controllo seguaci di x--------------------------------------------"<<endl;

    cout<<"amici di ut ------------------------"<<endl;
    for(container<Utente*>::const_iterator it=ut.get_amici().begin();it!=ut.get_amici().end();++it,i++){
       cout<<"amico n. "<<i<<endl<<**it<<endl;
    }
    i=1;
    cout<<endl<<"fine amici di ut ------------------------"<<endl;
    ut.aggiungi_amico(x);
    cout<<"riaggiunto x agli amici di ut"<<endl;
    cout<<"amici di ut ------------------------"<<endl;
    for(container<Utente*>::const_iterator it=ut.get_amici().begin();it!=ut.get_amici().end();++it,i++){
       cout<<"amico n. "<<i<<endl<<**it<<endl;
    }
    cout<<endl<<"fine amici di ut ------------------------"<<endl;

    x.togli_seguace(&ut);
    //x.togli_seguace(&j); OK
    i=1;
    cout<<"tolto seguace ut da x"<<endl;
    cout<<"amici di ut ------------------------"<<endl;
    for(container<Utente*>::const_iterator it=ut.get_amici().begin();it!=ut.get_amici().end();++it,i++){
       cout<<"amico n. "<<i<<endl<<**it<<endl;
    }
    cout<<endl<<"fine amici di ut ------------------------"<<endl;

    cout<<"controllo seguaci di x--------------------------------------------"<<endl;
    i=1;
    for(container<Utente*>::const_iterator it=x.get_seguaci().begin();it!=x.get_seguaci().end();++it,i++){
        cout<<"seguace n. "<<i<<endl<<endl<<**it;
    }
    i=1;
    cout<<"fine del controllo seguaci di x--------------------------------------------"<<endl;


    //for (list<Utente*>::iterator it=l.begin();it!=l.end();++it)
            //cout<<**it;

    cout<<"modifica del profilo di ut tramite una copia--------------------------------------------"<<endl;
    container<Utente*> dd= ut.get_amici();
    for(container<Utente*>::iterator it=dd.begin();it!=dd.end();++it){
        (*it)->set_profilo("gesu bastardo");
        cout<<**it<<endl;
    }
    cout<<endl<<endl<<endl<<"dvnssdvnijndjsnvjdvnsjdvnskisdvnjdvnvjdfsbn dvs";
     //container<Utente*> dd2=ut.get_amici();
     for(container<Utente*>::const_iterator it=ut.get_amici().begin();it!=ut.get_amici().end();++it){
         (*it)->set_profilo("madonna bastarda");
        cout<<**it<<endl;
     }
     for(container<Utente*>::iterator it=dd.begin();it!=dd.end();++it){

         cout<<**it<<endl;
     }

   // for(auto it=ut.get_amici().cbegin();it!=ut.get_amici().cend();++it)
        // cout<<(**it)<<endl;
    //container<utente> d;
    //d.insertBack(ut);
    //d.insertBack(utente("non lo so","dioboia","diostronzo","porco","dio"));
    //model c(d);
    //cout<<c.get_utenti();



cout<<endl<<endl<<endl<<"TEST DOMANDE"<<endl<<endl;
    // ///////////////////////////////////////////////////////////TEST DOMANDE ////////////////////////////////////////////////////////////
    Domanda* domanda=new Domanda("ho una domanda",&ut,0);
    cout<<"autore domanda "<<endl;
    cout<<*domanda->get_autore_domanda();// OK    
    domanda->get_autore_domanda()->get_profilo().SetCognome("dio ebete");
    cout<<endl<<"autore domanda modificato"<<endl;
    //cout<<*domanda->get_autore_domanda();// OK
    cout<<ut;
    Commento commento1("vaffanculo",nullptr);
    domanda->aggiungi_commento(Commento("non abbiamo chiesto",nullptr)); //OK
    domanda->aggiungi_commento(Commento("non ho commenti da aggiungere",nullptr)); //OK
    domanda->aggiungi_commento(commento1);//OK
    cout<<*domanda; //OK
    domanda->RimuoviCommento(Commento("non ho commenti da aggiungere",nullptr)); //OK
    domanda->RimuoviCommento(commento1);//OK
    cout<<endl<<*domanda;
    ut.fai_domanda(*domanda);
    // ut.fai_domanda("ma come mai il cielo è blu?");
    cout<<endl<<endl<<endl<<"DIOBOIAAAAAAAAAAAA"<<endl;
    const container<Domanda*>& store=ut.get_domande();// se passo per riferimento noto la differenza se ad ut aggiungo una domanda
    for(container<Domanda*>::const_iterator it=store.begin();it!=store.end();++it)
        cout<<**it<<endl;
    Domanda* domanda2=new Domanda("sono gesu di nazzaret",&ut,0);
    ut.fai_domanda(*domanda2);

    cout<<endl<<endl<<"aggiunta domanda a ut"<<endl;
          for(container<Domanda*>::const_iterator it=store.begin();it!=store.end();++it)
              cout<<**it<<endl;


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
    ut.get_profilo().SetNome("giovanni");
    cout<<"profilo di ut"<<endl<<ut.get_profilo();//ok modifica correttamente

    // /////////////////////////////////////////////////////// TEST DEEPPTR //////////////////////////////////////////
    cout<<endl<<endl<<endl<<"TEST DEEPPTR"<<endl<<endl;

    Utente* u=new Utente("Giorgio","0000","Giorgio","Armani","giorgioamrmani");
    DeepPtr<Utente> ptr=DeepPtr<Utente>(u);
    cout<<*ptr;
    //container<DeepPtr<Utente>> utente;
    //utente.push_back(DeepPtr<Utente>(new Utente("Giorgio","0000","Giorgio","Armani","giorgioamrmani")));
   // utentee.push_back(ptr);

    list<std::unique_ptr<Utente>> utentee;
    utentee.push_back(std::make_unique<Utente>(Utente("Giorgio","0000","Giorgio","Armani","giorgioamrmani")));
    utentee.push_back(std::make_unique<Utente>(ut));
    utentee.push_back(std::make_unique<Utente>(x));
    list<std::unique_ptr<Utente>*> utentee2;
    std::unique_ptr<Utente> punto=std::make_unique<Utente>(x2);
    utentee2.push_back(&punto);
    cout<<"stampapuntooooooooooo"<<endl<<*punto<<endl;
    for(list<std::unique_ptr<Utente>*>::iterator it=utentee2.begin();it!=utentee2.end();++it)// funziona
        cout<<"utente1111111"<<endl<<***it; //funziona

    Utente g(ut);
    cout<<"costruisco ut"<<endl<<endl<<endl<<endl<<ut<<"costruttore di copia"<<endl<<g<<endl<<"indirizzo di g "<<&g<<endl<<"indirizzo di ut "<<&ut<<endl;

    for (container<Domanda*>::const_iterator it=ut.get_domande().begin();it!=ut.get_domande().end();++it)
        cout<<**it;
}
