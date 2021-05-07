QT       += core gui sql printsupport network multimedia charts widgets serialport xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(QZXing_sourceV2.4/QZXing.pri)

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aaa.cpp \
    account.cpp \
    article.cpp \
    categorie.cpp \
    commande.cpp \
    connection.cpp \
    equipement.cpp \
    exportexcelobjet.cpp \
    fournisseur.cpp \
    googlesuggest.cpp \
    historique.cpp \
    historiques.cpp \
    journaliste.cpp \
    journaux.cpp \
    main.cpp \
    mainwindow.cpp \
    missions.cpp \
    publicite.cpp \
    qcustomplot.cpp \
    qrcode.cpp \
    searchbox.cpp \
    smtp.cpp \
    sponsors_crud.cpp \
    statistique.cpp \
    statistiques.cpp

HEADERS += \
    aaa.hpp \
    account.h \
    article.h \
    categorie.h \
    commande.h \
    connection.h \
    equipement.h \
    exportexcelobjet.h \
    fournisseur.h \
    googlesuggest.h \
    historique.h \
    historiques.h \
    journaliste.h \
    journaux.h \
    mainwindow.h \
    missions.h \
    publicite.h \
    qcustomplot.h \
    qrcode.h \
    searchbox.h \
    smtp.h \
    sponsors_crud.h \
    statistique.h \
    statistiques.h

FORMS += \
    mainwindow.ui \
    statistique.ui \
    statistiques.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    img_mus/screenshot.png



