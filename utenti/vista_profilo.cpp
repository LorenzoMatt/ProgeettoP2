#include "vista_profilo.h"

void vistaProfilo::creaCampoPunti()
{
    QHBoxLayout* layoutPunti=new QHBoxLayout;
    QLabel* etichettaPunti=new QLabel("PUNTI RESIDUI:");
    QLineEdit* testoPunti=new QLineEdit;
    string punti=std::to_string(a->getPunti());
    testoPunti->setText(QString::fromStdString(punti));
    testoPunti->setReadOnly(true);
    layoutPunti->addWidget(etichettaPunti);
    layoutPunti->addWidget(testoPunti);
    //set elementi
    etichettaPunti->setAlignment(Qt::AlignRight);
    layoutTotale->addLayout(layoutPunti);
}

void vistaProfilo::creaCampoNome()
{
    QString stringaNome=QString::fromStdString(a->getProfilo().get_nome());
    nome=new widgetCampoDati("Nome: ",stringaNome);
    connect(nome,SIGNAL(invioNome(const QString&)),a,SLOT(modificaNome(const QString&)));
    connect(nome,SIGNAL(invioNome(const QString&)),this,SLOT(creaCampoNome()));
}

void vistaProfilo::creaCampoCognome()
{
    QString stringaCognome=QString::fromStdString(a->getProfilo().get_cognome());
    cognome=new widgetCampoDati("Cognome: ",stringaCognome);
    connect(cognome,SIGNAL(invioNome(const QString&)),a,SLOT(modificaCognome(const QString&)));
    connect(cognome,SIGNAL(invioNome(const QString&)),this,SLOT(creaCampoCognome()));
}

void vistaProfilo::creaCampoPassword()
{
    QString stringaPassword=QString::fromStdString(a->getAccesso().get_password());
    password=new widgetCampoDati("Password: ",stringaPassword);
    connect(password,SIGNAL(invioNome(const QString&)),a,SLOT(modificaPassword(const QString&)));
    connect(password,SIGNAL(invioNome(const QString&)),this,SLOT(creaCampoPassword()));
}

void vistaProfilo::creaCampoEmail()
{
    QString stringaEmail=QString::fromStdString(a->getProfilo().get_email());
    email=new widgetCampoDati("Email: ",stringaEmail);
    connect(email,SIGNAL(invioNome(const QString&)),a,SLOT(modificaEmail(const QString&)));
    connect(email,SIGNAL(invioNome(const QString&)),this,SLOT(creaCampoEmail()));
}

void vistaProfilo::creaTornaAllaHome()
{
    //pulsante torna alla home
    QIcon icona("../home");
    home=new QPushButton(icona," HOME");
    connect(home,SIGNAL(clicked()),this,SLOT(close()));
}



void vistaProfilo::creaCampoCompetenze()
{
    layoutCompetenzeProfessionali=new QVBoxLayout;
    QLabel* etichettaCompetenzeProfessionali=new QLabel("Competenze professionali:");
    QTextEdit* testoCompetenzeProfessionali=new QTextEdit;
    container<string> competenze=a->getProfilo().GetCompetenze();
    string testoCompetenze;
    for(auto it=competenze.cbegin();it!=competenze.cend();++it){
        testoCompetenze.append("-");
        testoCompetenze.append(*it);
        testoCompetenze.append("\n");
    }
    testoCompetenzeProfessionali->setText(QString::fromStdString(testoCompetenze));
    testoCompetenzeProfessionali->setReadOnly(true);
    QPushButton* aggiungiCompetenzaProfessionale=new QPushButton("Aggiungi");
    aggiungiCompetenzaProfessionale->setMaximumWidth(70);
    layoutCompetenzeProfessionali->addWidget(etichettaCompetenzeProfessionali);
    layoutCompetenzeProfessionali->addWidget(testoCompetenzeProfessionali);
    layoutCompetenzeProfessionali->addWidget(aggiungiCompetenzaProfessionale,0,Qt::AlignRight);
}

void vistaProfilo::creaCampoTitoliDiStudio()
{
    layoutTitoliDiStudio=new QVBoxLayout;
    QLabel* EtichettaTitoliDiStudio=new QLabel("Titoli di studio:");
    QTextEdit* testoTitoliDiStudio=new QTextEdit;
    testoTitoliDiStudio->setReadOnly(true);
    container<string> TitoliDiStudio=a->getProfilo().GetTitoliDiStudio();
    string stringaTitoliDiStudio;
    for(auto it=TitoliDiStudio.cbegin();it!=TitoliDiStudio.cend();++it){
        stringaTitoliDiStudio.append("-");
        stringaTitoliDiStudio.append(*it);
        stringaTitoliDiStudio.append("\n");
    }
    testoTitoliDiStudio->setText(QString::fromStdString(stringaTitoliDiStudio));

    QPushButton* aggiungiTitoloDiStudio=new QPushButton("Aggiungi");
    aggiungiTitoloDiStudio->setMaximumWidth(70);
    layoutTitoliDiStudio->addWidget(EtichettaTitoliDiStudio);
    layoutTitoliDiStudio->addWidget(testoTitoliDiStudio);
    layoutTitoliDiStudio->addWidget(aggiungiTitoloDiStudio,0,Qt::AlignRight);
    layoutTitoliDiStudio->addSpacing(20);
}

vistaProfilo::vistaProfilo(Controller * c):a(c),layoutTotale(new QVBoxLayout)
{
    //file di stile
    setStyleSheet(imposta_stile());

    //campi dati
    creaCampoPunti();

    creaCampoNome();

    creaCampoCognome();

    creaCampoPassword();

    creaCampoEmail();

    creaCampoCompetenze();

    creaCampoTitoliDiStudio();

    creaTornaAllaHome();

    //aggiungo tutto al layout principale

    layoutTotale->addWidget(nome);
    layoutTotale->addWidget(cognome);
    layoutTotale->addWidget(password);
    layoutTotale->addWidget(email);
    layoutTotale->addLayout(layoutCompetenzeProfessionali);
    layoutTotale->addLayout(layoutTitoliDiStudio);
    layoutTotale->addWidget(home);

    //imposto il layout principale
    setLayout(layoutTotale);
}






