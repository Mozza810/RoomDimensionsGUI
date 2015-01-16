#-------------------------------------------------
#
# Project created by QtCreator 2014-11-21T14:31:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RoomDimensionsGUI
TEMPLATE = app


SOURCES += main.cpp\
        RoomDimensionsGUI.cpp \
    dialogEditing.cpp

HEADERS  += RoomDimensionsGUI.h \
    dialogEditing.h

FORMS    += RoomDimensionsGUI.ui \
    editDialog.ui

OTHER_FILES +=

RESOURCES += \
    backgrounds.qrc
