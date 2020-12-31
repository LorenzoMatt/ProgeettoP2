#ifndef CREAUTENTE_H
#define CREAUTENTE_H

#include <QDialog>

#include<QComboBox>
#include<QLineEdit>
#include<QDialogButtonBox>
class creautente : public QDialog
{
    Q_OBJECT

public:
    explicit creautente(QWidget *parent = 0);
    ~creautente();

private:
    QLineEdit* Username;
    QLineEdit* Password;
    QLineEdit* Nome;
    QLineEdit* Cognome;
    QLineEdit* Email;
    QComboBox* Piano;
    QDialogButtonBox* conferma;

    void crea_tasti();
signals:
    void invia(const QString& u, const QString & p, const QString & n,const QString & co,const QString & em,const QString & pi);  //invia i dati admin
private slots:
    void dati();

};

#endif // CREAUTENTE_H
