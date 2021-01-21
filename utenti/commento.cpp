#include "commento.h"


Commento::Commento(const string& t, Utente* u, bool l):testo(t),autore(u->get_credenziali().get_username()),like(l){}

Commento::Commento(const string & t, const string & u, bool l):testo(t),autore(u),like(l){}

string Commento::get_testo() const{
    return testo;
}
string Commento::get_autore() const{
    return autore;
}

void Commento::set_like(bool l)
{
    like=l;
}

bool Commento::get_like() const
{
    return like;
}
bool Commento:: operator==(const Commento& c) const{
    return testo==c.get_testo() && autore==c.get_autore();
}

std::ostream &operator<<(std::ostream & os, const Commento& c){

    return os<<"commento di: "<<c.autore<<endl<<c.testo;
}
