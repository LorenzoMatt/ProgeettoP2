#include "vistaprofilo.h"

vistaProfilo::vistaProfilo(Controller * c):a(c)
{
    //creo il layout che contiene tutto
    QVBoxLayout* layoutTotale=new QVBoxLayout;

    //campo dati punti
    QHBoxLayout* layoutPunti=new QHBoxLayout;
    QLabel* etichettaPunti=new QLabel("PUNTI RESIDUI:");
    layoutPunti->addWidget(etichettaPunti);
    //set elementi
    etichettaPunti->setAlignment(Qt::AlignRight);



    //campo dati nome
    QVBoxLayout* layoutNome=new QVBoxLayout;
    QLabel* EtichettaNome=new QLabel("Nome:");
    QLineEdit* testoNome=new QLineEdit;
    testoNome->setReadOnly(true);
    testoNome->setPlaceholderText(QString::fromStdString(a->getProfilo().get_nome()));
    QPushButton* confermaNome=new QPushButton("Conferma");
    confermaNome->setMaximumWidth(70);
    layoutNome->addWidget(EtichettaNome);
    layoutNome->addWidget(testoNome);
    layoutNome->addWidget(confermaNome,0,Qt::AlignRight);
    //set elementi
//    confermaNome->setAlignment(Qt::AlignRight);

    //campo dati cognome
    QVBoxLayout* layoutCognome=new QVBoxLayout;
    QLabel* EtichettaCognome=new QLabel("Cognome:");
    QLineEdit* testoCognome=new QLineEdit;
    testoCognome->setPlaceholderText(QString::fromStdString(a->getProfilo().get_cognome()));
    QPushButton* confermaCognome=new QPushButton("Conferma");
    layoutCognome->addWidget(EtichettaCognome);
    layoutCognome->addWidget(testoCognome);
    layoutCognome->addWidget(confermaCognome);
    //set elementi
//    confermaCognome->setAlignment(Qt::AlignRight);

    //campo dati password
    QVBoxLayout* layoutPassword=new QVBoxLayout;
    QLabel* etichettaPassword=new QLabel("Password:");
    QLineEdit* testoPassword=new QLineEdit;
    testoPassword->setPlaceholderText(QString::fromStdString(a->getAccesso().get_password()));
    QPushButton* confermaPassword=new QPushButton("Conferma");
    layoutPassword->addWidget(etichettaPassword);
    layoutPassword->addWidget(testoPassword);
    layoutPassword->addWidget(confermaPassword);
    //set elementi
//    confermaPassword->setAlignment(Qt::AlignRight);

    //campo dati email
    QVBoxLayout* layoutEmail=new QVBoxLayout;
    QLabel* etichettaEmail=new QLabel("Email:");
    QLineEdit* testoEmail=new QLineEdit;
    testoEmail->setPlaceholderText(QString::fromStdString(a->getProfilo().get_email()));
    QPushButton* confermaEmail=new QPushButton("Conferma");
    layoutEmail->addWidget(etichettaEmail);
    layoutEmail->addWidget(testoEmail);
    layoutEmail->addWidget(confermaEmail);
    //set elementi
//    confermaEmail->setAlignment(Qt::AlignRight);


    //campo dati aggiungi competenza
    QVBoxLayout* layoutAggiungiCompetenzaProfessionale=new QVBoxLayout;
    QLabel* etichettaAggiungiCompetenzaProfessionale=new QLabel("Aggiungi competenza professionale:");
    QTextEdit* testoAggiungiCompetenzaProfessionale=new QTextEdit;
    container<string> competenze=a->getProfilo().GetCompetenze();
    string testoCompetenze;
    for(auto it=competenze.cbegin();it!=competenze.cend();++it){
        testoCompetenze.append("-");
        testoCompetenze.append(*it);
        testoCompetenze.append("\n");
    }
    testoAggiungiCompetenzaProfessionale->setPlaceholderText(QString::fromStdString(testoCompetenze));
    QPushButton* confermaCompetenzaProfessionale=new QPushButton("Conferma");
    layoutAggiungiCompetenzaProfessionale->addWidget(etichettaAggiungiCompetenzaProfessionale);
    layoutAggiungiCompetenzaProfessionale->addWidget(testoAggiungiCompetenzaProfessionale);
    layoutAggiungiCompetenzaProfessionale->addWidget(confermaCompetenzaProfessionale);
    //set elementi
//    confermaCompetenzaProfessionale->setAlignment(Qt::AlignRight);

    //campo dati aggiungi titolo di studio
    QVBoxLayout* layoutAggiungiTitoloDiStudio=new QVBoxLayout;
    QLabel* EtichettaAggiungiTitoloDiStudio=new QLabel("Aggiungi titolo di studio:");
    QTextEdit* testoAggiungiTitoloDiStudio=new QTextEdit;
    container<string> TitoliDiStudio=a->getProfilo().GetTitoliDiStudio();
    string testoTitoliDiStudio;
    for(auto it=TitoliDiStudio.cbegin();it!=TitoliDiStudio.cend();++it){
        testoTitoliDiStudio.append("-");
        testoTitoliDiStudio.append(*it);
        testoTitoliDiStudio.append("\n");
    }
    testoAggiungiTitoloDiStudio->setPlaceholderText(QString::fromStdString(testoTitoliDiStudio));

    QPushButton* confermaTitoloDiStudio=new QPushButton("Conferma");
    layoutAggiungiTitoloDiStudio->addWidget(EtichettaAggiungiTitoloDiStudio);
    layoutAggiungiTitoloDiStudio->addWidget(testoAggiungiTitoloDiStudio);
    layoutAggiungiTitoloDiStudio->addWidget(confermaTitoloDiStudio);
    layoutAggiungiTitoloDiStudio->addSpacing(20);





    //set elementi
//    confermaTitoloDiStudio->setAlignment(Qt::AlignRight);

    //pulsante torna alla home
//    QPixmap immagineProfilo("../profilo");
    QIcon icona("../profilo");
    QPushButton* home=new QPushButton(icona,"");






    //aggiungo tutto al layout principale
    layoutTotale->addLayout(layoutPunti);
    layoutTotale->addLayout(layoutNome);
    layoutTotale->addLayout(layoutCognome);
    layoutTotale->addLayout(layoutPassword);
    layoutTotale->addLayout(layoutEmail);
    layoutTotale->addLayout(layoutAggiungiCompetenzaProfessionale);
    layoutTotale->addLayout(layoutAggiungiTitoloDiStudio);
    layoutTotale->addWidget(home);




    setLayout(layoutTotale);
}
