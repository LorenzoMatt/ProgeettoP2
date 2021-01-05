#include "vista_domanda.h"
//aggiunge la domanda
void vista_domanda::aggiungiWidgetDomanda(Domanda* d)
{
    QVBoxLayout* bloccoDomanda=new QVBoxLayout;

    QTextEdit* testoDomanda=new QTextEdit(QString::fromStdString(d->get_testo()));
    testoDomanda->setReadOnly(true);

    QString autoreDomanda=QString::fromStdString(d->get_autore_domanda()->get_credenziali().get_username());
    QLabel* autore=new QLabel(autoreDomanda);
    autore->setBuddy(testoDomanda);
    bloccoDomanda->addWidget(autore);
    bloccoDomanda->addWidget(testoDomanda);


    scrollwidgetLayout->addLayout(bloccoDomanda);
}

//aggiunge i commenti
void vista_domanda::aggiungiWidgetCommenti(Domanda* d)
{
    QVBoxLayout* bloccoCommenti=new QVBoxLayout;

    //etichetta commenti:
    QLabel* risposte=new QLabel("Commenti:");
    bloccoCommenti->addWidget(risposte);

    //contenitore che contiene tutti i commenti degli amici riguardanti la domanda
    const container<Commento>& com=d->get_commenti();

    int num_commento=0;
    for(auto it=com.cbegin();it!=com.cend();++it,++num_commento){

        //testo commento
        QTextEdit* testoCommento=new QTextEdit(QString::fromStdString(it->get_testo()));
        testoCommento->setReadOnly(true);

        //etichetta autore domanda
        QString autoreCommento=QString::fromStdString(it->get_autore()->get_credenziali().get_username());
        QLabel* autore=new QLabel(autoreCommento);
        autore->setBuddy(testoCommento);
        bloccoCommenti->addWidget(autore);
        bloccoCommenti->addWidget(testoCommento);

        QHBoxLayout* valutaCommento=new QHBoxLayout;
        QPushButton* rimuovi=new QPushButton("rimuovi");
        valutaCommento->addWidget(rimuovi);
        QPushButton* like=new QPushButton("like");
        valutaCommento->addWidget(like);
        bloccoCommenti->addLayout(valutaCommento);
        connect(like,SIGNAL(clicked()),this,SLOT(buildLike(num_commento)));
        connect(rimuovi,SIGNAL(clicked()),this,SLOT(buildRimuovi(num_commento)));
    }

    scrollwidgetLayout->addLayout(bloccoCommenti);
}

//barra di testo
void vista_domanda::aggiungiBarraDiTesto()
{
    QHBoxLayout* inserisciCommento=new QHBoxLayout;
    testoCommento=new QLineEdit;
    testoCommento->setPlaceholderText("Scrivi un commento");
    QPushButton* invio=new QPushButton("invio");

    inserisciCommento->addWidget(testoCommento);
    inserisciCommento->addWidget(invio);

    scrollwidgetLayout->addLayout(inserisciCommento);

    connect(invio,SIGNAL(clicked()),this,SLOT(buildCommento()));
}

//costruttore
vista_domanda::vista_domanda(Domanda * d, QWidget *parent) :QWidget(parent),domanda(new QVBoxLayout),
    scrollarea(new QScrollArea),scrollwidget(new QWidget),scrollwidgetLayout(new QVBoxLayout)
{
    setStyleSheet(imposta_stile());

    //aggiunge allo scrollWidgetLayout il widget che contiene la domanda
    aggiungiWidgetDomanda(d);

    //aggiunge allo scrollWidgetLayout il widget che contiene tutti i commenti relativi alla domanda
    aggiungiWidgetCommenti(d);

    //aggiunge una barra di testo editabile con il pulsante invio
    aggiungiBarraDiTesto();

    //settaggi
    scrollwidget->setLayout(scrollwidgetLayout);
    scrollarea->setWidget(scrollwidget);
    scrollarea->setWidgetResizable(true);
    domanda->addWidget(scrollarea);
    setLayout(domanda);
}

void vista_domanda::buildCommento()
{
    emit commento(testoCommento->text());
    messaggio_informativo("commento aggiunto","Il messaggio è stato inserito correttamente",this);
}

void vista_domanda::buildLike(int i)
{
    emit like(i);
    messaggio_informativo("like aggiunto","l'utente apprezzerà il tuo like!",this);
}

void vista_domanda::buildRimuovi(int i)
{
    emit rimuovi(i);
    messaggio_informativo("commento rimosso","hai rimosso il commento",this);
}

