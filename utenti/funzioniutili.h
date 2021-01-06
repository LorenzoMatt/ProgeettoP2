#ifndef FUNZIONIUTILI_H
#define FUNZIONIUTILI_H

#include <QFile>
#include <QMessageBox>
#include <QErrorMessage>
QString  imposta_stile();
void messaggio_informativo(const QString& titolo,const QString& testo, QWidget* parent=nullptr);
void messaggio_errore(const QString& titolo,const QString& testo, QWidget* parent=nullptr);

#endif // FUNZIONIUTILI_H
