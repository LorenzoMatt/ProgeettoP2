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
    string testo;
    Utente* autore_domanda;
    container<Commento> commenti;
    unsigned int priorita;
public:
    Domanda();
    Domanda(const string&,Utente*,unsigned int);//OK
    Domanda(const string&,Utente*,unsigned int,const container<Commento>&);//OK
    Domanda(const string&,unsigned int,const container<Commento>&);//OK

    Domanda(const Domanda&);//OK
    void aggiungi_commento(const Commento&);//OK
    void rimuovi_commento(unsigned int i);//OK
    Utente* get_autore_domanda() const;//OK
    void set_autore(Utente*);
    string get_testo() const; //OK
    void set_priorita(unsigned int); //OK
    bool operator <(const Domanda&) const;
    bool operator <=(const Domanda&) const; //OK
    bool operator >=(const Domanda&) const;//OK
    bool operator >(const Domanda&) const;
    unsigned int get_priorita() const;//OK
    container<Commento>& get_commenti();//OK
    void set_commenti(const container<Commento>);
//    Domanda& operator =(const Domanda& d);

};

#endif // DOMANDA_H
