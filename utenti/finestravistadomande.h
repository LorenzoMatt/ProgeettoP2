#ifndef FINESTRAVISTADOMANDE_H
#define FINESTRAVISTADOMANDE_H

#include <QDialog>
#include "container.h"
#include "domanda.h"
#include "controller.h"
class finestraVistaDomande : public QDialog
{
    Q_OBJECT

private:
    container<Domanda*> domande;
    Controller* c;
    QScrollArea* paginaDomande;
    QVBoxLayout* layoutWidgetPagina;
public:
    explicit finestraVistaDomande(container<Domanda*>,Controller*, QWidget *parent = nullptr);
    ~finestraVistaDomande();


};

#endif // FINESTRAVISTADOMANDE_H
