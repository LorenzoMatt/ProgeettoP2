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


class vista_domanda : public QWidget
{
    Q_OBJECT
    QVBoxLayout* domanda;

    //funzioni di utilitá:

    //ritorna un blocco autore/testo
    QVBoxLayout* addAutoreDomanda();

    //ritorna un blocco autore/testo/barra rimuovi e like
    QVBoxLayout *addAutoreDomandaLike();

public:
    explicit vista_domanda(QWidget *parent = nullptr);

signals:

};

#endif // VISTA_DOMANDA_H
