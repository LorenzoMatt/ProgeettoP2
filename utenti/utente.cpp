#include "utente.h"



std::ostream &operator<<(std::ostream &os, const Utente &u) //OK
{
    os<<u.pf<<endl;
    os<<"username: "<<u.credenziali.get_username()<<endl<<"password: "<<u.credenziali.get_password()<<endl;
    return os;
}

Utente::~Utente()
{
    unsigned int i=1;
    for(auto it=domande.begin();it!=domande.end();++it,i++)
    {
        Domanda* d=*it;
        delete d;
        cout<<"delete domanda n. "<<i<<endl;
    }
}

Utente::Utente(const Utente &u):pf(u.pf),credenziali(u.credenziali),amici(u.amici),seguaci(u.seguaci),domande(u.domande),punti(u.punti),risposte_date(u.risposte_date)
{

}


Utente::Utente(std::string username, std::string password, std::string nome, std::string cognome, std::string email, unsigned int punti)
    :pf(Profilo(nome,cognome,email)),credenziali(Accesso(username,password)),punti(punti),risposte_date(0){}

Utente::Utente(Profilo p, Accesso c, container<Utente *> a, container<Utente *> s, container<Domanda *> d, unsigned int punti, unsigned int risposte)
    :pf(p),credenziali(c),amici(a),seguaci(s),domande(d),punti(punti),risposte_date(risposte)
{

}

Profilo Utente::get_profilo() const  //OK
{
    return pf;
}

Accesso Utente::get_credenziali() const //OK
{
    return credenziali;
}

unsigned int Utente::get_punti() const
{
    return punti;
}

unsigned int Utente::get_risposte_date() const
{
    return risposte_date;
}

void Utente::modifica_password(const std::string & pw)
{
    credenziali.set_password(pw);
}

//void Utente::fai_domanda(Domanda* domanda)// il sollevamento dell'eccezione funziona a dovere
//{
//    try{
//        if(this==domanda->get_autore_domanda())
//            domande.push_back(domanda);
//        else
//            throw non_autore_domanda();
//    }catch(non_autore_domanda){
//        std::cerr<<"non è l'autore della domanda";
//    }
//}

//Utente *Utente::clone()
//{
//    return new Utente(*this);
//}
void Utente::togli_amico_ausiliario(Utente *utente) // funziona ma il codice commentato non funziona e non so perchè
{
    bool tolto=false;

    for(auto it=amici.begin();it!=amici.end() && !tolto;++it)
        if((*it)==utente)
        {
            amici.erase(it);
            tolto=true;
        }
}
void Utente::aggiungi_seguace(Utente& utente) //OK
{
    if(this!=&utente)
    {
    seguaci.push_back(&utente);
    }
}
void Utente::aggiungi_amico(Utente* utente) //OK
{
    try
    {
        if(this!=utente)
        {
            amici.push_back(utente);
            utente->aggiungi_seguace(*this);
        }else
        {
            throw(amico_non_presente());
        }
    }catch(amico_non_presente)
    {
        std::cerr<<"non ti puoi aggiungere fra gli amici!";
        return;
    }
}

void Utente::togli_amico(Utente *utente) // OK, serve a togliere un utente dalla sua lista degli amici se presente e
//l'utente che ha tolto l'amico dalla lista viene rimosso dalla lista dei seguaci dell'ex amico
{
    bool tolto=false;

    try{
        if(this!=utente){
        for(auto it=amici.begin();it!=amici.end() && !tolto;++it)
            if((*it)==utente)
            {
                amici.erase(it);
                tolto=true;
                utente->togli_seguace_ausiliario(this); // tolto dai seguaci di utente
            }
        if(!tolto)
            throw amico_non_presente();
        }else{
             throw togliere_te_stesso_dagli_amici();
        }
    }
    catch(amico_non_presente)
    {
        std::cerr<<"amico non trovato";
        return;
    }
    catch(togliere_te_stesso_dagli_amici) //funziona
    {
        std::cerr<<"non puoi togliere te stesso dagli amici!";
        return;
    }
}

void Utente::cerca_amico(const std::string & username, container<std::string>& lista_di_elementi) const{

    try
    {
            Utente* utente;
            bool trovato=false;
            for(auto it=amici.begin();it!=amici.end() && !trovato;++it)
                if((*it)->get_credenziali().get_username()==username){
                    trovato=true;
                    utente=*it;
                }
            if(!trovato){
                throw amico_non_presente();
            }

            Utente::Funtore f(3);//nelle funzioni polimorfe il numero_funtore sarà sostituito con 1 in account gratuito,2 in gold e 3 in premium
            f(utente, lista_di_elementi);
    }
    catch(amico_non_presente){
        std::cerr<<"utente non presente";
    }
}

container<Domanda *> Utente::get_domande_amici() const
{
    container<Domanda *> domande;
    for(auto it=amici.begin();it!=amici.end();++it){
       domande=domande+(*it)->get_domande();
    }
    return domande;
}

void Utente::togli_seguace_ausiliario(Utente *utente) // È stato testato, ma non so perchè se tolgo il booleano non funziona
// serve a togliere un seguace dalla propria lista. È una funzione utilizzata da togli_amico
{
    bool tolto=false;

for(auto it=seguaci.begin();it!=seguaci.end() && !tolto;++it)
    if((*it)==utente)
    {
        seguaci.erase(it);
        tolto=true;
    }

}

bool Utente::check_presenza_amico(const std::string & username) const
{
    bool trovato=false;
    for(auto it=amici.begin();it!=amici.end() && !trovato;++it)
    {
        if((*it)->get_credenziali().get_username()==username)
            trovato=true;
    }
    return trovato;

}

container<std::string> Utente::split(const std::string & text, const std::string & delims)
{
       container<string> tokens;
        std::size_t start = text.find_first_not_of(delims), end = 0;

        while((end = text.find_first_of(delims, start)) != std::string::npos)
        {
            tokens.push_back(text.substr(start, end - start));
            start = text.find_first_not_of(delims, end);
        }
        if(start != std::string::npos)
            tokens.push_back(text.substr(start));

        return tokens;
}
void Utente::togli_seguace(Utente *utente) // OK, toglie un suo seguace dalla coda se è presente e l'utente che ha rimosso il
//seguace viene a sua volta tolto dalla lista degli amici dell'ex seguace
{
    bool tolto=false;
    try{
    for(auto it=seguaci.begin();it!=seguaci.end() && !tolto;++it)
        if((*it)==utente)
        {
            seguaci.erase(it);
            tolto=true;
            utente->togli_amico_ausiliario(this);
        }
    if(!tolto)
        throw amico_non_presente();
    }catch(amico_non_presente){
        std::cerr<<"seguace non trovato";
        return;
    }
}


container<Utente *> &Utente::get_amici()//OK
{
    return amici;
}

const container<Utente *> &Utente::get_seguaci() const // OK
{
    return seguaci;
}

container<Domanda *> &Utente::get_domande()
{
    return domande;
}

const container<Utente *> &Utente::get_amici() const
{
    return amici;
}

void Utente::set_nome_profilo(const string & nome)
{
    pf.SetNome(nome);
}

void Utente::scrivi_commento(Domanda *d, std::string risposta)
{
    d->aggiungi_commento(Commento(risposta,this));
}

void Utente::dai_punti(Utente* utente) const
{
    utente->get_punti();
}

//container<Domanda *> Utente::cerca_domanda(const std::string & domanda, const Model & m)//OK, manca da implementare un insertion_sort in modo da avere una lista ordinata doi domande
//{
//    container<string> domanda_fatta=split(domanda," ");// divido la stringa domanda per spazi
//    container<Domanda*> domande_trovate;
//    for(auto it=amici.begin();it!=amici.end();++it)//scorro gli amici
//    {
//        const container<Domanda*>& domande_utente=(*it)->get_domande();//lista di domande dell'amico esaminato
//        for(auto it=domande_utente.begin();it!=domande_utente.end();++it)// scorro la lista delle domande dell'amico corrente
//        {
//            container<string> domanda_esaminata=split((*it)->get_testo()," ");// divido la domanda corrente per spazi
//            unsigned int lunghezza_parola_esaminata=domanda_esaminata.countElements();
//            unsigned int count=0;//numero di parole che matchano fra domanda_fatta e domande_esaminata
//            for(auto ut=domanda_esaminata.begin();ut!=domanda_esaminata.end() && count<=(lunghezza_parola_esaminata*0.6);++ut)
//                //scorri le parole della domanda_esaminata
//            {
//                bool ok=false;
//                for(auto d=domanda_fatta.begin();d!=domanda_fatta.end() && !ok;++d)//scorro le parole  della domanda fatta
//                {
//                    if(*ut==*d)//confronto fra parola della domanda_esaminata e della parola della domanda_fatta
//                    {
//                        ok=true;
//                        count++;//incremento il numero di parole uguali fra la domanda fatta e quella esaminata
//                    }
//                }

//             }
//            if(count>=(lunghezza_parola_esaminata*0.6))// basterebbe ==
//            {
//                domande_trovate.insertion_sort(*it);
//            }
//        }

//    }
//    return domande_trovate;
//}


string Utente::get_username_amici() const //OK
{
    string username;
    for(container<Utente*>::const_iterator it=amici.begin();it!=amici.end();++it)
        username=username+" "+(*it)->get_credenziali().get_username();
    return username;
}

//void Utente::cerca_utente(const string & username, const Model & model, container<std::string> &lista_di_elementi, int numero_funtore) const
//{
//    Utente* utente = model.get_utente(username);
//    Utente::Funtore f(numero_funtore);//nelle funzioni polimorfe il numero_funtore sarà sostituito con 1 in account gratuito,2 in gold e 3 in premium
//    f(utente, lista_di_elementi);
//}

void Utente::AggiungiCompetenza(const std::string & competenza)
{
    pf.AggiungiCompetenza(competenza);
}

void Utente::AggiungiTitoloDiStudio(const std::string & titolo)
{
    pf.AggiungiTitoloDiStudio(titolo);
}


Utente::Funtore::Funtore(int x) : search(x)
{

}

void Utente::Funtore::operator()(const Utente *ut, container<std::string> &l) const
{
    {
        switch(search)
        {
            case 1:
                l.push_back(ut->credenziali.get_username());
                l.push_back(ut->pf.GetNome());
                l.push_back(ut->pf.GetCognome());
                l.push_back(ut->pf.GetEmail());
                break;

            case 2:
                l.push_back(ut->credenziali.get_username());
                l.push_back(ut->pf.GetNome());
                l.push_back(ut->pf.GetCognome());
                l.push_back(ut->pf.GetEmail());
                l.push_back(ut->pf.titoli_di_studio_toString());
                l.push_back(ut->pf.competenze_toString());
                break;

            case 3:
                l.push_back(ut->credenziali.get_username());
                l.push_back(ut->pf.GetNome());
                l.push_back(ut->pf.GetCognome());
                l.push_back(ut->pf.GetEmail());
                l.push_back(ut->pf.titoli_di_studio_toString());
                l.push_back(ut->pf.competenze_toString());
                l.push_back(ut->get_username_amici());
                break;
        }
    }
}
