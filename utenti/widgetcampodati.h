#ifndef WIDGETCAMPODATI_H
#define WIDGETCAMPODATI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <string>
//ciaooo
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

    //utilitá


public:
    widgetCampoDati(const QString& n, const QString& t);

public slots:
    void sbloccaBloccaTesto();
    void annullaModifica();

    void confermaModifica();

signals:


    void invioNome(const QString&);
//    void invioCognome(const QString&);
//    void invioPassword(const QString&);
//    void invioEmail(const QString&);

};

#endif // WIDGETCAMPODATI_H
