#include "mission_journaliste.h"
#include "ui_mission_journaliste.h"
#include "journaliste.h"
mission_journaliste::mission_journaliste(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mission_journaliste)
{
    ui->setupUi(this);
}

mission_journaliste::~mission_journaliste()
{
    delete ui;
}

void mission_journaliste::on_pushButton_clicked()
{
    hide();
        gesjournaliste gesjournaliste;
        gestion_des_article.setModal(true);
        gestion_des_article.exec();
}
