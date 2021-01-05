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
    QLineEdit* testoNome;
public:
    vistaProfilo(Controller*,QWidget* parent=nullptr);
signals:
    void inviaNome(const string&);
    void inviaCognome(const string&);
    void inviaPassword(const string&);
    void inviaEmail(const string&);

    void inviaCompetenza(const string&);
    void inviaTitoloDiStudio(const string&);
};

#endif // VISTAPROFILO_H
