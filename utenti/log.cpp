#include "log.h"
#include "creautente.h"
#include "vista_utente.h"
//#include "vista_amministratore.h"
#include "basic.h"
#include "gold.h"
#include "premium.h"
void Login::build_pulsanti()
{
    accedi=new QPushButton("accedi");
    registrati=new QPushButton("registrati");
    accedi_come_admin=new QPushButton("accedi come admin");
    connect(accedi,SIGNAL(clicked()),SLOT(login_user()));
    connect(registrati,SIGNAL(clicked()),SLOT(registrazione()));
    connect(accedi_come_admin,SIGNAL(clicked()),SLOT(login_admin()));
}

void Login::build_line_edit()
{
    username=new QLineEdit();
    password=new QLineEdit();
    password->setEchoMode(QLineEdit::Password);

    connect(username,SIGNAL(returnPressed()),this,SLOT(login_user()));
    connect(password,SIGNAL(returnPressed()),this,SLOT(login_user()));
}

void Login::build_form_layout(QLabel* password_label, QLabel* user_label)
{
    accesso=new QFormLayout();
    accesso->addRow(user_label,username);
    accesso->addRow(password_label,password);
}

void Login::build_main_layout(QVBoxLayout* a, QLabel* oppure)
{
    mainLayout->addLayout(a);
    mainLayout->addWidget(oppure,0,Qt::AlignCenter);
    mainLayout->addWidget(accedi_come_admin);
    setLayout(mainLayout);
}

void Login::imposta_stile()
{
    QFile file("../style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    file.close();
    setStyleSheet(styleSheet);
}

Login::Login(QWidget *parent) : QWidget(parent) ,db(new Database())
{
    db->import();

    setWindowTitle("Login");
    mainLayout=new QVBoxLayout();

    /*******Pulsanti*******/

    build_pulsanti();

    /*******testo*******/

    build_line_edit();

    /*******Label******/

     QLabel* user_label=new QLabel("Username");
     user_label->setBuddy(username);
     QLabel* password_label=new QLabel("Password");
     password_label->setBuddy(password);
     QLabel* oppure=new QLabel("Oppure");

     /*******layoutForm*******/

     build_form_layout(password_label, user_label);
     QVBoxLayout* a=new QVBoxLayout();
     a->addLayout(accesso);
     a->addWidget(accedi);
     a->addWidget(registrati);

     /*******layout*******/

     imposta_stile();
     build_main_layout(a, oppure);
     Login::setMaximumSize(300,300);
}

Login::~Login()
{

}


void Login::login_user()
{
//    string user=username->text().toStdString();
//    string pw=password->text().toStdString();
//    Utente* utente=db.check_credenziali(user,pw);


        VistaUtente* v=new VistaUtente("Pikachu");
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
    vista_amministratore* vista=new vista_amministratore();
    vista->show();
    close();
}

void Login::registrazione()
{
    creautente* utente=new creautente(this);
    utente->setWindowTitle("aggiungi un utente");

    utente->show();
    connect(utente,SIGNAL(invia(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&)),
            this, SLOT(aggiungi_utente(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&)));
}



void Login::aggiungi_utente(const QString & username, const QString & password, const QString & nome, const QString & cognome, const QString & email,const QString& piano)
{
    string u=username.toStdString(),p=password.toStdString(),n=nome.toStdString(),co=cognome.toStdString(),em=email.toStdString(),pi=piano.toStdString();
    try
    {
        if(pi=="Basic")
            db->aggiungi_utente(new Basic(u,p,n,co,em));
        if(pi=="Gold")
            db->aggiungi_utente(new Gold(u,p,n,co,em));
        if(pi=="Premium")
            db->aggiungi_utente(new Premium(u,p,n,co,em));
        db->exportdati();
        VistaUtente* v=new VistaUtente(username);//ci andra l'account appena creato
        v->show();
        close();
    }catch(utente_gia_presente)
    {
        QErrorMessage* messaggio=new QErrorMessage(this);
        messaggio->setWindowTitle("utente non registrato");
        messaggio->showMessage("l'username "+username+" è già stato usato");
        connect(messaggio,SIGNAL(accepted()),this,SLOT(registrazione()));
    }
}
