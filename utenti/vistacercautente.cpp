#include "vistacercautente.h"
#include "QMessageBox"
#include <QHeaderView>
#include "funzioniutili.h"
//ciaoooo
void vistaCercaUtente::build_tabella()
{
    tabella=new QTableWidget();
    tabella->setRowCount(8);
    tabella->setColumnCount(1);
    verticalheader=new QStringList;
    verticalheader->append("Username");
    verticalheader->append("Nome");
    verticalheader->append("Cognome");
    verticalheader->append("E-mail");
    verticalheader->append("Titoli di studio");
    verticalheader->append("Competenze");
    verticalheader->append("Amici");
    verticalheader->append("Seguaci");
    tabella->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabella->setVerticalHeaderLabels(*verticalheader);
    tabella->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QHeaderView * header = tabella->verticalHeader();// adatta la larghezza delle colonne
    header->setSectionResizeMode(QHeaderView::Stretch);// adatta la larghezza delle colonne
    tabella->horizontalHeader()->setStretchLastSection(true);
    tabella->setMaximumHeight(500);
    tabella->setWindowTitle("Utente");
    QVector<QTableWidgetItem*> caratteristiche;

    for(int i=0;i<tabella->rowCount();i++){//inizializzo le scritte
        caratteristiche.append(new QTableWidgetItem("???"));
        tabella->setItem(0,i,caratteristiche[i]);
    }
    int col=0;
    for(auto it=proprieta.begin();it!=proprieta.end();++it)
    {
        caratteristiche[col]->setText(QString::fromStdString(*it));
        col++;
    }
}

void vistaCercaUtente::build_bottoni()
{
    segui=new QPushButton("Aggiungi agli amici");
//    segui->setVisible(a);// se l'utente cercato non è un amico allora attivo il pulsante
    togli=new QPushButton("Togli dagli amici");
//    segui->setVisible(!a);// se l'utente cercato è un amico allora attivo il pulsante
    esci=new QPushButton("Esci");
    connect(segui,SIGNAL(clicked()),this,SLOT(segui_utente()));
    connect(togli,SIGNAL(clicked()),this,SLOT(togli_utente()));
    connect(esci,SIGNAL(clicked()),this,SLOT(close()));
}

vistaCercaUtente::vistaCercaUtente(container<std::string> p, bool amico, QWidget *parent) :QDialog(parent),proprieta(p),a(!amico)
{// a(!amico) perchè se l'amico è presente allora il pulsante "segui" non deve essere visibile
    QVBoxLayout* mainLayout=new QVBoxLayout;
    build_tabella();
    build_bottoni();

    QHBoxLayout* layoutBottoni=new QHBoxLayout;
    layoutBottoni->addWidget(esci);
    if(a)
    {
        layoutBottoni->addWidget(segui);
    }
    else
    {
        layoutBottoni->addWidget(togli);
    }
    mainLayout->addWidget(tabella);
    mainLayout->addLayout(layoutBottoni);
    setLayout(mainLayout);
    setMaximumSize(500,500);
}

vistaCercaUtente::~vistaCercaUtente()
{

}

void vistaCercaUtente::segui_utente()
{
    QString utente(QString::fromStdString(proprieta[0]));
    messaggio_informativo("Aggiunto amico","utente "+utente+" aggiunto agli amici!",this);
    emit  invia(utente);
    close();
}

void vistaCercaUtente::togli_utente()
{
    QString utente(QString::fromStdString(proprieta[0]));
    QMessageBox* messaggio=new QMessageBox(this);
    messaggio->setWindowTitle("rimosso dagli amici");
    messaggio->setText("utente "+utente+" rimosso agli amici!");
    messaggio->exec();
    emit  rimuovi(utente);
    close();
}
