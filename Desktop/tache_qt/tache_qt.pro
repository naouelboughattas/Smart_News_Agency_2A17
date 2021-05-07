QT       += core gui sql printsupport network multimedia charts widgets serialport xml

CONFIG += console
CONFIG   -= app_bundle
CONFIG +=static
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(QZXing_sourceV2.4/QZXing.pri)


CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    arduino.cpp \
    connection.cpp \
    exportexcelobjet.cpp \
    googlesuggest.cpp \
    journaliste.cpp \
    journaliste_mission.cpp \
    main.cpp \
    missions.cpp \
    qrcode.cpp \
    qrcode2.cpp \
    searchbox.cpp \
    smtp.cpp
HEADERS += \
    account.h \
    arduino.h \
    connection.h \
    exportexcelobjet.h \
    googlesuggest.h \
    journaliste.h \
    journaliste_mission.h \
    missions.h \
    qrcode.h \
    qrcode2.h \
    searchbox.h \
    smtp.h
FORMS += \
    journaliste_mission.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



RESOURCES += \
    multi.qrc

DISTFILES += \
    play0002.png




