#ifndef CONTROLLER_ADMIN_H
#define CONTROLLER_ADMIN_H
#include "vista_amministratore.h"
class controller_admin
{

public:
    explicit controller_admin(vista_amministratore* =nullptr);
    Database* get_db() const;
    void togli_utente(const string&);
    void salva() const;
    Utente* get_utente(const string&) const;
    void aggiungi_utente(const QString &, const QString &, const QString &,const QString &, const QString &, const QString &);
    void cambia_piano(const QString&, const QString &);
    void set_vista(vista_amministratore* v);
private:
    vista_amministratore* vista;
    Database* db;
};

#endif // CONTROLLER_ADMIN_H
