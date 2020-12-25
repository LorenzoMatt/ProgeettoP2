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
    Domanda(const string&,Utente*,unsigned int);//OK
    Domanda(const Domanda&);//OK
    void aggiungi_commento(const Commento&);//OK
    void rimuovi_commento(const Commento&);//OK
    Utente* get_autore_domanda() const;//OK
    string get_testo() const; //OK
    void set_priorita(unsigned int); //OK
    bool operator <=(const Domanda&) const; //OK
    bool operator >=(const Domanda&) const;//OK
    unsigned int get_priorita() const;//OK
};

#endif // DOMANDA_H
