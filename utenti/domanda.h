#ifndef DOMANDA_H
#define DOMANDA_H

#include "container.h"
#include "commento.h"
#include "utente.h"
#include <iostream>
#include <string>
class Commento;
using std::string;
using std::endl;
class Utente;

class Domanda
{
    friend std::ostream &operator<<(std::ostream &, const Domanda&);
private:
    Utente* autore_domanda;
    string testo;
    container<Commento> commenti;
    unsigned int priorita;
    Domanda();
public:
    Domanda(const string&,Utente*,unsigned int);
    void AggiungiCommento(const Commento&);//OK
    void RimuoviCommento(const Commento&);//OK
    Utente* get_autore_domanda() const;//OK

};

#endif // DOMANDA_H
