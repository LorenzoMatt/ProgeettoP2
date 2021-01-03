#include "controller_admin.h"

controller_admin::controller_admin() : db(new Database()),vista(new vista_amministratore())
{
    vista->show();
}
