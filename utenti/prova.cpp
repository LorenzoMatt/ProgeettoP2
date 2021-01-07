#include "prova.h"
#include "amico_non_presente.h"
Utente *prova::cambia_piano(Utente *utente, const std::string &piano)
{

        bool trovato=false;
        try
        {
            for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
            {
                if(&(**it)==utente)
                {
//                    sistema_amici_seguaci(utente);
                    trovato=true;
                    Profilo pf=(*it)->get_profilo();
                    Accesso credenziali=(*it)->get_credenziali();
                    container<Domanda*> domande=(*it)->get_domande();
                    container<Utente*> amici=(*it)->get_amici();
                    container<Utente*> seguaci=(*it)->get_seguaci();
                    unsigned int risposte_date=(*it)->get_risposte_date();
                    unsigned int punti=(*it)->get_punti();
                    it=utenti.erase(it);
    //                Utente* u=0;
                    if(piano=="Basic")
    //                    utenti.push_back(DeepPtr<Utente>(new Basic(pf,credenziali,amici,seguaci,domande,punti,risposte_date)));
                        it=utenti.insert(it,DeepPtr<Utente>(new Basic(pf,credenziali,amici,seguaci,domande,punti,risposte_date)));
                    if(piano=="Gold")
    //                    utenti.push_back(DeepPtr<Utente>(new Gold(pf,credenziali,amici,seguaci,domande,punti,risposte_date)));
                        it=utenti.insert(it,DeepPtr<Utente>(new Gold(pf,credenziali,amici,seguaci,domande,punti,risposte_date)));
                    if(piano=="Premium")
    //                    utenti.push_back(DeepPtr<Utente>(new Premium(pf,credenziali,amici,seguaci,domande,punti,risposte_date)));

                        it=utenti.insert(it,DeepPtr<Utente>(new Premium(pf,credenziali,amici,seguaci,domande,punti,risposte_date)));
    //                u=&*(utenti[utenti.size()]);
    //                reverse_seguaci_amici(u);
//                    reverse_seguaci_amici(&(**it));
    //                return u;
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

void prova::aggiungi_utente(const DeepPtr<Utente> & utente)
{
    utenti.push_back(utente);
}

Utente *prova::get_utente(const std::string & username) const
{
        bool trovato=false;
            for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
                if((*it)->get_credenziali().get_username()==username)
                {
                    trovato=true;
                    return &(**it);
                }
            return 0;
}

prova::prova()
{

}
