#ifndef VISTAPROFILO_H
#define VISTAPROFILO_H

#include <QWidget>
#include "account.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include "container.h"



class vistaProfilo:public QWidget
{
    Q_OBJECT
    Account* a;
public:
    vistaProfilo(Account*);
};

#endif // VISTAPROFILO_H
