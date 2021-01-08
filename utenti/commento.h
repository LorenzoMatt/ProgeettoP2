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
    string autore;
    bool like;
public:
    Commento(const string&,Utente *,bool l=false);
    Commento(const string&,const string&,bool l=false);
    bool operator==(const Commento&) const;
    string get_testo() const;
    string get_autore() const;
    void set_like(bool);
    bool get_like() const;
};

#endif // COMMENTO_H
