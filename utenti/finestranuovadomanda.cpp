#include "finestranuovadomanda.h"
#include <QLabel>
#include <QErrorMessage>
#include <QMessageBox>
#include <QVBoxLayout>
void finestraNuovaDomanda::buildPulsanteConferma()
{
    conferma=new QDialogButtonBox(this);
    conferma->addButton("Aggiungi",QDialogButtonBox::AcceptRole);
    conferma->addButton("Cancella",QDialogButtonBox::RejectRole);

    connect(conferma,SIGNAL(accepted()),this,SLOT(dati()));
    connect(conferma,SIGNAL(rejected()),this,SLOT(close()));
}

finestraNuovaDomanda::finestraNuovaDomanda(QWidget *parent) :
    QDialog(parent)
{
    QVBoxLayout* mainLayout=new QVBoxLayout;

    QLabel* l=new QLabel("Scrivi una domanda qui sotto");
    testo=new QLineEdit;
    testo->setPlaceholderText("Scrivi una domanda...");
    l->setBuddy(testo);

    priorita=new QSpinBox;
    priorita->setRange(1,5);

    buildPulsanteConferma();

    mainLayout->addWidget(l);
    mainLayout->addWidget(testo);
    mainLayout->addWidget(priorita);
    mainLayout->addWidget(conferma);

    setLayout(mainLayout);
}

finestraNuovaDomanda::~finestraNuovaDomanda()
{
}

void finestraNuovaDomanda::dati()
{
    if(testo->text().isEmpty())
    {
        QErrorMessage* messaggio=new QErrorMessage(this);
        messaggio->setWindowTitle("testo del messaggio vuoto");
        messaggio->showMessage("Il testo non può essere vuoto!");
    }
    else
    {
        emit invia(testo->text(),priorita->value());
        close();
    }
}
