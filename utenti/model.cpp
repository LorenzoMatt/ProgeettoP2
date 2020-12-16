#include "model.h"

Model::Model()
{

}

Model::Model(const container<Utente>& u):utenti(u)
{

}

void Model::aggiungi_utente_gratuito()
{

}

void Model::aggiungi_utente_premium()
{

}

void Model::aggiungi_utente_gold()
{

}

container<Utente> Model::get_utenti() const
{
    return utenti;
}
