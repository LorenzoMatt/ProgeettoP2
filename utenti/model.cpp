#include "model.h"
#include "basic.h"
#include "gold.h"
#include "premium.h"


Database::Database()
{

}

bool Database::check_presenza(const std::string &username)
{
    bool trovato=false;
    for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
    {
        if((*it)->get_credenziali().get_username()==username)
            trovato=true;
    }
    return trovato;
}

void Database::sistema_amici_seguaci(Utente* utente)
{
        for(auto it=utente->seguaci.begin();it!=utente->seguaci.end();++it)
        {
            (*it)->togli_amico_ausiliario(utente);
        }
        for(auto it=utente->amici.begin();it!=utente->amici.end();++it)
        {
            (*it)->togli_seguace_ausiliario(utente);
        }
}

void Database::reverse_seguaci_amici(Utente* utente)
{
        for(auto it=utente->seguaci.begin();it!=utente->seguaci.end();++it)
        {
            (*it)->amici.push_back(utente);
        }
        for(auto it=utente->amici.begin();it!=utente->amici.end();++it)
        {
            (*it)->seguaci.push_back(utente);
        }
}

Database::Database(const container<DeepPtr<Utente> > &u):utenti(u)
{
}

void Database::aggiungi_utente(const DeepPtr<Utente> &utente)
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

void Database::togli_utente(Utente *utente)
{
    bool trovato=false;
    try
    {
        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
        {
            if(&(**it)==utente)
            {
                sistema_amici_seguaci(utente);
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

void Database::togli_utente(const std::string & username)
{
        bool trovato=false;
        try
        {
            for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
            {
                if((*it)->get_credenziali().get_username()==username)
                {
                    sistema_amici_seguaci(&(**it));
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

Utente* Database::cambia_piano(Utente *utente, const std::string &piano)
{
    bool trovato=false;
    try
    {
        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
        {
            if(&(**it)==utente)
            {
                sistema_amici_seguaci(utente);
                trovato=true;
                Profilo pf=(*it)->get_profilo();
                Accesso credenziali=(*it)->get_credenziali();
                container<Domanda*> domande=(*it)->get_domande();
                container<Utente*> amici=(*it)->get_amici();
                container<Utente*> seguaci=(*it)->get_seguaci();
                unsigned int risposte_date=(*it)->get_risposte_date();
                unsigned int punti=(*it)->get_punti();
                if(piano=="Basic")
                    it=utenti.insert(utenti.erase(it),DeepPtr<Utente>(new Basic(pf,credenziali,amici,seguaci,domande,punti,risposte_date)));
                if(piano=="Gold")
                    it=utenti.insert(utenti.erase(it),DeepPtr<Utente>(new Gold(pf,credenziali,amici,seguaci,domande,punti,risposte_date)));
                if(piano=="Premium")
                    it=utenti.insert(utenti.erase(it),DeepPtr<Utente>(new Premium(pf,credenziali,amici,seguaci,domande,punti,risposte_date)));
                reverse_seguaci_amici(&(**it));
                return &(**it);
            }
        }
        if(!trovato)
            throw amico_non_presente();
    }catch(amico_non_presente)
    {
        std::cerr<<"utente non trovato";
    }
    return nullptr;
}

const container<DeepPtr<Utente>>& Database::get_utenti() const
{
    return utenti;
}

Utente* Database::get_utente(const string& username) const
{
    bool trovato=false;

        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
            if((*it)->get_credenziali().get_username()==username)
            {
                trovato=true;
                return &(**it);
            }
        if(!trovato)
            throw amico_non_presente();
    return 0;

}

DeepPtr<Utente> *Database::get_utente_deep(const std::string & username)
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
