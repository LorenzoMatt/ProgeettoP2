#include "log.h"
#include "creautente.h"
#include "vista_utente.h"
//#include "vista_amministratore.h"
Login::Login(QWidget *parent)
{
    setWindowTitle("Login");
    mainLayout=new QVBoxLayout();

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

     accesso=new QFormLayout();
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
//    string user=username->text().toStdString();
//    string pw=password->text().toStdString();
//    Utente* utente=db.check_credenziali(user,pw);


        VistaUtente* v=new VistaUtente();
        v->show();
        close();

//    else
//    {
//        QErrorMessage * e=new QErrorMessage();
//        e->showMessage("Username o Password non corretti");
//    }
}

void Login::login_admin()
{
//    this->hide();
    vista_amministratore* v=new vista_amministratore(new controller_admin());
    v->show();
//    controller_admin v(new vista_amministratore(&v));
    close();
}

void Login::registrazione()
{
//    creautente* utente=new creautente(this);
//    utente->setWindowTitle("aggiungi un utente");

//    utente->show();
//    connect(utente,SIGNAL(invia(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&)),
//            this, SLOT(aggiungi_utente(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&)));
//    connect(utente,SIGNAL(invia(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&)),
//            this,SLOT(build_vista_utente(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&)));
}

void Login::build_vista_utente(const QString& username,const QString& pw,const QString& nome,
                               const QString& cognome,const QString& email,const QString& piano)
{

}
