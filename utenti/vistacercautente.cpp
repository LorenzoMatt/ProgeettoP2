#include "vistacercautente.h"
#include "QMessageBox"
#include <QHeaderView>
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
    //modofico le scritte
    int col=0;
//    for(unsigned int i=0;i<proprieta.size();i++,col++)
//    {
//        caratteristiche[col]->setText(QString::fromStdString(proprieta[i]));

//    }
    for(auto it=proprieta.begin();it!=proprieta.end();++it)
    {
        caratteristiche[col]->setText(QString::fromStdString(*it));
        col++;
    }


//    list<string> l;
//    client->ricerca(us, l);
//    int i=0;
//    list<string>::iterator it;
//    ui->tableWidgetWindowClientCerca->insertColumn(0);
//    for(it=l.begin(); it!=l.end(); ++it)
//    {
//        QTableWidgetItem *info=new QTableWidgetItem (QString::fromStdString(*it));
//        ui->tableWidgetWindowClientCerca->setItem(0,i,info);
//        i++;
//    }
}

void vistaCercaUtente::build_bottoni()
{
    segui=new QPushButton("Aggiungi agli amici");
    esci=new QPushButton("Esci");
    connect(segui,SIGNAL(clicked()),this,SLOT(segui_utente()));
    connect(esci,SIGNAL(clicked()),this,SLOT(close()));
}

vistaCercaUtente::vistaCercaUtente(container<std::string> p, QWidget *parent) :proprieta(p), QWidget(parent)
{
    QVBoxLayout* mainLayout=new QVBoxLayout;
    build_tabella();
    build_bottoni();

    QHBoxLayout* layoutBottoni=new QHBoxLayout;
    layoutBottoni->addWidget(esci);
    layoutBottoni->addWidget(segui);
    mainLayout->addWidget(tabella);
    mainLayout->addLayout(layoutBottoni);
    setLayout(mainLayout);
}

vistaCercaUtente::~vistaCercaUtente()
{

}

void vistaCercaUtente::segui_utente()
{
    QString utente(QString::fromStdString(proprieta[0]));
    emit  invia(utente);
    QMessageBox* messaggio=new QMessageBox(this);
    messaggio->setWindowTitle("Aggiunto amico");
    messaggio->setText("utente "+utente+" aggiunto agli amici!");
    messaggio->exec();
}
