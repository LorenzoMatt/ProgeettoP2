#include "basic.h"

unsigned int basic::limiteDomandeVisualizzate=5;
unsigned int basic::puntiDetrattiDomandaFatta=10;
unsigned int basic::puntiPerDomandaData=15;
unsigned int basic::limitePerAverePuntiBonus=200;
unsigned int basic::puntiBonus=30;

basic::basic(std::string username, std::string password, std::string nome, std::string cognome, std::string email,unsigned int punti)
    :Utente(username,password,nome,cognome,email,punti)
{

}

void basic::cerca_utente(const Model & model, const std::string & username, container<std::string> & lista_di_elementi, int n) const
{
    Utente* utente = model.get_utente(username);
    Utente::Funtore f(2);//nelle funzioni polimorfe il numero_funtore sarà sostituito con 1 in account gratuito,2 in gold e 3 in premium
    f(utente, lista_di_elementi);
}
