#-------------------------------------------------
#
# Project created by QtCreator 2018-01-05T12:11:16
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = Dev-ChatDesktop
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
        server_list_window.cpp \
    dbmanager.cpp \
    items_server_list.cpp \
    client_info.cpp \
    chat_client.cpp \
    new_server_window.cpp \
    message_chat.cpp

HEADERS += \
        server_list_window.h \
    dbmanager.h \
    items_server_list.h \
    client_info.h \
    chat_client.h \
    new_server_window.h \
    message_chat.h

FORMS += \
        server_list_window.ui \
    items_server_list.ui \
    chat_client.ui \
    new_server_window.ui \
    message_chat.ui
