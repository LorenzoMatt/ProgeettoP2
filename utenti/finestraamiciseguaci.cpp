#include "finestraamiciseguaci.h"
#include "vistacercautente.h"

void FinestraAmiciSeguaci::buildListe()
{
    amici->clear();
    seguaci->clear();
    int row=0;
    for(auto it=controller->getAmici().begin();it!=controller->getAmici().end();++it,++row)
    {
        amici->insertItem(row,new QListWidgetItem(QString::fromStdString((*it)->get_credenziali().get_username())));
    }
    row=0;
    for(auto it=controller->getSeguaci().begin();it!=controller->getSeguaci().end();++it,++row)
    {
        seguaci->insertItem(row,new QListWidgetItem(QString::fromStdString((*it)->get_credenziali().get_username())));
    }
}
void FinestraAmiciSeguaci::buildCercaUtente(const QListWidget* lista)
{
    container<string> parametri=controller->cercaUtente(lista->currentItem()->text());
    bool amico_presente=controller->check_presenza_amico(lista->currentItem()->text());
    vistaCercaUtente* v=new vistaCercaUtente(parametri,amico_presente,this);
    v->show();
    connect(v,SIGNAL(invia(const QString&)),controller,SLOT(aggiungi_amico(const QString&)));
    connect(v,SIGNAL(rimuovi(const QString&)),controller,SLOT(togli_amico(const QString&)));
    connect(v,SIGNAL(invia(const QString&)),this,SLOT(buildListe()));
    connect(v,SIGNAL(rimuovi(const QString&)),this,SLOT(buildListe()));
}

void FinestraAmiciSeguaci::buildCercaAmico()
{
    buildCercaUtente(amici);
}

void FinestraAmiciSeguaci::buildCercaSeguace()
{
    buildCercaUtente(seguaci);
}
FinestraAmiciSeguaci::FinestraAmiciSeguaci(Controller* c, QWidget *parent) :
    QDialog(parent), controller(c)
{
    QVBoxLayout* mainLayout=new QVBoxLayout;
    amici=new QListWidget;
    seguaci=new QListWidget;
    buildListe();

    tab=new QTabWidget;
    tab->addTab(amici,"amici");
    tab->addTab(seguaci,"seguaci");
    mainLayout->addWidget(tab);
    connect(seguaci,SIGNAL(itemPressed(QListWidgetItem*)),this,SLOT(buildCercaSeguace()));
    connect(amici,SIGNAL(itemPressed(QListWidgetItem*)),this,SLOT(buildCercaAmico()));
    setMaximumSize(500,500);
    setLayout(mainLayout);
}
