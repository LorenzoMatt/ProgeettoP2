#ifndef VISTAUTENTE_H
#define VISTAUTENTE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QString>
#include <QLineEdit>
#include <QTabWidget>
#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QScrollArea>
#include <QString>
#include "bottonevedicommento.h"
#include "funzioniutili.h"

class Controller;

class VistaUtente:public QWidget
{
    Q_OBJECT
    friend class Controller;
private:
    Controller* c;

    //totale
    QVBoxLayout* mainLayout;

    //barra superiore
    QHBoxLayout* layoutBarraSuperiore;
    QPushButton* profilo;
    QPushButton* invioDomanda;
    QPushButton* invioUtente;
    QLineEdit* scriviDomanda;
    QLineEdit* scriviUtente;


    //tabella
    QTabWidget* tabella;
    QScrollArea* pagina1;
    QWidget* widgetPagina1;
    QVBoxLayout* layoutWidgetPagina1;
    QVBoxLayout* layoutDomandaAmici;



    QWidget* pagina2;
    QVBoxLayout* layoutPagina2;
    QHBoxLayout* layoutAggiungiDomanda;
    QScrollArea* scrollPagina2;
    QWidget* WidgetScroll2;
    QVBoxLayout* layoutWidgetScroll2;



    QLabel* numeroDomandePersonali;
    QPushButton* aggiungiDomanda;

    //logout
    QPushButton* logout;

//funzioni di utilitá
    void buildBarraSuperiore();
    void buildTabella();



public:
    explicit VistaUtente(const QString&,QWidget* parent=nullptr);
    ~VistaUtente();
private slots:
    void vediProfilo();
    void buildCercaUtente();
    void buildFaiDomanda();
    void buildDomandeCercate();
    void aggiornaAreaDomandeAmici();
    void aggiornaNumeroDomande();
    void buildLogout();
    void aggiungiAreaDomandaAmici();
    void aggiungiAreaDomandePersonali();
};

#endif // VISTAUTENTE_H
