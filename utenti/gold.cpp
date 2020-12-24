#include "gold.h"



unsigned int Gold::puntiDetrattiDomandaFatta=8;
unsigned int Gold::puntiPerDomandaData=17;
unsigned int Gold::puntiBonus=50;
unsigned int Gold::supplementoDomandaPriorita=4;
unsigned int Gold::limitePerAverePuntiBonus=20;

Gold::Gold()
{

}

Gold::Gold(std::string username, std::string password, std::string nome, std::string cognome, std::string email,unsigned int punti)
    :Pagamento(username,password,nome,cognome,email,punti)
{

}

Gold::Gold(Profilo p, Accesso c, container<Utente *> a, container<Utente *> s, container<Domanda *> d)
    :Pagamento(p,c,a,s,d)
{

}

void Gold::cerca_utente(const std::string & username, const Model & model, container<std::string> & lista_di_elementi) const
{
    try
    {

        Utente* utente = model.get_utente(username);
        if(utente)
        {
            Utente::Funtore f(2);//nelle funzioni polimorfe il numero_funtore sarà sostituito con 1 in account gratuito,2 in gold e 3 in premium
            f(utente, lista_di_elementi);
        }else
        {
            throw amico_non_presente();
        }
    }catch(amico_non_presente)
    {
        std::cerr<<"utente non presente"<<endl;
    }
}

void Gold::get_punti_domanda()
{
    punti+=puntiPerDomandaData;
    risposte_date++;
    if(risposte_date>=limitePerAverePuntiBonus)
    {
        get_punti_bonus();
    }
}

void Gold::fai_domanda(Domanda *domanda)
{
    try{
        if(this==domanda->get_autore_domanda())
        {
            if(domanda->get_priorita()<=2)
            {
                get_domande().push_back(domanda);
            }
            else
            {
                if(supplementoDomandaPriorita*(domanda->get_priorita()-1)>punti)
                    throw punti_non_sufficienti();
                else{
                    get_domande().push_back(domanda);
                    punti-=(domanda->get_priorita()-1)*supplementoDomandaPriorita;
                }

            }
        }
        else
            throw non_autore_domanda();
    }catch(non_autore_domanda){
        std::cerr<<"non è l'autore della domanda";
    }
    catch(punti_non_sufficienti){
        std::cerr<<"punti per fare la domanda non sufficienti";
    }
    // dovrà essere aggiunta il controllo per il punteggio
}


void Gold::get_punti_bonus()
{
    punti+=puntiBonus;
}

Gold *Gold::clone()
{
    return new Gold(*this);
}

