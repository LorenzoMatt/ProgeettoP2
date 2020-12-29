#include "vista_utente.h"


//void vistaUtente::creaBarraDiRicerca()
//{
//    barraDiRicerca=new QHBoxLayout();

//    //creo i pulsanti
//    QPushButton* profilo=new QPushButton("profilo");
//    QPushButton* invioDomanda=new QPushButton("Cerca");
//    QPushButton* invioUtente=new QPushButton("Cerca");

//    //creo le linee di testo
//    QLineEdit* scriviDomanda=new QLineEdit();
//    scriviDomanda->setPlaceholderText("cerca domanda");
//    QLineEdit* scriviUtente=new QLineEdit();
//    scriviUtente->setPlaceholderText("cerca utente");

//    //aggiungo alla barra di ricerca
//    barraDiRicerca->addWidget(profilo);
//    barraDiRicerca->addWidget(scriviDomanda);
//    barraDiRicerca->addWidget(invioDomanda);
//    barraDiRicerca->addWidget(scriviUtente);
//    barraDiRicerca->addWidget(invioUtente);
//}

//void vistaUtente::creaTabella()
//{
//    tabella=new QTabWidget();

//    pagina1=new QScrollArea();
//    pagina1->setLayout(new QVBoxLayout());
//    tabella->addTab(pagina1,"Domande amici");


//    pagina2=new QScrollArea();
//    pagina2->setLayout(new QVBoxLayout());
//    tabella->addTab(pagina2,"Domande Personali");
//}

//void vistaUtente::SpazioDomandaAmici(QScrollArea* pagina)
//{
//    QVBoxLayout* domanda=new QVBoxLayout();
//    QLabel* autore=new QLabel();
//    QTextBrowser* testoDomanda=new QTextBrowser();

//    autore->setBuddy(testoDomanda);
//    domanda->addWidget(autore);
//    domanda->addWidget(testoDomanda);

//    QPushButton* commenti=new QPushButton("commenti");
//    domanda->addWidget(commenti,0,Qt::AlignRight);
//    pagina->setLayout(domanda);
//}

vistaUtente::vistaUtente(QWidget *parent):QWidget(parent)
{
//    creo la label principale
    QVBoxLayout* mainLayout=new QVBoxLayout();
    mainLayout->addWidget(new QPushButton);
    QScrollArea* scrollarea=new QScrollArea;

    QTabWidget* tabella=new QTabWidget();

    QWidget* scrollwidget=new QWidget;

    QVBoxLayout* layout_widget=new QVBoxLayout;
    layout_widget->addWidget(new QPushButton);
    layout_widget->addWidget(new QPushButton);
    layout_widget->addWidget(new QPushButton);
    layout_widget->addWidget(new QPushButton);
    layout_widget->addWidget(new QPushButton);




    scrollwidget->setLayout(layout_widget);
    scrollarea->setWidget(scrollwidget);
    scrollarea->setWidgetResizable(true);

    // costruisco il widget che contiene il layout orizzontale e la scrool area

    QWidget* totale=new QWidget;// widget che contiene tutto
    QVBoxLayout* laytotale=new QVBoxLayout;// layout che contiene la barra orizzontale e la scool area

    QHBoxLayout* lay=new QHBoxLayout;// layout che continene label e pushbutton

    lay->addWidget(new QLabel("numero di domande"));
    lay->addWidget(new QPushButton("fai domanda"));

    laytotale->addLayout(lay);
    laytotale->addWidget(scrollarea);
    totale->setLayout(laytotale);
    tabella->addTab(totale,"dio booia");
    mainLayout->addWidget(tabella);


    setLayout(mainLayout);
//    setLayout(vista);

//    //creo i campi dati
//    barraDiRicerca=new QHBoxLayout();

//    //creo i pulsanti
//    QPushButton* profilo=new QPushButton("profilo");
//    QPushButton* invioDomanda=new QPushButton("Cerca");
//    QPushButton* invioUtente=new QPushButton("Cerca");

//    //creo le linee di testo
//    QLineEdit* scriviDomanda=new QLineEdit();
//    scriviDomanda->setPlaceholderText("cerca domanda");
//    QLineEdit* scriviUtente=new QLineEdit();
//    scriviUtente->setPlaceholderText("cerca utente");

//    //aggiungo alla barra di ricerca
//    barraDiRicerca->addWidget(profilo);
//    barraDiRicerca->addWidget(scriviDomanda);
//    barraDiRicerca->addWidget(invioDomanda);
//    barraDiRicerca->addWidget(scriviUtente);
//    barraDiRicerca->addWidget(invioUtente);


//    Domanda* d=new Domanda("dio boia",new Basic("ff","ff","ff","ff","ff"),4);
//    Domanda* d1=new Domanda("dio boia",new Basic("ff","ff","ff","ff","ff"),4);
//    Domanda* d3=new Domanda("dio boia",new Basic("ff","ff","ff","ff","ff"),4);
//    Domanda* d4=new Domanda("dio boia",new Basic("ff","ff","ff","ff","ff"),4);
//    Domanda* d5=new Domanda("dio boia",new Basic("ff","ff","ff","ff","ff"),4);
//    Domanda* d6=new Domanda("dio boia",new Basic("ff","ff","ff","ff","ff"),4);
//    Domanda* d7=new Domanda("dio boia",new Basic("ff","ff","ff","ff","ff"),4);
//    Domanda* d8=new Domanda("dio boia",new Basic("ff","ff","ff","ff","ff"),4);

//    container<Domanda*> domande;
//    domande.push_back(d);
//    domande.push_back(d1);
//    domande.push_back(d3);
//    domande.push_back(d4);
//    domande.push_back(d5);
//    domande.push_back(d6);
//    domande.push_back(d7);
//    domande.push_back(d8);

//    QTabWidget* tabella=new QTabWidget();
//    pagina1=new QScrollArea();
//    QVBoxLayout* layoutpag1=new QVBoxLayout();
//    QWidget* g=new QWidget;
//    g->setLayout(layoutpag1);
//    for(auto it=domande.begin();it!=domande.end();++it)
//    {
//        QLabel* autore=new QLabel(QString::fromStdString((*it)->get_autore_domanda()->get_credenziali().get_username()));
//        autore->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
//        QTextEdit* testoDomanda=new QTextEdit(QString::fromStdString((*it)->get_testo()));
//        testoDomanda->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

//        testoDomanda->setReadOnly(true);
//        autore->setBuddy(testoDomanda);
//        QPushButton* commenti=new QPushButton("commenti");
//        commenti->
//        layoutpag1->addWidget(autore);
//        layoutpag1->addWidget(testoDomanda);
//        layoutpag1->addWidget(commenti,0,Qt::AlignRight);
//    }
//    pagina1->setWidget(g);
//    tabella->addTab(pagina1,"Domande amici");

//    pagina2=new QScrollArea();
//    pagina2->setLayout(new QVBoxLayout());
//    tabella->addTab(pagina2,"Domande Personali");

//    vista->addLayout(barraDiRicerca);
//    vista->addWidget(tabella);


////    this->setGeometry(200,200,200,200);
//    this->setMaximumSize(500,500);
//    setLayout(vista);
//    pagina=new QScrollArea();
//    QGroupBox* g=new QGroupBox();
//    QPushButton* u=new QPushButton("didid");
//    QPushButton* u2=new QPushButton("didid");
//    QPushButton* u3=new QPushButton("didid");
//    QPushButton* u4=new QPushButton("didid");
//    QPushButton* u5=new QPushButton("didid");

//    QVBoxLayout* s=new QVBoxLayout;
//    s->addWidget(u);
//    s->addWidget(u2);
//    s->addWidget(u3);
//    s->addWidget(u4);
//    s->addWidget(u5);

//    g->setLayout(s);
//    pagina->setWidget(g);
//    pagina->setWidgetResizable(true);
////    pagina->setFixedHeight(400);
//    QVBoxLayout* v=new QVBoxLayout;
//    v->addWidget(pagina);
//    setLayout(v);

}

