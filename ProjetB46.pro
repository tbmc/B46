TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    arbres.c \
    liste_chainees.c \
    table_hash.c \
    fichiers.c \
    menu.c

HEADERS += \
    arbres.h \
    table_hash.h \
    liste_chainees.h \
    all.h \
    fichiers.h \
    menu.h
