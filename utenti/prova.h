#ifndef PROVA_H
#define PROVA_H

#include <vector>
#include "deepptr.h"
#include "gold.h"
#include "basic.h"
#include "premium.h"
class prova
{
private:
    std::vector<DeepPtr<Utente>> utenti;
public:

    Utente* cambia_piano(Utente* utente,const string& piano);//OK
    void aggiungi_utente(const DeepPtr<Utente> &);//OK
    Utente *get_utente(const string&) const; //OK
    prova();
};

#endif // PROVA_H
