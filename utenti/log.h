#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include "funzioniutili.h"
#include "controller_admin.h"
class controller_admin;
class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = 0);
    ~Login();
private:
    Database* db;
    QFormLayout* accesso;
    QVBoxLayout* mainLayout;
    QPushButton* accedi;
    QPushButton* accedi_come_admin;
    QPushButton* registrati;
    QLineEdit* username;
    QLineEdit* password;
    void build_pulsanti();
    void build_line_edit();
    void build_form_layout(QLabel*, QLabel*);
    void build_main_layout(QVBoxLayout*, QLabel*);
private slots:
    void login_user();
    void login_admin();
    void registrazione();
    void aggiungi_utente(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&);
};

#endif // HOME_H
