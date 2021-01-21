#ifndef FINESTRAAMICISEGUACI_H
#define FINESTRAAMICISEGUACI_H

#include <QDialog>
#include <QListWidget>
#include "controller.h"

class FinestraAmiciSeguaci : public QDialog
{
    Q_OBJECT

public:
    explicit FinestraAmiciSeguaci(Controller* c, QWidget *parent = 0);
private:
    Controller* controller;
    QTabWidget* tab;
    QListWidget* amici;
    QListWidget* seguaci;


    void buildCercaUtente(const QListWidget *lista);
private slots:
    void buildListe();
    void buildCercaAmico();
    void buildCercaSeguace();
};

#endif // FINESTRAAMICISEGUACI_H
