#include "log.h"


Login::Login(QWidget *parent)
{
    setWindowTitle("Login");
    QVBoxLayout* mainLayout=new QVBoxLayout();

    /*******Pulsanti*******/

    accedi=new QPushButton("accedi");
    registrati=new QPushButton("registrati");
    accedi_come_admin=new QPushButton("accedi come admin");

    /*******testo*******/

    username=new QLineEdit();
    password=new QLineEdit();
    password->setEchoMode(QLineEdit::Password);

    /*******Label******/

     QLabel* user_label=new QLabel("Username");
     user_label->setBuddy(username);
     QLabel* password_label=new QLabel("Password");
     password_label->setBuddy(password);
     QLabel* oppure=new QLabel("Oppure");

     /*******layoutForm*******/

     QFormLayout* accesso=new QFormLayout();
     accesso->addRow(user_label,username);
     accesso->addRow(password_label,password);
     QVBoxLayout* a=new QVBoxLayout();
     a->addLayout(accesso);
     a->addWidget(accedi);
     a->addWidget(registrati);

     /*******layout*******/


     mainLayout->addLayout(a);
     mainLayout->addWidget(oppure,0,Qt::AlignCenter);
     mainLayout->addWidget(accedi_come_admin);
     setLayout(mainLayout);
     Login::setMaximumSize(300,300);

     connect(username,SIGNAL(returnPressed()),this,SLOT(login_user()));
     connect(password,SIGNAL(returnPressed()),this,SLOT(login_user()));
     connect(accedi,SIGNAL(clicked()),SLOT(login_user()));
     connect(registrati,SIGNAL(clicked()),SLOT(registrazione()));
     connect(accedi_come_admin,SIGNAL(clicked()),SLOT(login_admin()));

}

Login::~Login()
{
}

void Login::login_user()
{
}

void Login::login_admin()
{

}

void Login::registrazione()
{

}
