/********************************************************************************
** Form generated from reading UI file 'journaliste_mission.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNALISTE_MISSION_H
#define UI_JOURNALISTE_MISSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_journaliste_mission
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *gestion_journaliste;
    QPushButton *gestion_des_mission;
    QLabel *label;
    QLabel *animation;
    QWidget *page_2;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QPushButton *pb_ajouter_2;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *id;
    QLineEdit *le_nom_2;
    QLineEdit *le_prenom_2;
    QLineEdit *le_fonction_2;
    QLineEdit *le_diplome_2;
    QPushButton *return_3;
    QWidget *tab_5;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_21;
    QLineEdit *id_rechercher_2;
    QPushButton *recherchep_2;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_10;
    QTableView *tab_journaliste_2;
    QWidget *horizontalLayoutWidget_11;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_14;
    QPushButton *pdf_p_2;
    QPushButton *tri_p_2;
    QPushButton *trieprenom;
    QWidget *horizontalLayoutWidget_12;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *le_id_6;
    QLineEdit *le_nom_5;
    QLineEdit *le_prenom_5;
    QLineEdit *le_fonction_4;
    QLineEdit *le_diplome_4;
    QTableView *recherche_tab_2;
    QWidget *horizontalLayoutWidget_13;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *afficherp_2;
    QPushButton *modifierp_2;
    QPushButton *supprimer_2;
    QWidget *tab_6;
    QWidget *horizontalLayoutWidget_14;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_32;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *mail_2;
    QLineEdit *objet_2;
    QLineEdit *contenu_2;
    QPushButton *envoyer;
    QWidget *page_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QPushButton *pb_ajouter_3;
    QWidget *horizontalLayoutWidget_15;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_33;
    QLabel *label_34;
    QVBoxLayout *verticalLayout_14;
    QLineEdit *id_mission;
    QLineEdit *libelle;
    QLineEdit *description;
    QLineEdit *confidentialite;
    QPushButton *return_4;
    QWidget *tab_8;
    QWidget *horizontalLayoutWidget_16;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_35;
    QLineEdit *id_rechercher_3;
    QPushButton *recherchep_3;
    QWidget *horizontalLayoutWidget_17;
    QHBoxLayout *horizontalLayout_17;
    QTableView *tab_journaliste_3;
    QWidget *horizontalLayoutWidget_18;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_36;
    QPushButton *pdf_p_3;
    QPushButton *tri_p_3;
    QTableView *recherche_tab_3;
    QWidget *horizontalLayoutWidget_19;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QVBoxLayout *verticalLayout_16;
    QLineEdit *id_miss_mod;
    QLineEdit *libelle_miss_mod;
    QLineEdit *description_mod;
    QLineEdit *confidentialite_mod;
    QWidget *horizontalLayoutWidget_20;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *afficherp_3;
    QPushButton *modifierp_3;
    QPushButton *supprimer_3;

    void setupUi(QDialog *journaliste_mission)
    {
        if (journaliste_mission->objectName().isEmpty())
            journaliste_mission->setObjectName(QString::fromUtf8("journaliste_mission"));
        journaliste_mission->resize(831, 421);
        journaliste_mission->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color:#f0f0f0;\n"
"}\n"
"QCheckBox {\n"
"	padding:2px;\n"
"}\n"
"QCheckBox:hover {\n"
"	border-radius:4px;\n"
"	border-style:solid;\n"
"	border-width:1px;\n"
"	padding-left: 1px;\n"
"	padding-right: 1px;\n"
"	padding-bottom: 1px;\n"
"	padding-top: 1px;\n"
"	border-color: rgb(255,150,60);\n"
"	background-color:qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(190, 90, 50, 50), stop:1 rgba(250, 130, 40, 50));\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"	border-radius:4px;\n"
"	border-style:solid;\n"
"	border-width:1px;\n"
"	border-color: rgb(246, 134, 86);\n"
"  	background-color:rgb(246, 134, 86)\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	border-radius:4px;\n"
"	border-style:solid;\n"
"	border-width:1px;\n"
"	border-color:rgb(246, 134, 86);\n"
"  	background-color:rgb(255,255,255);\n"
"}\n"
"QColorDialog {\n"
"	background-color:#f0f0f0;\n"
"}\n"
"QComboBox {\n"
"	color:rgb(81,72,65);\n"
"	background: #ffffff;\n"
"}\n"
"QComboBox:editable {\n"
"	background: #"
                        "ffffff;\n"
"	color: rgb(81,72,65);\n"
"	selection-color:rgb(81,72,65);\n"
"	selection-background-color: #ffffff;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"	color:rgb(81,72,65);	\n"
"	background: #ffffff;\n"
"	selection-color: #ffffff;\n"
"	selection-background-color: rgb(246, 134, 86);\n"
"}\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"	color:  #1e1d23;	\n"
"	background: #ffffff;\n"
"}\n"
"QDateTimeEdit {\n"
"	color:rgb(81,72,65);\n"
"	background-color: #ffffff;\n"
"}\n"
"QDateEdit {\n"
"	color:rgb(81,72,65);\n"
"	background-color: #ffffff;\n"
"}\n"
"QDialog {\n"
"	background-color:#f0f0f0;\n"
"}\n"
"QDoubleSpinBox {\n"
"	color:rgb(81,72,65);\n"
"	background-color: #ffffff;\n"
"}\n"
"QFontComboBox {\n"
"	color:rgb(81,72,65);\n"
"	background-color: #ffffff;\n"
"}\n"
"QLabel {\n"
"	color:rgb(17,17,17);\n"
"}\n"
"QLineEdit {\n"
"	background-color:rgb(255,255,255);\n"
"	selection-background-color:rgb(236,116,64);\n"
"	color:rgb(17,17,17);\n"
"}\n"
"QMenuBar {\n"
"	color:rgb(223,219,210);\n"
""
                        "	background-color:rgb(65,64,59);\n"
"}\n"
"QMenuBar::item {\n"
"	padding-top:4px;\n"
"	padding-left:4px;\n"
"	padding-right:4px;\n"
"	color:rgb(223,219,210);\n"
"	background-color:rgb(65,64,59);\n"
"}\n"
"QMenuBar::item:selected {\n"
"	color:rgb(255,255,255);\n"
"	padding-top:2px;\n"
"	padding-left:2px;\n"
"	padding-right:2px;\n"
"	border-top-width:2px;\n"
"	border-left-width:2px;\n"
"	border-right-width:2px;\n"
"	border-top-right-radius:4px;\n"
"	border-top-left-radius:4px;\n"
"	border-style:solid;\n"
"	background-color:rgb(65,64,59);\n"
"	border-top-color: rgb(47,47,44);\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(90, 87, 78, 255), stop:1 rgba(47,47,44, 255));\n"
"	border-left-color:  qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 rgba(90, 87, 78, 255), stop:1 rgba(47,47,44, 255));\n"
"}\n"
"QMenu {\n"
"	color:rgb(223,219,210);\n"
"	background-color:rgb(65,64,59);\n"
"}\n"
"QMenu::item {\n"
"	color:rgb(223,219,210);\n"
"	padding-left:20px;\n"
"	padding"
                        "-top:4px;\n"
"	padding-bottom:4px;\n"
"	padding-right:10px;\n"
"}\n"
"QMenu::item:selected {\n"
"	color:rgb(255,255,255);\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(225, 108, 54, 255), stop:1 rgba(246, 134, 86, 255));\n"
"	border-style:solid;\n"
"	border-width:3px;\n"
"	padding-left:17px;\n"
"	padding-top:4px;\n"
"	padding-bottom:4px;\n"
"	padding-right:7px;\n"
"	border-bottom-color:qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(175,85,48,255), stop:1 rgba(236,114,67, 255));\n"
"	border-top-color:qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(253,156,113,255), stop:1 rgba(205,90,46, 255));\n"
"	border-right-color:qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgba(253,156,113,255), stop:1 rgba(205,90,46, 255));\n"
"	border-left-color:qlineargradient(spread:pad, x1:1, y1:0.5, x2:0, y2:0.5, stop:0 rgba(253,156,113,255), stop:1 rgba(205,90,46, 255));\n"
"}\n"
"QPlainTextEdit {\n"
"	border-width: 1px;\n"
"	bor"
                        "der-style: solid;\n"
"	border-color:transparent;\n"
"	color:rgb(17,17,17);\n"
"	selection-background-color:rgb(236,116,64);\n"
"}\n"
"QProgressBar {\n"
"	text-align: center;\n"
"	color: rgb(0, 0, 0);\n"
"	border-width: 1px; \n"
"	border-radius: 10px;\n"
"	border-style: inset;\n"
"	border-color: rgb(150,150,150);\n"
"	background-color:rgb(221,221,219);\n"
"}\n"
"QProgressBar::chunk:horizontal {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(225, 108, 54, 255), stop:1 rgba(246, 134, 86, 255));\n"
"	border-style: solid;\n"
"	border-radius:8px;\n"
"	border-width:1px;\n"
"	border-bottom-color:qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(175,85,48,255), stop:1 rgba(236,114,67, 255));\n"
"	border-top-color:qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(253,156,113,255), stop:1 rgba(205,90,46, 255));\n"
"	border-right-color:qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgba(253,156,113,255), stop:1 rgba(205,90,46, "
                        "255));\n"
"	border-left-color:qlineargradient(spread:pad, x1:1, y1:0.5, x2:0, y2:0.5, stop:0 rgba(253,156,113,255), stop:1 rgba(205,90,46, 255));\n"
"}\n"
"QPushButton{\n"
"	color:rgb(17,17,17);\n"
"	border-width: 1px;\n"
"	border-radius: 6px;\n"
"	border-bottom-color: rgb(150,150,150);\n"
"	border-right-color: rgb(165,165,165);\n"
"	border-left-color: rgb(165,165,165);\n"
"	border-top-color: rgb(180,180,180);\n"
"	border-style: solid;\n"
"	padding: 4px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(220, 220, 220, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QPushButton:hover{\n"
"	color:rgb(17,17,17);\n"
"	border-width: 1px;\n"
"	border-radius:6px;\n"
"	border-top-color: rgb(255,150,60);\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(200, 70, 20, 255), stop:1 rgba(255,150,60, 255));\n"
"	border-left-color:  qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 rgba(200, 70, 20, 255), stop:1 rgba(255,150,60, 255));"
                        "\n"
"	border-bottom-color: rgb(200,70,20);\n"
"	border-style: solid;\n"
"	padding: 2px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(220, 220, 220, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QPushButton:default{\n"
"	color:rgb(17,17,17);\n"
"	border-width: 1px;\n"
"	border-radius:6px;\n"
"	border-top-color: rgb(255,150,60);\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(200, 70, 20, 255), stop:1 rgba(255,150,60, 255));\n"
"	border-left-color:  qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 rgba(200, 70, 20, 255), stop:1 rgba(255,150,60, 255));\n"
"	border-bottom-color: rgb(200,70,20);\n"
"	border-style: solid;\n"
"	padding: 2px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(220, 220, 220, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QPushButton:pressed{\n"
"	color:rgb(17,17,17);\n"
"	border-width: 1px;\n"
"	border-radius: 6px;\n"
"	border-width: 1px;\n"
"	"
                        "border-top-color: rgba(255,150,60,200);\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(200, 70, 20, 255), stop:1 rgba(255,150,60, 200));\n"
"	border-left-color:  qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 rgba(200, 70, 20, 255), stop:1 rgba(255,150,60, 200));\n"
"	border-bottom-color: rgba(200,70,20,200);\n"
"	border-style: solid;\n"
"	padding: 2px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(220, 220, 220, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QPushButton:disabled{\n"
"	color:rgb(174,167,159);\n"
"	border-width: 1px;\n"
"	border-radius: 6px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(230, 230, 230, 255));\n"
"}\n"
"QRadioButton {\n"
"	padding: 1px;\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-width: 1px;\n"
"	border-col"
                        "or: rgba(246, 134, 86, 255);\n"
"	color: #a9b7c6;\n"
"	background-color:rgba(246, 134, 86, 255);\n"
"}\n"
"QRadioButton::indicator:!checked {\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-width: 1px;\n"
"	border-color: rgb(246, 134, 86);\n"
"	color: #a9b7c6;\n"
"	background-color: transparent;\n"
"}\n"
"QScrollArea {\n"
"	color: #FFFFFF;\n"
"	background-color:#f0f0f0;\n"
"}\n"
"QSlider::groove {\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(207,207,207);\n"
"}\n"
"QSlider::groove:horizontal {\n"
"	height: 5px;\n"
"	background: rgb(246, 134, 86);\n"
"}\n"
"QSlider::groove:vertical {\n"
"	width: 5px;\n"
"	background: rgb(246, 134, 86);\n"
"}\n"
"QSlider::handle:horizontal {\n"
"	background: rgb(253,253,253);\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(207,207,207);\n"
"	width: 12px;\n"
"	margin: -5px 0;\n"
"	border-radius: 7px;\n"
"}\n"
"QSlider::handle:vertical {\n"
"	background: rgb(253,253,253);\n"
"	bo"
                        "rder-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(207,207,207);\n"
"	height: 12px;\n"
"	margin: 0 -5px;\n"
"	border-radius: 7px;\n"
"}\n"
"QSlider::add-page:horizontal {\n"
" 	background: white;\n"
"}\n"
"QSlider::add-page:vertical {\n"
"	background: white;\n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"	background: rgb(246, 134, 86);\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"  	background: rgb(246, 134, 86);\n"
"}\n"
"QStatusBar {\n"
"	color:rgb(81,72,65);\n"
"}\n"
"QSpinBox {\n"
"	color:rgb(81,72,65);\n"
"	background-color: #ffffff;\n"
"}\n"
"QScrollBar:horizontal {\n"
"	max-height: 20px;\n"
"	border: 1px transparent grey;\n"
"	margin: 0px 20px 0px 20px;\n"
"}\n"
"QScrollBar::handle:horizontal {\n"
"	background: rgb(253,253,253);\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(207,207,207);\n"
"	border-radius: 7px;\n"
"	min-width: 25px;\n"
"}\n"
"QScrollBar::handle:horizontal:hover {\n"
"	background: rgb(253,253,253);\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
""
                        "	border-color: rgb(255,150,60);\n"
"	border-radius: 7px;\n"
"	min-width: 25px;\n"
"}\n"
"QScrollBar::add-line:horizontal {\n"
"  	border: 1px solid;\n"
"  	border-color: rgb(207,207,207);\n"
"  	border-top-right-radius: 7px;\n"
"  	border-top-left-radius: 7px;\n"
"  	border-bottom-right-radius: 7px;\n"
"  	background: rgb(255, 255, 255);\n"
"  	width: 20px;\n"
"  	subcontrol-position: right;\n"
"  	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::add-line:horizontal:hover {\n"
"  	border: 1px solid;\n"
"  	border-top-right-radius: 7px;\n"
"  	border-top-left-radius: 7px;\n"
"  	border-bottom-right-radius: 7px;\n"
"  	border-color: rgb(255,150,60);\n"
"  	background: rgb(255, 255, 255);\n"
"  	width: 20px;\n"
"  	subcontrol-position: right;\n"
"  	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::add-line:horizontal:pressed {\n"
"  	border: 1px solid grey;\n"
"  	border-top-left-radius: 7px;\n"
"  	border-top-right-radius: 7px;\n"
"  	border-bottom-right-radius: 7px;\n"
"  	background: rgb(231,231,231);\n"
"  	w"
                        "idth: 20px;\n"
"  	subcontrol-position: right;\n"
"  	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:horizontal {\n"
"  	border: 1px solid;\n"
"  	border-color: rgb(207,207,207);\n"
"  	border-top-right-radius: 7px;\n"
"  	border-top-left-radius: 7px;\n"
"  	border-bottom-left-radius: 7px;\n"
"  	background: rgb(255, 255, 255);\n"
"  	width: 20px;\n"
"  	subcontrol-position: left;\n"
"  	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:horizontal:hover {\n"
"  	border: 1px solid;\n"
"  	border-color: rgb(255,150,60);\n"
"  	border-top-right-radius: 7px;\n"
"  	border-top-left-radius: 7px;\n"
"  	border-bottom-left-radius: 7px;\n"
"  	background: rgb(255, 255, 255);\n"
"  	width: 20px;\n"
"  	subcontrol-position: left;\n"
"  	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:horizontal:pressed {\n"
"  	border: 1px solid grey;\n"
"  	border-top-right-radius: 7px;\n"
"  	border-top-left-radius: 7px;\n"
"  	border-bottom-left-radius: 7px;\n"
"  	background: rgb(231,231,231);\n"
"  	widt"
                        "h: 20px;\n"
"  	subcontrol-position: left;\n"
"  	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::left-arrow:horizontal {\n"
"  	border: 1px transparent grey;\n"
"  	border-top-left-radius: 3px;\n"
"  	border-bottom-left-radius: 3px;\n"
"  	width: 6px;\n"
"  	height: 6px;\n"
"  	background: rgb(230,230,230);\n"
"}\n"
"QScrollBar::right-arrow:horizontal {\n"
"	border: 1px transparent grey;\n"
"	border-top-right-radius: 3px;\n"
"	border-bottom-right-radius: 3px;\n"
"  	width: 6px;\n"
"  	height: 6px;\n"
" 	background: rgb(230,230,230);\n"
"}\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {\n"
" 	background: none;\n"
"} \n"
"QScrollBar:vertical {\n"
"	max-width: 20px;\n"
"	border: 1px transparent grey;\n"
"	margin: 20px 0px 20px 0px;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"	border: 1px solid;\n"
"	border-color: rgb(207,207,207);\n"
"	border-bottom-right-radius: 7px;\n"
"	border-bottom-left-radius: 7px;\n"
"	border-top-left-radius: 7px;\n"
"	background: rgb(255, 255, 255);\n"
"  	heigh"
                        "t: 20px;\n"
"  	subcontrol-position: bottom;\n"
"  	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::add-line:vertical:hover {\n"
"  	border: 1px solid;\n"
"  	border-color: rgb(255,150,60);\n"
"  	border-bottom-right-radius: 7px;\n"
"  	border-bottom-left-radius: 7px;\n"
"  	border-top-left-radius: 7px;\n"
"  	background: rgb(255, 255, 255);\n"
"  	height: 20px;\n"
"  	subcontrol-position: bottom;\n"
"  	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::add-line:vertical:pressed {\n"
"  	border: 1px solid grey;\n"
"  	border-bottom-left-radius: 7px;\n"
"  	border-bottom-right-radius: 7px;\n"
"  	border-top-left-radius: 7px;\n"
"  	background: rgb(231,231,231);\n"
"  	height: 20px;\n"
"  	subcontrol-position: bottom;\n"
"  	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"  	border: 1px solid;\n"
"  	border-color: rgb(207,207,207);\n"
"  	border-top-right-radius: 7px;\n"
"  	border-top-left-radius: 7px;\n"
"  	border-bottom-left-radius: 7px;\n"
"  	background: rgb(255, 255, 255);\n"
"  	"
                        "height: 20px;\n"
"  	subcontrol-position: top;\n"
"  	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical:hover {\n"
"  	border: 1px solid;\n"
"  	border-color: rgb(255,150,60);\n"
"  	border-top-right-radius: 7px;\n"
"  	border-top-left-radius: 7px;\n"
"  	border-bottom-left-radius: 7px;\n"
"	background: rgb(255, 255, 255);\n"
"  	height: 20px;\n"
"  	subcontrol-position: top;\n"
"  	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical:pressed {\n"
"  	border: 1px solid grey;\n"
"  	border-top-left-radius: 7px;\n"
"  	border-top-right-radius: 7px;\n"
"  	background: rgb(231,231,231);\n"
" 	height: 20px;\n"
"  	subcontrol-position: top;\n"
"  	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"	background: rgb(253,253,253);\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(207,207,207);\n"
"	border-radius: 7px;\n"
"	min-height: 25px;\n"
"}\n"
"QScrollBar::handle:vertical:hover {\n"
"	background: rgb(253,253,253);\n"
"	border-style: solid;\n"
""
                        "	border-width: 1px;\n"
"	border-color: rgb(255,150,60);\n"
"	border-radius: 7px;\n"
"	min-height: 25px;\n"
"}\n"
"QScrollBar::up-arrow:vertical {\n"
"	border: 1px transparent grey;\n"
"  	border-top-left-radius: 3px;\n"
"	border-top-right-radius: 3px;\n"
"  	width: 6px;\n"
"  	height: 6px;\n"
"  	background: rgb(230,230,230);\n"
"}\n"
"QScrollBar::down-arrow:vertical {\n"
"  	border: 1px transparent grey;\n"
"  	border-bottom-left-radius: 3px;\n"
"  	border-bottom-right-radius: 3px;\n"
"  	width: 6px;\n"
"  	height: 6px;\n"
"  	background: rgb(230,230,230);\n"
"}\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"  	background: none;\n"
"}\n"
"QTabWidget {\n"
"	color:rgb(0,0,0);\n"
"	background-color:rgb(247,246,246);\n"
"}\n"
"QTabWidget::pane {\n"
"	border-color: rgb(180,180,180);\n"
"	background-color:rgb(247,246,246);\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"  	border-radius: 6px;\n"
"}\n"
"QTabBar::tab {\n"
"	padding-left:4px;\n"
"	padding-right:4px;\n"
"	padding-bottom:2p"
                        "x;\n"
"	padding-top:2px;\n"
"	color:rgb(81,72,65);\n"
"  	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(221,218,217,255), stop:1 rgba(240,239,238,255));\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"  	border-top-right-radius:4px;\n"
"	border-top-left-radius:4px;\n"
"	border-top-color: rgb(180,180,180);\n"
"	border-left-color: rgb(180,180,180);\n"
"	border-right-color: rgb(180,180,180);\n"
"	border-bottom-color: transparent;\n"
"}\n"
"QTabBar::tab:selected, QTabBar::tab:last:selected, QTabBar::tab:hover {\n"
"  	background-color:rgb(247,246,246);\n"
"  	margin-left: 0px;\n"
"  	margin-right: 1px;\n"
"}\n"
"QTabBar::tab:!selected {\n"
"	margin-top: 1px;\n"
"	margin-right: 1px;\n"
"}\n"
"QTextEdit {\n"
"	border-width: 1px;\n"
"	border-style: solid;\n"
"	border-color:transparent;\n"
"	color:rgb(17,17,17);\n"
"	selection-background-color:rgb(236,116,64);\n"
"}\n"
"QTimeEdit {\n"
"	color:rgb(81,72,65);\n"
"	background-color: #ffffff;\n"
"}\n"
"QToolBox {\n"
"	color:rg"
                        "b(81,72,65);\n"
"	background-color: #ffffff;\n"
"}\n"
"QToolBox::tab {\n"
"	color:rgb(81,72,65);\n"
"	background-color: #ffffff;\n"
"}\n"
"QToolBox::tab:selected {\n"
"	color:rgb(81,72,65);\n"
"	background-color: #ffffff;\n"
"}"));
        stackedWidget = new QStackedWidget(journaliste_mission);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 10, 831, 391));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gestion_journaliste = new QPushButton(page);
        gestion_journaliste->setObjectName(QString::fromUtf8("gestion_journaliste"));
        gestion_journaliste->setGeometry(QRect(50, 150, 331, 71));
        gestion_journaliste->setStyleSheet(QString::fromUtf8("font: 75 22pt \"Roboto\";"));
        gestion_des_mission = new QPushButton(page);
        gestion_des_mission->setObjectName(QString::fromUtf8("gestion_des_mission"));
        gestion_des_mission->setGeometry(QRect(430, 150, 331, 71));
        gestion_des_mission->setStyleSheet(QString::fromUtf8("font: 75 22pt \"Roboto\";"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 360, 47, 13));
        animation = new QLabel(page);
        animation->setObjectName(QString::fromUtf8("animation"));
        animation->setGeometry(QRect(260, -70, 301, 231));
        animation->setPixmap(QPixmap(QString::fromUtf8(":/sq-01.png")));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        tabWidget = new QTabWidget(page_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 831, 401));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        pb_ajouter_2 = new QPushButton(tab_4);
        pb_ajouter_2->setObjectName(QString::fromUtf8("pb_ajouter_2"));
        pb_ajouter_2->setGeometry(QRect(340, 270, 181, 34));
        pb_ajouter_2->setStyleSheet(QString::fromUtf8("#upLeft\342\200\213 {\n"
"background-color: transparent;\n"
"border-image: url(:off.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        horizontalLayoutWidget_8 = new QWidget(tab_4);
        horizontalLayoutWidget_8->setObjectName(QString::fromUtf8("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(70, 60, 651, 211));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_9 = new QLabel(horizontalLayoutWidget_8);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        verticalLayout_5->addWidget(label_9);

        label_10 = new QLabel(horizontalLayoutWidget_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_5->addWidget(label_10);

        label_11 = new QLabel(horizontalLayoutWidget_8);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_5->addWidget(label_11);

        label_12 = new QLabel(horizontalLayoutWidget_8);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_5->addWidget(label_12);

        label_13 = new QLabel(horizontalLayoutWidget_8);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_5->addWidget(label_13);


        horizontalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        id = new QLineEdit(horizontalLayoutWidget_8);
        id->setObjectName(QString::fromUtf8("id"));

        verticalLayout_6->addWidget(id);

        le_nom_2 = new QLineEdit(horizontalLayoutWidget_8);
        le_nom_2->setObjectName(QString::fromUtf8("le_nom_2"));

        verticalLayout_6->addWidget(le_nom_2);

        le_prenom_2 = new QLineEdit(horizontalLayoutWidget_8);
        le_prenom_2->setObjectName(QString::fromUtf8("le_prenom_2"));

        verticalLayout_6->addWidget(le_prenom_2);

        le_fonction_2 = new QLineEdit(horizontalLayoutWidget_8);
        le_fonction_2->setObjectName(QString::fromUtf8("le_fonction_2"));

        verticalLayout_6->addWidget(le_fonction_2);

        le_diplome_2 = new QLineEdit(horizontalLayoutWidget_8);
        le_diplome_2->setObjectName(QString::fromUtf8("le_diplome_2"));

        verticalLayout_6->addWidget(le_diplome_2);


        horizontalLayout_6->addLayout(verticalLayout_6);

        return_3 = new QPushButton(tab_4);
        return_3->setObjectName(QString::fromUtf8("return_3"));
        return_3->setGeometry(QRect(720, 330, 75, 23));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        horizontalLayoutWidget_9 = new QWidget(tab_5);
        horizontalLayoutWidget_9->setObjectName(QString::fromUtf8("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(10, 270, 371, 81));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(horizontalLayoutWidget_9);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        label_21->setFont(font);
        label_21->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_9->addWidget(label_21);

        id_rechercher_2 = new QLineEdit(horizontalLayoutWidget_9);
        id_rechercher_2->setObjectName(QString::fromUtf8("id_rechercher_2"));

        horizontalLayout_9->addWidget(id_rechercher_2);

        recherchep_2 = new QPushButton(horizontalLayoutWidget_9);
        recherchep_2->setObjectName(QString::fromUtf8("recherchep_2"));
        recherchep_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_9->addWidget(recherchep_2);

        horizontalLayoutWidget_10 = new QWidget(tab_5);
        horizontalLayoutWidget_10->setObjectName(QString::fromUtf8("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(10, 50, 401, 211));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        tab_journaliste_2 = new QTableView(horizontalLayoutWidget_10);
        tab_journaliste_2->setObjectName(QString::fromUtf8("tab_journaliste_2"));

        horizontalLayout_10->addWidget(tab_journaliste_2);

        horizontalLayoutWidget_11 = new QWidget(tab_5);
        horizontalLayoutWidget_11->setObjectName(QString::fromUtf8("horizontalLayoutWidget_11"));
        horizontalLayoutWidget_11->setGeometry(QRect(10, 10, 401, 36));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget_11);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("font: 12pt \"Roboto\";"));

        horizontalLayout_11->addWidget(label_14);

        pdf_p_2 = new QPushButton(horizontalLayoutWidget_11);
        pdf_p_2->setObjectName(QString::fromUtf8("pdf_p_2"));
        pdf_p_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_11->addWidget(pdf_p_2);

        tri_p_2 = new QPushButton(horizontalLayoutWidget_11);
        tri_p_2->setObjectName(QString::fromUtf8("tri_p_2"));
        tri_p_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_11->addWidget(tri_p_2);

        trieprenom = new QPushButton(horizontalLayoutWidget_11);
        trieprenom->setObjectName(QString::fromUtf8("trieprenom"));

        horizontalLayout_11->addWidget(trieprenom);

        horizontalLayoutWidget_12 = new QWidget(tab_5);
        horizontalLayoutWidget_12->setObjectName(QString::fromUtf8("horizontalLayoutWidget_12"));
        horizontalLayoutWidget_12->setGeometry(QRect(460, 50, 341, 221));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget_12);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_27 = new QLabel(horizontalLayoutWidget_12);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        verticalLayout_10->addWidget(label_27);

        label_28 = new QLabel(horizontalLayoutWidget_12);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        verticalLayout_10->addWidget(label_28);

        label_29 = new QLabel(horizontalLayoutWidget_12);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        verticalLayout_10->addWidget(label_29);

        label_30 = new QLabel(horizontalLayoutWidget_12);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        verticalLayout_10->addWidget(label_30);

        label_31 = new QLabel(horizontalLayoutWidget_12);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        verticalLayout_10->addWidget(label_31);


        horizontalLayout_12->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        le_id_6 = new QLineEdit(horizontalLayoutWidget_12);
        le_id_6->setObjectName(QString::fromUtf8("le_id_6"));

        verticalLayout_11->addWidget(le_id_6);

        le_nom_5 = new QLineEdit(horizontalLayoutWidget_12);
        le_nom_5->setObjectName(QString::fromUtf8("le_nom_5"));

        verticalLayout_11->addWidget(le_nom_5);

        le_prenom_5 = new QLineEdit(horizontalLayoutWidget_12);
        le_prenom_5->setObjectName(QString::fromUtf8("le_prenom_5"));

        verticalLayout_11->addWidget(le_prenom_5);

        le_fonction_4 = new QLineEdit(horizontalLayoutWidget_12);
        le_fonction_4->setObjectName(QString::fromUtf8("le_fonction_4"));

        verticalLayout_11->addWidget(le_fonction_4);

        le_diplome_4 = new QLineEdit(horizontalLayoutWidget_12);
        le_diplome_4->setObjectName(QString::fromUtf8("le_diplome_4"));

        verticalLayout_11->addWidget(le_diplome_4);


        horizontalLayout_12->addLayout(verticalLayout_11);

        recherche_tab_2 = new QTableView(tab_5);
        recherche_tab_2->setObjectName(QString::fromUtf8("recherche_tab_2"));
        recherche_tab_2->setGeometry(QRect(390, 270, 411, 79));
        horizontalLayoutWidget_13 = new QWidget(tab_5);
        horizontalLayoutWidget_13->setObjectName(QString::fromUtf8("horizontalLayoutWidget_13"));
        horizontalLayoutWidget_13->setGeometry(QRect(460, 10, 341, 36));
        horizontalLayout_13 = new QHBoxLayout(horizontalLayoutWidget_13);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        afficherp_2 = new QPushButton(horizontalLayoutWidget_13);
        afficherp_2->setObjectName(QString::fromUtf8("afficherp_2"));
        afficherp_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_13->addWidget(afficherp_2);

        modifierp_2 = new QPushButton(horizontalLayoutWidget_13);
        modifierp_2->setObjectName(QString::fromUtf8("modifierp_2"));
        modifierp_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_13->addWidget(modifierp_2);

        supprimer_2 = new QPushButton(horizontalLayoutWidget_13);
        supprimer_2->setObjectName(QString::fromUtf8("supprimer_2"));
        supprimer_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_13->addWidget(supprimer_2);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        horizontalLayoutWidget_14 = new QWidget(tab_6);
        horizontalLayoutWidget_14->setObjectName(QString::fromUtf8("horizontalLayoutWidget_14"));
        horizontalLayoutWidget_14->setGeometry(QRect(100, 110, 631, 121));
        horizontalLayout_14 = new QHBoxLayout(horizontalLayoutWidget_14);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_15 = new QLabel(horizontalLayoutWidget_14);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_7->addWidget(label_15);

        label_16 = new QLabel(horizontalLayoutWidget_14);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_7->addWidget(label_16);

        label_32 = new QLabel(horizontalLayoutWidget_14);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        verticalLayout_7->addWidget(label_32);


        horizontalLayout_14->addLayout(verticalLayout_7);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        mail_2 = new QLineEdit(horizontalLayoutWidget_14);
        mail_2->setObjectName(QString::fromUtf8("mail_2"));

        verticalLayout_12->addWidget(mail_2);

        objet_2 = new QLineEdit(horizontalLayoutWidget_14);
        objet_2->setObjectName(QString::fromUtf8("objet_2"));

        verticalLayout_12->addWidget(objet_2);

        contenu_2 = new QLineEdit(horizontalLayoutWidget_14);
        contenu_2->setObjectName(QString::fromUtf8("contenu_2"));

        verticalLayout_12->addWidget(contenu_2);


        horizontalLayout_14->addLayout(verticalLayout_12);

        envoyer = new QPushButton(tab_6);
        envoyer->setObjectName(QString::fromUtf8("envoyer"));
        envoyer->setGeometry(QRect(360, 240, 161, 34));
        tabWidget->addTab(tab_6, QString());
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        tabWidget_2 = new QTabWidget(page_3);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 821, 421));
        tabWidget_2->setLayoutDirection(Qt::LeftToRight);
        tabWidget_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        pb_ajouter_3 = new QPushButton(tab_7);
        pb_ajouter_3->setObjectName(QString::fromUtf8("pb_ajouter_3"));
        pb_ajouter_3->setGeometry(QRect(340, 260, 181, 34));
        pb_ajouter_3->setStyleSheet(QString::fromUtf8("#upLeft\342\200\213 {\n"
"background-color: transparent;\n"
"border-image: url(:off.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        horizontalLayoutWidget_15 = new QWidget(tab_7);
        horizontalLayoutWidget_15->setObjectName(QString::fromUtf8("horizontalLayoutWidget_15"));
        horizontalLayoutWidget_15->setGeometry(QRect(60, 100, 651, 151));
        horizontalLayout_15 = new QHBoxLayout(horizontalLayoutWidget_15);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        label_17 = new QLabel(horizontalLayoutWidget_15);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        verticalLayout_13->addWidget(label_17);

        label_18 = new QLabel(horizontalLayoutWidget_15);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_13->addWidget(label_18);

        label_33 = new QLabel(horizontalLayoutWidget_15);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        verticalLayout_13->addWidget(label_33);

        label_34 = new QLabel(horizontalLayoutWidget_15);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        verticalLayout_13->addWidget(label_34);


        horizontalLayout_15->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        id_mission = new QLineEdit(horizontalLayoutWidget_15);
        id_mission->setObjectName(QString::fromUtf8("id_mission"));

        verticalLayout_14->addWidget(id_mission);

        libelle = new QLineEdit(horizontalLayoutWidget_15);
        libelle->setObjectName(QString::fromUtf8("libelle"));

        verticalLayout_14->addWidget(libelle);

        description = new QLineEdit(horizontalLayoutWidget_15);
        description->setObjectName(QString::fromUtf8("description"));

        verticalLayout_14->addWidget(description);

        confidentialite = new QLineEdit(horizontalLayoutWidget_15);
        confidentialite->setObjectName(QString::fromUtf8("confidentialite"));

        verticalLayout_14->addWidget(confidentialite);


        horizontalLayout_15->addLayout(verticalLayout_14);

        return_4 = new QPushButton(tab_7);
        return_4->setObjectName(QString::fromUtf8("return_4"));
        return_4->setGeometry(QRect(720, 330, 75, 23));
        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        horizontalLayoutWidget_16 = new QWidget(tab_8);
        horizontalLayoutWidget_16->setObjectName(QString::fromUtf8("horizontalLayoutWidget_16"));
        horizontalLayoutWidget_16->setGeometry(QRect(10, 270, 261, 81));
        horizontalLayout_16 = new QHBoxLayout(horizontalLayoutWidget_16);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_35 = new QLabel(horizontalLayoutWidget_16);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setFont(font);
        label_35->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_16->addWidget(label_35);

        id_rechercher_3 = new QLineEdit(horizontalLayoutWidget_16);
        id_rechercher_3->setObjectName(QString::fromUtf8("id_rechercher_3"));

        horizontalLayout_16->addWidget(id_rechercher_3);

        recherchep_3 = new QPushButton(horizontalLayoutWidget_16);
        recherchep_3->setObjectName(QString::fromUtf8("recherchep_3"));
        recherchep_3->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_16->addWidget(recherchep_3);

        horizontalLayoutWidget_17 = new QWidget(tab_8);
        horizontalLayoutWidget_17->setObjectName(QString::fromUtf8("horizontalLayoutWidget_17"));
        horizontalLayoutWidget_17->setGeometry(QRect(10, 50, 391, 211));
        horizontalLayout_17 = new QHBoxLayout(horizontalLayoutWidget_17);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        tab_journaliste_3 = new QTableView(horizontalLayoutWidget_17);
        tab_journaliste_3->setObjectName(QString::fromUtf8("tab_journaliste_3"));

        horizontalLayout_17->addWidget(tab_journaliste_3);

        horizontalLayoutWidget_18 = new QWidget(tab_8);
        horizontalLayoutWidget_18->setObjectName(QString::fromUtf8("horizontalLayoutWidget_18"));
        horizontalLayoutWidget_18->setGeometry(QRect(10, 10, 391, 36));
        horizontalLayout_18 = new QHBoxLayout(horizontalLayoutWidget_18);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        label_36 = new QLabel(horizontalLayoutWidget_18);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setFont(font1);
        label_36->setStyleSheet(QString::fromUtf8("font: 12pt \"Roboto\";"));

        horizontalLayout_18->addWidget(label_36);

        pdf_p_3 = new QPushButton(horizontalLayoutWidget_18);
        pdf_p_3->setObjectName(QString::fromUtf8("pdf_p_3"));
        pdf_p_3->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_18->addWidget(pdf_p_3);

        tri_p_3 = new QPushButton(horizontalLayoutWidget_18);
        tri_p_3->setObjectName(QString::fromUtf8("tri_p_3"));
        tri_p_3->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_18->addWidget(tri_p_3);

        recherche_tab_3 = new QTableView(tab_8);
        recherche_tab_3->setObjectName(QString::fromUtf8("recherche_tab_3"));
        recherche_tab_3->setGeometry(QRect(280, 270, 511, 79));
        horizontalLayoutWidget_19 = new QWidget(tab_8);
        horizontalLayoutWidget_19->setObjectName(QString::fromUtf8("horizontalLayoutWidget_19"));
        horizontalLayoutWidget_19->setGeometry(QRect(410, 90, 381, 131));
        horizontalLayout_19 = new QHBoxLayout(horizontalLayoutWidget_19);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        label_37 = new QLabel(horizontalLayoutWidget_19);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        verticalLayout_15->addWidget(label_37);

        label_38 = new QLabel(horizontalLayoutWidget_19);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        verticalLayout_15->addWidget(label_38);

        label_39 = new QLabel(horizontalLayoutWidget_19);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        verticalLayout_15->addWidget(label_39);

        label_40 = new QLabel(horizontalLayoutWidget_19);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        verticalLayout_15->addWidget(label_40);


        horizontalLayout_19->addLayout(verticalLayout_15);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        id_miss_mod = new QLineEdit(horizontalLayoutWidget_19);
        id_miss_mod->setObjectName(QString::fromUtf8("id_miss_mod"));

        verticalLayout_16->addWidget(id_miss_mod);

        libelle_miss_mod = new QLineEdit(horizontalLayoutWidget_19);
        libelle_miss_mod->setObjectName(QString::fromUtf8("libelle_miss_mod"));

        verticalLayout_16->addWidget(libelle_miss_mod);

        description_mod = new QLineEdit(horizontalLayoutWidget_19);
        description_mod->setObjectName(QString::fromUtf8("description_mod"));

        verticalLayout_16->addWidget(description_mod);

        confidentialite_mod = new QLineEdit(horizontalLayoutWidget_19);
        confidentialite_mod->setObjectName(QString::fromUtf8("confidentialite_mod"));

        verticalLayout_16->addWidget(confidentialite_mod);


        horizontalLayout_19->addLayout(verticalLayout_16);

        horizontalLayoutWidget_20 = new QWidget(tab_8);
        horizontalLayoutWidget_20->setObjectName(QString::fromUtf8("horizontalLayoutWidget_20"));
        horizontalLayoutWidget_20->setGeometry(QRect(520, -10, 271, 80));
        horizontalLayout_20 = new QHBoxLayout(horizontalLayoutWidget_20);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(0, 0, 0, 0);
        afficherp_3 = new QPushButton(horizontalLayoutWidget_20);
        afficherp_3->setObjectName(QString::fromUtf8("afficherp_3"));
        afficherp_3->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_20->addWidget(afficherp_3);

        modifierp_3 = new QPushButton(horizontalLayoutWidget_20);
        modifierp_3->setObjectName(QString::fromUtf8("modifierp_3"));
        modifierp_3->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_20->addWidget(modifierp_3);

        supprimer_3 = new QPushButton(horizontalLayoutWidget_20);
        supprimer_3->setObjectName(QString::fromUtf8("supprimer_3"));
        supprimer_3->setStyleSheet(QString::fromUtf8("font: 10pt \"Roboto\";"));

        horizontalLayout_20->addWidget(supprimer_3);

        tabWidget_2->addTab(tab_8, QString());
        stackedWidget->addWidget(page_3);

        retranslateUi(journaliste_mission);

        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(journaliste_mission);
    } // setupUi

    void retranslateUi(QDialog *journaliste_mission)
    {
        journaliste_mission->setWindowTitle(QCoreApplication::translate("journaliste_mission", "Dialog", nullptr));
        gestion_journaliste->setText(QCoreApplication::translate("journaliste_mission", "Gestion Des journaliste", nullptr));
        gestion_des_mission->setText(QCoreApplication::translate("journaliste_mission", "Gestion des missions", nullptr));
        label->setText(QString());
#if QT_CONFIG(whatsthis)
        animation->setWhatsThis(QCoreApplication::translate("journaliste_mission", "<html><head/><body><p><span style=\" font-size:16pt; font-style:italic;\"><br/>gestion des journalistes <br> et missions</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        animation->setText(QCoreApplication::translate("journaliste_mission", "<html><head/><body><p><img src=\":/sq-01.png\"/></p></body></html>", nullptr));
        pb_ajouter_2->setText(QCoreApplication::translate("journaliste_mission", "ajouter", nullptr));
        label_9->setText(QCoreApplication::translate("journaliste_mission", "id journaliste:", nullptr));
        label_10->setText(QCoreApplication::translate("journaliste_mission", "nom :", nullptr));
        label_11->setText(QCoreApplication::translate("journaliste_mission", "prenom :", nullptr));
        label_12->setText(QCoreApplication::translate("journaliste_mission", "fonction :", nullptr));
        label_13->setText(QCoreApplication::translate("journaliste_mission", "diplome :", nullptr));
        return_3->setText(QCoreApplication::translate("journaliste_mission", "retourne", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("journaliste_mission", "ajouter", nullptr));
        label_21->setText(QCoreApplication::translate("journaliste_mission", "recherche", nullptr));
        recherchep_2->setText(QCoreApplication::translate("journaliste_mission", "recherche", nullptr));
        label_14->setText(QCoreApplication::translate("journaliste_mission", "Affichage des journalistes", nullptr));
        pdf_p_2->setText(QCoreApplication::translate("journaliste_mission", "pdf", nullptr));
        tri_p_2->setText(QCoreApplication::translate("journaliste_mission", "trie par nom", nullptr));
        trieprenom->setText(QCoreApplication::translate("journaliste_mission", "trie  prenom", nullptr));
        label_27->setText(QCoreApplication::translate("journaliste_mission", "id journaliste:", nullptr));
        label_28->setText(QCoreApplication::translate("journaliste_mission", "nom :", nullptr));
        label_29->setText(QCoreApplication::translate("journaliste_mission", "prenom:", nullptr));
        label_30->setText(QCoreApplication::translate("journaliste_mission", "fonction:", nullptr));
        label_31->setText(QCoreApplication::translate("journaliste_mission", "diplome :", nullptr));
        afficherp_2->setText(QCoreApplication::translate("journaliste_mission", "afficher", nullptr));
        modifierp_2->setText(QCoreApplication::translate("journaliste_mission", "modifer", nullptr));
        supprimer_2->setText(QCoreApplication::translate("journaliste_mission", "supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("journaliste_mission", "Gestion des journalistes", nullptr));
        label_15->setText(QCoreApplication::translate("journaliste_mission", "Mail", nullptr));
        label_16->setText(QCoreApplication::translate("journaliste_mission", "objet", nullptr));
        label_32->setText(QCoreApplication::translate("journaliste_mission", "Contenu", nullptr));
        envoyer->setText(QCoreApplication::translate("journaliste_mission", "envoyer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("journaliste_mission", "Mailling", nullptr));
        pb_ajouter_3->setText(QCoreApplication::translate("journaliste_mission", "ajouter", nullptr));
        label_17->setText(QCoreApplication::translate("journaliste_mission", "id mission", nullptr));
        label_18->setText(QCoreApplication::translate("journaliste_mission", "libelle mission", nullptr));
        label_33->setText(QCoreApplication::translate("journaliste_mission", "description mission", nullptr));
        label_34->setText(QCoreApplication::translate("journaliste_mission", "confidentialite", nullptr));
        return_4->setText(QCoreApplication::translate("journaliste_mission", "retourne", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("journaliste_mission", "ajouter", nullptr));
        label_35->setText(QCoreApplication::translate("journaliste_mission", "recherche", nullptr));
        recherchep_3->setText(QCoreApplication::translate("journaliste_mission", "recherche", nullptr));
        label_36->setText(QCoreApplication::translate("journaliste_mission", "Affichage des mission", nullptr));
        pdf_p_3->setText(QCoreApplication::translate("journaliste_mission", "pdf", nullptr));
        tri_p_3->setText(QCoreApplication::translate("journaliste_mission", "tri", nullptr));
        label_37->setText(QCoreApplication::translate("journaliste_mission", "id mission", nullptr));
        label_38->setText(QCoreApplication::translate("journaliste_mission", "libelle mission", nullptr));
        label_39->setText(QCoreApplication::translate("journaliste_mission", "description mission", nullptr));
        label_40->setText(QCoreApplication::translate("journaliste_mission", "confidentialite", nullptr));
        afficherp_3->setText(QCoreApplication::translate("journaliste_mission", "afficher", nullptr));
        modifierp_3->setText(QCoreApplication::translate("journaliste_mission", "modifer", nullptr));
        supprimer_3->setText(QCoreApplication::translate("journaliste_mission", "supprimer", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QCoreApplication::translate("journaliste_mission", "Gestion des missions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class journaliste_mission: public Ui_journaliste_mission {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNALISTE_MISSION_H
