#include "model.h"

model::model()
{

}

model::model(const container<utente>& u):utenti(u)
{

}

void model::aggiungi_utente_gratuito()
{

}

void model::aggiungi_utente_premium()
{

}

void model::aggiungi_utente_gold()
{

}

container<utente> model::get_utenti() const
{
    return utenti;
}
