#include "domanda.h"




Domanda::Domanda(const string& t, Utente* autore, unsigned int priorita):testo(t),autore_domanda(autore),priorita(priorita){}

void Domanda::aggiungi_commento(const Commento& c){
    commenti.push_back(c);
}
void Domanda::RimuoviCommento(const Commento& c){
    bool sent=false;
    for(auto it=commenti.begin();it!=commenti.end() && !sent;++it)
        if((*it)==c){
            commenti.remove(it);
            sent=true;
        }
}

Utente* Domanda::get_autore_domanda() const
{
    return autore_domanda;
}

std::string Domanda::get_testo() const
{
    return testo;
}


std::ostream &operator<<(std::ostream & os, const Domanda& d){

    return os<<"autore domanda "<<d.autore_domanda->get_credenziali().get_username()<<endl<<"domanda: "<<d.testo<<endl<<"commenti: "<<d.commenti;
}






