#-------------------------------------------------
#
# Project created by QtCreator 2020-12-14T20:18:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = utenti
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        home.cpp \
    model.cpp \
    utente.cpp \
    profilo.cpp \
    accesso.cpp \
    domanda.cpp \
    commento.cpp \
    amico_non_presente.cpp \
    non_autore_domanda.cpp

HEADERS += \
        home.h \
    model.h \
    container.h \
    utente.h \
    profilo.h \
    accesso.h \
    domanda.h \
    commento.h \
    amico_non_presente.h \
    deepptr.h \
    non_autore_domanda.h


FORMS += \
        home.ui
