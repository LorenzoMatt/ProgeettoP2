
#include "vista_utente.h"
#include "controller.h"
#include "vista_profilo.h"
#include "vistacercautente.h"
#include "stile.h"

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

    string stringaAutore=c->getDomandeAmici()[i]->get_autore_domanda()->get_profilo().get_nome();
    stringaAutore=stringaAutore+ " " +(c->getDomandeAmici()[i]->get_autore_domanda()->get_profilo().get_cognome());
    QLabel* autoreDomanda=new QLabel(QString::fromStdString(stringaAutore));

    //creo lo spazio che conterrá la domanda
    QTextEdit* testoDomanda=new QTextEdit(QString::fromStdString(c->getDomandeAmici()[i]->get_testo()));
    testoDomanda->setReadOnly(true);

    layoutWidgetDomandaAmici->addWidget(autoreDomanda);
    layoutWidgetDomandaAmici->addWidget(testoDomanda);
    //creo la barra orizzontale con il pulsante per visualizzare i commenti

    bottoneVediCommento* commenti=new bottoneVediCommento(c->getDomandeAmici()[i],"vedi commenti");
    //pulsante per vedere i commenti
    connect(commenti,SIGNAL(clicked()),commenti,SLOT(vediCommenti()));

    //aggiungo il pulsante commenti sotto al testo della domanda
    layoutWidgetDomandaAmici->addWidget(commenti);
    layoutWidgetDomandaAmici->setAlignment(commenti,Qt::AlignRight);

    }

    //imposto come layout del widget il layout appena creato
    widgetDomandaAmici->setLayout(layoutWidgetDomandaAmici);
    layoutWidgetPagina1->addWidget(widgetDomandaAmici);

}

void VistaUtente::aggiungiAreaDomandePersonali()
{
    QWidget* widgetScrollAreaPagina2=new QWidget;
    QVBoxLayout* layoutScrollAreaPagina2=new QVBoxLayout;

    container<Domanda*> contenitoreDomandePersonali=c->getDomandePersonali();

    for(unsigned int i=0;i<contenitoreDomandePersonali.size();i++){

    //creo lo spazio che conterrá la domanda
    QTextEdit* testoDomanda=new QTextEdit(QString::fromStdString(c->getDomandePersonali()[i]->get_testo()));
    testoDomanda->setReadOnly(true);

    layoutScrollAreaPagina2->addWidget(testoDomanda);
    //creo la barra orizzontale con il pulsante per visualizzare i commenti

    bottoneVediCommento* commenti=new bottoneVediCommento(c->getDomandePersonali()[i],"vedi commenti");
    //pulsante per vedere i commenti
    connect(commenti,SIGNAL(clicked()),commenti,SLOT(vediCommenti()));

    layoutScrollAreaPagina2->addWidget(commenti);
    layoutScrollAreaPagina2->setAlignment(commenti,Qt::AlignRight);
    }

    widgetScrollAreaPagina2->setLayout(layoutScrollAreaPagina2);
    pagina2->setWidget(widgetScrollAreaPagina2);
}

void VistaUtente::buildBarraSuperiore()
{
    layoutBarraSuperiore=new QHBoxLayout;

//  pulsanti della barra di ricerca
    QIcon iconaProfilo("../profilo");
    profilo=new QPushButton(iconaProfilo," Profilo");
    connect(profilo,SIGNAL(clicked()),this,SLOT(vediProfilo()));
    QIcon iconaCerca("../cerca");
    invioDomanda=new QPushButton(iconaCerca,"Cerca");
    invioUtente=new QPushButton(iconaCerca,"Cerca");
    connect(invioUtente,SIGNAL(clicked()),this,SLOT(buildCercaUtente()));

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
    pagina1=new QScrollArea;
    pagina2=new QScrollArea;
    pagina1->setWidgetResizable(true);
    pagina2->setWidgetResizable(true);

    //creo i widget che contengono le scrollArea delle pagine
    QWidget* widgetPagina1=new QWidget;
    QWidget* widgetPagina2=new QWidget;
    layoutWidgetPagina1=new QVBoxLayout;
    layoutWidgetPagina2=new QVBoxLayout;

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

    //nella pagina2 devo creare le domande con i commenti delle domane personali
    aggiungiAreaDomandePersonali();

    //aggiungo le scrollArea alla tabella
    tabella->addTab(pagina1,"Domande amici");
    tabella->addTab(totalePagina2,"Domande personali");

}

VistaUtente::VistaUtente(const QString& utente, QWidget *parent):QWidget(parent),c(new Controller(utente,this))
{
    setStyleSheet(imposta_stile());
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
    profilo->setMinimumWidth(500);
    profilo->show();
}

void VistaUtente::buildCercaUtente()
{
        container<string> parametri=c->cercaUtente(scriviUtente->text());
        if(!parametri.empty())
        {
            bool amico_presente=c->check_presenza_amico(scriviUtente->text());
            vistaCercaUtente* v=new vistaCercaUtente(parametri,amico_presente);
            v->show();
            connect(v,SIGNAL(invia(const QString&)),c,SLOT(aggiungi_amico(const QString&)));
            connect(v,SIGNAL(rimuovi(const QString&)),c,SLOT(togli_amico(const QString&)));
            connect(v,SIGNAL(invia(const QString&)),this,SLOT(buildCercaUtente()));
            connect(v,SIGNAL(rimuovi(const QString&)),this,SLOT(buildCercaUtente()));
        }else
        {
            QErrorMessage* messaggio=new QErrorMessage(this);
            messaggio->setWindowTitle("Utente non presente");
            messaggio->showMessage("L'utente "+scriviUtente->text()+" non è stato trovato");
        }
}

