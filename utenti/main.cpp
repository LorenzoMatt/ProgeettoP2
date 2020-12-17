#include "home.h"
#include <QApplication>
#include "utente.h"
#include <list>
struct nodoP
{
    int info;
    nodoP  *next;
    nodoP(int i=0, nodoP *n=0):info(i),next(n){}
};
nodoP* insric(nodoP* x,nodoP* L);
nodoP* riordina(nodoP* x)
{
    if(!x)
        return 0;

        nodoP* L=riordina(x->next);
        nodoP* ord=insric(x,L);
        return ord;
}
nodoP* insric(nodoP* x,nodoP* L)
{
    if(!L)
        return x;
    if(x->info<=L->info)
    {
        x->next=L;
        return x;
    }
    else
    {
        L->next=insric(x,L->next);
        return L;
    }
}
void printList(nodoP* L)
{
    if(L)
    {
        cout<<L->info<<" ";
        printList(L->next);
    }
}

nodoP* creaLista(int* A,int dim,int i){
    if(i==dim)
        return 0;
    nodoP* L=creaLista(A,dim,i+1);
    nodoP* x=new nodoP(A[i],L);
    return x;
}

int main()
{
    int a[5]={4,88,67,0,45};
    nodoP* L=creaLista(a,5,0);
    printList(L);
    nodoP* ord=riordina(L);
    cout<<endl;
    printList(ord);


//    QApplication a(argc, argv);
//    Home w;
//    w.show();


/*
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
    ut.aggiungi_amico(x);
    ut.aggiungi_amico(x2);
    ut.aggiungi_amico(x3);
    ut.aggiungi_amico(x4);


    list<Utente*> l;
    l.push_back(&x);
    l.push_back(&x2);
    l.push_back(&x3);
    //for (list<Utente*>::iterator it=l.begin();it!=l.end();++it)
            //cout<<**it;
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
    Domanda domanda("ho una domanda",&ut,0);
    cout<<*(domanda.get_autore_domanda());// OK
    Commento commento1("vaffanculo",nullptr);
    domanda.aggiungi_commento(Commento("non abbiamo chiesto",nullptr)); //OK
    domanda.aggiungi_commento(Commento("non ho commenti da aggiungere",nullptr)); //OK
    domanda.aggiungi_commento(commento1);//OK
    cout<<domanda; //OK
   // domanda.RimuoviCommento(Commento("non ho commenti da aggiungere",nullptr)); //OK
    //domanda.RimuoviCommento(commento1);//OK
    cout<<endl<<domanda;
    ut.fai_domanda(domanda);
    cout<<endl<<endl<<endl<<"DIOBOIAAAAAAAAAAAA"<<endl;
    container<Domanda*> store=ut.get_domande();
    for(container<Domanda*>::iterator it=store.begin();it!=store.end();++it)
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


*/

}
