#ifndef CONTROLLER_ADMIN_H
#define CONTROLLER_ADMIN_H
#include "vista_amministratore.h"
#include "database.h"
class controller_admin
{
public:
    controller_admin();
private:
    vista_amministratore* vista;
    Database* db;
};

#endif // CONTROLLER_ADMIN_H
