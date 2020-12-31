#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{

}

void Controller::setModel(Account * modello)
{
    a=modello;
}

void Controller::setVista(VistaUtente * vista)
{
    v=vista;
}

void Controller::faiDomanda(const QString & testo)
{
    a->fai_domanda(testo.toStdString());

}
