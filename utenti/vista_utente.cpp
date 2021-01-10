
#include "vista_utente.h"
#include "controller.h"
#include "vista_profilo.h"
#include "vistacercautente.h"
#include "funzioniutili.h"
#include"finestranuovadomanda.h"
#include "finestravistadomande.h"
#include "log.h"

//aggiunge area domanda utente con pulsante commenti
void VistaUtente::aggiungiAreaDomandaAmici() //giusto
{
//    layoutWidgetPagina1

    container<Domanda*> contenitoreDomandeAmici=c->getDomandeAmici();
    for(unsigned int i=0;i<contenitoreDomandeAmici.size();i++){
    //costruisco il layout del widget che conterrá le domande che dovranno essere visualizzate e il pulsante
    //Vedi commenti

    string stringaAutore=c->getDomandeAmici()[i]->get_autore_domanda()->get_credenziali().get_username();
    QLabel* autoreDomanda=new QLabel(QString::fromStdString(stringaAutore));

    //creo lo spazio che conterrá la domanda
    QTextEdit* testoDomanda=new QTextEdit(QString::fromStdString(c->getDomandeAmici()[i]->get_testo()));
    testoDomanda->setReadOnly(true);


    //creo la barra orizzontale con il pulsante per visualizzare i commenti
    QString u(QString::fromStdString(c->getAccesso().get_username()));
    bottoneVediCommento* commenti=new bottoneVediCommento(c->getDomandeAmici()[i],u,"vedi commenti");




    //aggiungo il pulsante commenti sotto al testo della domanda
    layoutDomandaAmici->addWidget(autoreDomanda);
    layoutDomandaAmici->addWidget(testoDomanda);
    layoutDomandaAmici->addWidget(commenti);
    layoutDomandaAmici->setAlignment(commenti,Qt::AlignRight);
    layoutWidgetPagina1->addLayout(layoutDomandaAmici);

    connect(commenti,SIGNAL(clicked()),commenti,SLOT(vediCommenti()));
    connect(commenti,SIGNAL(commento(const QString&,Domanda*)),c,SLOT(scrivi_commento(const QString&,Domanda*)));
    connect(commenti,SIGNAL(commento(const QString&,Domanda*)),commenti,SLOT(vediCommenti()));//aggiorno la vista delle domande
    }

}

void VistaUtente::aggiungiAreaDomandePersonali() //giusto
{
//    layoutWidgetScroll2


    container<Domanda*> contenitoreDomandePersonali=c->getDomandePersonali();

    for(unsigned int i=0;i<contenitoreDomandePersonali.size();i++){

    //creo lo spazio che conterrá la domanda
    QTextEdit* testoDomanda=new QTextEdit(QString::fromStdString(c->getDomandePersonali()[i]->get_testo()));
    testoDomanda->setReadOnly(true);


    //creo la barra orizzontale con il pulsante per visualizzare i commenti
    QString u(QString::fromStdString(c->getAccesso().get_username()));
    bottoneVediCommento* commenti=new bottoneVediCommento(c->getDomandePersonali()[i],u,"vedi commenti");

    layoutWidgetScroll2->addWidget(testoDomanda);
    layoutWidgetScroll2->addWidget(commenti);
    layoutWidgetScroll2->setAlignment(commenti,Qt::AlignRight);
    //pulsante per vedere i commenti
    connect(commenti,SIGNAL(clicked()),commenti,SLOT(vediCommenti()));
    connect(commenti,SIGNAL(commento(const QString&,Domanda*)),c,SLOT(scrivi_commento(const QString&,Domanda*)));
    connect(commenti,SIGNAL(commento(const QString&,Domanda*)),commenti,SLOT(vediCommenti()));
    connect(commenti,SIGNAL(like(int,Domanda*)),c,SLOT(dai_like(int,Domanda*)));
    connect(commenti,SIGNAL(like(int,Domanda*)),commenti,SLOT(vediCommenti()));
    connect(commenti,SIGNAL(rimuovi(int,Domanda*)),c,SLOT(rimuovi_commento(int,Domanda*)));   
    connect(commenti,SIGNAL(rimuovi(int,Domanda*)),commenti,SLOT(vediCommenti()));

    }

}

void VistaUtente::buildBarraSuperiore() //giusto
{
   //setter
    scriviDomanda->setPlaceholderText("cerca domanda");
    scriviDomanda->setMinimumWidth(300);   
    scriviUtente->setPlaceholderText("cerca utente");

    //aggiungo alla barra di ricerca gli elementi creati
    layoutBarraSuperiore->addWidget(profilo);
    layoutBarraSuperiore->addWidget(scriviDomanda);
    layoutBarraSuperiore->addWidget(invioDomanda);
    layoutBarraSuperiore->addWidget(scriviUtente);
    layoutBarraSuperiore->addWidget(invioUtente);
    connect(invioUtente,SIGNAL(clicked()),this,SLOT(buildCercaUtente()));
    connect(scriviUtente,SIGNAL(returnPressed()),this,SLOT(buildCercaUtente()));
    connect(invioDomanda,SIGNAL(clicked()),this,SLOT(buildDomandeCercate()));
    connect(scriviDomanda,SIGNAL(returnPressed()),this,SLOT(buildDomandeCercate()));
    connect(profilo,SIGNAL(clicked()),this,SLOT(vediProfilo()));
}

//costruisce la tabella con le due pagine (domande amici,domande personali)
//entrambe le pagine sono delle scrollArea ma nella pagina domande amici c'é una barra fissa per aggiungere domande
void VistaUtente::buildTabella() //giusto
{
    tabella->addTab(pagina1,"Domande amici");
    tabella->addTab(pagina2,"Domande personali");

    pagina1->setWidget(widgetPagina1);
    widgetPagina1->setLayout(layoutWidgetPagina1); //layout dove lavorare
    pagina2->setLayout(layoutPagina2);
    layoutPagina2->addLayout(layoutAggiungiDomanda);
    numeroDomandePersonali=new QLabel("numero di domande "+QString::number((c->getDomandePersonali().size())));
    layoutAggiungiDomanda->addWidget(numeroDomandePersonali);
    aggiungiDomanda=new QPushButton("fai domanda");
    layoutAggiungiDomanda->addWidget(aggiungiDomanda);
    layoutPagina2->addWidget(scrollPagina2);
    scrollPagina2->setWidget(WidgetScroll2);
    WidgetScroll2->setLayout(layoutWidgetScroll2); //layout dove lavorare

    //fino a qua tutto ok

    //nella pagina1 devo creare le domande con i commenti degli amici dell'utente
    aggiungiAreaDomandaAmici();

    //nella pagina2 devo creare le domande con i commenti delle domande personali
    aggiungiAreaDomandePersonali();


    connect(aggiungiDomanda,SIGNAL(clicked()),this,SLOT(buildFaiDomanda()));
}



VistaUtente::~VistaUtente()
{
    delete c;
}

void VistaUtente::vediProfilo()
{
    vistaProfilo* profilo=new vistaProfilo(c,this);
    profilo->setWindowTitle("Profilo");
    profilo->setMinimumWidth(500);
    profilo->show();
}

void VistaUtente::buildCercaUtente()
{
        container<string> parametri=c->cercaUtente(scriviUtente->text());
        if(scriviUtente->text()==QString::fromStdString(c->getAccesso().get_username()))// se è se stesso
        {
            messaggio_informativo("visita utente","per vedere i tuoi dati vai nella sezione profilo!",this);
            scriviUtente->clear();
        }
        else
        {
            if(!parametri.empty())
            {
                bool amico_presente=c->check_presenza_amico(scriviUtente->text());
                vistaCercaUtente* v=new vistaCercaUtente(parametri,amico_presente,this);
                v->show();
                connect(v,SIGNAL(invia(const QString&)),c,SLOT(aggiungi_amico(const QString&))); 
                connect(v,SIGNAL(invia(const QString&)),this,SLOT(buildCercaUtente()));
                connect(v,SIGNAL(invia(const QString&)),this,SLOT(aggiornaAreaDomandeAmici()));

                connect(v,SIGNAL(rimuovi(const QString&)),c,SLOT(togli_amico(const QString&)));
                connect(v,SIGNAL(rimuovi(const QString&)),this,SLOT(buildCercaUtente()));
                connect(v,SIGNAL(rimuovi(const QString&)),this,SLOT(aggiornaAreaDomandeAmici()));
            }else
            {
                messaggio_errore("Utente non presente","L'utente "+scriviUtente->text()+" non è stato trovato",this);
            }
        }
}

void VistaUtente::buildFaiDomanda()
{
    finestraNuovaDomanda* domanda=new finestraNuovaDomanda(this);
    domanda->show();
    connect(domanda,SIGNAL(invia(const QString&,int)),c,SLOT(faiDomanda(const QString&,int)));
    connect(domanda,SIGNAL(invia(const QString&,int)),this,SLOT(aggiornaNumeroDomande()));
    connect(domanda,SIGNAL(invia(const QString&,int)),this,SLOT(aggiungiAreaDomandePersonali()));
}

void VistaUtente::buildDomandeCercate()
{
    QString domanda=scriviDomanda->text();
    container<Domanda*> d=c->cercaDomanda(domanda);
    FinestraVistaDomande* f=new FinestraVistaDomande(d,c,this);
    f->show();
    scriviDomanda->clear();
}

void VistaUtente::aggiornaAreaDomandeAmici()
{
    aggiungiAreaDomandaAmici();
}

void VistaUtente::aggiornaNumeroDomande()
{
    numeroDomandePersonali->clear();
    numeroDomandePersonali->setText("numero di domande "+QString::number((c->getDomandePersonali().size())));
}

void VistaUtente::buildLogout()
{
    Login* l=new Login;
    l->show();
    close();
}
VistaUtente::VistaUtente(const QString& utente, QWidget *parent):QWidget(parent),c(new Controller(utente,this)),
    mainLayout(new QVBoxLayout()),
    //iniz elementi barra superiore
    layoutBarraSuperiore(new QHBoxLayout()),
    profilo(new QPushButton("Profilo")),
    invioDomanda(new QPushButton("Cerca")),
    invioUtente(new QPushButton("Cerca")),
    scriviDomanda(new QLineEdit()),
    scriviUtente(new QLineEdit()),


    //iniz elementi tabella
    tabella(new QTabWidget()),
    pagina1(new QScrollArea()),
    widgetPagina1(new QWidget()),
    layoutWidgetPagina1(new QVBoxLayout()),
    layoutDomandaAmici(new QVBoxLayout()),


    pagina2(new QWidget()),
    layoutPagina2(new QVBoxLayout()),
    layoutAggiungiDomanda(new QHBoxLayout()),
    scrollPagina2(new QScrollArea()),
    WidgetScroll2(new QWidget()),
    layoutWidgetScroll2(new QVBoxLayout()),



    numeroDomandePersonali(new QLabel()),
    aggiungiDomanda(new QPushButton()),



    logout(new QPushButton("Logout"))
{
    //setter generale
    setAttribute(Qt::WA_DeleteOnClose);// serve a chiamare la delete della finestra, che a sua volta chiama la delete del controller che effettua il salvataggio del contenuto
    setStyleSheet(imposta_stile());
    pagina1->setWidgetResizable(true);
    scrollPagina2->setWidgetResizable(true);

    //aggiunte giuste
    mainLayout->addLayout(layoutBarraSuperiore);
    mainLayout->addWidget(tabella);
    mainLayout->addWidget(logout);

    logout->setObjectName("annulla");
    setLayout(mainLayout);

    //build
    buildBarraSuperiore();
    buildTabella();

    connect(logout,SIGNAL(clicked()),this,SLOT(buildLogout()));

}
