#ifndef FINESTRANUOVADOMANDA_H
#define FINESTRANUOVADOMANDA_H

#include <QDialog>
#include <QLineEdit>
#include<QDialogButtonBox>
#include <QSpinBox>

class finestraNuovaDomanda : public QDialog
{
    Q_OBJECT

public:
    explicit finestraNuovaDomanda(QWidget *parent = 0);
    ~finestraNuovaDomanda();
private:
    QLineEdit* testo;
    QSpinBox* priorita;
    QDialogButtonBox* conferma;

    void buildPulsanteConferma();

signals:
    void invia(const QString& t,int p);
private slots:
    void dati();
};

#endif // FINESTRANUOVADOMANDA_H
