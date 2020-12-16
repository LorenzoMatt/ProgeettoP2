#ifndef MODEL_H
#define MODEL_H
#include "utente.h"
class Utente;
class Domanda;
class Model
{
private:
    container<Utente> utenti;
    container<Domanda> domande;
public:
    Model();
    Model(const container<Utente>&);
    void aggiungi_utente_gratuito();
    void aggiungi_utente_premium();
    void aggiungi_utente_gold();
    container<Utente> get_utenti() const;
};

#endif // MODEL_H
