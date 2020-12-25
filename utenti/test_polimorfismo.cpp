#include "test_polimorfismo.h"
#include "home.h"
#include <QApplication>
#include "model.h"
#include <list>
#include "deepptr.h"
#include <memory>
#include "prova.h"
#include "premium.h"
#include "gold.h"
#include "basic.h"

int test_polimorfismo()
{
    Utente* b=new Basic("b","password","nome","cogmone","email");
    Utente* g=new Utente("g","password","nome","cogmone","email");
    Utente* p=new Premium("p","password","nome","cogmone","email");
}
