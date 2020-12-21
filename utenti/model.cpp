#include "model.h"

bool Model::check_presenza(const std::string &username)
{
    bool trovato=false;
    for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
    {
        if((*it)->get_credenziali().get_username()==username)
            trovato=true;
    }
    return trovato;
}

Model::Model()
{

}

Model::Model(const container<DeepPtr<Utente> > &u):utenti(u)
{

}

void Model::aggiungi_utente(const DeepPtr<Utente> &utente)
{
    try{
        if(!check_presenza((*utente).get_credenziali().get_username()))
            utenti.push_back(utente);
        else
            throw utente_gia_presente();
    }catch(utente_gia_presente)
    {
        std::cerr<<"utente con questo username già presente";
    }

}

void Model::aggiungi_utente(Utente* utente)
{
    try
    {
        // da implementare il check se è presente un utente con l'username uguale
        if(!check_presenza(utente->get_credenziali().get_username()))
            utenti.push_back(DeepPtr<Utente>(utente));
        else
            throw utente_gia_presente();
    }catch(utente_gia_presente)
    {
        std::cerr<<"utente con questo username già presente";
    }



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

Utente* Model::get_utente(const string& username) const
{
    bool trovato=false;
    try{
        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
            if((*it)->get_credenziali().get_username()==username)
            {
                trovato=true;
                return &(**it);
            }
        if(!trovato)
            throw amico_non_presente();
    }catch(amico_non_presente)
    {
        std::cerr<<"utente non presente";
    }
    return 0;


}

DeepPtr<Utente> *Model::get_utente_deep(const std::string & username)
{
    bool trovato=false;
    try{
        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
            if((*it)->get_credenziali().get_username()==username)
            {
                trovato=true;
                return &(*it);
            }
        if(!trovato)
            throw amico_non_presente();
    }catch(amico_non_presente)
    {
        std::cerr<<"utente non presente";
    }
    return 0;
}
/*Utente* DB::find(const Username& u) const
{
    vector<Utente*>::const_iterator i;
    for(i=db.begin(); i!=db.end(); ++i)
    {
        if((*i)->getUsername()==u)
        {
            return *i;
        }
    }
    return 0;
}*/

