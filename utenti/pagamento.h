#ifndef PAGAMENTO_H
#define PAGAMENTO_H
#include "utente.h"

class Pagamento : public Utente
{
public:
    Pagamento();
    void get_punti_bonus();
    //virtual Pagamento* clone() const;
};

#endif // PAGAMENTO_H
