#ifndef COMMENTO_H
#define COMMENTO_H
#include <string>
#include <iostream>
#include "utente.h"
class Utente;
using std::string;
class Commento
{
    friend std::ostream &operator<<(std::ostream &, const Commento&);
private:
    string testo;
    Utente* autore;
public:
    Commento(const string&,Utente *);
    bool operator==(const Commento&) const;
    string get_testo() const;
    Utente* get_autore() const;
};

#endif // COMMENTO_H
