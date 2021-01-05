#include "widgetcampodati.h"

widgetCampoDati::widgetCampoDati(const QString& n, const QString& t,const int& ti):tipo(ti),layoutTotale(new QVBoxLayout),
    layoutNome(new QVBoxLayout),testoNome(new QLineEdit),layoutModNome(new QHBoxLayout),
    modNome(new QPushButton("Modifica")),canc(new QPushButton("Annulla"))
{
    //creo etichetta nome
    QLabel* EtichettaNome=new QLabel(n);
    layoutNome->addWidget(EtichettaNome);

    //setto il testo
    testoNome->setText(t);
    testoNome->setReadOnly(true);
    layoutNome->addWidget(testoNome);

    //setto il pulsante modNome
    modNome->setMaximumWidth(70);

    //setto il pulsante canc
    canc->setMaximumWidth(70);
    canc->setVisible(false);


    //aggiungo pulsante modNome e canc
    layoutModNome->addWidget(modNome,0,Qt::AlignRight);
    layoutModNome->addWidget(canc,0,Qt::AlignRight);

    //aggiungo tutto al layoutTotale
    layoutTotale->addLayout(layoutNome);
    layoutTotale->addLayout(layoutModNome);

    //connessioni
    connect(modNome,SIGNAL(clicked()),this,SLOT(sbloccaBloccaTesto()));
    connect(canc,SIGNAL(clicked()),this,SLOT(annullaModifica()));
}

//implementazione degli slots
void widgetCampoDati::sbloccaBloccaTesto()
{
   if(testoNome->isReadOnly()){
   testoNome->setReadOnly(false);
   modNome->setText("Conferma");
   canc->setVisible(true);
   }
   else
   {
       testoNome->setReadOnly(true);
       modNome->setText("Modifica");
       canc->setVisible(true);
   }

}

void widgetCampoDati::annullaModifica()
{
    sbloccaBloccaTesto();
}

void widgetCampoDati::confermaModifica()
{
    //setto il testo del campo dati e aggiorno il campo relativo dell'utente nel database
    testoNome->setText();
    switch (tipo) {
    case(Nome):
        break;
    case(Cognome):
        break;
    case(Email):
        break;
    case(Password):
        break;
    }
    sbloccaBloccaTesto();
}


