#include "model.h"

Model::Model()
{

}

Model::Model(const container<DeepPtr<Utente> > &u):utenti(u)
{

}

void Model::aggiungi_utente_gratuito()
{

}

void Model::aggiungi_utente_premium()
{

}

void Model::aggiungi_utente_gold()
{

}

container<DeepPtr<Utente> > Model::get_utenti() const
{
    return utenti;
}

Utente *Model::get_utente(const string& username) const
{
    bool trovato=false;
    Utente* utente;
    try{
        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
            if((*it)->get_credenziali().get_username()==username)
            {
                trovato=true;
                utente=&(**it);
            }
        if(!trovato)
            throw amico_non_presente();
    }catch(amico_non_presente)
    {
        std::cerr<<"utente non presente";
    }
    return utente;

}
