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
public:
    Domanda()=delete;
    Domanda(const string&,Utente*,unsigned int);
    Domanda(const Domanda&);
    void aggiungi_commento(const Commento&);//OK
    void RimuoviCommento(const Commento&);//OK
    Utente* get_autore_domanda() const;//OK
    string get_testo() const; //OK
    bool operator <=(const Domanda&) const;
    bool operator >=(const Domanda&) const;
    unsigned int get_priorita() const;
};

#endif // DOMANDA_H
