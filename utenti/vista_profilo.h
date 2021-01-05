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
    widgetCampoDati* competenze;
    widgetCampoDati* studio;
    QPushButton* home;

    //funzioni di utilitá
    void creaCampoPunti();
    void creaCampoNome();
    void creaCampoCognome();
    void creaCampoPassword();
    void creaCampoEmail();


    void creaTornaAllaHome();

public:
    vistaProfilo(Controller*);

signals:
    void inviaNome(const string&);
    void inviaCognome(const string&);
    void inviaPassword(const string&);
    void inviaEmail(const string&);

    void inviaCompetenza(const string&);
    void inviaTitoloDiStudio(const string&);

};

#endif // VISTAPROFILO_H
