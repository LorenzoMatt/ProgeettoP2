#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include<QErrorMessage>
class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private:
    QPushButton* accedi;
    QPushButton* accedi_come_admin;
    QPushButton* registrati;
    QLineEdit* username;
    QLineEdit* password;
private slots:
    void login_user();
    void login_admin();
    void registrazione();
    void build_vista_utente(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&);
};

#endif // HOME_H
