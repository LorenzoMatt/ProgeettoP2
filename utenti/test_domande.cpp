#include "home.h"
#include <QApplication>
#include "premium.h"
#include "gold.h"
#include "basic.h"
#include "model.h"
#include <list>
#include "deepptr.h"
#include <memory>
#include "prova.h"
int test_domande()
{
        Model m;
        m.aggiungi_utente(new Premium("Lorenzo","222222","Lorenzo","Matterazzo","lorenzomatt312"));
        m.aggiungi_utente(new Premium("Mirko","ss","Mirko","Stella","stellamirko"));
        Utente* ut=m.get_utente("Lorenzo");
        Utente* ut2=m.get_utente("Mirko");
        Domanda* d=new Domanda("perchè il cielo è blu",ut,2);
        ut->fai_domanda(d);
        ut2->scrivi_commento(d,"dioboia");
        cout<<*d;
        for(auto it=ut->get_domande().begin();it!=ut->get_domande().end();++it)
            cout<<**it;
        Domanda* domanda=new Domanda("ho una domanda",ut,1);
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
        domanda->rimuovi_commento(Commento("non ho commenti da aggiungere",nullptr)); //OK
        domanda->rimuovi_commento(commento1);//OK
        cout<<endl<<*domanda;
        ut->fai_domanda(domanda);
        // ut.fai_domanda("ma come mai il cielo è blu?");
        cout<<endl<<endl<<endl<<"DIOBOIAAAAAAAAAAAA"<<endl;
        const container<Domanda*>& store=ut->get_domande();// se passo per riferimento noto la differenza se ad ut aggiungo una domanda
        for(container<Domanda*>::const_iterator it=store.begin();it!=store.end();++it)
            cout<<**it<<endl;
        Domanda* domanda2=new Domanda("sono gesu di nazzaret",ut,0);
        ut->fai_domanda(domanda2);
        cout<<endl<<endl<<"aggiunta domanda a ut"<<endl;
        for(container<Domanda*>::const_iterator it=store.begin();it!=store.end();++it)
                  cout<<**it<<endl;
    return 0;
}
