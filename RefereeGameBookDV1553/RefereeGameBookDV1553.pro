#-------------------------------------------------
#
# Project created by QtCreator 2017-11-30T21:50:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RefereeGameBookDV1553
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
        mainwindow.cpp \
    referee.cpp \
    referees.cpp \
    refereewindow.cpp \
    team.cpp \
    teams.cpp \
    teamwindow.cpp

HEADERS += \
        mainwindow.h \
    ../../../Qt projekt/RefereeGameBook Projekt/RefereeGameBookQt/referee.h \
    ../../../Qt projekt/RefereeGameBook Projekt/RefereeGameBookQt/referees.h \
    ../../../Qt projekt/RefereeGameBook Projekt/RefereeGameBookQt/refereewindow.h \
    ../../../Qt projekt/RefereeGameBook Projekt/RefereeGameBookQt/team.h \
    ../../../Qt projekt/RefereeGameBook Projekt/RefereeGameBookQt/referee.h \
    referee.h \
    referees.h \
    refereewindow.h \
    team.h \
    teams.h \
    teamwindow.h

FORMS += \
        mainwindow.ui \
    refereewindow.ui \
    teamwindow.ui
