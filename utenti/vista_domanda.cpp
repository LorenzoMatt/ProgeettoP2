#include "vista_domanda.h"

QVBoxLayout* vista_domanda::addAutoreDomanda()
{
    QVBoxLayout* layout_widget=new QVBoxLayout;


    //creo lo spazio che conterrá la domanda
    QTextEdit* testoDomanda=new QTextEdit; //al momento della creazione verrá inserito il testo della domanda
    testoDomanda->setReadOnly(true);



    QLabel* autoreDomanda=new QLabel("Autore");
    autoreDomanda->setBuddy(testoDomanda);
    layout_widget->addWidget(autoreDomanda);
    layout_widget->addWidget(testoDomanda);

    return layout_widget;
}

QVBoxLayout* vista_domanda::addAutoreDomandaLike(){

    QVBoxLayout* blocco=addAutoreDomanda();
    QHBoxLayout* valutaCommento=new QHBoxLayout;
    QPushButton* rimuovi=new QPushButton("rimuovi");
    valutaCommento->addWidget(rimuovi);
    QPushButton* like=new QPushButton("like");
    valutaCommento->addWidget(like);
    blocco->addLayout(valutaCommento);

    return blocco;

}
vista_domanda::vista_domanda(QWidget *parent) :QWidget(parent),domanda(new QVBoxLayout)
{

    QScrollArea* scrollarea=new QScrollArea;

    //creo il widget da inserire dentro alla scrollArea
    QWidget* scrollwidget=new QWidget;

    QVBoxLayout* blocco=addAutoreDomanda();

    scrollwidget->setLayout(blocco);


    QLabel* risposte=new QLabel("Commenti:");
    blocco->addWidget(risposte);

    //aggiungo dei commenti alla domada
    QVBoxLayout* bloccoCommenti=addAutoreDomandaLike();
    blocco->addLayout(bloccoCommenti);
    QVBoxLayout* bloccoCommenti1=addAutoreDomandaLike();
    blocco->addLayout(bloccoCommenti1);
    QVBoxLayout* bloccoCommenti2=addAutoreDomandaLike();
    blocco->addLayout(bloccoCommenti2);
    QVBoxLayout* bloccoCommenti3=addAutoreDomandaLike();
    blocco->addLayout(bloccoCommenti3);




    scrollarea->setWidget(scrollwidget);
    scrollarea->setWidgetResizable(true);


    domanda->addWidget(scrollarea);


    //aggiungo una barra di testo editabile con il pulsante invio
    QHBoxLayout* inserisciCommento=new QHBoxLayout;
    QLineEdit* testoCommento=new QLineEdit;
    testoCommento->setPlaceholderText("Scrivi un commento");
    //setto la dimensione della barra di testo
    QPushButton* invio=new QPushButton("invio");

    inserisciCommento->addWidget(testoCommento);
    inserisciCommento->addWidget(invio);

    domanda->addLayout(inserisciCommento);
    //setLayout(domanda);

}

