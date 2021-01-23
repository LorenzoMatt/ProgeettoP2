#ifndef MODEL_H
#define MODEL_H
#include "utente.h"
#include "deepptr.h"
#include "utente_gia_presente.h"

#include <QFile>
#include <QDomDocument>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class Utente;
class Domanda;
class Database
{
private:
    container<DeepPtr<Utente>> utenti;
    bool check_presenza(const string&);
    void sistema_amici_seguaci(Utente*);//serve a togliere dagli amici e dai seguaci di utente il riferimento ad utente
    void reverse_seguaci_amici(Utente*);//aggiunge agli amici e ai seguaci di utente i riferimenti ad utente
    void aggiungi_amici_ad_utente(const string&, const string&);
public:
    Database();
    ~Database();
    Database(const container<DeepPtr<Utente>>&);
    const container<DeepPtr<Utente>>& get_utenti() const;
    Utente *get_utente(const string&) const; 
    void aggiungi_utente(const DeepPtr<Utente> &);
    void togli_utente(Utente* utente);
    void togli_utente(const string&);
    Utente* cambia_piano(Utente* utente,const string& piano);
    Utente* check_credenziali(const string&, const string&) const;
    void importa_dati_utenti();
    void importa_amici_e_domande_utenti();
    void import();
    void exportdati() const;
    void fai_domanda(const string&,const string&,unsigned int);
};

#endif // MODEL_H
