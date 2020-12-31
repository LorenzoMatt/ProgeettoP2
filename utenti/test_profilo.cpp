#include "log.h"
#include <QApplication>
#include "premium.h"
#include "gold.h"
#include "basic.h"
#include "database.h"
#include <list>
#include "deepptr.h"
#include <memory>

int test_profilo()
{

    // /////////////////////////////////////////////////////// TEST PROFILO //////////////////////////////////////////
     cout<<endl<<endl<<endl<<"TEST PROFILO"<<endl<<endl;
     Premium* ut=new Premium("Pikachu","dioboia","diostronzo","porco","dio");
     Profilo e("porco","dio","bastardo");
     e.aggiungi_competenza("farsi le seghe");
     e.aggiungi_competenza("bestemmiare");
     e.aggiungi_competenza("pisciare");
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
     ut->get_profilo().set_nome("giovanni");
     cout<<"profilo di ut"<<endl<<ut->get_profilo();//ok modifica correttamente
    return 0;
}
