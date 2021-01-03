#ifndef CONTROLLER_ADMIN_H
#define CONTROLLER_ADMIN_H
#include "vista_amministratore.h"
#include "database.h"
class vista_amministratore;
class controller_admin
{
public:
    controller_admin(/*vista_amministratore* =nullptr,*/Database* d=new Database());
    ~controller_admin();
    Database* get_db() const;
    void togli_utente(const string&);
    void salva() const;
    Utente* get_utente(const string&) const;
    void aggiungi_utente(const string & username, const string & password, const string & nome,
                         const string & cognome, const string & email,const string& piano);
private:
//    vista_amministratore* vista;
    Database* db;

};

#endif // CONTROLLER_ADMIN_H
