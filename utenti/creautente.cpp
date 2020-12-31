#include "creautente.h"
#include<QLabel>
#include<QFormLayout>

creautente::creautente(QWidget *parent) :QDialog(parent)
{
    crea_tasti();
    setWindowTitle("aggiungi un utente");
    /*********Creazioni Label******/
    QLabel* Username_label=new QLabel("Username");
    QLabel* Password_label=new QLabel("Password");
    QLabel* Nome_label=new QLabel("Nome");
    QLabel* Cognome_label=new QLabel("Cognome");
    QLabel* email_label=new QLabel("e-mail");
    QLabel* Piano_label=new QLabel("Piano");


    /********Set buddy*********/

    Username_label->setBuddy(Username);
    Password_label->setBuddy(Password);
    Nome_label->setBuddy(Nome);
    Cognome_label->setBuddy(Cognome);
    email_label->setBuddy(Email);
    Piano_label->setBuddy(Piano);

    /*********Layout principale********/

    QFormLayout* layout_form=new QFormLayout;
    layout_form->addRow(Username_label,Username);
    layout_form->addRow(Password_label,Password);
    layout_form->addRow(Nome_label,Nome);
    layout_form->addRow(Cognome_label,Cognome);
    layout_form->addRow(email_label,Email);
    layout_form->addRow(Piano_label,Piano);

    conferma=new QDialogButtonBox(this);
    conferma->addButton("Aggiungi",QDialogButtonBox::AcceptRole);
    conferma->addButton("Cancella",QDialogButtonBox::RejectRole);

    QVBoxLayout* mainLayout=new QVBoxLayout;
    mainLayout->addLayout(layout_form);
    mainLayout->addWidget(conferma);

    setLayout(mainLayout);
    connect(conferma,SIGNAL(accepted()),this,SLOT(dati()));
    connect(conferma,SIGNAL(rejected()),this,SLOT(close()));
}
//void CreaModificaInquilino::checkDati()
//{
//    bool errore=false;
//    if(_useredit->text().isEmpty() || _pwedit->text().isEmpty())
//        errore=true;
//    if(!errore)
//    {
//        raccogliDati();
//        close();
//        showSuccess("Operazione eseguita con successo");
//    }
//    else
//        showMessage("Attenzione! I campi user e password non possono essere vuoti");
//}

void creautente::dati()
{
    const QString & user=Username->text(),password= Password->text(),nome=Nome->text(),cognome=Cognome->text(),email=Email->text(),piano=Piano->currentText();
    emit  invia(user, password,nome,cognome,email,piano);
    close();
}
creautente::~creautente()
{
}

void creautente::crea_tasti()
{
    Username=new QLineEdit();
    Password=new QLineEdit();
    Nome=new QLineEdit();
    Cognome=new QLineEdit();
    Email=new QLineEdit();
    Piano=new QComboBox;
    Piano->addItem("Basic");
    Piano->addItem("Gold");
    Piano->addItem("Premium");
}
