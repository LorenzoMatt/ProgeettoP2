#include "domanda.h"


domanda::domanda(const string& t):testo(t){}

void domanda::AggiungiCommento(const commento& c){
    commenti.insertBack(c);
}
void domanda::RimuoviCommento(const commento& c){
    bool sent=false;
    for(auto it=commenti.begin();it!=commenti.end() && !sent;++it)
        if(&(*it)==&c){
            commenti.remove(it);
            sent=true;
        }
}

std::ostream &operator<<(std::ostream & os, const domanda& d){

    return os<<d.testo<<endl<<d.commenti;
}







