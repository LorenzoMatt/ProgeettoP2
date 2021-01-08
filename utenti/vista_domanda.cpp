#include "vista_domanda.h"
//aggiunge la domanda
void vista_domanda::aggiungiWidgetDomanda(Domanda* d)
{
    QVBoxLayout* bloccoDomanda=new QVBoxLayout;

    QTextEdit* testoDomanda=new QTextEdit(QString::fromStdString(d->get_testo()));
    testoDomanda->setReadOnly(true);

    QString autoreDomanda=QString::fromStdString(d->get_autore_domanda());
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
        QString autoreCommento=QString::fromStdString(it->get_autore());
        QLabel* autore=new QLabel(autoreCommento);
        autore->setBuddy(testoCommento);
        bloccoCommenti->addWidget(autore);
        bloccoCommenti->addWidget(testoCommento);


        QHBoxLayout* valutaCommento=new QHBoxLayout;
        QString autoreDomanda=QString::fromStdString(d->get_autore_domanda());
        if(utente==autoreDomanda)
        {
            QPushButton* rimuovi=new QPushButton("rimuovi");
            valutaCommento->addWidget(rimuovi);

            if((!(it->get_like())) && autoreCommento!=autoreDomanda)
            {
                QPushButton* like=new QPushButton("like");
                valutaCommento->addWidget(like);
                connect(like, SIGNAL(clicked()), signalMapperLike,SLOT(map()));
                signalMapperLike->setMapping(like,num_commento);
            }
            bloccoCommenti->addLayout(valutaCommento);
            connect(rimuovi,SIGNAL(clicked()),signalMapperRimuovi,SLOT(map()));
            signalMapperRimuovi->setMapping(rimuovi,num_commento);
        }
    }
    connect(signalMapperLike,SIGNAL(mappedInt(int)),SLOT(buildLike(int)));
    connect(signalMapperRimuovi,SIGNAL(mappedInt(int)),SLOT(buildRimuovi(int)));
    scrollwidgetLayout->addLayout(bloccoCommenti);
}

//barra di testo
void vista_domanda::aggiungiBarraDiTesto()
{
    QHBoxLayout* inserisciCommento=new QHBoxLayout;
    testoCommento=new QLineEdit;
    testoCommento->setPlaceholderText("Scrivi un commento");
    QPushButton* invio=new QPushButton("invio");
    inserisciCommento->addSpacing(20);

    inserisciCommento->addWidget(testoCommento);
    inserisciCommento->addWidget(invio);

    scrollwidgetLayout->addLayout(inserisciCommento);

    connect(invio,SIGNAL(clicked()),this,SLOT(buildCommento()));
    connect(testoCommento,SIGNAL(returnPressed()),this,SLOT(buildCommento()));
}

//costruttore
vista_domanda::vista_domanda(Domanda * d, const QString & u, QWidget *parent) :QDialog(parent),domanda(new QVBoxLayout), dom(d),utente(u),
    scrollarea(new QScrollArea),scrollwidget(new QWidget),scrollwidgetLayout(new QVBoxLayout)
{
    setStyleSheet(imposta_stile());
    signalMapperLike=new QSignalMapper;
    signalMapperRimuovi=new QSignalMapper;
    //aggiunge allo scrollWidgetLayout il widget che contiene la domanda
    aggiungiWidgetDomanda(dom);

    //aggiunge allo scrollWidgetLayout il widget che contiene tutti i commenti relativi alla domanda
    aggiungiWidgetCommenti(dom);

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
    if(!testoCommento->text().isEmpty())
    {
        emit commento(testoCommento->text(),dom);
        close();
        messaggio_informativo("commento aggiunto","Il messaggio è stato inserito correttamente",this);
    }
    else
    {
        messaggio_errore("commento vuoto","non è possibile scrivere un commento vuoto",this);
    }
}

void vista_domanda::buildLike(int i)
{
    emit like(i,dom);
    close();
    messaggio_informativo("like aggiunto","l'utente apprezzerà il tuo like!",this);
}

void vista_domanda::buildRimuovi(int i)
{
    emit rimuovi(i,dom);
    close();
    messaggio_informativo("commento rimosso","hai rimosso il commento",this);
}

