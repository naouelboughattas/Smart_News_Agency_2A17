#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "article.h"
#include "categorie.h"
#include "connection.h"
#include"qrcode.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include"journaliste.h"
#include"missions.h"
#include"publicite.h"
#include"sponsors_crud.h"
#include"equipement.h"
#include"fournisseur.h"
#include<QTimer>
#include"journaux.h"
#include"commande.h"
#include"searchbox.h"
#include"googlesuggest.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
#include "QZXing.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString *currdate;
    void open();
    void decode();
    QString getCurrentId();

    QString getTime();
    void timerEvent(QTimerEvent *event);

private slots:


    void on_pb_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_pushButton_clicked();

    void on_gestion_article_clicked();

    void on_return_2_clicked();

    void on_trier_clicked();

    void on_recherche_clicked();

    void on_pdf_clicked();

    void on_tab_article_activated(const QModelIndex &index);

    void on_gestion_categorie_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pushButton_3_clicked();

    void on_modifier_3_clicked();

    void on_supprimer_3_clicked();

    void on_trier_3_clicked();

    void on_pdf_3_clicked();

    void on_recherche_3_clicked();

    void on_tab_categorie_activated(const QModelIndex &index);

    void on_return_4_clicked();

    void on_trier2_clicked();

    void on_trier2_2_clicked();

    void on_mailing_clicked();




    void on_pButtonSave_clicked();

    void on_sBoxScale_valueChanged(int arg1);
    void on_pTextEditQRText_textChanged();
    void on_pButtonQuit_clicked();

    void on_pushButton_2_clicked();

    void on_historique_clicked();

    void on_back_clicked();

    void on_historique_2_clicked();

    void on_pushButton_5_clicked();

    void on_excel_clicked();
    void showTime();


    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_3_currentChanged(int index);



    void on_makeShot_clicked();

    void on_pb_ajouter_8_clicked();

    void on_modifierp_7_clicked();

    void on_supprimer_8_clicked();

    void on_recherchep_7_clicked();

    void on_afficherp_7_clicked();

    void on_tri_p_7_clicked();

    void on_trieprenom_3_clicked();

    void on_pdf_p_7_clicked();

    void on_pushButton_7_clicked();

    void on_pButtonSave_4_clicked();

    void on_pButtonQuit_4_clicked();

    void on_sBoxScale_4_valueChanged(int arg1);

    void on_pTextEditQRText_4_textChanged();
    //void on_calendarWidget_clicked(const QDate &date);
    //void on_pushButton_2_clicked();

   // void on_checkBox_3_clicked(bool checked);


    void on_push_2_clicked();


    void on_excel_3_clicked();

    void on_qrcode_4_clicked();

    void on_saveit_2_clicked();

    void on_pButtonOpen_2_clicked();

    void on_loginbutton_clicked();

    void on_signupbutton_clicked();

    void on_completeRegButton_clicked();

    void on_backButton_clicked();

    void on_pb_mission_clicked();

    void on_modifierp_6_clicked();

    void on_supprimer_7_clicked();

    void on_afficherp_6_clicked();

    void on_tri_p_6_clicked();

    void on_pdf_p_6_clicked();

    void on_recherchep_6_clicked();

    void on_tab_mission_activated(const QModelIndex &index);

    void on__tab_journaliste_2_activated(const QModelIndex &index);

    void on_makeShot_4_clicked();

    void on_calendarWidget_2_clicked(const QDate &date);

    void on_checkBox_4_clicked(bool checked);
    void on_actionSave_triggered();
    void on_add_to_list_3_clicked();

    void on_list_items_3_itemChanged(QListWidgetItem *item);

    void on_item_text_3_returnPressed();

    void on_move_item_up_3_clicked();

    void on_move_item_down_3_clicked();

    void on_delete_item_3_clicked();


    void on_afficher_s_clicked();

    void on_gestion_des_mission_clicked();

    void on_gestion_journaliste_clicked();

    void on_backButton_2_clicked();
    void on_p_ajoutersahar_clicked();

    void on_Afficherpsahar_clicked();

    void on_Modifierpsahar_clicked();

    void on_supprimerpsahar_clicked();

   // void on_trie_publicite_clicked();


    void on_recherche_publicitesahar_clicked();

    //void on_tri_publicite_clicked(bool checked);

    void on_tri_publicitesahar_clicked();

    //void on_envoyer_clicked();

    void on_pushButtonsahar_clicked();

    void on_pushButton_2sahar_clicked();

    void on_pushButton_3sahar_clicked();

    void on_pushButton_4sahar_clicked();

    //void on_gestionpub_clicked();

    void on_p_ajouter_2sahar_clicked();

    void on_Afficherp_2sahar_clicked();

    void on_Modifierp_2sahar_clicked();

    void on_supprimerp_2sahar_clicked();

    void on_tri_publicite_2sahar_clicked();

    void on_recherche_publicite_2sahar_clicked();

    void on_pushButton_5sahar_clicked();

    void on_pushButton_7sahar_clicked();

    void on_pushButton_6sahar_clicked();

    void on_tab_pubsahar_activated(const QModelIndex &index);

    void on_tab_sponsorsahar_activated(const QModelIndex &index);

    void on_mailingsahar_clicked();
    void on_pButtonSave_3sahar_clicked();

    void on_sBoxScale_3sahar_valueChanged(int arg1);
    void on_pTextEditQRText_3sahar_textChanged();
    void on_pButtonQuit_3sahar_clicked();



    void on_statistiquesahar_clicked();

    void on_historiquesahar_clicked();

    void on_backsahar_clicked();

    void on_voir_historiquesahar_clicked();

    void on_makeShotsahar_clicked();

    void on_excelsahar_clicked();

    //*EMNA*//

    void on_p_ajouter_2emna_clicked();

    void on_p_ajouterE_2emna_clicked();

    void on_afficherE_2emna_clicked();

    void on_afficherF_2emna_clicked();

    void on_ModifierE_2emna_clicked();

    void on_modifierF_2emna_clicked();

    void on_supprimerF_2emna_clicked();

    void on_supprimerE_2emna_clicked();
    void digit_pressed();

    void on_pushButton_dot_released();
    void unary_operation_pressed();
    void on_pushButton_clear_released();
    void on_pushButton_equals_released();
    void binary_operation_pressed();


void  showTimeemna();

    void on_radioButton_2emna_clicked();

    void on_radioButton_3emna_clicked();

    void on_p_rech_id_2emna_clicked();

    void on_p_rech_libelle_2emna_clicked();

    void on_p_rech_marque_2emna_clicked();

    void on_pdf_2emna_clicked();


    void on_radioButton_4emna_clicked();


    void on_pushButtonemna_clicked();

    void on_makeShotemna_clicked();

    void on_tache_emna_1_clicked();

    void on_tache_emna_clicked();

    void on_qrcode_clicked();

    /*********ayedi************/
    void on_ajouteryass_clicked();

    void on_pushButtonyass_clicked();

    void on_modifieryass_clicked();

    void on_supprimeryass_clicked();

    void on_rechercher_2yass_clicked();

    void on_trieyass_clicked();

    void on_ajouter_2yass_clicked();

    void on_pushButton_3yass_clicked();

    void on_rechercher_5yass_clicked();

    void on_trie_3yass_clicked();

    void on_modifier_3yass_clicked();

    void on_supprimer_3yass_clicked();

    void on_afficher_2yass_clicked();



    void on_journauxyass_clicked();

    void on_commandeyass_clicked();

    void on_return1yass_clicked();

    void on_return_2yass_clicked();



    void on_excelyass_clicked();

   void on_makeShotyass_clicked();

   void on_PDFyass_clicked();
   void on_pButtonSaveyass_clicked();

       void on_sBoxScaleyass_valueChanged(int arg1);
       void on_pTextEditQRTextyass_textChanged();
       void on_pButtonQuityass_clicked();
       void on_mailingyass_clicked();



       void on_backButton_5_clicked();

       void on_return_5_clicked();

       void on_musicNext_clicked();

       void on_musicPlay_clicked();

       void on_musicBack_clicked();

       void on_musicStop_clicked();

       void on_backButton_4_clicked();

       void on_recherchep_11_clicked();

private:
    void updateQRImage();
    void setScale(int);
    void updateQRImage2();
    void setScale2(int);
    void updateQRImagesahar();
    void setScalesahar(int);
    void updateQRImageyass();
    void setScaleyass(int);

private:
    Ui::MainWindow *ui;
    Article *s ;
    Categorie *h;
    gesjournaliste *g ;
    missions *a;


    QMediaPlayer *click;
    CQR_Encode qrEncode;
    bool successfulEncoding;
    int encodeImageSize;
    QPoint lastPos;
    CQR_Encode qrEncode2;
    bool successfulEncoding2;
    int encodeImageSize2;
    QPoint lastPos2;
     QZXing zxing;

     publicite *b;
     sponsors_crud *e;
     QPropertyAnimation *animation;
     QPropertyAnimation *animation1;
     CQR_Encode qrEncodesahar;
     bool successfulEncodingsahar;
     int encodeImageSizesahar;
     QPoint lastPossahar;
     equipement *v;
     Fournisseur *f;
     QTimer *timer;
     journaux *t;
     commande *n;
     CQR_Encode qrEncodeyass;
         bool successfulEncodingyass;
         int encodeImageSizeyass;
         QPoint lastPosyass;

        SearchBox search;


protected:
    void closeEvent(QCloseEvent *);
    bool eventFilter( QObject * object, QEvent * event );
    void changeEvent(QEvent *e);
    void closeEvent2(QCloseEvent *);
    bool eventFilter2( QObject * object, QEvent * event );
    void changeEvent2(QEvent *e);
    void dragEnterEvent( QDragEnterEvent * event );
    void dropEvent( QDropEvent * event );
    bool eventFilterscanner( QObject * object, QEvent * event );
    void closeEventscanner(QCloseEvent *);
    void closeEventsahar(QCloseEvent *);
    bool eventFiltersahar( QObject * object, QEvent * event );
    void changeEventsahar(QEvent *e);
    void changeEventemna(QEvent *e);
    void closeEventyass(QCloseEvent *);
    bool eventFilteryass( QObject * object, QEvent * event );
    void changeEventyass(QEvent *e);

};
#endif // MAINWINDOW_H

