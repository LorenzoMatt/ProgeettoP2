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
#include <QErrorMessage>
#include <QMessageBox>
#include "bottonevedicommento.h"

class Controller;

class VistaUtente:public QWidget
{
    Q_OBJECT
    friend class Controller;
private:
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

//funzioni di utilitá
    void aggiungiAreaDomandaAmici();
    void aggiungiPulsanteDomandaPersonale();
    void aggiungiPulsanteDomandaAmico();
    void buildBarraSuperiore();
    void buildTabella();

public:
    VistaUtente(const QString&,QWidget* parent=nullptr);
private slots:
    void vediProfilo();
    void buildCercaUtente();
};

#endif // VISTAUTENTE_H
