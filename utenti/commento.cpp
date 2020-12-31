#include "commento.h"


Commento::Commento(const string& t,Utente* u):testo(t),autore(u){}

string Commento::GetCommento() const{
    return testo;
}
Utente* Commento::GetAutore() const{
    return autore;
}
bool Commento:: operator==(const Commento& c) const{
    return testo==c.GetCommento() && autore==c.GetAutore();
}

std::ostream &operator<<(std::ostream & os, const Commento& c){

    return os<<"commento di: "<<c.autore->get_credenziali().get_username()<<endl<<c.testo;
}
