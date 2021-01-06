#include "finestranuovadomanda.h"
#include <QLabel>
#include <QVBoxLayout>
#include "funzioniutili.h"
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

    QLabel* l=new QLabel("Scrivi una domanda e inserisci la priorita");
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

    setMaximumSize(QSize(300,200));

    setLayout(mainLayout);
}

finestraNuovaDomanda::~finestraNuovaDomanda()
{
}

void finestraNuovaDomanda::dati()
{
    if(testo->text().isEmpty())
    {
        messaggio_errore("testo del messaggio vuoto","Il testo non può essere vuoto!",this);
    }
    else
    {
        emit invia(testo->text(),priorita->value());
        close();
    }
}
