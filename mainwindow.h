#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "publicite.h"
#include "sponsors_crud.h"
#include"qrcode.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_p_ajouter_clicked();

    void on_Afficherp_clicked();

    void on_Modifierp_clicked();

    void on_supprimerp_clicked();

   // void on_trie_publicite_clicked();


    void on_recherche_publicite_clicked();

    //void on_tri_publicite_clicked(bool checked);

    void on_tri_publicite_clicked();

    //void on_envoyer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    //void on_gestionpub_clicked();

    void on_p_ajouter_2_clicked();

    void on_Afficherp_2_clicked();

    void on_Modifierp_2_clicked();

    void on_supprimerp_2_clicked();

    void on_tri_publicite_2_clicked();

    void on_recherche_publicite_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_tab_pub_activated(const QModelIndex &index);

    void on_tab_sponsor_activated(const QModelIndex &index);

    void on_mailing_clicked();
    void on_pButtonSave_3_clicked();

    void on_sBoxScale_3_valueChanged(int arg1);
    void on_pTextEditQRText_3_textChanged();
    void on_pButtonQuit_3_clicked();



private:
    void updateQRImage();
    void setScale(int);

private:
    Ui::MainWindow *ui;
    publicite *a;
    publicite *b;
    publicite *c;
    publicite *d;
    publicite *s;
    sponsors_crud *e;
    sponsors_crud *f;
    sponsors_crud *g;
    sponsors_crud *h;
    QMediaPlayer *click;
    QPropertyAnimation *animation;
    QPropertyAnimation *animation1;
    CQR_Encode qrEncode;
    bool successfulEncoding;
    int encodeImageSize;
    QPoint lastPos;
protected:
    void closeEvent(QCloseEvent *);
    bool eventFilter( QObject * object, QEvent * event );

};
#endif // MAINWINDOW_H
