#include <QApplication>
#include "log.h"

int main(int argc ,char** argv)
{
   QApplication x(argc, argv);
   Login v;
   v.show();
   return x.exec();
}
