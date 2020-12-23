#include "premium.h"

unsigned int Premium::puntiDetrattiDomandaFatta=5;
unsigned int Premium::puntiPerDomandaData=20;
unsigned int Premium::puntiBonus=60;
unsigned int Premium::limitePerAverePuntiBonus=15;
Premium::Premium()
{

}

Premium::Premium(std::string username, std::string password, std::string nome, std::string cognome, std::string email,unsigned int punti)
    :Pagamento(username,password,nome,cognome,email,punti)
{

}

void Premium::cerca_utente(const std::string &username, const Model &model, container<std::string> &lista_di_elementi) const
{
    try
    {

        Utente* utente = model.get_utente(username);
        if(utente)
        {
            Utente::Funtore f(3);//nelle funzioni polimorfe il numero_funtore sarà sostituito con 1 in account gratuito,2 in gold e 3 in premium
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

void Premium::get_punti_domanda()
{
    punti+=puntiPerDomandaData;
    risposte_date++;
    if(risposte_date>=limitePerAverePuntiBonus)
    {
        get_punti_bonus();
    }
}

void Premium::fai_domanda(Domanda *domanda)
{
    try
    {
        if(this==domanda->get_autore_domanda())
        {
            if(punti>=puntiDetrattiDomandaFatta)
            {
                get_domande().push_back(domanda);
                punti-=puntiDetrattiDomandaFatta;
            }
            else
            {
                throw punti_non_sufficienti();
            }
        }else
            throw non_autore_domanda();
    }catch(non_autore_domanda){
        std::cerr<<"non è l'autore della domanda";
    }
    catch(punti_non_sufficienti)
    {
        std::cerr<<"punti non sufficienti";
    }
}

void Premium::get_punti_bonus()
{
    punti+=puntiBonus;
}

Premium *Premium::clone()
{
    return new Premium(*this);
}
