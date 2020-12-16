#ifndef UTENTE_H
#define UTENTE_H
#include "container.h"
#include "profilo.h"
#include "accesso.h"
#include "domanda.h"
#include "model.h"
class utente
{
    friend std::ostream& operator<<(std::ostream& os,const utente& u);
private:
    accesso credenziali;
    profilo pf;
    unsigned int punti=0;
    container<utente*> amici;
    container<utente*> seguaci;
    unsigned int risposte_date;
    container<domanda> domande;
public:
    utente();
    utente(string username,string password,string nome,string cognome,string email);
    profilo get_profilo() const;
    accesso get_credenziali() const;
    unsigned int get_punti() const;
};

#endif // UTENTE_H
