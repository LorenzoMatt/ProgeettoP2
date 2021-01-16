#include "domanda.h"




container<Commento>& Domanda::get_commenti()
{
    return commenti;
}

void Domanda::set_commenti(const container<Commento> com)
{
    commenti=com;
}

Domanda::Domanda(const string& t, Utente *autore, unsigned int priorita):testo(t),autore_domanda(autore),priorita(priorita > 0 ? priorita: 1)
{}

Domanda::Domanda(const string & s, Utente * u, unsigned int p, const container<Commento> & c) : testo(s),autore_domanda(u),commenti(c),priorita(p)
{

}

Domanda::Domanda(const string & s, unsigned int p, const container<Commento> & c) : testo(s),autore_domanda(nullptr),commenti(c),priorita(p)
{

}
void Domanda::set_autore(Utente *u)
{
    autore_domanda=u;
}

void Domanda::aggiungi_commento(const Commento& c){
    commenti.push_back(c);
}

void Domanda::rimuovi_commento(unsigned int i){

    if(i<commenti.size())
    {
        unsigned int n=0;
        bool ok=false;
        for(auto it=commenti.begin();it!=commenti.end() && !ok;++it,++n)
            if(n==i){
                commenti.erase(it);
                ok=true;
            }
    }
}


Utente* Domanda::get_autore_domanda() const
{
    return autore_domanda;
}

string Domanda::get_testo() const
{
    return testo;
}

void Domanda::set_priorita(unsigned int p)
{
    priorita=p;
}

bool Domanda::operator <(const Domanda & d) const
{
    return priorita<d.priorita;
}

bool Domanda::operator <=(const Domanda &d) const
{
    return priorita<=d.priorita;
}

bool Domanda::operator >=(const Domanda &d) const
{
    return priorita >=d.priorita;
}

bool Domanda::operator >(const Domanda &d) const
{
    return priorita>d.priorita;
}

unsigned int Domanda::get_priorita() const
{
    return priorita;
}

std::ostream &operator<<(std::ostream & os, const Domanda& d){

    os<<"autore domanda ";
    if(d.autore_domanda)
        os<<d.autore_domanda->get_credenziali().get_username()<<endl;
    else
        os<<"autore non disponibile "<<endl;
    os<<"domanda: "<<d.testo<<endl<<"commenti: "<<endl<<d.commenti;
    return os;
}
