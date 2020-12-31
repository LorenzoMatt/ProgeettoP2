#ifndef MODEL_H
#define MODEL_H
#include "utente.h"
#include "deepptr.h"
#include "utente_gia_presente.h"
class Utente;
class Domanda;
class Database
{
private:
    container<DeepPtr<Utente>> utenti;
    bool check_presenza(const string&);
    void sistema_amici_seguaci(Utente*);
    void reverse_seguaci_amici(Utente*);
public:
    Database();
    Database(const container<DeepPtr<Utente>>&);
    const container<DeepPtr<Utente>>& get_utenti() const;
    Utente *get_utente(const string&) const; //OK
    DeepPtr<Utente> *get_utente_deep(const string&username);
    void aggiungi_utente(const DeepPtr<Utente> &);//OK
    void togli_utente(Utente* utente);//OK
    void togli_utente(const string&);
    Utente* cambia_piano(Utente* utente,const string& piano);//OK

};

#endif // MODEL_H
