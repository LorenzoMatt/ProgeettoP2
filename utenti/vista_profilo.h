#ifndef VISTAPROFILO_H
#define VISTAPROFILO_H


#include <QVBoxLayout>
#include <QTextEdit>
#include <QListWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QMessageBox>
#include "funzioniutili.h"
#include "container.h"
#include "controller.h"
#include "widgetcampodati.h"
class vistaProfilo:public QDialog
{
    Q_OBJECT
private:
    Controller* a;


    QVBoxLayout* layoutTotale;
    widgetCampoDati* nome;
    widgetCampoDati* cognome;
    widgetCampoDati* password;
    widgetCampoDati* email;

    QLabel* etichettaCompetenzeProfessionali;
    QVBoxLayout* layoutCompetenzeProfessionali;
    QPushButton* aggiungiCompetenzaProfessionale;
    QLineEdit* inserisciCompetenzaProfessionale;
    QListWidget* testoCompetenzeProfessionali;
    QHBoxLayout* layoutInserimentoCompetenza;

    QLabel* etichettaTitoliDiStudio;
    QVBoxLayout* layoutTitoliDiStudio;
    QPushButton* aggiungiTitoloDiStudio;
    QLineEdit* inserisciTitoloDiStudio;
    QListWidget* testoTitoliDiStudio;
    QHBoxLayout* layoutInserimentoTitoloDiStudio;

    QComboBox* cambio_piano_combo;
    QMessageBox* messaggio;
    QPushButton* home;
    QMessageBox* dialogo;

    QLineEdit* testoPunti;
    QPushButton* invio;
    QPushButton* invioT;
    QString testoCambioPiano;
    QLabel* piano;


    //funzioni di utilitá
    void creaCampoPuntiEPiano();
    void creaCampoCompetenze();
    void creaCampoTitoliDiStudio();
    void creaTornaAllaHome();
public:
    explicit vistaProfilo(Controller*,QWidget* parent=nullptr);

private slots:


    void mostraC();
    void mostraT();
    void invioDatoC();
    void invioDatoT();
    void invioPiano();
    void creaCampoNome();
    void creaCampoCognome();
    void creaCampoPassword();
    void creaCampoEmail();


    void finestraDiConferma(const QString&);

signals:
    void inviaC(const QString&);
    void inviaT(const QString&);

};

#endif // VISTAPROFILO_H
