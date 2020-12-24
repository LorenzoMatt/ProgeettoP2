#include "model.h"
#include "basic.h"
#include "gold.h"
 #include "premium.h"

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
        if(!check_presenza(utente->get_credenziali().get_username()))
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

void Model::togli_utente(Utente *utente)
{
    bool trovato=false;
    try
    {
        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
        {
            if(&(**it)==utente)
            {
                utenti.erase(it);
                trovato=true;
            }
        }
        if(!trovato)
        {
            throw amico_non_presente();
        }
    }catch(amico_non_presente)
    {
        std::cerr<<"utente non presente";
    }
}

void Model::cambia_piano(Utente *utente, const std::string &piano)
{
    bool trovato=false;
    try
    {
        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
        {
            if(&(**it)==utente)
            {
                trovato=true;
                Profilo pf=(*it)->get_profilo();
                Accesso credenziali=(*it)->get_credenziali();
                container<Domanda*> domande=(*it)->get_domande();
                container<Utente*> amici=(*it)->get_amici();
                container<Utente*> seguaci=(*it)->get_seguaci();
                if(piano=="Basic")
                    utenti.insert(utenti.erase(it),DeepPtr<Utente>(new Basic(pf,credenziali,amici,seguaci,domande)));
                if(piano=="Gold")
                    utenti.insert(utenti.erase(it),DeepPtr<Utente>(new Gold(pf,credenziali,amici,seguaci,domande)));
                if(piano=="Premium")
                    utenti.insert(utenti.erase(it),DeepPtr<Utente>(new Premium(pf,credenziali,amici,seguaci,domande)));
            }
        }
        if(!trovato)
            throw amico_non_presente();
    }catch(amico_non_presente)
    {
        std::cerr<<"utente non trovato";
    }
}

const container<DeepPtr<Utente>>& Model::get_utenti() const
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

