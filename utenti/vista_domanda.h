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
#include "funzioniutili.h"
#include "controller.h"

class vista_domanda : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* domanda;
    QScrollArea* scrollarea;
    QWidget* scrollwidget;
    QVBoxLayout* scrollwidgetLayout;
//    Controller* controller;
    QLineEdit* testoCommento;



    //funzioni di utilitá:

    //aggiunge allo scrollwidgetLayout il widget che contiene la domanda
    void aggiungiWidgetDomanda(Domanda*);

    //aggiunge allo scrollWidgetLayout il widget che contiene tutti i commenti relativi alla domanda
    void aggiungiWidgetCommenti(Domanda*);

    //aggiunge una barra di testo editabile con il pulsante invio
    void aggiungiBarraDiTesto();
public:
    explicit vista_domanda(Domanda*, QWidget *parent = 0);
signals:
    void commento(const QString&);
    void like(int);
    void rimuovi(int);
private slots:
    void buildCommento();
    void buildLike(int);// riceve la posizione del commento in cui inserire il like
    void buildRimuovi(int);// riceve la posizione del commento da togliere
};

#endif // VISTA_DOMANDA_H
