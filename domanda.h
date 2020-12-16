#ifndef DOMANDA_H
#define DOMANDA_H

#include "Container.h"

#include "commento.h"
#include <iostream>
#include <string>

using container::dList;
using std::string;
using std::endl;


class domanda
{
    friend std::ostream &operator<<(std::ostream &, const domanda&);
private:

    string testo;
    dList<commento> commenti;
public:
    domanda(const string&);
    void AggiungiCommento(const commento&);
    void RimuoviCommento(const commento&);

};

#endif // DOMANDA_H
