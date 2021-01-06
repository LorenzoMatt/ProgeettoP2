#ifndef FINESTRAVISTADOMANDE_H
#define FINESTRAVISTADOMANDE_H

#include <QDialog>
#include "container.h"
#include "domanda.h"
#include "controller.h"
class FinestraVistaDomande : public QDialog
{
    Q_OBJECT

public:
    explicit FinestraVistaDomande(container<Domanda*>,Controller*, QWidget *parent = 0);
    ~FinestraVistaDomande();
private:
    container<Domanda*> domande;
    Controller* c;
    QScrollArea* paginaDomande;
    QVBoxLayout* layoutWidgetPagina;

};

#endif // FINESTRAVISTADOMANDE_H
