#include "pagamento.h"

//Pagamento::Pagamento(const Pagamento & p) : Utente(p)
//{

//}

Pagamento::Pagamento(std::string username, std::string password, std::string nome, std::string cognome, std::string email,unsigned int punti)
    :Utente(username,password,nome,cognome,email,punti)
{

}

Pagamento::Pagamento(Profilo p, Accesso c, container<Utente *> a, container<Utente *> s, container<Domanda *> d,unsigned int punti, unsigned int risposte)
    :Utente(p,c,a,s,d,punti,risposte)
{

}
container<Domanda *> Pagamento::cerca_domanda(const std::string & domanda, const Model & m) const
{
    container<string> domanda_fatta=split(domanda," ");// divido la stringa domanda per spazi
    container<Domanda*> domande_trovate_amici;
    for(auto it=get_amici().begin();it!=get_amici().end();++it)//scorro gli amici
    {
        const container<Domanda*>& domande_utente=(*it)->get_domande();//lista di domande dell'amico esaminato
        for(auto dt=domande_utente.begin();dt!=domande_utente.end();++dt)// scorro la lista delle domande dell'amico corrente
        {
            container<string> domanda_esaminata=split((*dt)->get_testo()," ");// divido la domanda corrente per spazi
            unsigned int lunghezza_parola_esaminata=domanda_esaminata.countElements();
            unsigned int count=0;//numero di parole che matchano fra domanda_fatta e domande_esaminata
            for(auto ut=domanda_esaminata.begin();ut!=domanda_esaminata.end() && count<=(lunghezza_parola_esaminata*0.6);++ut)
                //scorri le parole della domanda_esaminata
            {
                bool ok=false;
                for(auto d=domanda_fatta.begin();d!=domanda_fatta.end() && !ok;++d)//scorro le parole  della domanda fatta
                {
                    if(*ut==*d)//confronto fra parola della domanda_esaminata e della parola della domanda_fatta
                    {
                        ok=true;
                        count++;//incremento il numero di parole uguali fra la domanda fatta e quella esaminata
         }
                }

             }
            if(count>=(lunghezza_parola_esaminata*0.6))// basterebbe ==
            {
                domande_trovate_amici.insertion_sort_pointer(&*dt);
            }
        }

    }

    container<Domanda*> domande_trovate_modello;
    for(auto it=m.get_utenti().begin();it!=m.get_utenti().end();++it)
    {
        if(&**it!=this && (!(check_presenza_amico((*it)->get_credenziali().get_username()))))
// se non è se stesso e se l'utente esaminato non è fra gli amici
        {
            const container<Domanda*>& domande_utente=(*it)->get_domande();//lista di domande dell'amico esaminato
            for(auto dt=domande_utente.begin();dt!=domande_utente.end();++dt)// scorro la lista delle domande dell'amico corrente
            {
                container<string> domanda_esaminata=split((*dt)->get_testo()," ");// divido la domanda corrente per spazi
                unsigned int lunghezza_parola_esaminata=domanda_esaminata.countElements();
                unsigned int count=0;//numero di parole che matchano fra domanda_fatta e domande_esaminata
                for(auto ut=domanda_esaminata.begin();ut!=domanda_esaminata.end() && count<=(lunghezza_parola_esaminata*0.6);++ut)
                    //scorri le parole della domanda_esaminata
                {
                    bool ok=false;
                    for(auto d=domanda_fatta.begin();d!=domanda_fatta.end() && !ok;++d)//scorro le parole  della domanda fatta
                    {
                        if(*ut==*d)//confronto fra parola della domanda_esaminata e della parola della domanda_fatta
                        {
                            ok=true;
                            count++;//incremento il numero di parole uguali fra la domanda fatta e quella esaminata
                        }
                    }

                }
                if(count>=(lunghezza_parola_esaminata*0.6))// basterebbe ==
                {
                    domande_trovate_modello.insertion_sort_pointer(&*dt);
                }
            }
        }
    }
    return domande_trovate_amici+domande_trovate_modello;
}

