#ifndef STILE_H
#define STILE_H

#include <QFile>

    QString static imposta_stile()
    {
        QFile file("../style.css");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        file.close();
        return styleSheet;
    }

#endif // STILE_H
