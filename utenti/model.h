#ifndef MODEL_H
#define MODEL_H
#include "utente.h"
class utente;
class model
{
private:
    container<utente> utenti;
public:
    model();
    model(const container<utente>&);
    void aggiungi_utente_gratuito();
    void aggiungi_utente_premium();
    void aggiungi_utente_gold();
    container<utente> get_utenti() const;
};

#endif // MODEL_H
