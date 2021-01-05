#ifndef FUNZIONIUTILI_H
#define FUNZIONIUTILI_H

#include <QFile>
#include <QMessageBox>
#include <QErrorMessage>
static QString  imposta_stile()
{
    QFile file("../style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    file.close();
    return styleSheet;
}
 static void messaggio_informativo(const QString& titolo,const QString& testo, QWidget* parent=nullptr)
{
     QMessageBox* messaggio=new QMessageBox(parent);
     messaggio->setWindowTitle(titolo);
     messaggio->setText(testo);
     messaggio->exec();
 }

 static void messaggio_errore(const QString& titolo,const QString& testo, QWidget* parent=nullptr)
 {
     QErrorMessage* messaggio=new QErrorMessage(parent);
     messaggio->setWindowTitle(titolo);
     messaggio->showMessage(testo);
 }


#endif // FUNZIONIUTILI_H
