#ifndef CONTROLLER_ADMIN_H
#define CONTROLLER_ADMIN_H
#include "vistaamministratore.h"
class controllerAdmin
{
public:
    explicit controllerAdmin(vistaAmministratore* =nullptr);
    Database* get_db() const;
    void togli_utente(const string&);
    void salva() const;
    Utente* get_utente(const string&) const;
    void aggiungi_utente(const QString &, const QString &, const QString &,const QString &, const QString &, const QString &);
    void cambia_piano(const QString&, const QString &);
private:
    vistaAmministratore* vista;
    Database* db;
};

#endif // CONTROLLER_ADMIN_H
