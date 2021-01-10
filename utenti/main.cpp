
#include <QApplication>
#include "database.h"
#include "controller.h"
#include "account.h"
#include "basic.h"
#include "gold.h"
#include "premium.h"
#include "log.h"

int main(int argc ,char** argv)
{

   QApplication x(argc, argv);
   Login v;
   v.show();
   return x.exec();
}
