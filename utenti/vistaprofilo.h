#ifndef VISTAPROFILO_H
#define VISTAPROFILO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include "container.h"
#include "controller.h"
#include "stile.h"



class vistaProfilo:public QWidget
{
    Q_OBJECT
    Controller* a;
public:
    vistaProfilo(Controller*);

};

#endif // VISTAPROFILO_H
