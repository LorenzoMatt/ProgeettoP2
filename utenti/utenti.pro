######################################################################
# Automatically generated by qmake (3.1) Sun Dec 20 15:06:11 2020
######################################################################

TEMPLATE = app
TARGET = utenti
INCLUDEPATH += .
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += accesso.h \
           amico_non_presente.h \
           commento.h \
           container.h \
    controller.h \
           deepptr.h \
           domanda.h \
           non_autore_domanda.h \
           profilo.h \
           togliere_te_stesso_dagli_amici.h \
           utente.h \
    utente_gia_presente.h \
    test_deep_ptr.h \
    test_domande.h \
    test_model.h \
    test_profilo.h \
    test_utenti.h \
    basic.h \
    pagamento.h \
    gold.h \
    punti_non_sufficienti.h \
    premium.h \
    test_polimorfismo.h \
    account.h \
    test_account.h \
    log.h \
    vista_domanda.h \
    vista_utente.h \
    creautente.h \
    database.h \
    vista_amministratore.h
FORMS +=
SOURCES += accesso.cpp \
           amico_non_presente.cpp \
           commento.cpp \
    controller.cpp \
           domanda.cpp \
           main.cpp \
           non_autore_domanda.cpp \
           profilo.cpp \
           utente.cpp \
    utente_gia_presente.cpp \
    test_domande.cpp \
    test_utenti.cpp \
    test_profilo.cpp \
    test_deep_ptr.cpp \
    test_model.cpp \
    basic.cpp \
    pagamento.cpp \
    gold.cpp \
    punti_non_sufficienti.cpp \
    premium.cpp \
    test_polimorfismo.cpp \
    account.cpp \
    test_account.cpp \
    log.cpp \
    vista_domanda.cpp \
    vista_utente.cpp \
    creautente.cpp \
    database.cpp \
    vista_amministratore.cpp
