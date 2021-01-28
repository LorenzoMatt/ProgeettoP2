#ifndef DOMANDA_H
#define DOMANDA_H

#include "container.h"
#include "commento.h"
#include "utente.h"
class Commento;
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
    Domanda()=delete;
    Domanda(const Domanda&)=delete;//una domanda non può essere copiata
    Domanda(const string&,Utente*,unsigned int);
    Domanda(const string&,Utente*,unsigned int,const container<Commento>&);
    Domanda(const string&,unsigned int,const container<Commento>&);
    Utente* get_autore_domanda() const;
    string get_testo() const; 
    container<Commento> &get_commenti();//possono essere modificati
    void set_priorita(unsigned int); 
    void set_autore(Utente*);
    void aggiungi_commento(const Commento&);
    void rimuovi_commento(unsigned int i);
    bool operator <(const Domanda&) const;
    bool operator <=(const Domanda&) const; 
    bool operator >=(const Domanda&) const;
    bool operator >(const Domanda&) const;
    unsigned int get_priorita() const;
    void set_commenti(const container<Commento>);
};

#endif // DOMANDA_H
