#ifndef VISTAPROFILO_H
#define VISTAPROFILO_H


#include <QVBoxLayout>
#include <QTextEdit>
#include "container.h"
#include "controller.h"
#include "funzioniutili.h"
#include "widgetcampodati.h"
#include <QListWidget>
#include <QLineEdit>

class vistaProfilo:public QWidget
{
    Q_OBJECT
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


    QPushButton* home;


    //funzioni di utilitá

    void creaTornaAllaHome();
public:
    vistaProfilo(Controller*);

private slots:
      void creaCampoPunti();
      void creaCampoNome();
      void creaCampoCognome();
      void creaCampoPassword();
      void creaCampoEmail();

      void creaCampoCompetenze();
      void creaCampoTitoliDiStudio();

      void mostraC();
      void mostraT();
      void invioDatoC();
      void invioDatoT();

signals:
    void inviaC(const QString&);
    void inviaT(const QString&);
};

#endif // VISTAPROFILO_H
