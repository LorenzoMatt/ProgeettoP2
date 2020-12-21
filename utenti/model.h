#ifndef MODEL_H
#define MODEL_H
#include "utente.h"
#include "deepptr.h"
#include "utente_gia_presente.h"
class Utente;
class Domanda;
class Model
{
private:
    container<DeepPtr<Utente>> utenti;
    container<Domanda> domande;
    bool check_presenza(const string&);
public:
    Model();
    Model(const container<DeepPtr<Utente>>&);
    void aggiungi_utente(const DeepPtr<Utente> &);
    void aggiungi_utente(Utente *);
    void aggiungi_utente_gratuito();
    void aggiungi_utente_premium();
    void aggiungi_utente_gold();
    container<DeepPtr<Utente>> get_utenti() const;
    Utente *get_utente(const string&) const;
    DeepPtr<Utente> *get_utente_deep(const string&username);
};

#endif // MODEL_H
