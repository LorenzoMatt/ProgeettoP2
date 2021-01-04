
#include "vista_utente.h"
#include "controller.h"
#include "vistaprofilo.h"

//aggiunge area domanda utente con pulsante commenti
void VistaUtente::aggiungiAreaDomandaAmici()
{
    //creo il widget da inserire dentro alla scrollArea

    QWidget* widgetDomandaAmici=new QWidget;
    QVBoxLayout* layoutWidgetDomandaAmici=new QVBoxLayout;

    container<Domanda*> contenitoreDomandeAmici=c->getDomandeAmici();
    for(unsigned int i=0;i<contenitoreDomandeAmici.size();i++){
    //costruisco il layout del widget che conterrá le domande che dovranno essere visualizzate e il pulsante
    //Vedi commenti


    //creo lo spazio che conterrá la domanda
        QTextEdit* testoDomanda=new QTextEdit(QString::fromStdString(c->getDomandeAmici()[i]->get_testo())); //al momento della creazione verrá inserito il testo della domanda
    testoDomanda->setReadOnly(true);


    layoutWidgetDomandaAmici->addWidget(testoDomanda);
    //creo la barra orizzontale con il pulsante per visualizzare i commenti
    QHBoxLayout* layVediCommenti=new QHBoxLayout;



    bottoneVediCommento* commenti=new bottoneVediCommento(c->getDomandeAmici()[i],"vedi commenti");
    //pulsante per vedere i commenti
    connect(commenti,SIGNAL(clicked()),commenti,SLOT(vediCommenti()));
    //inserisco il pulsante nel layout




    layVediCommenti->addWidget(commenti);
    layVediCommenti->setAlignment(commenti,Qt::AlignRight);
    //aggiungo la barra sotto al testo della domanda
    layoutWidgetDomandaAmici->addLayout(layVediCommenti);

    }

    //imposto come layout del widget il layout appena creato
    widgetDomandaAmici->setLayout(layoutWidgetDomandaAmici);
    layoutWidgetPagina1->addWidget(widgetDomandaAmici);

}

void VistaUtente::buildBarraSuperiore()
{
    layoutBarraSuperiore=new QHBoxLayout;



//  pulsanti della barra di ricerca
    profilo=new QPushButton("profilo");
    profilo->setObjectName("profilo");
    connect(profilo,SIGNAL(clicked()),this,SLOT(vediProfilo()));
    invioDomanda=new QPushButton("Cerca");
    invioUtente=new QPushButton("Cerca");

//  linee di testo della barra di ricerca
    scriviDomanda=new QLineEdit();
    scriviDomanda->setPlaceholderText("cerca domanda");
    scriviUtente=new QLineEdit();
    scriviUtente->setPlaceholderText("cerca utente");

    //aggiungo alla barra di ricerca gli elementi creati
    layoutBarraSuperiore->addWidget(profilo);
    layoutBarraSuperiore->addWidget(scriviDomanda);
    layoutBarraSuperiore->addWidget(invioDomanda);
    layoutBarraSuperiore->addWidget(scriviUtente);
    layoutBarraSuperiore->addWidget(invioUtente);
}

//costruisce la tabella con le due pagine (domande amici,domande personali)
//entrambe le pagine sono delle scrollArea ma nella pagina domande amici c'é una barra fissa per aggiungere domande
void VistaUtente::buildTabella()
{
    tabella=new QTabWidget;
    QScrollArea* pagina1=new QScrollArea;
    QScrollArea* pagina2=new QScrollArea;
    pagina1->setWidgetResizable(true);
    pagina2->setWidgetResizable(true);

    //creo i widget che contengono le scrollArea delle pagine
    QWidget* widgetPagina1=new QWidget;
    QWidget* widgetPagina2=new QWidget;
    layoutWidgetPagina1=new QVBoxLayout();
    layoutWidgetPagina2=new QVBoxLayout();

    //creo layout totale per la tabella
    QWidget* totalePagina2=new QWidget;
    QVBoxLayout* layoutTotalePagina2=new QVBoxLayout();
    totalePagina2->setLayout(layoutTotalePagina2);

    //QHBoxLayout che indica il numero di domande presenti e aggiungi domanda
    QHBoxLayout* layoutAggiungiDomanda=new QHBoxLayout;
    numeroDomandePersonali=new QLabel("numero di domande");
    layoutAggiungiDomanda->addWidget(numeroDomandePersonali);
    aggiungiDomanda=new QPushButton("fai domanda");
    layoutAggiungiDomanda->addWidget(aggiungiDomanda);

    widgetPagina1->setLayout(layoutWidgetPagina1);
    widgetPagina2->setLayout(layoutWidgetPagina2);
    //aggiungo i widget alle scrollArea
    pagina1->setWidget(widgetPagina1);
    pagina2->setWidget(widgetPagina2);

    layoutTotalePagina2->addLayout(layoutAggiungiDomanda);
    layoutTotalePagina2->addWidget(pagina2);

    //nella pagina1 devo creare le domande con i commenti degli amici dell'utente

    aggiungiAreaDomandaAmici();

    //aggiungo le scrollArea alla tabella
    tabella->addTab(pagina1,"Domande amici");
    tabella->addTab(totalePagina2,"Domande personali");

}

void VistaUtente::imposta_stile()
{
    QFile file("../style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    file.close();
    setStyleSheet(styleSheet);
}

VistaUtente::VistaUtente(const QString& utente, QWidget *parent):QWidget(parent),c(new Controller(utente,this))
{
    imposta_stile();

    QVBoxLayout* mainLayout=new QVBoxLayout();

    //creo gli elementi da aggiungere al mainLayout
    buildBarraSuperiore();
    buildTabella();
    mainLayout->addLayout(layoutBarraSuperiore);
    mainLayout->addWidget(tabella);

    setLayout(mainLayout);
}

void VistaUtente::vediProfilo()
{
    vistaProfilo* profilo=new vistaProfilo(c);
    profilo->setWindowTitle("Profilo");
    profilo->show();

}



























