/********************************************************************************
** Form generated from reading UI file 'journaliste_mission.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNALISTE_MISSION_H
#define UI_JOURNALISTE_MISSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
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
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_10;
    QTableView *tab_journaliste_2;
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
    QPushButton *recherchep_2;
    QPushButton *trieprenom;
    QPushButton *tri_p_2;
    QPushButton *pdf_p_2;
    QPushButton *afficherp_2;
    QPushButton *modifierp_2;
    QPushButton *supprimer_2;
    QWidget *tab_6;
    QFrame *statv;
    QVBoxLayout *verticalLayout;
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
    QWidget *horizontalLayoutWidget_17;
    QHBoxLayout *horizontalLayout_17;
    QTableView *tab_journaliste_3;
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
    QPushButton *pdf_p_3;
    QPushButton *tri_p_3;
    QLabel *label_36;
    QPushButton *afficherp_3;
    QPushButton *modifierp_3;
    QPushButton *supprimer_3;
    QPushButton *recherchep_3;

    void setupUi(QDialog *journaliste_mission)
    {
        if (journaliste_mission->objectName().isEmpty())
            journaliste_mission->setObjectName(QStringLiteral("journaliste_mission"));
        journaliste_mission->resize(831, 421);
        journaliste_mission->setStyleSheet(QStringLiteral(""));
        stackedWidget = new QStackedWidget(journaliste_mission);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 10, 841, 401));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setStyleSheet(QStringLiteral(""));
        gestion_journaliste = new QPushButton(page);
        gestion_journaliste->setObjectName(QStringLiteral("gestion_journaliste"));
        gestion_journaliste->setGeometry(QRect(50, 150, 331, 71));
        gestion_journaliste->setStyleSheet(QLatin1String("font: 75 22pt \"Roboto\";\n"
"border-image: url(:/xxx.png);\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
""));
        gestion_des_mission = new QPushButton(page);
        gestion_des_mission->setObjectName(QStringLiteral("gestion_des_mission"));
        gestion_des_mission->setGeometry(QRect(430, 150, 331, 71));
        gestion_des_mission->setStyleSheet(QLatin1String("font: 75 22pt \"Roboto\";\n"
"\n"
"border-image: url(:/gesmiss.png);\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
""));
        animation = new QLabel(page);
        animation->setObjectName(QStringLiteral("animation"));
        animation->setGeometry(QRect(330, 30, 171, 101));
        animation->setPixmap(QPixmap(QString::fromUtf8("../cccc-01.png")));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        tabWidget = new QTabWidget(page_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 831, 401));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setStyleSheet(QLatin1String("font: 10pt \"Roboto\";\n"
"border-image: url(:/click.mp3);"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        pb_ajouter_2 = new QPushButton(tab_4);
        pb_ajouter_2->setObjectName(QStringLiteral("pb_ajouter_2"));
        pb_ajouter_2->setGeometry(QRect(340, 280, 181, 34));
        pb_ajouter_2->setStyleSheet(QLatin1String("border-image: url(:/add.png);\n"
"\n"
"\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;"));
        horizontalLayoutWidget_8 = new QWidget(tab_4);
        horizontalLayoutWidget_8->setObjectName(QStringLiteral("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(70, 60, 651, 211));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_9 = new QLabel(horizontalLayoutWidget_8);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QStringLiteral("font: 10pt \"Roboto\";"));

        verticalLayout_5->addWidget(label_9);

        label_10 = new QLabel(horizontalLayoutWidget_8);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_5->addWidget(label_10);

        label_11 = new QLabel(horizontalLayoutWidget_8);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_5->addWidget(label_11);

        label_12 = new QLabel(horizontalLayoutWidget_8);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_5->addWidget(label_12);

        label_13 = new QLabel(horizontalLayoutWidget_8);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_5->addWidget(label_13);


        horizontalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        id = new QLineEdit(horizontalLayoutWidget_8);
        id->setObjectName(QStringLiteral("id"));

        verticalLayout_6->addWidget(id);

        le_nom_2 = new QLineEdit(horizontalLayoutWidget_8);
        le_nom_2->setObjectName(QStringLiteral("le_nom_2"));

        verticalLayout_6->addWidget(le_nom_2);

        le_prenom_2 = new QLineEdit(horizontalLayoutWidget_8);
        le_prenom_2->setObjectName(QStringLiteral("le_prenom_2"));

        verticalLayout_6->addWidget(le_prenom_2);

        le_fonction_2 = new QLineEdit(horizontalLayoutWidget_8);
        le_fonction_2->setObjectName(QStringLiteral("le_fonction_2"));

        verticalLayout_6->addWidget(le_fonction_2);

        le_diplome_2 = new QLineEdit(horizontalLayoutWidget_8);
        le_diplome_2->setObjectName(QStringLiteral("le_diplome_2"));

        verticalLayout_6->addWidget(le_diplome_2);


        horizontalLayout_6->addLayout(verticalLayout_6);

        return_3 = new QPushButton(tab_4);
        return_3->setObjectName(QStringLiteral("return_3"));
        return_3->setGeometry(QRect(704, 330, 91, 23));
        return_3->setStyleSheet(QLatin1String("border-image: url(:/return.png);\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        horizontalLayoutWidget_9 = new QWidget(tab_5);
        horizontalLayoutWidget_9->setObjectName(QStringLiteral("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(10, 270, 221, 81));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(horizontalLayoutWidget_9);
        label_21->setObjectName(QStringLiteral("label_21"));
        QFont font;
        font.setFamily(QStringLiteral("Roboto"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_21->setFont(font);
        label_21->setStyleSheet(QStringLiteral("font: 10pt \"Roboto\";"));

        horizontalLayout_9->addWidget(label_21);

        id_rechercher_2 = new QLineEdit(horizontalLayoutWidget_9);
        id_rechercher_2->setObjectName(QStringLiteral("id_rechercher_2"));

        horizontalLayout_9->addWidget(id_rechercher_2);

        horizontalLayoutWidget_10 = new QWidget(tab_5);
        horizontalLayoutWidget_10->setObjectName(QStringLiteral("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(10, 50, 401, 211));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        tab_journaliste_2 = new QTableView(horizontalLayoutWidget_10);
        tab_journaliste_2->setObjectName(QStringLiteral("tab_journaliste_2"));

        horizontalLayout_10->addWidget(tab_journaliste_2);

        horizontalLayoutWidget_12 = new QWidget(tab_5);
        horizontalLayoutWidget_12->setObjectName(QStringLiteral("horizontalLayoutWidget_12"));
        horizontalLayoutWidget_12->setGeometry(QRect(460, 50, 341, 221));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget_12);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_27 = new QLabel(horizontalLayoutWidget_12);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setStyleSheet(QStringLiteral("font: 10pt \"Roboto\";"));

        verticalLayout_10->addWidget(label_27);

        label_28 = new QLabel(horizontalLayoutWidget_12);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setStyleSheet(QStringLiteral("font: 10pt \"Roboto\";"));

        verticalLayout_10->addWidget(label_28);

        label_29 = new QLabel(horizontalLayoutWidget_12);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setStyleSheet(QStringLiteral("font: 10pt \"Roboto\";"));

        verticalLayout_10->addWidget(label_29);

        label_30 = new QLabel(horizontalLayoutWidget_12);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setStyleSheet(QStringLiteral("font: 10pt \"Roboto\";"));

        verticalLayout_10->addWidget(label_30);

        label_31 = new QLabel(horizontalLayoutWidget_12);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setStyleSheet(QStringLiteral("font: 10pt \"Roboto\";"));

        verticalLayout_10->addWidget(label_31);


        horizontalLayout_12->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        le_id_6 = new QLineEdit(horizontalLayoutWidget_12);
        le_id_6->setObjectName(QStringLiteral("le_id_6"));

        verticalLayout_11->addWidget(le_id_6);

        le_nom_5 = new QLineEdit(horizontalLayoutWidget_12);
        le_nom_5->setObjectName(QStringLiteral("le_nom_5"));

        verticalLayout_11->addWidget(le_nom_5);

        le_prenom_5 = new QLineEdit(horizontalLayoutWidget_12);
        le_prenom_5->setObjectName(QStringLiteral("le_prenom_5"));

        verticalLayout_11->addWidget(le_prenom_5);

        le_fonction_4 = new QLineEdit(horizontalLayoutWidget_12);
        le_fonction_4->setObjectName(QStringLiteral("le_fonction_4"));

        verticalLayout_11->addWidget(le_fonction_4);

        le_diplome_4 = new QLineEdit(horizontalLayoutWidget_12);
        le_diplome_4->setObjectName(QStringLiteral("le_diplome_4"));

        verticalLayout_11->addWidget(le_diplome_4);


        horizontalLayout_12->addLayout(verticalLayout_11);

        recherche_tab_2 = new QTableView(tab_5);
        recherche_tab_2->setObjectName(QStringLiteral("recherche_tab_2"));
        recherche_tab_2->setGeometry(QRect(390, 270, 411, 79));
        recherchep_2 = new QPushButton(tab_5);
        recherchep_2->setObjectName(QStringLiteral("recherchep_2"));
        recherchep_2->setGeometry(QRect(250, 301, 81, 20));
        recherchep_2->setStyleSheet(QLatin1String("font: 10pt \"Roboto\";\n"
"\n"
"border-image: url(:/recherche.png);\n"
"\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;"));
        trieprenom = new QPushButton(tab_5);
        trieprenom->setObjectName(QStringLiteral("trieprenom"));
        trieprenom->setGeometry(QRect(100, 20, 81, 21));
        trieprenom->setStyleSheet(QLatin1String("\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"border-image: url(:/prenom.png);"));
        tri_p_2 = new QPushButton(tab_5);
        tri_p_2->setObjectName(QStringLiteral("tri_p_2"));
        tri_p_2->setGeometry(QRect(190, 21, 81, 20));
        tri_p_2->setStyleSheet(QLatin1String("\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"border-image: url(:/nom.png);"));
        pdf_p_2 = new QPushButton(tab_5);
        pdf_p_2->setObjectName(QStringLiteral("pdf_p_2"));
        pdf_p_2->setGeometry(QRect(10, 20, 81, 21));
        pdf_p_2->setStyleSheet(QLatin1String("border-image: url(:/pdf.png);\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;"));
        afficherp_2 = new QPushButton(tab_5);
        afficherp_2->setObjectName(QStringLiteral("afficherp_2"));
        afficherp_2->setGeometry(QRect(460, 20, 111, 21));
        afficherp_2->setStyleSheet(QLatin1String("font: 10pt \"Roboto\";\n"
"border-image: url(:/afficher.png);\n"
"\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;"));
        modifierp_2 = new QPushButton(tab_5);
        modifierp_2->setObjectName(QStringLiteral("modifierp_2"));
        modifierp_2->setGeometry(QRect(580, 20, 111, 21));
        modifierp_2->setStyleSheet(QLatin1String("font: 10pt \"Roboto\";\n"
"background-color: transparent;\n"
"border-image: url(:/modifier.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;"));
        supprimer_2 = new QPushButton(tab_5);
        supprimer_2->setObjectName(QStringLiteral("supprimer_2"));
        supprimer_2->setGeometry(QRect(700, 20, 111, 21));
        supprimer_2->setStyleSheet(QLatin1String("font: 10pt \"Roboto\";\n"
"border-image: url(:/delete.png);\n"
"\n"
"\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        statv = new QFrame(tab_6);
        statv->setObjectName(QStringLiteral("statv"));
        statv->setGeometry(QRect(100, 40, 561, 281));
        verticalLayout = new QVBoxLayout(statv);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget->addTab(tab_6, QString());
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        tabWidget_2 = new QTabWidget(page_3);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 821, 421));
        tabWidget_2->setLayoutDirection(Qt::LeftToRight);
        tabWidget_2->setStyleSheet(QStringLiteral("font: 10pt \"Roboto\";"));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        pb_ajouter_3 = new QPushButton(tab_7);
        pb_ajouter_3->setObjectName(QStringLiteral("pb_ajouter_3"));
        pb_ajouter_3->setGeometry(QRect(340, 260, 181, 34));
        pb_ajouter_3->setStyleSheet(QLatin1String("\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"border-image: url(:/add.png);"));
        horizontalLayoutWidget_15 = new QWidget(tab_7);
        horizontalLayoutWidget_15->setObjectName(QStringLiteral("horizontalLayoutWidget_15"));
        horizontalLayoutWidget_15->setGeometry(QRect(60, 100, 651, 151));
        horizontalLayout_15 = new QHBoxLayout(horizontalLayoutWidget_15);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        label_17 = new QLabel(horizontalLayoutWidget_15);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setStyleSheet(QStringLiteral("font: 10pt \"Roboto\";"));

        verticalLayout_13->addWidget(label_17);

        label_18 = new QLabel(horizontalLayoutWidget_15);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout_13->addWidget(label_18);

        label_33 = new QLabel(horizontalLayoutWidget_15);
        label_33->setObjectName(QStringLiteral("label_33"));

        verticalLayout_13->addWidget(label_33);

        label_34 = new QLabel(horizontalLayoutWidget_15);
        label_34->setObjectName(QStringLiteral("label_34"));

        verticalLayout_13->addWidget(label_34);


        horizontalLayout_15->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        id_mission = new QLineEdit(horizontalLayoutWidget_15);
        id_mission->setObjectName(QStringLiteral("id_mission"));

        verticalLayout_14->addWidget(id_mission);

        libelle = new QLineEdit(horizontalLayoutWidget_15);
        libelle->setObjectName(QStringLiteral("libelle"));

        verticalLayout_14->addWidget(libelle);

        description = new QLineEdit(horizontalLayoutWidget_15);
        description->setObjectName(QStringLiteral("description"));

        verticalLayout_14->addWidget(description);

        confidentialite = new QLineEdit(horizontalLayoutWidget_15);
        confidentialite->setObjectName(QStringLiteral("confidentialite"));

        verticalLayout_14->addWidget(confidentialite);


        horizontalLayout_15->addLayout(verticalLayout_14);

        return_4 = new QPushButton(tab_7);
        return_4->setObjectName(QStringLiteral("return_4"));
        return_4->setGeometry(QRect(704, 330, 91, 23));
        return_4->setStyleSheet(QLatin1String("\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"border-image: url(:/return.png);"));
        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        horizontalLayoutWidget_16 = new QWidget(tab_8);
        horizontalLayoutWidget_16->setObjectName(QStringLiteral("horizontalLayoutWidget_16"));
        horizontalLayoutWidget_16->setGeometry(QRect(10, 270, 211, 81));
        horizontalLayout_16 = new QHBoxLayout(horizontalLayoutWidget_16);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_35 = new QLabel(horizontalLayoutWidget_16);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setFont(font);
        label_35->setStyleSheet(QStringLiteral("font: 10pt \"Roboto\";"));

        horizontalLayout_16->addWidget(label_35);

        id_rechercher_3 = new QLineEdit(horizontalLayoutWidget_16);
        id_rechercher_3->setObjectName(QStringLiteral("id_rechercher_3"));

        horizontalLayout_16->addWidget(id_rechercher_3);

        horizontalLayoutWidget_17 = new QWidget(tab_8);
        horizontalLayoutWidget_17->setObjectName(QStringLiteral("horizontalLayoutWidget_17"));
        horizontalLayoutWidget_17->setGeometry(QRect(10, 50, 391, 211));
        horizontalLayout_17 = new QHBoxLayout(horizontalLayoutWidget_17);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        tab_journaliste_3 = new QTableView(horizontalLayoutWidget_17);
        tab_journaliste_3->setObjectName(QStringLiteral("tab_journaliste_3"));

        horizontalLayout_17->addWidget(tab_journaliste_3);

        recherche_tab_3 = new QTableView(tab_8);
        recherche_tab_3->setObjectName(QStringLiteral("recherche_tab_3"));
        recherche_tab_3->setGeometry(QRect(400, 270, 391, 79));
        horizontalLayoutWidget_19 = new QWidget(tab_8);
        horizontalLayoutWidget_19->setObjectName(QStringLiteral("horizontalLayoutWidget_19"));
        horizontalLayoutWidget_19->setGeometry(QRect(440, 90, 351, 131));
        horizontalLayout_19 = new QHBoxLayout(horizontalLayoutWidget_19);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_37 = new QLabel(horizontalLayoutWidget_19);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setStyleSheet(QStringLiteral("font: 10pt \"Roboto\";"));

        verticalLayout_15->addWidget(label_37);

        label_38 = new QLabel(horizontalLayoutWidget_19);
        label_38->setObjectName(QStringLiteral("label_38"));

        verticalLayout_15->addWidget(label_38);

        label_39 = new QLabel(horizontalLayoutWidget_19);
        label_39->setObjectName(QStringLiteral("label_39"));

        verticalLayout_15->addWidget(label_39);

        label_40 = new QLabel(horizontalLayoutWidget_19);
        label_40->setObjectName(QStringLiteral("label_40"));

        verticalLayout_15->addWidget(label_40);


        horizontalLayout_19->addLayout(verticalLayout_15);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        id_miss_mod = new QLineEdit(horizontalLayoutWidget_19);
        id_miss_mod->setObjectName(QStringLiteral("id_miss_mod"));

        verticalLayout_16->addWidget(id_miss_mod);

        libelle_miss_mod = new QLineEdit(horizontalLayoutWidget_19);
        libelle_miss_mod->setObjectName(QStringLiteral("libelle_miss_mod"));

        verticalLayout_16->addWidget(libelle_miss_mod);

        description_mod = new QLineEdit(horizontalLayoutWidget_19);
        description_mod->setObjectName(QStringLiteral("description_mod"));

        verticalLayout_16->addWidget(description_mod);

        confidentialite_mod = new QLineEdit(horizontalLayoutWidget_19);
        confidentialite_mod->setObjectName(QStringLiteral("confidentialite_mod"));

        verticalLayout_16->addWidget(confidentialite_mod);


        horizontalLayout_19->addLayout(verticalLayout_16);

        pdf_p_3 = new QPushButton(tab_8);
        pdf_p_3->setObjectName(QStringLiteral("pdf_p_3"));
        pdf_p_3->setGeometry(QRect(180, 20, 101, 21));
        pdf_p_3->setStyleSheet(QLatin1String("\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"border-image: url(:/pdf.png);"));
        tri_p_3 = new QPushButton(tab_8);
        tri_p_3->setObjectName(QStringLiteral("tri_p_3"));
        tri_p_3->setGeometry(QRect(290, 20, 111, 21));
        tri_p_3->setStyleSheet(QLatin1String("font: 10pt \"Roboto\";\n"
"\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"border-image: url(:/TRIE.png);"));
        label_36 = new QLabel(tab_8);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(10, -70, 161, 209));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_36->setFont(font1);
        label_36->setStyleSheet(QStringLiteral("font: 12pt \"Roboto\";"));
        afficherp_3 = new QPushButton(tab_8);
        afficherp_3->setObjectName(QStringLiteral("afficherp_3"));
        afficherp_3->setGeometry(QRect(440, 20, 111, 21));
        afficherp_3->setStyleSheet(QLatin1String("border-image: url(:/afficher.png);\n"
"\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;"));
        modifierp_3 = new QPushButton(tab_8);
        modifierp_3->setObjectName(QStringLiteral("modifierp_3"));
        modifierp_3->setGeometry(QRect(690, 20, 111, 23));
        modifierp_3->setStyleSheet(QLatin1String("border-image: url(:/modifier.png);\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"font: 10pt \"Roboto\";"));
        supprimer_3 = new QPushButton(tab_8);
        supprimer_3->setObjectName(QStringLiteral("supprimer_3"));
        supprimer_3->setGeometry(QRect(560, 20, 121, 23));
        supprimer_3->setStyleSheet(QLatin1String("\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"border-image: url(:/delete.png);\n"
"font: 10pt \"Roboto\";"));
        recherchep_3 = new QPushButton(tab_8);
        recherchep_3->setObjectName(QStringLiteral("recherchep_3"));
        recherchep_3->setGeometry(QRect(240, 300, 81, 21));
        recherchep_3->setStyleSheet(QLatin1String("border-image: url(:/recherche.png);\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;"));
        tabWidget_2->addTab(tab_8, QString());
        stackedWidget->addWidget(page_3);

        retranslateUi(journaliste_mission);

        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(journaliste_mission);
    } // setupUi

    void retranslateUi(QDialog *journaliste_mission)
    {
        journaliste_mission->setWindowTitle(QApplication::translate("journaliste_mission", "Dialog", Q_NULLPTR));
        gestion_journaliste->setText(QString());
        gestion_des_mission->setText(QString());
#ifndef QT_NO_WHATSTHIS
        animation->setWhatsThis(QApplication::translate("journaliste_mission", "<html><head/><body><p><span style=\" font-size:16pt; font-style:italic;\"><br/>gestion des journalistes <br> et missions</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        animation->setText(QString());
        pb_ajouter_2->setText(QString());
        label_9->setText(QApplication::translate("journaliste_mission", "id journaliste:", Q_NULLPTR));
        label_10->setText(QApplication::translate("journaliste_mission", "nom :", Q_NULLPTR));
        label_11->setText(QApplication::translate("journaliste_mission", "prenom :", Q_NULLPTR));
        label_12->setText(QApplication::translate("journaliste_mission", "fonction :", Q_NULLPTR));
        label_13->setText(QApplication::translate("journaliste_mission", "diplome :", Q_NULLPTR));
        return_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("journaliste_mission", "ajouter", Q_NULLPTR));
        label_21->setText(QApplication::translate("journaliste_mission", "recherche", Q_NULLPTR));
        label_27->setText(QApplication::translate("journaliste_mission", "id journaliste:", Q_NULLPTR));
        label_28->setText(QApplication::translate("journaliste_mission", "nom :", Q_NULLPTR));
        label_29->setText(QApplication::translate("journaliste_mission", "prenom:", Q_NULLPTR));
        label_30->setText(QApplication::translate("journaliste_mission", "fonction:", Q_NULLPTR));
        label_31->setText(QApplication::translate("journaliste_mission", "diplome :", Q_NULLPTR));
        recherchep_2->setText(QString());
        trieprenom->setText(QString());
        tri_p_2->setText(QString());
        pdf_p_2->setText(QString());
        afficherp_2->setText(QString());
        modifierp_2->setText(QString());
        supprimer_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("journaliste_mission", "Gestion des journalistes", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("journaliste_mission", "Mailling", Q_NULLPTR));
        pb_ajouter_3->setText(QString());
        label_17->setText(QApplication::translate("journaliste_mission", "id mission", Q_NULLPTR));
        label_18->setText(QApplication::translate("journaliste_mission", "libelle mission", Q_NULLPTR));
        label_33->setText(QApplication::translate("journaliste_mission", "description mission", Q_NULLPTR));
        label_34->setText(QApplication::translate("journaliste_mission", "confidentialite", Q_NULLPTR));
        return_4->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("journaliste_mission", "ajouter", Q_NULLPTR));
        label_35->setText(QApplication::translate("journaliste_mission", "recherche", Q_NULLPTR));
        label_37->setText(QApplication::translate("journaliste_mission", "id mission", Q_NULLPTR));
        label_38->setText(QApplication::translate("journaliste_mission", "libelle mission", Q_NULLPTR));
        label_39->setText(QApplication::translate("journaliste_mission", "description mission", Q_NULLPTR));
        label_40->setText(QApplication::translate("journaliste_mission", "confidentialite", Q_NULLPTR));
        pdf_p_3->setText(QString());
        tri_p_3->setText(QString());
        label_36->setText(QApplication::translate("journaliste_mission", "Affichage des mission", Q_NULLPTR));
        afficherp_3->setText(QString());
        modifierp_3->setText(QString());
        supprimer_3->setText(QString());
        recherchep_3->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("journaliste_mission", "Gestion des missions", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class journaliste_mission: public Ui_journaliste_mission {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNALISTE_MISSION_H
