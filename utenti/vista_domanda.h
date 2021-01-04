#ifndef VISTA_DOMANDA_H
#define VISTA_DOMANDA_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QString>
#include <QLineEdit>
#include <QTabWidget>
#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QTextEdit>
#include "domanda.h"

class vista_domanda : public QWidget
{
    Q_OBJECT
    QVBoxLayout* domanda;
    QScrollArea* scrollarea;
    QWidget* scrollwidget;
    QVBoxLayout* scrollwidgetLayout;










    //funzioni di utilitá:

    //aggiunge allo scrollwidgetLayout il widget che contiene la domanda
    void aggiungiWidgetDomanda(Domanda*);

    //aggiunge allo scrollWidgetLayout il widget che contiene tutti i commenti relativi alla domanda
    void aggiungiWidgetCommenti(Domanda*);

    //aggiunge una barra di testo editabile con il pulsante invio
    void aggiungiBarraDiTesto();




public:
    explicit vista_domanda(Domanda*,QWidget *parent = nullptr);

};

#endif // VISTA_DOMANDA_H
