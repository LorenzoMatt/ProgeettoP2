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
#include <vector>
#include <QString>

#include "account.h"
#include "bottonevedicommento.h"

#include "vistaprofilo.h"
class Controller;
class Domanda;

class VistaUtente:public QWidget
{
    Q_OBJECT
    Controller* c;
    Account* a;
    QLabel* numeroDomandePersonali;
    QPushButton* aggiungiDomanda;
    QHBoxLayout* layoutBarraSuperiore;
    QTabWidget* tabella;
    QPushButton* profilo;
    QPushButton* invioDomanda;
    QPushButton* invioUtente;
    QLineEdit* scriviDomanda;
    QLineEdit* scriviUtente;
    std::vector<QPushButton*> domandePersonali;
    std::vector<QPushButton*> domandeAmici;
    QVBoxLayout* layoutWidgetPagina1;
    QVBoxLayout* layoutWidgetPagina2;

    Domanda* dom;


//funzioni di utilitá
    void aggiungiAreaDomandaAmici();
    void aggiungiPulsanteDomandaPersonale();
    void aggiungiPulsanteDomandaAmico();
    void buildBarraSuperiore();
    void buildTabella();

public:
    VistaUtente(Account*,QWidget* parent=nullptr);
    void setController(Controller*);
public slots:
    void vediProfilo();

};

#endif // VISTAUTENTE_H
