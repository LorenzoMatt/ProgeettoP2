#include "domanda.h"




Domanda::Domanda(const string& t, Utente* autore, unsigned int priorita):testo(t),autore_domanda(autore),priorita(priorita > 0 ? priorita: 1){}

//Domanda::Domanda(const Domanda &d) :
//{

//}

void Domanda::aggiungi_commento(const Commento& c){
    commenti.push_back(c);
}
void Domanda::rimuovi_commento(const Commento& c){
    bool sent=false;
    for(auto it=commenti.begin();it!=commenti.end() && !sent;++it)
        if((*it)==c){
            commenti.erase(it);
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

void Domanda::set_priorita(unsigned int p)
{
    priorita=p;
}

bool Domanda::operator <=(const Domanda &d) const
{
    return priorita<=d.priorita;
}

bool Domanda::operator >=(const Domanda &d) const
{
    return priorita >=d.priorita;
}

unsigned int Domanda::get_priorita() const
{
    return priorita;
}


std::ostream &operator<<(std::ostream & os, const Domanda& d){

    return os<<"autore domanda "<<d.autore_domanda->get_credenziali().get_username()<<endl<<"domanda: "<<d.testo<<endl<<"commenti: "<<d.commenti;
}






