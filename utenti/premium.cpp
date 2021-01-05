#include "premium.h"

unsigned int Premium::puntiDetrattiDomandaFatta=5;
unsigned int Premium::puntiPerDomandaData=20;
unsigned int Premium::puntiBonus=60;
unsigned int Premium::limitePerAverePuntiBonus=15;
unsigned int Premium::supplementoDomandaPriorita=3;

//Premium::Premium(const Premium &p): Pagamento(p)
//{

//}

Premium::Premium(std::string username, std::string password, std::string nome, std::string cognome, std::string email, unsigned int punti, unsigned int risposte_date)
    :Pagamento(username,password,nome,cognome,email,punti,risposte_date)
{

}

Premium::Premium(Profilo p, Accesso c, container<Utente *> a, container<Utente *> s, container<Domanda *> d, unsigned int punti, unsigned int risposte)
    :Pagamento(p,c,a,s,d,punti< puntiBonus ? puntiBonus : punti,risposte)
{

}

void Premium::cerca_utente(const std::string &username, const Database &model, container<std::string> &lista_di_elementi) const
{
    Utente* utente = model.get_utente(username);
        if(utente)
        {
            Utente::Funtore f(3);//nelle funzioni polimorfe il numero_funtore sarà sostituito con 1 in account gratuito,2 in gold e 3 in premium
            f(utente, lista_di_elementi);
        }
}

void Premium::get_punti_domanda()
{
    punti+=puntiPerDomandaData;
    risposte_date++;
    if(risposte_date>=limitePerAverePuntiBonus)
    {
        get_punti_bonus();
        risposte_date=0;
    }
}

void Premium::fai_domanda(Domanda *domanda)
{
    try{
        if(this==domanda->get_autore_domanda())
        {
            unsigned int punti_da_sottrarre=puntiDetrattiDomandaFatta;
            if(domanda->get_priorita()>=3)
            {
                punti_da_sottrarre+=(supplementoDomandaPriorita*(domanda->get_priorita()-3));
            }
            else
            {
                domanda->set_priorita(3);
            }
            if(punti>=punti_da_sottrarre)
            {
                punti-=punti_da_sottrarre;
                get_domande().push_front(domanda);
            }
            else
            {
                throw punti_non_sufficienti();
            }
        }
        else
        {
            throw non_autore_domanda();
        }
    }catch(non_autore_domanda){
        std::cerr<<"non è l'autore della domanda";
    }
    catch(punti_non_sufficienti){
        std::cerr<<"punti per fare la domanda non sufficienti";
    }
}

void Premium::get_punti_bonus()
{
    punti+=puntiBonus;
}


Premium *Premium::clone() const
{
    return new Premium(*this);
}
