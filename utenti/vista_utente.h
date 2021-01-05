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

#include "bottonevedicommento.h"
#include "stile.h"

class Controller;

class VistaUtente:public QWidget
{
    Q_OBJECT
    Controller* c;

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
    VistaUtente(const QString&,QWidget* parent=nullptr);
public slots:
    void vediProfilo();

};

#endif // VISTAUTENTE_H
