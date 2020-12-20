#ifndef MODEL_H
#define MODEL_H
#include "utente.h"
#include "deepptr.h"
class Utente;
class Domanda;
class Model
{
private:
    container<DeepPtr<Utente>> utenti;
    container<Domanda> domande;
public:
    Model();
    Model(const container<DeepPtr<Utente>>&);
    void aggiungi_utente_gratuito();
    void aggiungi_utente_premium();
    void aggiungi_utente_gold();
    container<DeepPtr<Utente>> get_utenti() const;
    Utente* get_utente(const string&) const;
};

#endif // MODEL_H
