#include "utente.h"

std::ostream &operator<<(std::ostream &os, const utente &u)
{
    os<<u.pf<<endl;
    os<<"username: "<<u.credenziali.get_username()<<endl<<"password: "<<u.credenziali.get_password()<<endl;
    return os;
}


utente::utente():pf(profilo("ciao","ciao","ciao")),credenziali(accesso("lorenzo","1111"))
{

}

utente::utente(std::string username, std::string password, std::string nome, std::string cognome, std::string email)
    :credenziali(accesso(username,password)),pf(profilo(nome,cognome,email)){}

profilo utente::get_profilo() const
{
    return pf;
}

accesso utente::get_credenziali() const
{
    return credenziali;
}

unsigned int utente::get_punti() const
{
    return punti;
}
