QT       += core gui sql
QT += sql
QT       += core gui sql printsupport
QT       += core gui network
QT       += core gui sql multimedia printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    main.cpp \
    mainwindow.cpp \
    publicite.cpp \
    qrcode.cpp \
    smtp.cpp \
    sponsors_crud.cpp

HEADERS += \
    connexion.h \
    mainwindow.h \
    publicite.h \
    qrcode.h \
    smtp.h \
    sponsors_crud.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background1.qrc \
    resources.qrc
