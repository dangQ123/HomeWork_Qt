#-------------------------------------------------
#
# Project created by QtCreator 2021-09-19T19:17:32
#
#-------------------------------------------------

QT       += core gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HomeWork2
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

QT       += multimedia

SOURCES += \
        main.cpp \
        mainscene.cpp \
    gameobject.cpp \
    map.cpp \
    player.cpp \
    audio.cpp \
    monster.cpp \
    monsterclose.cpp \
    start.cpp \
    boss.cpp \
    sphere.cpp

HEADERS += \
        mainscene.h \
    config.h \
    gameobject.h \
    map.h \
    player.h \
    lookme.h \
    audio.h \
    monster.h \
    monsterclose.h \
    start.h \
    boss.h \
    sphere.h

RESOURCES += \
    res.qrc
CONFIG+=resources_big

DISTFILES +=

FORMS += \
    start.ui
