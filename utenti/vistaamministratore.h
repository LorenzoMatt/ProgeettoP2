#ifndef VISTA_AMMINISTRATORE_H
#define VISTA_AMMINISTRATORE_H

#include <QWidget>
#include<QPushButton>
#include<QTableWidget>
#include<QVBoxLayout>
#include<QLabel>
#include<QFile>
#include<QHeaderView>
#include<QComboBox>
#include<QFormLayout>
#include<QLineEdit>
#include "creautente.h"
#include "database.h"
class controllerAdmin;
class vistaAmministratore : public QWidget
{
    Q_OBJECT
    friend class controllerAdmin;
public:
    explicit vistaAmministratore(QWidget *parent = 0);
    ~vistaAmministratore();
private:
    controllerAdmin* controller;
    QVBoxLayout* mainLyaout;
    QLabel* cambio_piano_label;
    QLabel* togli_utente_label;
    QLabel* nuovo_piano;
    QLabel* utenti;
    QPushButton* aggiungi;
    QPushButton* togli_utente_button;
    QPushButton* cambia_piano_button;
    QLineEdit* cambio_piano_username;
    QComboBox* cambio_piano_combo;
    QLineEdit* togli_utente_line;
    QPushButton* esci;
    QPushButton* salva;
    QTableWidget* tabella_utenti;
    QStringList* horizontalheader;
    QHBoxLayout* layout_salva_esci;
    QHBoxLayout* layout_togli_utente;
    QFormLayout* cambio_piano_layout;

    void build_buttons();
    void creazione_tabella();
    void build_togli_utente();
    void build_cambio_piano();
    void layout_parte_superiore();
    void scritta_utente();
    void creazione_mainLayout();
    void aggiorna_tabella();
private slots:
    void finestra_aggiungi_utente();
    void togli_utente();
    void cambio_piano();
    void salva_db();
    void logout();
    void aggiungi_utente(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&);
};

#endif // VISTA_AMMINISTRATORE_H
