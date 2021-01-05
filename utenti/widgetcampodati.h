#ifndef WIDGETCAMPODATI_H
#define WIDGETCAMPODATI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>

enum{Nome,Cognome,Email,Password};

class widgetCampoDati:public QWidget
{
    Q_OBJECT
    int tipo;

    QVBoxLayout* layoutTotale;

    QVBoxLayout* layoutNome;
    QLineEdit* testoNome;

    QHBoxLayout* layoutModNome;
    QPushButton* modNome;
    QPushButton* canc;

public:
    widgetCampoDati(const QString& n, const QString& t, const int &ti);

public slots:
    void sbloccaBloccaTesto();
    void annullaModifica();
    void confermaModifica();
};

#endif // WIDGETCAMPODATI_H
