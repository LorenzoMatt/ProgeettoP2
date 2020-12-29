#ifndef VISTAUTENTE_H
#define VISTAUTENTE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QString>
#include <QLineEdit>
#include <QTabWidget>
#include <QMainWindow>
#include <QTextBrowser>
#include <QLabel>
#include <QScrollArea>
#include <QGroupBox>
#include "domanda.h"
#include "basic.h"

class vistaUtente:public QWidget
{
    Q_OBJECT

    QHBoxLayout* barraDiRicerca;
    QTabWidget* tabella;
    QScrollArea* pagina;
    QScrollArea* pagina1;
    QScrollArea* pagina2;
//    void creaBarraDiRicerca();
//    void creaTabella();

//    void SpazioDomandaAmici(QScrollArea *pagina);
public:
    vistaUtente(QWidget* parent=nullptr);


};

#endif // VISTAUTENTE_H
