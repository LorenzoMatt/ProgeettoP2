#include "vista_profilo.h"




void vistaProfilo::finestraDiConferma(const QString & t){
    if(t!=""){
    testoCambioPiano=t;
    dialogo=new QMessageBox(this);
    dialogo->setInformativeText (( "Vuoi salvare le modifiche?" ));
    QPushButton* salva=new QPushButton("Conferma");
    QPushButton* annulla=new QPushButton("Annulla");
    salva->setObjectName("ok");
    dialogo->setIcon(QMessageBox::Question);
    dialogo->addButton(salva,QMessageBox::AcceptRole);
    dialogo->addButton(annulla,QMessageBox::RejectRole);

    connect(salva,SIGNAL(clicked()),this,SLOT(invioPiano()));
    connect(annulla,SIGNAL(clicked()),dialogo,SLOT(close()));



    dialogo->exec();
    }
}

void vistaProfilo::invioPiano()
{
    bool esitoPiano=a->cambiaPiano(cambio_piano_combo->currentText());
    if(esitoPiano){
        messaggio_informativo("Cambio piano completato","Cambio piano andato a buon fine!",this);
        testoPunti->setText(QString::fromStdString(std::to_string(a->getPunti())));
        piano->setText(QString::fromStdString(a->getUtente()->piano()));
    }
    else
        messaggio_errore("Cambio piano non avvenuto","Il piano non é stato modificato perché uguale a quello attualmente attivo",this);


}

void vistaProfilo::creaCampoPuntiEPiano()
{
    QHBoxLayout* layoutPuntiEPiano=new QHBoxLayout;
    QHBoxLayout* layoutPunti=new QHBoxLayout;
    QHBoxLayout* layoutPiano=new QHBoxLayout;
    //piano
    QLabel* nuovo_piano=new QLabel("Cambia piano:");
    nuovo_piano->setAlignment(Qt::AlignLeft);

    cambio_piano_combo->setMinimumWidth(150);
    cambio_piano_combo->addItem("");
    cambio_piano_combo->addItem("Basic");
    cambio_piano_combo->addItem("Gold");
    cambio_piano_combo->addItem("Premium");


    nuovo_piano->setBuddy(cambio_piano_combo);
    layoutPiano->addWidget(nuovo_piano);
    layoutPiano->addWidget(cambio_piano_combo);

    connect(cambio_piano_combo,SIGNAL(currentTextChanged(const QString&)),this,SLOT(finestraDiConferma(const QString&)));
    //punti
    QLabel* etichettaPunti=new QLabel("PUNTI RESIDUI:");
    testoPunti=new QLineEdit;
    string punti=std::to_string(a->getPunti());
    testoPunti->setText(QString::fromStdString(punti));
    testoPunti->setReadOnly(true);
    testoPunti->setMaximumWidth(70);
    layoutPunti->addWidget(etichettaPunti);
    layoutPunti->addWidget(testoPunti);
    //set elementi

    layoutPuntiEPiano->addLayout(layoutPiano);
    layoutPuntiEPiano->addWidget(piano);
    layoutPuntiEPiano->addLayout(layoutPunti);

    etichettaPunti->setAlignment(Qt::AlignRight);
    layoutTotale->addLayout(layoutPuntiEPiano);
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
        if(aggiungiCompetenzaProfessionale->isVisible()){
            aggiungiCompetenzaProfessionale->setVisible(false);
            inserisciCompetenzaProfessionale->setVisible(true);
            invio->setVisible(true);
            connect(invio,SIGNAL(clicked()),this,SLOT(invioDatoC()));
//            connect(inserisciCompetenzaProfessionale,SIGNAL(returnPressed()),this,SLOT(invioDatoC()));
        }

}

void vistaProfilo::mostraT()
{
        if(aggiungiTitoloDiStudio->isVisible()){
            inserisciTitoloDiStudio->setVisible(true);
            aggiungiTitoloDiStudio->setVisible(false);
            invioT->setVisible(true);
            connect(invioT,SIGNAL(clicked()),this,SLOT(invioDatoT()));
//            connect(inserisciTitoloDiStudio,SIGNAL(returnPressed()),this,SLOT(invioDatoT()));
        }

}

void vistaProfilo::invioDatoC()
{
    QString testo=inserisciCompetenzaProfessionale->text();
    aggiungiCompetenzaProfessionale->setVisible(true);
    inserisciCompetenzaProfessionale->setVisible(false);
    invio->setVisible(false);
    if(!testo.isEmpty()){
        testoCompetenzeProfessionali->addItem(testo);
        testoCompetenzeProfessionali->scrollToBottom();
        inserisciCompetenzaProfessionale->setText("");
        emit inviaC(testo);
    }

}
void vistaProfilo::invioDatoT()
{
    QString testo=inserisciTitoloDiStudio->text();
    inserisciTitoloDiStudio->setVisible(false);
    aggiungiTitoloDiStudio->setVisible(true);
    invioT->setVisible(false);
    if(!testo.isEmpty()){
        testoTitoliDiStudio->addItem(testo);
        testoTitoliDiStudio->scrollToBottom();       
        inserisciTitoloDiStudio->setText("");
        emit inviaT(testo);

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
    layoutInserimentoCompetenza->addWidget(invio);
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
    layoutInserimentoTitoloDiStudio->addWidget(invioT);
    layoutInserimentoTitoloDiStudio->addWidget(aggiungiTitoloDiStudio);
    layoutTitoliDiStudio->addLayout(layoutInserimentoTitoloDiStudio);

    connect(aggiungiTitoloDiStudio,SIGNAL(clicked()),this,SLOT(mostraT()));
    connect(this,SIGNAL(inviaT(const QString&)),a,SLOT(aggiungiTitoloDiStudio(const QString&)));
}

vistaProfilo::vistaProfilo(Controller * c, QWidget *parent):QDialog(parent),a(c),layoutTotale(new QVBoxLayout),
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
    layoutInserimentoTitoloDiStudio(new QHBoxLayout),
    cambio_piano_combo(new QComboBox),invio(new QPushButton("Invio")),
    invioT(new QPushButton("Invio")),
    piano(new QLabel(QString::fromStdString(a->getUtente()->piano())))

{
    //file di stile
//    setStyleSheet(imposta_stile());

    //campi dati
    invio->setVisible(false);
    invio->setObjectName("ok");
    invioT->setVisible(false);
    invioT->setObjectName("ok");
    piano->setObjectName("piano");

    creaCampoPuntiEPiano();

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
