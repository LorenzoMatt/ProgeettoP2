#include "vista_amministratore.h"
#include "basic.h"
#include "gold.h"
#include "premium.h"
#include "controller_admin.h"
void vista_amministratore::build_buttons()
{
    aggiungi=new QPushButton("Aggiungi utente");
    togli_utente_button=new QPushButton("Conferma");
    cambia_piano_button=new QPushButton("Conferma");
    esci=new QPushButton("esci");
    salva=new QPushButton("salva database");
    connect(aggiungi,SIGNAL(clicked()),this,SLOT(finestra_aggiungi_utente()));
    connect(togli_utente_button,SIGNAL(clicked()),this,SLOT(togli_utente()));
    connect(cambia_piano_button,SIGNAL(clicked()),this,SLOT(cambio_piano()));
    connect(salva,SIGNAL(clicked()),this,SLOT(salva_db()));
    connect(esci,SIGNAL(clicked()),this,SLOT(logout()));

}

void vista_amministratore::finestra_aggiungi_utente()
{
    creautente* utente=new creautente(this);
    utente->setWindowTitle("aggiungi un utente");

    utente->show();
    connect(utente,SIGNAL(invia(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&)),
            this, SLOT(aggiungi_utente(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&)));
}

void vista_amministratore::togli_utente()
{

}

void vista_amministratore::cambio_piano()
{

}

void vista_amministratore::salva_db()
{

}

void vista_amministratore::logout()
{

}

void vista_amministratore::aggiungi_utente(const QString & username, const QString & password, const QString & nome, const QString & cognome, const QString & email,const QString& piano)
{

}




void vista_amministratore::creazione_tabella()
{
    tabella_utenti=new QTableWidget();
    tabella_utenti->setColumnCount(7);
    horizontalheader=new QStringList();
    horizontalheader->append("Username");
    horizontalheader->append("Nome");
    horizontalheader->append("Cognome");
    horizontalheader->append("E-mail");
    horizontalheader->append("Competenze");
    horizontalheader->append("Titoli di studio");
    horizontalheader->append("Piano");
    tabella_utenti->setEditTriggers(0);
    tabella_utenti->setHorizontalHeaderLabels(*horizontalheader);
    tabella_utenti->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QHeaderView* header = tabella_utenti->horizontalHeader();// adatta la larghezza delle colonne
    header->setSectionResizeMode(QHeaderView::Stretch);// adatta la larghezza delle colonne
    tabella_utenti->setMaximumHeight(400);

    aggiorna_tabella();
}

void vista_amministratore::build_togli_utente()
{
    togli_utente_label=new QLabel("togli utente");
    togli_utente_line=new QLineEdit;
    togli_utente_label->setBuddy(togli_utente_line);
}

void vista_amministratore::build_cambio_piano()
{
    cambio_piano_label=new QLabel("cambio piano utente");
    cambio_piano_username=new QLineEdit;
    cambio_piano_label->setBuddy(cambio_piano_username);
    nuovo_piano=new QLabel("nuovo piano");
    cambio_piano_combo=new QComboBox;
    cambio_piano_combo->addItem("Basic");
    cambio_piano_combo->addItem("Gold");
    cambio_piano_combo->addItem("Premium");
    nuovo_piano->setBuddy(cambio_piano_combo);
}

void vista_amministratore::layout_parte_superiore()
{
    layout_togli_utente=new QHBoxLayout;
    layout_togli_utente->addWidget(togli_utente_label);
    layout_togli_utente->addWidget(togli_utente_line);

    cambio_piano_layout=new QFormLayout;
    cambio_piano_layout->addRow(cambio_piano_label,cambio_piano_username);
    cambio_piano_layout->addRow(nuovo_piano,cambio_piano_combo);

    layout_salva_esci=new QHBoxLayout;
    layout_salva_esci->addWidget(esci);
    layout_salva_esci->addWidget(salva);
}

void vista_amministratore::scritta_utente()
{
    utenti=new QLabel("Utenti presenti nel database");
    utenti->setFont(  QFont("Times", 30, QFont::Bold));
    utenti->setBuddy(tabella_utenti);
    utenti->setMargin(50);
}

void vista_amministratore::creazione_mainLayout()
{
    mainLyaout->addLayout(layout_togli_utente);
    mainLyaout->addWidget(togli_utente_button);
    mainLyaout->addLayout(cambio_piano_layout);
    mainLyaout->addWidget(cambia_piano_button);
    mainLyaout->addWidget(aggiungi);
    mainLyaout->addWidget(utenti,1,Qt::AlignHCenter);
    mainLyaout->addWidget(tabella_utenti,3);
    mainLyaout->addLayout(layout_salva_esci);
}

//void vista_amministratore::set_controller(Controller_admin *c)
//{
//    controller=c;
//}
//{
//    _elencoInquilini->clear();
//    vector<string> elenco= _controller->getInquilini();
//    if (elenco.size()>0)
//        for (auto i=elenco.cbegin(); i!=elenco.cend(); i++)
//            _elencoInquilini->addItem(QString::fromStdString(*i));
//    _rimuovi->setDisabled(true);
//    _modifica->setDisabled(true);
//}
void vista_amministratore::aggiorna_tabella()
{
    tabella_utenti->clearContents();
//    auto c=controller->get_utenti();
    Database c;
    crea_lista_utenti(c);
    tabella_utenti->setRowCount(c.get_utenti().size());

    int row=0;
    for(auto it=c.get_utenti().begin();it!=c.get_utenti().end();++it,++row)
    {
        QTableWidgetItem* Username=new QTableWidgetItem(QString::fromStdString((*it)->get_credenziali().get_username()));
        QTableWidgetItem* Nome=new QTableWidgetItem(QString::fromStdString((*it)->get_profilo().get_nome()));
        QTableWidgetItem* Cognome=new QTableWidgetItem(QString::fromStdString((*it)->get_profilo().get_cognome()));
        QTableWidgetItem* email=new QTableWidgetItem(QString::fromStdString((*it)->get_profilo().get_email()));
        QTableWidgetItem* Competenze=new QTableWidgetItem(QString::fromStdString((*it)->get_profilo().competenze_toString()));
        QTableWidgetItem* Titoli=new QTableWidgetItem(QString::fromStdString((*it)->get_profilo().titoli_di_studio_toString()));
        QTableWidgetItem* Piano=new QTableWidgetItem();
        if(dynamic_cast<Basic*>(&**it))
            Piano->setText("Basic");
        if(dynamic_cast<Gold*>(&**it))
            Piano->setText("Gold");
        if(dynamic_cast<Premium*>(&**it))
            Piano->setText("Premium");
        tabella_utenti->setItem(row,0,Username);
        tabella_utenti->setItem(row,1,Nome);
        tabella_utenti->setItem(row,2,Cognome);
        tabella_utenti->setItem(row,3,email);
        tabella_utenti->setItem(row,4,Competenze);
        tabella_utenti->setItem(row,5,Titoli);
        tabella_utenti->setItem(row,6,Piano);
    }

}

void vista_amministratore::crea_lista_utenti(Database& c)
{
    c.aggiungi_utente(new Basic("lorenzo99","000000","Lorenzo","Matterazzo","lorenzo.matterazzo@studenti.unipd.it"));
    c.aggiungi_utente(new Gold("lorenzo98","000000","Lorenzo","Matterazzo","lorenzo.matterazzo@studenti.unipd.it"));
    c.aggiungi_utente(new Premium("lorenzo97","000000","Lorenzo","Matterazzo","lorenzo.matterazzo@studenti.unipd.it"));
    c.aggiungi_utente(new Premium("lorenzo96","000000","Lorenzo","Matterazzo","lorenzo.matterazzo@studenti.unipd.it"));
    c.aggiungi_utente(new Gold("lorenzo95","000000","Lorenzo","Matterazzo","lorenzo.matterazzo@studenti.unipd.it"));
    c.aggiungi_utente(new Basic("lorenzo94","000000","Lorenzo","Matterazzo","lorenzo.matterazzo@studenti.unipd.it"));
    c.aggiungi_utente(new Premium("lorenzo93","000000","Lorenzo","Matterazzo","lorenzo.matterazzo@studenti.unipd.it"));
    c.aggiungi_utente(new Basic("lorenzo92","000000","Lorenzo","Matterazzo","lorenzo.matterazzo@studenti.unipd.it"));
    c.aggiungi_utente(new Basic("lorenzo91","000000","Lorenzo","Matterazzo","lorenzo.matterazzo@studenti.unipd.it"));
    c.aggiungi_utente(new Gold("lorenzo90","000000","Lorenzo","Matterazzo","lorenzo.matterazzo@studenti.unipd.it"));


    Utente* lorenzo99=c.get_utente("lorenzo99");
    lorenzo99->AggiungiCompetenza("ciaooo");
    lorenzo99->AggiungiCompetenza("ciaooo");
    lorenzo99->AggiungiCompetenza("ciaooo");
    lorenzo99->AggiungiCompetenza("ciaooo");
    lorenzo99->AggiungiCompetenza("ciaooo");
    lorenzo99->AggiungiTitoloDiStudio("ciaooo");
    lorenzo99->AggiungiTitoloDiStudio("ciaooo");
    lorenzo99->AggiungiTitoloDiStudio("ciaooo");
    lorenzo99->AggiungiTitoloDiStudio("ciaooo");
}


vista_amministratore::vista_amministratore(controller_admin *c, QWidget *parent) :controller(c), QWidget(parent)
{

    mainLyaout=new QVBoxLayout;

    build_buttons();

    build_togli_utente();

    build_cambio_piano();

    layout_parte_superiore();

//    Database d;
//    crea_lista_utenti(d);

    creazione_tabella();

    scritta_utente();

    creazione_mainLayout();

    setLayout(mainLyaout);
    setMaximumSize(1000,800);
    setWindowTitle("Amministratore");
}



vista_amministratore::~vista_amministratore()
{

}
