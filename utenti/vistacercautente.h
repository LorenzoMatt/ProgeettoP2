#ifndef VISTACERCAUTENTE_H
#define VISTACERCAUTENTE_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "container.h"
class vistaCercaUtente : public QWidget
{
    Q_OBJECT
private:
    QTableWidget* tabella;
    QPushButton* segui;
    QPushButton* esci;
    QStringList* verticalheader;
    container<std::string> proprieta;
    void build_tabella();
    void build_bottoni();
public:
    explicit vistaCercaUtente(container<std::string> p,QWidget *parent = 0);
    ~vistaCercaUtente();
private slots:
    void segui_utente();
signals:
    void invia(const QString&);
};

#endif // VISTACERCAUTENTE_H
