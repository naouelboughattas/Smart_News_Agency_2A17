#ifndef JOURNALISTE_MISSION_H
#define JOURNALISTE_MISSION_H

#include <QDialog>
#include "journaliste.h"
#include "connection.h"
#include"missions.h"
#include<QMediaPlayer>
#include<QtCharts>
#include<qchartview.h>
#include<QLineSeries>
#include <QEvent>
#include"qrcode.h"
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QScrollArea>
#include <arduino.h>
#include <QListWidgetItem>
#include <QColor>
#include <QRectF>
#include <QTime>
#include <QTimer>
#include <QPoint>
#include <QColor>
#include <QFont>
#include <QPainter>
#include <QtMath>
#include"searchbox.h"
#include"googlesuggest.h"
#include <QLineEdit>

namespace Ui {
class journaliste_mission;
}
#include "QZXing.h"

class journaliste_mission : public QDialog
{
    Q_OBJECT

public:
    explicit journaliste_mission(QWidget *parent = nullptr);
    ~journaliste_mission();
    QString getTime();
    void timerEvent(QTimerEvent *event);

    QString *currdate;
    void open();
    void decode();



private slots:
    void on_pb_ajouter_2_clicked();

    void on_pdf_p_2_clicked();

    void on_tri_p_2_clicked();

    void on_afficherp_2_clicked();

    void on_modifierp_2_clicked();

    void on_supprimer_2_clicked();

    void on_recherchep_2_clicked();


    void on_pb_ajouter_3_clicked();

    void on_pdf_p_3_clicked();

    void on_tri_p_3_clicked();

    void on_afficherp_3_clicked();

    void on_modifierp_3_clicked();

    void on_supprimer_3_clicked();

    void on_recherchep_3_clicked();

    void on_tab_journaliste_3_activated(const QModelIndex &index);

    void on_tab_journaliste_2_activated(const QModelIndex &index);


    void on_gestion_journaliste_clicked();

    void on_gestion_des_mission_clicked();

    void on_return_4_clicked();

    void on_return_3_clicked();

    void on_trieprenom_clicked();


    void on_pushButton_clicked();

    void on_pButtonSave_clicked();

    void on_sBoxScale_valueChanged(int arg1);
    void on_pTextEditQRText_textChanged();
    void on_pButtonQuit_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_2_clicked();

    void on_actionExit_triggered();

    void on_plainTextEdit_textChanged();

     void on_push_clicked();


    void on_checkBox_3_clicked(bool checked);

    void on_actionSave_triggered();



    void on_loginbutton_clicked();

    void on_signupbutton_clicked();

    void on_backButton_clicked();

    void on_completeRegButton_clicked();

    void on_excel_clicked();

    void on_makeShot_clicked();

    void on_qrcode_clicked();

    void on_qrcodelabel_linkActivated(const QString &link);

    void on_saveit_clicked();
    void on_pButtonOpen_clicked();
    void on_pButtonQuitt_clicked();
    void ard();   // slot permettant la mise à jour du label état de la lampe 1,


    void on_add_to_list_clicked();

    void on_list_items_itemChanged(QListWidgetItem *item);

    void on_item_text_returnPressed();

    void on_move_item_up_clicked();

    void on_move_item_down_clicked();

    void on_delete_item_clicked();

    void on_musicNext_clicked();

    void on_musicPlay_clicked();

    void on_musicBack_clicked();

    void on_musicStop_clicked();

    void on_googlesearch_clicked();

private:
    void updateQRImage();
    void setScale(int);
    void save();

    //! [1]



private:
    Ui::journaliste_mission *ui;
    gesjournaliste *g ;
    gesjournaliste *r ;
    gesjournaliste *t ;

    gesjournaliste m;
    missions *a;
    missions *s;
    missions *b;
    missions *tri;
    QMediaPlayer *click;
    CQR_Encode qrEncode;
    bool successfulEncoding;
    int encodeImageSize;
    QPoint lastPos;
    QZXing zxing;
    Arduino A;
    QByteArray data; // variable contenant les données reçues
    QSystemTrayIcon *notification;
    void animateObj(QWidget* widget, int current=255);
    void animateObjWhite(QWidget* widget, int current);
    SearchBox search;
protected:
    void closeEvent(QCloseEvent *);
    bool eventFilter( QObject * object, QEvent * event );
    void dragEnterEvent( QDragEnterEvent * event );
    void dropEvent( QDropEvent * event );
    bool eventFilterscanner( QObject * object, QEvent * event );
    void closeEventscanner(QCloseEvent *);
    void doSearch();

};

#endif // JOURNALISTE_MISSION_H
