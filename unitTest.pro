#-------------------------------------------------
#
# Project created by QtCreator 2019-02-03T23:37:38
#
#-------------------------------------------------

QT       += testlib sql

QT       -= gui

TARGET = tst_unittest
CONFIG   += console
CONFIG   -= app_bundle

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
        tst_unittest.cpp \ 
    ../ST_test/baseworker.cpp \
    ../ST_test/employeeworker.cpp \
    ../ST_test/managerworker.cpp \
    ../ST_test/salesworker.cpp \
    ../ST_test/databaseadapter.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../ST_test/baseworker.h \
    ../ST_test/employeeworker.h \
    ../ST_test/managerworker.h \
    ../ST_test/salesworker.h \
    ../ST_test/databaseadapter.h
