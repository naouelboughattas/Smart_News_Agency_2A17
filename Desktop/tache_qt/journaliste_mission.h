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
namespace Ui {
class journaliste_mission;
}

class journaliste_mission : public QDialog
{
    Q_OBJECT

public:
    explicit journaliste_mission(QWidget *parent = nullptr);
    ~journaliste_mission();

private slots:
    void on_pb_ajouter_2_clicked();

    void on_pdf_p_2_clicked();

    void on_tri_p_2_clicked();

    void on_afficherp_2_clicked();

    void on_modifierp_2_clicked();

    void on_supprimer_2_clicked();

    void on_recherchep_2_clicked();

    void on_envoyer_2_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pdf_p_3_clicked();

    void on_tri_p_3_clicked();

    void on_afficherp_3_clicked();

    void on_modifierp_3_clicked();

    void on_supprimer_3_clicked();

    void on_recherchep_3_clicked();

    void on_tab_journaliste_3_activated(const QModelIndex &index);

    void on_tab_journaliste_2_activated(const QModelIndex &index);

    void on_envoyer_clicked();

    void on_gestion_journaliste_clicked();

    void on_gestion_des_mission_clicked();

    void on_return_4_clicked();

    void on_return_3_clicked();

    void on_trieprenom_clicked();

    void on_send_clicked();

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

};

#endif // JOURNALISTE_MISSION_H
