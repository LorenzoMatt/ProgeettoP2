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
    bool modo; //indica come viene visualizzata la password
    QString testoTemporaneo;


public:
    widgetCampoDati(const QString& n, const QString& t,bool m=true);

public slots:
    void sbloccaBloccaTesto();
    void annullaModifica();
    void confermaModifica();


signals:
    void invioNome(const QString&);


};

#endif // WIDGETCAMPODATI_H
