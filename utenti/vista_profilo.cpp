#include "vista_profilo.h"

vistaProfilo::vistaProfilo(Controller * c,QWidget* parent):a(c),QWidget(parent)
{
    setStyleSheet(imposta_stile());
    //creo il layout che contiene tutto
    QVBoxLayout* layoutTotale=new QVBoxLayout;

    //campo dati punti
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



    //campo dati nome
    QVBoxLayout* layoutNome=new QVBoxLayout;
    QLabel* EtichettaNome=new QLabel("Nome:");
    QLineEdit* testoNome=new QLineEdit;
    testoNome->setText(QString::fromStdString(a->getProfilo().get_nome()));
    testoNome->setReadOnly(true);
    QPushButton* modificaNome=new QPushButton("Modifica");
    modificaNome->setMaximumWidth(70);
    layoutNome->addWidget(EtichettaNome);
    layoutNome->addWidget(testoNome);
    layoutNome->addWidget(modificaNome,0,Qt::AlignRight);

    //campo dati cognome
    QVBoxLayout* layoutCognome=new QVBoxLayout;
    QLabel* EtichettaCognome=new QLabel("Cognome:");
    QLineEdit* testoCognome=new QLineEdit;
    testoCognome->setText(QString::fromStdString(a->getProfilo().get_cognome()));
    testoCognome->setReadOnly(true);
    QPushButton* modificaCognome=new QPushButton("Modifica");
    modificaCognome->setMaximumWidth(70);
    layoutCognome->addWidget(EtichettaCognome);
    layoutCognome->addWidget(testoCognome);
    layoutCognome->addWidget(modificaCognome,0,Qt::AlignRight);

    //campo dati password
    QVBoxLayout* layoutPassword=new QVBoxLayout;
    QLabel* etichettaPassword=new QLabel("Password:");
    QLineEdit* testoPassword=new QLineEdit;
    testoPassword->setText(QString::fromStdString(a->getAccesso().get_password()));
    testoPassword->setReadOnly(true);
    QPushButton* modificaPassword=new QPushButton("Modifica");
    modificaPassword->setMaximumWidth(70);
    layoutPassword->addWidget(etichettaPassword);
    layoutPassword->addWidget(testoPassword);
    layoutPassword->addWidget(modificaPassword,0,Qt::AlignRight);

    //campo dati email
    QVBoxLayout* layoutEmail=new QVBoxLayout;
    QLabel* etichettaEmail=new QLabel("Email:");
    QLineEdit* testoEmail=new QLineEdit;
    testoEmail->setText(QString::fromStdString(a->getProfilo().get_email()));
    testoEmail->setReadOnly(true);
    QPushButton* modificaEmail=new QPushButton("Modifica");
    modificaEmail->setMaximumWidth(70);
    layoutEmail->addWidget(etichettaEmail);
    layoutEmail->addWidget(testoEmail);
    layoutEmail->addWidget(modificaEmail,0,Qt::AlignRight);

    //campo dati aggiungi competenza
    QVBoxLayout* layoutCompetenzeProfessionali=new QVBoxLayout;
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

    //campo dati aggiungi titolo di studio
    QVBoxLayout* layoutTitoliDiStudio=new QVBoxLayout;
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

    //pulsante torna alla home
    QIcon icona("../home");
    QPushButton* home=new QPushButton(icona," HOME");
    connect(home,SIGNAL(clicked()),this,SLOT(close()));

    //aggiungo tutto al layout principale
    layoutTotale->addLayout(layoutPunti);
    layoutTotale->addLayout(layoutNome);
    layoutTotale->addLayout(layoutCognome);
    layoutTotale->addLayout(layoutPassword);
    layoutTotale->addLayout(layoutEmail);
    layoutTotale->addLayout(layoutCompetenzeProfessionali);
    layoutTotale->addLayout(layoutTitoliDiStudio);
    layoutTotale->addWidget(home);

    //imposto il layout principale
    setLayout(layoutTotale);
}


