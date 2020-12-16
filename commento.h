#ifndef COMMENTO_H
#define COMMENTO_H
#include "utente.h"
#include <string>
#include <iostream>


using std::string;
class commento
{
    friend std::ostream &operator<<(std::ostream &, const commento&);
private:
    string testo;
    utente* autore;
public:
    commento(const string&,utente *);
    bool operator==(const commento&) const;
    string GetCommento() const;
    utente* GetAutore() const;
};

#endif // COMMENTO_H
