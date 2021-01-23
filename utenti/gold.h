#ifndef GOLD_H
#define GOLD_H
#include "pagamento.h"

class Gold : public Pagamento
{
private:
    static unsigned int puntiPerDomandaData;
    static unsigned int puntiDetrattiDomandaFatta;
    static unsigned int limiteDomandeVisualizzate;
    static unsigned int puntiBonus;
    static unsigned int supplementoDomandaPriorita;
    static unsigned int limitePerAverePuntiBonus;
public:
    Gold()=delete;
    Gold(string username,string password,string nome,string cognome,string email, unsigned int= puntiBonus,unsigned int =0);
    Gold(Profilo p,Accesso c,container<Utente*> a,container<Utente*> s,unsigned int punti,unsigned int risposte);
    void cerca_utente(const string&,const Database&, container<string>&) const override;
    void get_punti_domanda() override; 
    void fai_domanda(Domanda* domanda) override;
    void get_punti_bonus() override; 
    Gold* clone() const override;
    string piano() const override;

};

#endif // GOLD_H
