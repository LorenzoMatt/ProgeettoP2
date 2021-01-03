#include "vista_utente.h"
#include "controller.h"

//costruttore
//QScrollArea* VistaUtente::aggiungiAreaDomanda()
//{
//    QScrollArea* scrollarea=new QScrollArea;

//    //creo il widget da inserire dentro alla scrollArea
//    QWidget* scrollwidget=new QWidget;

//    //costruisco il layout del widget che conterrá le domande che dovranno essere visualizzate e il pulsante
//    //Vedi commenti
//    QVBoxLayout* layout_widget=new QVBoxLayout;

//    //creo lo spazio che conterrá la domanda
//    QTextEdit* testoDomanda=new QTextEdit; //al momento della creazione verrá inserito il testo della domanda
//    testoDomanda->setReadOnly(true);

//    layout_widget->addWidget(testoDomanda);
//    //creo la barra orizzontale con il pulsante per visualizzare i commenti
//    QHBoxLayout* layVediCommenti=new QHBoxLayout;
//    //pulsante per vedere i commenti
//    QPushButton* commenti=new QPushButton("Vedi commenti");
//    //inserisco il pulsante nel layout
//    layVediCommenti->addWidget(commenti);
//    layVediCommenti->setAlignment(commenti,Qt::AlignRight);
//    //aggiungo la barra sotto al testo della domanda
//    layout_widget->addLayout(layVediCommenti);



//    //imposto come layout del widget il layout appena creato
//    scrollwidget->setLayout(layout_widget);
//    //imposto come widget della scollArea il widget appena creato
//    scrollarea->setWidget(scrollwidget);
//    //mettendo a true il layout del widget contenuto si adatta a quello della scrollArea
//    scrollarea->setWidgetResizable(true);

//    return scrollarea;
//}

//VistaUtente::VistaUtente(QWidget *parent):QWidget(parent)
//{
////    creo la label principale
//    QVBoxLayout* mainLayout=new QVBoxLayout();

////  barra di ricerca superiore
//    QHBoxLayout* barraDiRicerca=new QHBoxLayout();

////  pulsanti della barra di ricerca
//    profilo=new QPushButton("profilo");
//    invioDomanda=new QPushButton("Cerca");
//    invioUtente=new QPushButton("Cerca");

////  linee di testo della barra di ricerca
//    scriviDomanda=new QLineEdit();
//    scriviDomanda->setPlaceholderText("cerca domanda");
//    scriviUtente=new QLineEdit();
//    scriviUtente->setPlaceholderText("cerca utente");

//    //aggiungo alla barra di ricerca gli elementi creati
//    barraDiRicerca->addWidget(profilo);
//    barraDiRicerca->addWidget(scriviDomanda);
//    barraDiRicerca->addWidget(invioDomanda);
//    barraDiRicerca->addWidget(scriviUtente);
//    barraDiRicerca->addWidget(invioUtente);

//    //aggiungo al mainLayout la barra di ricerca
//    mainLayout->addLayout(barraDiRicerca);

//    //creo la tabella ed il widget da inserire al suo interno alla prima pagina
//    //il widget é totale e contiene la barra orizzontale e la scrollArea
//    QTabWidget* tabella=new QTabWidget();

//    //creo l'area per visualizzare la domanda e i relativi commenti
//    QScrollArea* pagina1=aggiungiAreaDomanda();

//    // costruisco il widget che contiene il layout orizzontale e la scrool area appena creata
//    QWidget* totale=new QWidget;
//    // layout che contiene la barra orizzontale e la scool area
//    QVBoxLayout* laytotale=new QVBoxLayout;
//    // layout che continene label e pushbutton
//    QHBoxLayout* lay=new QHBoxLayout;

//    lay->addWidget(new QLabel("numero di domande"));
//    lay->addWidget(new QPushButton("fai domanda"));

//    //aggiungo la barra orizzontale e la scrollArea al layout totale
//    laytotale->addLayout(lay);
//    laytotale->addWidget(pagina1);
//    //imposto a totale il layout totale
//    totale->setLayout(laytotale);
//    //imposto come widget della tabella il totale appena creato
//    tabella->addTab(totale,"Domande personali");


//    //creo scrollArea della seconda pagina
//    QScrollArea* pagina2=aggiungiAreaDomanda();
//    //creo la Label che per indicare l'autore della domanda
//    QLabel* autoreDomanda=new QLabel("Autore domanda");
//    //creo il widget da inserire nella seconda pagina della tabella
//    QWidget* totale2=new QWidget;
//    //creo il layout che contiene la Label Autore domanda
//    QHBoxLayout* lay2=new QHBoxLayout;
//    //aggiungo la Label al layout
//    lay2->addWidget(autoreDomanda);
//    lay2->setAlignment(Qt::AlignLeft);
//    //creo il layout di totale2
//    QVBoxLayout* laytotale2=new QVBoxLayout;
//    laytotale2->addLayout(lay2);
//    laytotale2->addWidget(pagina2);
//    totale2->setLayout(laytotale2);

//    //creo la seconda pagina della tabella
//    tabella->addTab(totale2,"Domande amici");


//    //aggiungo al mainLayout la tabella
//    mainLayout->addWidget(tabella);


//    //imposto il mainLayout come layout principale
//    setLayout(mainLayout);
//}

void VistaUtente::buildBarraSuperiore()
{
    layoutBarraSuperiore=new QHBoxLayout;



//  pulsanti della barra di ricerca
    profilo=new QPushButton("profilo");
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
    //aggiungo le scrollArea alla tabella
    tabella->addTab(pagina1,"Domande amici");
    tabella->addTab(totalePagina2,"Domande personali");
}

VistaUtente::VistaUtente(QWidget *parent):QWidget(parent)
{
    QVBoxLayout* mainLayout=new QVBoxLayout();

    //creo gli elementi da aggiungere al mainLayout
    buildBarraSuperiore();
    buildTabella();
    mainLayout->addLayout(layoutBarraSuperiore);
    mainLayout->addWidget(tabella);

    setLayout(mainLayout);
}

void VistaUtente::setController(Controller * controller)
{
    c=controller;
}

























