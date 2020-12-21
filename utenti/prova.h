#ifndef PROVA_H
#define PROVA_H
#include "container.h"
#include "utente.h"
class Prova
{
private:
    container<Utente*> utenti;
public:
    Prova();
    void add(Utente*);
    Utente *find(const string&);
};

#endif // PROVA_H
