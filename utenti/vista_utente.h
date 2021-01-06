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
#include <QErrorMessage>
#include <QMessageBox>
#include "bottonevedicommento.h"
#include "funzioniutili.h"

class Controller;

class VistaUtente:public QWidget
{
    Q_OBJECT
    friend class Controller;
private:
    Controller* c;

    QLabel* numeroDomandePersonali;
    QPushButton* aggiungiDomanda;
    QPushButton* logout;
    QHBoxLayout* layoutBarraSuperiore;
    QTabWidget* tabella;
    QPushButton* profilo;
    QPushButton* invioDomanda;
    QPushButton* invioUtente;
    QLineEdit* scriviDomanda;
    QLineEdit* scriviUtente;
    QVBoxLayout* layoutWidgetPagina1;
    QVBoxLayout* layoutWidgetPagina2;
    QScrollArea* pagina1;
    QScrollArea* pagina2;

//funzioni di utilitá
    void aggiungiAreaDomandaAmici();
    void aggiungiAreaDomandePersonali();
    void aggiungiPulsanteDomandaPersonale();
    void aggiungiPulsanteDomandaAmico();
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
};

#endif // VISTAUTENTE_H
