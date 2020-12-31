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


//funzioni di utilitá
    QScrollArea *aggiungiAreaDomanda();
    void aggiungiPulsanteDomandaPersonale();
    void aggiungiPulsanteDomandaAmico();
    void buildBarraSuperiore();
    void buildTabella();

public:
    VistaUtente(QWidget* parent=nullptr);
    void setController(Controller*);



};

#endif // VISTAUTENTE_H
