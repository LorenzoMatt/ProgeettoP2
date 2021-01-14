#include "finestravistadomande.h"

FinestraVistaDomande::FinestraVistaDomande(container<Domanda*>d, Controller *controller, QWidget *parent) :QDialog(parent),domande(d),c(controller)
{

    QVBoxLayout* layoutTotalePagina=new QVBoxLayout;
    paginaDomande=new QScrollArea;
    paginaDomande->setWidgetResizable(true);
    //creo i widget che contengono le scrollArea delle pagine
    QWidget* widgetDomande=new QWidget;
    layoutWidgetPagina=new QVBoxLayout;
    //creo layout totale per la tabella
    //QHBoxLayout che indica il numero di domande presenti e aggiungi domanda
    QHBoxLayout* layoutAggiungiDomanda=new QHBoxLayout;
    QLabel* numeroDomande=new QLabel("numero di domande "+QString::number(domande.size()));
    layoutAggiungiDomanda->addWidget(numeroDomande);
    widgetDomande->setLayout(layoutWidgetPagina);
    //aggiungo i widget alle scrollArea
    paginaDomande->setWidget(widgetDomande);
    layoutTotalePagina->addLayout(layoutAggiungiDomanda);
    layoutTotalePagina->addWidget(paginaDomande);
    for(unsigned int i=0;i<domande.size();i++){
    //costruisco il layout del widget che conterrá le domande che dovranno essere visualizzate e il pulsante
    //Vedi commenti
    Domanda* d=*(domande[i]);
    string stringaAutore=d->get_autore_domanda()->get_credenziali().get_username();
    stringaAutore=stringaAutore+ " " +(d->get_autore_domanda()->get_credenziali().get_username());
    QLabel* autoreDomanda=new QLabel(QString::fromStdString(stringaAutore));
    //creo lo spazio che conterrá la domanda
    QTextEdit* testoDomanda=new QTextEdit(QString::fromStdString(d->get_testo()));
    testoDomanda->setReadOnly(true);
    layoutWidgetPagina->addWidget(autoreDomanda);
    layoutWidgetPagina->addWidget(testoDomanda);
    //creo la barra orizzontale con il pulsante per visualizzare i commenti
    QString u(QString::fromStdString(c->getAccesso().get_username()));
    bottoneVediCommento* commenti=new bottoneVediCommento(d,u,"vedi commenti",this);
    //pulsante per vedere i commenti
    connect(commenti,SIGNAL(clicked()),commenti,SLOT(vediCommenti()));

    //aggiungo il pulsante commenti sotto al testo della domanda
    layoutWidgetPagina->addWidget(commenti);
    layoutWidgetPagina->setAlignment(commenti,Qt::AlignRight);
    connect(commenti,SIGNAL(commento(const QString&,Domanda*)),c,SLOT(scrivi_commento(const QString&,Domanda*)));
    connect(commenti,SIGNAL(commento(const QString&,Domanda*)),commenti,SLOT(vediCommenti()));//aggiorno la vista delle domande
    connect(commenti,SIGNAL(rimuovi(int,Domanda*)),c,SLOT(rimuovi_commento(int,Domanda*)));
    connect(commenti,SIGNAL(rimuovi(int,Domanda*)),commenti,SLOT(vediCommenti()));//aggiorno la vista delle domande
    }
    setLayout(layoutTotalePagina);
}

FinestraVistaDomande::~FinestraVistaDomande()
{

}
