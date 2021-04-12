#include "journaliste_mission.h"
#include "ui_journaliste_mission.h"
#include "journaliste.h"
#include"qmessagebox.h"
#include "QPainter"
#include "QPdfWriter"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"
#include"qsqlquery.h"
#include "qobject.h"
#include "qsqlerror.h"
#include"QIntValidator"
#include"qcoreapplication.h"
#include"journaliste_mission.h"
#include"qmainwindow.h"
#include"missions.h"
#include"mainwindow.h"
#include <QPropertyAnimation>
#include <QDesktopServices>
#include<mailing/SmtpMime>
#include <QSound>
#include <QFile>
#include <QMediaPlayer>
#include <QtCharts/QChartView>
#include <QtCharts/qlineseries.h>
#include <QtCharts/QBarSet>
journaliste_mission::journaliste_mission(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::journaliste_mission)
{
    ui->setupUi(this);
    click=new QMediaPlayer();
    click->setMedia(QUrl("qrc:/click.mp3"));
    QPropertyAnimation * animation = new QPropertyAnimation(ui->animation, "geometry");
        animation->setDuration(10000);
        animation->setLoopCount(-1);
        animation->setStartValue(QRect(-20, -125, 371, 400));
        animation->setEndValue(QRect(1050, -125, 371, 400));
        animation->start();

     QBarSet *set0= new QBarSet("Bac+3");
            QBarSet *set1= new QBarSet("Bac+4");
                *set0 << m.fetch("Bac+3");
                *set1 << m.fetch("Bac+4");

               QBarSeries *series= new QBarSeries();
               series->append(set0);
               series->append(set1);
               QChart *chart =new QChart ;
                chart->addSeries(series);
                chart->setTitle("diplome des journalistes");
                chart->createDefaultAxes();
                chart->setAnimationOptions(QChart::AllAnimations);

                QStringList cat;
                cat <<"bac+3"<<"bac+4";
                QBarCategoryAxis *axis =new QBarCategoryAxis();
                axis->append(cat);
                chart->createDefaultAxes();
                chart->setAxisX(axis,series);

                chart->legend()->setVisible(true);
                chart->legend()->setAlignment(Qt::AlignBottom);
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(420,280);
                chartView->setParent(ui->statv);
        }


journaliste_mission::~journaliste_mission()
{
    delete ui;
}
void journaliste_mission::on_pb_ajouter_2_clicked()
{
    click->play();

    int id = ui->id->text().toInt();
    QString nom= ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString fonction=ui->le_fonction_2->text();
    QString diplome=ui->le_diplome_2->text();

  gesjournaliste j(id,nom,prenom,fonction,diplome);
  bool test=j.ajouter();
  if(test)
{

QMessageBox::information(nullptr, QObject::tr("Ajouter un journaliste"),
                  QObject::tr("journaliste ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_journaliste_2->setModel(g->afficher());

}
  else

      QMessageBox::critical(nullptr, QObject::tr("Ajouter un journaliste"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tab_journaliste_2->setModel(g->afficher());
}

void journaliste_mission::on_modifierp_2_clicked()
{
    click->play();

    int id = ui->le_id_6->text().toInt();
    QString nom= ui->le_nom_5->text();
    QString prenom=ui->le_prenom_5->text();
    QString fonction=ui->le_fonction_4->text();
    QString diplome=ui->le_diplome_4->text();


          gesjournaliste j(id,nom,prenom,fonction,diplome);

             bool test =j.modifier();

             if(test)

             {
                 QMessageBox::information(nullptr, QObject::tr("Modifier un journaliste"),
                             QObject::tr("journaliste modifiée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_journaliste_2->setModel(g->afficher());

             }

             else

             {
                 QMessageBox::critical(nullptr, QObject::tr("modifier un journaliste"),
                             QObject::tr("Erreur !\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_journaliste_2->setModel(g->afficher());

             }
}


















void journaliste_mission::on_supprimer_2_clicked()
{
    click->play();


    int id = ui->le_id_6->text().toInt();
    if (ui->le_id_6->text().isEmpty())
     {

         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;

     }
    else {
        bool test=g->supprimer(id);
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("Supprimer un journaliste"),
                        QObject::tr("journaliste supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_journaliste_2->setModel(g->afficher());

        }

    }
}

void journaliste_mission::on_recherchep_2_clicked()
{

    click->play();

    if (ui->id_rechercher_2->text().isEmpty())
     {

         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;

     }
    else {
    QString nom= ui->id_rechercher_2->text();
    ui->recherche_tab_2->setModel(r->rechercher(nom));
    ui->tab_journaliste_2->setModel(g->afficher());}
}


void journaliste_mission::on_tri_p_2_clicked()
{
    click->play();

        bool test = t->tri_nom();
               if (test){
                   QMessageBox::information(nullptr, QObject::tr("tri des journaliste"),
                               QObject::tr("succée.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
               ui->tab_journaliste_2->setModel(t->tri_nom());}//refresh
               else
                   QMessageBox::critical(nullptr, QObject::tr("tri des journaliste"),
                               QObject::tr("Erreur !\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
               ui->tab_journaliste_2->setModel(t->tri_nom());}//refresh




void journaliste_mission::on_pdf_p_2_clicked()
{
    click->play();


    QPdfWriter pdf("C:/Users/user/Desktop/tache_qt/testpdf");
                          QPainter painter(&pdf);
                         int i = 4000;
                              painter.setPen(Qt::red);
                              painter.setFont(QFont("Arial", 30));
                              painter.drawText(2300,1200,"Liste Des journaliste");
                              painter.setPen(Qt::black);
                              painter.setFont(QFont("Arial", 50));
                             // painter.drawText(1100,2000,afficheDC);
                              painter.drawRect(1500,200,7300,2600);
                              //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                              painter.drawRect(0,3000,9600,500);
                              painter.setFont(QFont("Arial", 9));
                              painter.drawText(300,3300,"ID");
                              painter.drawText(2300,3300,"NOM");
                              painter.drawText(4300,3300,"PRENOM");
                              painter.drawText(6300,3300,"FONCTION");
                              painter.drawText(8300,3300,"DIPLOME");




                              QSqlQuery query;
                              query.prepare("select * from JOURNALISTE");
                              query.exec();
                              while (query.next())
                              {
                                  painter.drawText(300,i,query.value(0).toString());
                                  painter.drawText(2300,i,query.value(1).toString());
                                  painter.drawText(4300,i,query.value(2).toString());
                                  painter.drawText(6300,i,query.value(3).toString());
                                  painter.drawText(8300,i,query.value(4).toString());




                                 i = i +500;
                              }
                              int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                  if (reponse == QMessageBox::Yes)
                                  {

                                      painter.end();
                                  }
                                  if (reponse == QMessageBox::No)
                                  {
                                       painter.end();
                                  }


}


void journaliste_mission::on_tab_journaliste_2_activated(const QModelIndex &index)
{

    click->play();

    QString val=ui->tab_journaliste_2->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from journaliste where id='"+val+"'or nom='"+val+"'or prenom='"+val+"'or fonction='"+val+"'or diplome='"+val+"'");

    if(query.exec())
    {

     while(query.next())
    {
            ui->le_id_6->setText(query.value(0).toString());
            ui->le_nom_5->setText(query.value(1).toString());
            ui->le_prenom_5->setText(query.value(2).toString());
            ui->le_fonction_4->setText(query.value(3).toString());
            ui->le_diplome_4->setText(query.value(4).toString());

}

  }
    else {
        QMessageBox::critical(nullptr, QObject::tr("journaliste"),
                    QObject::tr("Erreur !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
   }

void journaliste_mission::on_afficherp_2_clicked()
{    click->play();

    ui->tab_journaliste_2->setModel(g->afficher());

}





void journaliste_mission::on_gestion_journaliste_clicked()
{    click->play();

    ui->stackedWidget->setCurrentIndex(1);
}


void journaliste_mission::on_return_3_clicked()
{    click->play();

    ui->stackedWidget->setCurrentIndex(0);

}


void journaliste_mission::on_gestion_des_mission_clicked()
{    click->play();

    ui->stackedWidget->setCurrentIndex(2);

}

void journaliste_mission::on_return_4_clicked()
{    click->play();

    ui->stackedWidget->setCurrentIndex(0);

}



void journaliste_mission::on_pb_ajouter_3_clicked()
{    click->play();

    int id_mission = ui->id_mission->text().toInt();
    QString libelle= ui->libelle->text();
    QString description=ui->description->text();
    QString confidentialite=ui->confidentialite->text();

  missions m(id_mission,libelle,description,confidentialite);
  bool test=m.ajouter();
  if(test)
{

QMessageBox::information(nullptr, QObject::tr("Ajouter mission "),
                  QObject::tr("mission ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_journaliste_3->setModel(a->afficher());

}
  else

      QMessageBox::critical(nullptr, QObject::tr("Ajouter mission"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tab_journaliste_3->setModel(a->afficher());
}

void journaliste_mission::on_modifierp_3_clicked()
{    click->play();

    int id_mission = ui->id_miss_mod->text().toInt();
    QString libelle= ui->libelle_miss_mod->text();
    QString description=ui->description_mod->text();
    QString confidentialite=ui->confidentialite_mod->text();


          missions j(id_mission,libelle,description,confidentialite);

             bool test =j.modifier();

             if(test)

             {
                 QMessageBox::information(nullptr, QObject::tr("Modifier mission"),
                             QObject::tr("mission modifiée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_journaliste_3->setModel(a->afficher());

             }

             else

             {
                 QMessageBox::critical(nullptr, QObject::tr("modifier mission"),
                             QObject::tr("Erreur !\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_journaliste_3->setModel(a->afficher());

             }
}

void journaliste_mission::on_supprimer_3_clicked()
{    click->play();

    int id_mission = ui->id_miss_mod->text().toInt();

        bool test=s->supprimer(id_mission);
        if(test)
        {
            ui->tab_journaliste_3->setModel(a->afficher());

            QMessageBox::information(nullptr, QObject::tr("Supprimer mission"),
                        QObject::tr("mission supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer mission"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_journaliste_3->setModel(a->afficher());
}

void journaliste_mission::on_afficherp_3_clicked()
{    click->play();

    ui->tab_journaliste_3->setModel(a->afficher());

}

void journaliste_mission::on_tab_journaliste_3_activated(const QModelIndex &index)
{
    QString val=ui->tab_journaliste_3->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from mission where id_mission='"+val+"'or libelle='"+val+"'or description='"+val+"'or confidentialite='"+val+"'");

    if(query.exec())
    {

     while(query.next())
    {
            ui->id_miss_mod->setText(query.value(0).toString());
            ui->libelle_miss_mod->setText(query.value(1).toString());
            ui->description_mod->setText(query.value(2).toString());
            ui->confidentialite_mod->setText(query.value(3).toString());


}}
    else {
        QMessageBox::critical(nullptr, QObject::tr("missions"),
                    QObject::tr("Erreur !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

void journaliste_mission::on_recherchep_3_clicked()
{    click->play();

    QString libelle= ui->id_rechercher_3->text();
    ui->recherche_tab_3->setModel(b->rechercher(libelle));
    ui->tab_journaliste_3->setModel(a->afficher());
}

void journaliste_mission::on_pdf_p_3_clicked()
{    click->play();

    missions E4;
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:/Users/user/Desktop/tache_qt/pdf2");
        QPainter painter;
        if(!painter.begin(&printer)){
            qWarning("failed to open");}
            QSqlQuery qry;
            qry.prepare("select * from mission");
            int kk=200,dd=300,bb=400;
        if(qry.exec())
            {
            while (qry.next()){
            QString n = qry.value(0).toString();
            QString d = qry.value(1).toString();
            QString e = qry.value(2).toString();
            QString f = qry.value(3).toString();
            QString g = qry.value(4).toString();
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Times",30));
            painter.drawText(300,100,"liste des missions");
            painter.setFont(QFont("Times",15));
            painter.setPen(Qt::black);
         painter.drawText(100,kk,n);
         painter.drawText(200,kk,d);
         painter.drawText(100,dd,e);
         painter.drawText(200,dd,f);
         painter.drawText(100,bb,g);
         printer.newPage();
        }}
          painter.end();
          qDebug()<<"le pdf a ete cree";
          QMessageBox::information(this,"pdf cree","ce pdf a ete cree");

        }










void journaliste_mission::on_tri_p_3_clicked()
{    click->play();

    bool test = tri->tri_id_mission();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des missions"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_journaliste_2->setModel(tri->tri_id_mission());}//refresh
           else
               QMessageBox::critical(nullptr, QObject::tr("tri des missions"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_journaliste_2->setModel(tri->tri_id_mission());}//refresh


void journaliste_mission::on_trieprenom_clicked()
{    click->play();

    bool test = t->tri_prenom();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des journaliste"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_journaliste_2->setModel(t->tri_prenom());}//refresh
           else
               QMessageBox::critical(nullptr, QObject::tr("tri des journaliste"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_journaliste_2->setModel(t->tri_prenom());}//refresh


/*void journaliste_mission::on_envoyer_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 25, SmtpClient::SslConnection);
    smtp.setUser("mohamedamine.balti@esprit.tn");
    smtp.setPassword("amineamine");
    MimeMessage message;
    message.setSender(new EmailAddress("mohamedamine.balti@esprit.tn", "amine"));
    message.addRecipient(new EmailAddress(ui->mail->text(), "Recipient's Name"));
    message.setSubject(ui->objet->text());
    MimeText text;
    text.setText(ui->message->text());
    message.addPart(&text);
    smtp.connectToHost();
    smtp.login();
    if (smtp.sendMail(message))
    {
    QMessageBox::information(this,"ok","message envoyer");
    }
    else {
        QMessageBox::critical(this,"error","error");
    }
     smtp.quit();
}*/

