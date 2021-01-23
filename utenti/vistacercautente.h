#ifndef VISTACERCAUTENTE_H
#define VISTACERCAUTENTE_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "container.h"
class vistaCercaUtente : public QDialog
{
    Q_OBJECT
private:
    QTableWidget* tabella;
    QPushButton* segui;
    QPushButton* togli;
    QPushButton* esci;
    QStringList* verticalheader;
    container<std::string> proprieta;
    void build_tabella();
    void build_bottoni();
    bool a;
public:
    explicit vistaCercaUtente(container<std::string> p,bool amico,QWidget *parent = 0);
    ~vistaCercaUtente();
private slots:
    void segui_utente();
    void togli_utente();
signals:
    void invia(const QString&);
    void rimuovi(const QString&);
};

#endif // VISTACERCAUTENTE_H
