#include "gold.h"



unsigned int Gold::puntiDetrattiDomandaFatta=8;
unsigned int Gold::puntiPerDomandaData=17;
unsigned int Gold::puntiBonus=50;
unsigned int Gold::supplementoDomandaPriorita=4;
unsigned int Gold::limitePerAverePuntiBonus=25;

//Gold::Gold(const Gold & g) : Pagamento(g)
//{

//}

Gold::Gold(std::string username, std::string password, std::string nome, std::string cognome, std::string email, unsigned int punti, unsigned int risposte_date)
    :Pagamento(username,password,nome,cognome,email,punti,risposte_date)
{
}

Gold::Gold(Profilo p, Accesso c, container<Utente *> a, container<Utente *> s, unsigned int punti, unsigned int risposte)
    :Pagamento(p,c,a,s,punti<puntiBonus ? puntiBonus : punti,risposte)
{

}

void Gold::cerca_utente(const std::string & username, const Database & model, container<std::string> & lista_di_elementi) const
{
        Utente* utente = model.get_utente(username);
        if(utente)
        {
            Utente::Funtore f(2);//nelle funzioni polimorfe il numero_funtore sarà sostituito con 1 in account gratuito,2 in gold e 3 in premium
            f(utente, lista_di_elementi);
        }
}

void Gold::get_punti_domanda()
{
    punti+=puntiPerDomandaData;
    risposte_date++;
    if(risposte_date>=limitePerAverePuntiBonus)
    {
        get_punti_bonus();
        risposte_date=0;
    }
}

void Gold::fai_domanda(Domanda *domanda)
{
    unsigned int punti_da_sottrarre=puntiDetrattiDomandaFatta;
    if(domanda->get_priorita()>=2)
    {
        punti_da_sottrarre+=(supplementoDomandaPriorita*(domanda->get_priorita()-2));
    }
    else
    {
        domanda->set_priorita(2);
    }
    if(punti>=punti_da_sottrarre)
    {
        punti-=punti_da_sottrarre;
        get_domande_rif().push_front(domanda);
    }
    else
    {
        throw punti_non_sufficienti();
    }
}


void Gold::get_punti_bonus()
{
    punti+=puntiBonus;
}

Gold *Gold::clone() const
{
    return new Gold(*this);
}

std::string Gold::piano() const
{
    return "Gold";
}



