#include "widgetcampodati.h"
//ciaooo
widgetCampoDati::widgetCampoDati(const QString& n, const QString& t, bool m):layoutTotale(new QVBoxLayout),
    layoutNome(new QVBoxLayout),testoNome(new QLineEdit),layoutModNome(new QHBoxLayout),
    modNome(new QPushButton("Modifica")),invio(new QPushButton("invio")),canc(new QPushButton("Annulla")),modo(m)

{
    //creo etichetta nome
    QLabel* EtichettaNome=new QLabel(n);
    layoutNome->addWidget(EtichettaNome);

    //setto il testo
    testoNome->setText(t);
    testoNome->setReadOnly(true);
    if(!modo)
        testoNome->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    layoutNome->addWidget(testoNome);

    //setto il pulsante modNome
    modNome->setMaximumWidth(70);

    //setto il pulsante canc
    canc->setMaximumWidth(70);
    canc->setVisible(false);
    invio->setVisible(false);
    invio->setObjectName("ok");


    //aggiungo pulsante modNome e canc
    layoutModNome->setAlignment(Qt::AlignRight);
    layoutModNome->addWidget(invio);
    layoutModNome->addWidget(modNome);
    layoutModNome->addWidget(canc);


    //aggiungo tutto al layoutTotale
    layoutTotale->addLayout(layoutNome);
    layoutTotale->addLayout(layoutModNome);
    setLayout(layoutTotale);

    //connessioni pulsanti
    connect(modNome,SIGNAL(clicked()),this,SLOT(sbloccaBloccaTesto()));
    connect(canc,SIGNAL(clicked()),this,SLOT(annullaModifica()));

}

//implementazione degli slots
void widgetCampoDati::sbloccaBloccaTesto()
{
   if(testoNome->isReadOnly()){
   testoNome->setReadOnly(false);
   modNome->setVisible(false);
   invio->setVisible(true);
   canc->setVisible(true);
   testoTemporaneo=testoNome->text();


   connect(invio,SIGNAL(clicked()),this,SLOT(confermaModifica()));
   }
   else
   {
       testoNome->setReadOnly(true);
       modNome->setVisible(true);
       invio->setVisible(false);
       canc->setVisible(false);
   }

}

void widgetCampoDati::annullaModifica()
{
    testoNome->setText(testoTemporaneo);

    sbloccaBloccaTesto();
}

void widgetCampoDati::confermaModifica()
{
    //setto il testo del campo dati e aggiorno il campo relativo dell'utente nel database

    QString testo=testoNome->text();
    if(!testo.isEmpty())
        emit invioNome(testo);

}


