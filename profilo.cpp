#include "profilo.h"

profilo::profilo():lingue(0){}

void profilo::SetNome(string n){nome=n;}
void profilo::SetCognome(string c){cognome=c;}
void profilo::SetEmail(string e){email=e;}

profilo::nodo::nodo():next(0){}
profilo::nodo::nodo(int i,nodo* n):info(i),next(n){}

void profilo::AggiungiLingua(int* l,int dim){
    if(dim){
        if(!lingue){
            lingue=new nodo(*l);
            l++;
            dim--;
            nodo* n=lingue;
            while(dim){
                n->next=new nodo(*l);
                n=n->next;
                dim--;
                l++;
            }
        }
        else
        {
            nodo* n=lingue;
            while(n->next){
                n=n->next;
            }
            while(dim){
                n->next=new nodo(*l);
                n=n->next;
                dim--;
                l++;
            }
        }

    }
}

void profilo::StampaProfilo() const{
        if(lingue){
        nodo* n=lingue;
        cout<<n->info<<endl;
        while(n->next){
            n=n->next;
            cout<<n->info<<endl;
        }

        }
}
