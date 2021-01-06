#ifndef VISTAPROFILO_H
#define VISTAPROFILO_H


#include <QVBoxLayout>
#include <QTextEdit>
#include "container.h"
#include "controller.h"
#include "stile.h"
#include "widgetcampodati.h"
class vistaProfilo:public QWidget
{
    Q_OBJECT
    Controller* a;
    QVBoxLayout* layoutTotale;

    widgetCampoDati* nome;
    widgetCampoDati* cognome;
    widgetCampoDati* password;
    widgetCampoDati* email;
    QVBoxLayout* layoutCompetenzeProfessionali;
    QVBoxLayout* layoutTitoliDiStudio;
    QPushButton* home;

    //funzioni di utilitá



    void creaTornaAllaHome();

    void creaCampoCompetenze();

    void creaCampoTitoliDiStudio();

public:
    vistaProfilo(Controller*);

private slots:
      void creaCampoPunti();
      void creaCampoNome();
      void creaCampoCognome();
      void creaCampoPassword();
      void creaCampoEmail();
//    void inviaCognome(const QString&);
//    void inviaPassword(const QString&);
//    void inviaEmail(const QString&);

//    void inviaCompetenza(const QString&);
//    void inviaTitoloDiStudio(const QString&);

signals:

};

#endif // VISTAPROFILO_H
