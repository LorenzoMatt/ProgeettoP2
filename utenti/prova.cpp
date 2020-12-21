#include "prova.h"

Prova::Prova()
{

}

void Prova::add(Utente *u)
{
    utenti.push_back(u);
}

Utente *Prova::find(const std::string &username)
{
    bool trovato=false;
    for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
        if((*it)->get_credenziali().get_username()==username)
        {
            trovato=true;
            return *it;
        }
    return 0;
}
