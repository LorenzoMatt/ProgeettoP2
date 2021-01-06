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
    password=new widgetCampoDati("Password: ",stringaPassword,false);

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

void vistaProfilo::mostraC()
{
    if(!inserisciCompetenzaProfessionale->isVisible()){
        inserisciCompetenzaProfessionale->setVisible(true);
        aggiungiCompetenzaProfessionale->setText("Invio");
        connect(aggiungiCompetenzaProfessionale,SIGNAL(clicked()),this,SLOT(invioDatoC()));
    }
    else
    {

        inserisciCompetenzaProfessionale->setVisible(false);
        aggiungiCompetenzaProfessionale->setText("Aggiungi");
    }
}

void vistaProfilo::mostraT()
{
    if(!inserisciTitoloDiStudio->isVisible()){
        inserisciTitoloDiStudio->setVisible(true);
        aggiungiTitoloDiStudio->setText("Invio");
        connect(aggiungiTitoloDiStudio,SIGNAL(clicked()),this,SLOT(invioDatoT()));
    }
    else
    {

        inserisciTitoloDiStudio->setVisible(false);
        aggiungiTitoloDiStudio->setText("Aggiungi");
    }
}

void vistaProfilo::invioDatoC()
{
    QString testo=inserisciCompetenzaProfessionale->text();
    if(!testo.isEmpty()){
        testoCompetenzeProfessionali->addItem(testo);
        testoCompetenzeProfessionali->scrollToBottom();
        emit inviaC(testo);
        inserisciCompetenzaProfessionale->setText("");
    }
}
void vistaProfilo::invioDatoT()
{
    QString testo=inserisciTitoloDiStudio->text();
    if(!testo.isEmpty()){
        testoTitoliDiStudio->addItem(testo);
        testoTitoliDiStudio->scrollToBottom();
        emit inviaT(testo);
        inserisciTitoloDiStudio->setText("");
    }
}

void vistaProfilo::creaCampoCompetenze()
{
    //inizializzazione lista di competenze

    container<string> competenze=a->getProfilo().GetCompetenze();
    for(auto it=competenze.cbegin();it!=competenze.cend();++it){

        QString* testoCompetenze=new QString(QString::fromStdString(*it));
        testoCompetenzeProfessionali->addItem(*testoCompetenze);

    }
    testoCompetenzeProfessionali->setMinimumHeight(120);
    layoutCompetenzeProfessionali->addWidget(etichettaCompetenzeProfessionali);
    layoutCompetenzeProfessionali->addWidget(testoCompetenzeProfessionali);

    layoutInserimentoCompetenza->setAlignment(Qt::AlignRight);
    aggiungiCompetenzaProfessionale->setMaximumWidth(70);
    inserisciCompetenzaProfessionale->setVisible(false);
    layoutInserimentoCompetenza->addWidget(inserisciCompetenzaProfessionale);
    layoutInserimentoCompetenza->addWidget(aggiungiCompetenzaProfessionale);
    layoutCompetenzeProfessionali->addLayout(layoutInserimentoCompetenza);

    connect(aggiungiCompetenzaProfessionale,SIGNAL(clicked()),this,SLOT(mostraC()));
    connect(this,SIGNAL(inviaC(const QString&)),a,SLOT(aggiungiCompetenza(const QString&)));
}

void vistaProfilo::creaCampoTitoliDiStudio()
{
    //inizializzazione lista titoli di studio

    container<string> titoliDiStudio=a->getProfilo().GetTitoliDiStudio();
    for(auto it=titoliDiStudio.cbegin();it!=titoliDiStudio.cend();++it){

        QString* testoTitoloDiStudio=new QString(QString::fromStdString(*it));
        testoTitoliDiStudio->addItem(*testoTitoloDiStudio);

    }
    testoTitoliDiStudio->setMinimumHeight(80);
    layoutTitoliDiStudio->addWidget(etichettaTitoliDiStudio);
    layoutTitoliDiStudio->addWidget(testoTitoliDiStudio);

    layoutInserimentoTitoloDiStudio->setAlignment(Qt::AlignRight);
    aggiungiTitoloDiStudio->setMaximumWidth(70);
    inserisciTitoloDiStudio->setVisible(false);
    layoutInserimentoTitoloDiStudio->addWidget(inserisciTitoloDiStudio);
    layoutInserimentoTitoloDiStudio->addWidget(aggiungiTitoloDiStudio);
    layoutTitoliDiStudio->addLayout(layoutInserimentoTitoloDiStudio);

    connect(aggiungiTitoloDiStudio,SIGNAL(clicked()),this,SLOT(mostraT()));
    connect(this,SIGNAL(inviaT(const QString&)),a,SLOT(aggiungiTitoloDiStudio(const QString&)));
}

vistaProfilo::vistaProfilo(Controller * c):a(c),layoutTotale(new QVBoxLayout),
    etichettaCompetenzeProfessionali(new QLabel("Competenze professionali:")),
    layoutCompetenzeProfessionali(new QVBoxLayout),
    aggiungiCompetenzaProfessionale(new QPushButton("Aggiungi")),
    inserisciCompetenzaProfessionale(new QLineEdit),
    testoCompetenzeProfessionali(new QListWidget),
    layoutInserimentoCompetenza(new QHBoxLayout),

    etichettaTitoliDiStudio(new QLabel("Titoli di studio:")),
    layoutTitoliDiStudio(new QVBoxLayout),
    aggiungiTitoloDiStudio(new QPushButton("Aggiungi")),
    inserisciTitoloDiStudio(new QLineEdit),
    testoTitoliDiStudio(new QListWidget),
    layoutInserimentoTitoloDiStudio(new QHBoxLayout)

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
