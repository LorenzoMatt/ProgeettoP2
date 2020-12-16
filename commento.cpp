#include "commento.h"

commento::commento(const string& t,utente* u):testo(t),autore(u){}

string commento::GetCommento() const{
    return testo;
}
utente* commento::GetAutore() const{
    return autore;
}
bool commento:: operator==(const commento& c) const{
    return testo==c.GetCommento() && autore==c.GetAutore();
}

std::ostream &operator<<(std::ostream & os, const commento& c){

    return os<<c.testo;
}
