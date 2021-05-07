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
#include "qsqlquery.h"
#include "smtp.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMouseEvent>
#include <QScrollArea>
#include <QImageWriter>
#include <QScrollBar>
#include <QSettings>
#include <QApplication>
#include <QDebug>
#include "qrcode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <qdatetime.h>
#include <QImageReader>
#include <QMimeData>
#include <QFileInfo>
#include <QUrl>
#include <QTextStream>
#include <QFileDialog>
#include "account.h"
#include"exportexcelobjet.h"
#include <QPixmap>
#include <QDesktopWidget>
#include <QDateTime>
#include <QThread>
#include"screenshot.h"
#include "qrcode2.h"
#include <QIntValidator>
#include <QSound>
#include <QTimerEvent>
#include <ctime>
#include <sstream>
#include"searchbox.h"
#include"googlesuggest.h"
const QString gsearchUrl = QStringLiteral("http://www.google.com/search?q=%1");

using namespace std;
using namespace qrcodegen;
int timer = 0; // Event Timer

QSound audio ("multi.qrc:/click.mp3");

QMediaPlayer* musicPlayer = new QMediaPlayer;
QString songsList[] = {"music1.mp3", "music2.mp3", "music3.mp3", "music4.mp3", "music5.mp3"};
int currentSong = 0;
bool autoPlay = true;

const QString getIniPath()
{
    const static QString iniPath( qApp->applicationDirPath() + "/settings.ini" );
    return iniPath;
}
QString saveFormats()
{
    static QString suffix;
    foreach ( const QByteArray & format , QImageWriter::supportedImageFormats() )
        suffix += QString( "%1 ( *.%2 )\n" )
                .arg( QString( format ).toUpper() )
                .arg( QString( format ) );

    return suffix;
}

const QString getFilter()
{
    static QString filter;
    filter += "Images (";
    foreach ( const QByteArray & format, QImageReader::supportedImageFormats() )
        filter += " *." + format;
    filter += " )";

    return filter;
}



 //le slot update_label suite à la reception du signal readyRead (reception des données).


journaliste_mission::journaliste_mission(QWidget *parent) :


    QDialog(parent),

    ui(new Ui::journaliste_mission),

    successfulEncoding(false)

{      currdate = new QString();

    QString windowTitle("newsgenix");

    ui->setupUi(this);
     ui->stackedWidget->setCurrentIndex(0);

      // connect(ui->get_data,SIGNAL(clicked()),this,SLOT(getcity()));

       ui->scrollArea_2->installEventFilter( this );
          int ret=A.connect_arduino(); // lancer la connexion à arduino
          switch(ret){
          case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
              break;
          case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
             break;
          case(-1):qDebug() << "arduino is not available";
          }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(arduino())); // permet de lancer
 notification = new QSystemTrayIcon(this) ;

data=A.read_from_arduino();
        if(data=="1"){
    notification->show();
    QString titre="Warning";
    QString textMessage="detecter";
    int duree=10000;
    notification->showMessage(titre,textMessage,QSystemTrayIcon::Information,duree);}


       // Расшифровываем qr коды
       zxing.setDecoder( QZXing::DecoderFormat_QR_CODE );

       QSettings ini2( getIniPath(), QSettings::IniFormat );
       ui->splitter_3->restoreState( ini2.value( ui->splitter_3->objectName() ).toByteArray() );
    //   restoreState( ini.value( "State" ).toByteArray() );
       restoreGeometry( ini2.value( "Geometry" ).toByteArray() );





this->setWindowTitle(windowTitle);

    QPropertyAnimation * animation = new QPropertyAnimation(ui->animation, "geometry");
        animation->setDuration(10000);
        animation->setLoopCount(-1);
        animation->setStartValue(QRect(-20, -125, 371, 400));
        animation->setEndValue(QRect(1050, -125, 371, 400));
        animation->start();


        ui->scrollArea->installEventFilter( this );

        QSettings ini( getIniPath(), QSettings::IniFormat );
        ui->splitter_2->restoreState( ini.value( ui->splitter_2->objectName() ).toByteArray() );
        ui->splitter->restoreState( ini.value( ui->splitter->objectName() ).toByteArray() );
        ui->sBoxScale->setValue( ini.value( ui->sBoxScale->objectName(), 4 ).toInt() );
       // restorestate( ini.value( "State" ).toByteArray() );
        restoreGeometry( ini.value( "Geometry" ).toByteArray() );

        setScale( ui->sBoxScale->value() );
        updateQRImage();





           ui->id->setValidator( new QIntValidator(0, 999999999, this));
           ui->id_mission->setValidator( new QIntValidator(0, 999999999, this));



              if(autoPlay)
              {

                  musicPlayer->setMedia(QUrl("qrc:/" + songsList[currentSong]));
                  musicPlayer->setVolume(50);
                  musicPlayer->play();
                  ui->musicStop->setVisible(true);
                  ui->musicPlay->setVisible(false);


              }
              else
              {
                  ui->musicStop->setVisible(false);
                  ui->musicPlay->setVisible(true);

              }

              startTimer(1000);   // 1-second timer


        }


journaliste_mission::~journaliste_mission()
{
    delete ui;
}
void journaliste_mission::on_pb_ajouter_2_clicked()
{
        audio.play();



    int id = ui->id->text().toInt();
    QString nom= ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString fonction=ui->le_fonction_2->text();
    QString diplome=ui->le_diplome_2->text();

    if (ui->id->text().isEmpty())
     {


        ui->id->setStyleSheet("border: 1px solid red ");
         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;
         QToolTip::showText(ui->id->mapToGlobal(QPoint(100,0)), tr("INSERT ID"));
    }else if(ui->le_nom_2->text().isEmpty()||nom.size()>21){


        ui->le_nom_2->setStyleSheet("border: 1px solid red ");
         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP  NOM!!!!") ;
          QToolTip::showText(ui->le_nom_2->mapToGlobal(QPoint(100,0)), tr("nom doit etre entre 0 et 20 charactere"));
    }
    else if(prenom.isEmpty()||prenom.size()>21){

            ui->le_prenom_2->setStyleSheet("border: 1px solid red ");
             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP PRENOM!!!!") ;
             QToolTip::showText(ui->le_prenom_2->mapToGlobal(QPoint(100,0)), tr("prenom doit etre entre 0 et 20 charactere"));

        }

    else if(fonction.isEmpty()||fonction.size()>21){

            ui->le_fonction_2->setStyleSheet("border: 1px solid red ");
             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP FOCNTION!!!!") ;
             QToolTip::showText(ui->le_fonction_2->mapToGlobal(QPoint(100,0)), tr("fonction doit etre entre 0 et 20 charactere"));


        }

    else if(diplome.isEmpty()||diplome.size()>21){

            ui->le_diplome_2->setStyleSheet("border: 1px solid red ");
             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP DIPLOME!!!!") ;
             QToolTip::showText(ui->le_diplome_2->mapToGlobal(QPoint(100,0)), tr("diplome doit etre entre 0 et 20 charactere"));

        }
    else {


  gesjournaliste j(id,nom,prenom,fonction,diplome);
  bool test=j.ajouter();
  if(test)
{

QMessageBox::information(nullptr, QObject::tr("Ajouter un journaliste"),
                  QObject::tr("journaliste ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_journaliste_2->setModel(g->afficher());
ui->id->setStyleSheet("border: 1px solid blue ");
ui->le_nom_2->setStyleSheet("border: 1px solid blue ");
ui->le_prenom_2->setStyleSheet("border: 1px solid blue ");
ui->le_fonction_2->setStyleSheet("border: 1px solid blue ");
ui->le_diplome_2->setStyleSheet("border: 1px solid blue ");


}
  else

      QMessageBox::critical(nullptr, QObject::tr("Ajouter un journaliste"),
                  QObject::tr("id journaliste existe deja  !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tab_journaliste_2->setModel(g->afficher());
}
}
void journaliste_mission::on_modifierp_2_clicked()
{
        audio.play();


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
        audio.play();



    int id = ui->le_id_6->text().toInt();
    if (ui->le_id_6->text().isEmpty())
     {

        QToolTip::showText(ui->le_id_6->mapToGlobal(QPoint(100,0)), tr("INSERT ID"));
        ui->le_id_6->setStyleSheet("border: 1px solid red ");
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
            ui->le_id_6->setStyleSheet("border: 1px solid blue ");

        }

    }
}

void journaliste_mission::on_recherchep_2_clicked()
{

        audio.play();


    if (ui->id_rechercher_2->text().isEmpty())
     {

         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;
         QToolTip::showText(ui->id_rechercher_2->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
         ui->id_rechercher_2->setStyleSheet("border: 1px solid red ");



     }
    else {
    QString nom= ui->id_rechercher_2->text();
    ui->tab_journaliste_2->setModel(r->rechercher(nom));
    ui->id_rechercher_2->setStyleSheet("border: 1px solid blue ");

    }
}


void journaliste_mission::on_tri_p_2_clicked()
{
        audio.play();


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
        audio.play();



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

        audio.play();


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
{        audio.play();


    ui->tab_journaliste_2->setModel(g->afficher());

}





void journaliste_mission::on_gestion_journaliste_clicked()
{        audio.play();


    ui->stackedWidget->setCurrentIndex(3);
}


void journaliste_mission::on_return_3_clicked()
{        audio.play();


    ui->stackedWidget->setCurrentIndex(2);

}


void journaliste_mission::on_gestion_des_mission_clicked()
{        audio.play();


    ui->stackedWidget->setCurrentIndex(4);

}

void journaliste_mission::on_return_4_clicked()
{        audio.play();


    ui->stackedWidget->setCurrentIndex(2);

}

void journaliste_mission::on_loginbutton_clicked()
{

    QString username=ui->username->text();
       QString password= ui->password->text();
int n = username.size();
int n1 = password.size();
if ((n != 0  or n1  != 0)  ) {


  if (n>3 and n<11)

  {
      if (n1>5 and n1<21 )
      {


       QSqlQuery query;
           query.prepare("SELECT * FROM LOGIN WHERE USERNAME= ? AND PASSWORD= ?");
           query.addBindValue(username);
           query.addBindValue(password);
            query.exec();

              if(query.next())

              {
                  QMessageBox::information(nullptr, QObject::tr("LOGIN"),
                                                      QObject::tr("\nvous avez connecté avec succès !\n"), QMessageBox::Ok);



                  ui->stackedWidget->setCurrentIndex(2);

               }
                    else
                       { QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                                    QObject::tr("\nvotre mot de passe ou votre nom est incorrect !\n"), QMessageBox::Cancel);
               ui->username->setStyleSheet("border: 1px solid red");
               ui->password->setStyleSheet("border: 1px solid red");

              ui->username->clear();
              ui->password->clear();}

      }
      else
      { QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                                  QObject::tr("\n votre mot passe doit etre entre \n"
                                              "6 et 21 characteres"), QMessageBox::Cancel);
          ui->password->setStyleSheet("border: 1px solid red");
      }
  }

  else
     {  QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                  QObject::tr("\n username doit etre entre \n"
                              "4 et 10 characteres"), QMessageBox::Cancel);
      ui->username->setStyleSheet("border: 1px solid red");
  }
}

else {

                    QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                                QObject::tr("\n remplir les champs avec les informations correctes\n"), QMessageBox::Cancel);
                    ui->username->setStyleSheet("border: 1px solid red" );
                    ui->password->setStyleSheet("border: 1px solid red");

}
}


void journaliste_mission::on_signupbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void journaliste_mission::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void journaliste_mission::on_completeRegButton_clicked()
{
    QString username= ui->usernamesign->text();
    QString password= ui->motpasse->text();
    QString nom= ui->nomsign->text();
    QString prenom= ui->prenomsign->text();


    if(ui->username->text().isEmpty()||username.size()>21){


        ui->usernamesign->setStyleSheet("border: 1px solid red ");
         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP  USERNAME!!!!") ;
          QToolTip::showText(ui->usernamesign->mapToGlobal(QPoint(100,0)), tr("username doit etre entre 0 et 20 charactere"));
    }
    else if(prenom.isEmpty()||prenom.size()>21){

            ui->prenomsign->setStyleSheet("border: 1px solid red ");
             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP PRENOM!!!!") ;
             QToolTip::showText(ui->prenomsign->mapToGlobal(QPoint(100,0)), tr("prenom doit etre entre 0 et 20 charactere"));

        }

    else if(password.isEmpty()||password.size()>21){

            ui->password->setStyleSheet("border: 1px solid red ");
             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP PASSWORD!!!!") ;
             QToolTip::showText(ui->password->mapToGlobal(QPoint(100,0)), tr("PASSWORD doit etre entre 0 et 20 charactere"));


        }

    else if(nom.isEmpty()||nom.size()>21){

            ui->nomsign->setStyleSheet("border: 1px solid red ");
             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP NOM!!!!") ;
             QToolTip::showText(ui->nomsign->mapToGlobal(QPoint(100,0)), tr("NOM doit etre entre 0 et 20 charactere"));

        }
    else {

    account e(username,password,nom,prenom);
    bool test=e.ajouter();
    if(test)
  {
        //refresh
           // ui->comboBox->setModel(tmpmatch.afficher_list());
  QMessageBox::information(nullptr, QObject::tr("Ajouter account"),
                    QObject::tr("account ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
  ui->stackedWidget->setCurrentIndex(0);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter account"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->usernamesign->clear();
    ui->motpasse->clear();
    ui->nomsign->clear();
    ui->prenomsign->clear();

}}







void journaliste_mission::on_pb_ajouter_3_clicked()
{        audio.play();


    int id_mission = ui->id_mission->text().toInt();
    QString libelle= ui->libelle->text();
    QString description=ui->description->text();
    QString confidentialite=ui->confidentialite->text();




     if (ui->id_mission->text().isEmpty())
      {


         ui->id_mission->setStyleSheet("border: 1px solid red ");
          QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;
          QToolTip::showText(ui->id_mission->mapToGlobal(QPoint(100,0)), tr("INSERT ID"));
     }else if(ui->libelle->text().isEmpty()||libelle.size()>21){


         ui->libelle->setStyleSheet("border: 1px solid red ");
          QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP  LIBELLE!!!!") ;
           QToolTip::showText(ui->libelle->mapToGlobal(QPoint(100,0)), tr("LIBELLE doit etre entre 0 et 20 charactere"));
     }
     else if(description.isEmpty()||description.size()>21){

             ui->description->setStyleSheet("border: 1px solid red ");
              QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP DESCRIPTION!!!!") ;
              QToolTip::showText(ui->description->mapToGlobal(QPoint(100,0)), tr("description doit etre entre 0 et 20 charactere"));

         }

     else if(confidentialite.isEmpty()||confidentialite.size()>21){

             ui->confidentialite->setStyleSheet("border: 1px solid red ");
              QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP confidentialite!!!!") ;
              QToolTip::showText(ui->confidentialite->mapToGlobal(QPoint(100,0)), tr("confidentialite doit etre entre 0 et 20 charactere"));


         }


     else {








  missions m(id_mission,libelle,description,confidentialite);
  bool test=m.ajouter();
  if(test)
{

QMessageBox::information(nullptr, QObject::tr("Ajouter mission "),
                  QObject::tr("mission ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_journaliste_3->setModel(a->afficher());
ui->id_mission->setStyleSheet("border: 1px solid blue ");
ui->libelle->setStyleSheet("border: 1px solid blue ");
ui->description->setStyleSheet("border: 1px solid blue ");
ui->confidentialite->setStyleSheet("border: 1px solid blue ");

}
  else

      QMessageBox::critical(nullptr, QObject::tr("Ajouter mission"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tab_journaliste_3->setModel(a->afficher());
}}

void journaliste_mission::on_modifierp_3_clicked()
{        audio.play();


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
{        audio.play();


    int id_mission = ui->id_miss_mod->text().toInt();
     if (ui->id_miss_mod->text().isEmpty())
      {

         QToolTip::showText(ui->id_miss_mod->mapToGlobal(QPoint(100,0)), tr("INSERT ID"));
         ui->id_miss_mod->setStyleSheet("border: 1px solid red ");
          QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;

      }
     else {
        bool test=s->supprimer(id_mission);
        if(test)
        {
            ui->tab_journaliste_3->setModel(a->afficher());

            QMessageBox::information(nullptr, QObject::tr("Supprimer mission"),
                        QObject::tr("mission supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->id_miss_mod->setStyleSheet("border: 1px solid blue ");

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer mission"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_journaliste_3->setModel(a->afficher());
}}

void journaliste_mission::on_afficherp_3_clicked()
{        audio.play();


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
{        audio.play();


    QString libelle= ui->id_rechercher_3->text();


     if (ui->id_rechercher_3->text().isEmpty())
      {

         QToolTip::showText(ui->id_rechercher_3->mapToGlobal(QPoint(100,0)), tr("INSERT LIBELLE"));
         ui->id_rechercher_3->setStyleSheet("border: 1px solid red ");
          QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP LIBELLE!!!!") ;

      }
     else {

    ui->recherche_tab_3->setModel(b->rechercher(libelle));
    ui->id_rechercher_3->setStyleSheet("border: 1px solid blue ");

    ui->tab_journaliste_3->setModel(a->afficher());
}}

void journaliste_mission::on_pdf_p_3_clicked()
{        audio.play();


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
{        audio.play();


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
{        audio.play();


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




void journaliste_mission::on_pushButton_clicked()
{
    bool test=true;


    if (ui->mail->text().isEmpty())
     {

        QToolTip::showText(ui->mail->mapToGlobal(QPoint(100,0)), tr("INSERT MAIL"));
        ui->mail->setStyleSheet("border: 1px solid red ");
         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP MAIL!!!!") ;

     }
    else {


        QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
        mailREX.setCaseSensitivity(Qt::CaseInsensitive);
        mailREX.setPatternSyntax(QRegExp::RegExp);
        qDebug() << mailREX.exactMatch("me@me.com");

        if(!mailREX.exactMatch(ui->mail->text()))
        {

            ui->mail->setStyleSheet("border: 1px solid red ");
             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP MAIL!!!!") ;
             QToolTip::showText(ui->mail->mapToGlobal(QPoint(100,0)), tr("MAUVAISE MAIL FORMAT"));

           test=false;
        }
    }
    if (ui->objet->text().isEmpty()){

        ui->objet->setStyleSheet("border: 1px solid red ");
         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP OBJET!!!!") ;
        QToolTip::showText(ui->objet->mapToGlobal(QPoint(100,0)), tr("INSERT OBJET"));
    }
    if (ui->message->text().isEmpty()){

        ui->message->setStyleSheet("border: 1px solid red ");
         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP MESSAGE!!!!") ;
        QToolTip::showText(ui->message->mapToGlobal(QPoint(100,0)), tr("INSERT MESSAGE"));
    }
    if(test==true){
        ui->mail->setStyleSheet("border: 1px solid blue ");
        ui->objet->setStyleSheet("border: 1px solid blue ");
        ui->message->setStyleSheet("border: 1px solid blue ");

    Smtp* smtp;
        smtp = new Smtp("Smartnewsagency1@gmail.com", "SMARTNEWSAGENCY", "smtp.gmail.com");
        //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

        smtp->sendMail(ui->mail->text(), ui->mail->text() ,ui->objet->text(), ui->message->text());

}}



void journaliste_mission::updateQRImage()
{
    int sizeText = ui->pTextEditQRText->toPlainText().size();
    ui->labelSizeText->setText( QString::number( sizeText ) );

    int levelIndex = 1;
    int versionIndex = 0;
    bool bExtent = true;
    int maskIndex = -1;
    QString encodeString = ui->pTextEditQRText->toPlainText();

    successfulEncoding = qrEncode.EncodeData( levelIndex, versionIndex, bExtent, maskIndex, encodeString.toUtf8().data() );
    if ( !successfulEncoding )
    {
        ui->image_label->clear();
        ui->image_label->setText( tr("QR Code...") );
        ui->labelSize->clear();
        ui->pButtonSave->setEnabled( successfulEncoding );
        return;
    }

    int qrImageSize = qrEncode.m_nSymbleSize;

    // Создаем двумерный образ кода
    encodeImageSize = qrImageSize + ( QR_MARGIN * 2 );
    QImage encodeImage( encodeImageSize, encodeImageSize, QImage::Format_Mono );
    encodeImage.fill( 1 );

    // Создать двумерный образ кода
    for ( int i = 0; i < qrImageSize; i++ )
        for ( int j = 0; j < qrImageSize; j++ )
            if ( qrEncode.m_byModuleData[i][j] )
                encodeImage.setPixel( i + QR_MARGIN, j + QR_MARGIN, 0 );

    ui->image_label->setPixmap( QPixmap::fromImage( encodeImage ) );

    setScale(ui->sBoxScale->value());
    ui->pButtonSave->setEnabled( successfulEncoding );
}
void journaliste_mission::setScale(int scale)
{
    if ( successfulEncoding )
    {
        int scale_size = encodeImageSize * scale;

        const QPixmap & scale_image = ui->image_label->pixmap()->scaled( scale_size, scale_size );
        ui->image_label->setPixmap( scale_image );

        const QString & size_info = QString( "%1x%2" ).arg( scale_size ).arg( scale_size );
        ui->labelSize->setText( size_info );
    }
}
void journaliste_mission::on_pButtonSave_clicked()
{
    const QString & path = QFileDialog::getSaveFileName( this, QString::null, "qrcode", saveFormats() );
    if ( path.isNull() )
        return;

    ui->image_label->pixmap()->save( path );
}
void journaliste_mission::on_sBoxScale_valueChanged(int arg1)
{
    setScale( arg1 );
}
void journaliste_mission::on_pTextEditQRText_textChanged()
{
    updateQRImage();
}
void journaliste_mission::on_pButtonQuit_clicked()
{
    close();
}

void journaliste_mission::closeEvent(QCloseEvent *)
{
    QSettings ini( getIniPath(), QSettings::IniFormat );
    ini.setValue( ui->splitter->objectName(), ui->splitter->saveState() );
    ini.setValue( ui->splitter_2->objectName(), ui->splitter_2->saveState() );
    ini.setValue( ui->sBoxScale->objectName(), ui->sBoxScale->value() );
  //  ini.setValue( "State", saveState() );
    ini.setValue( "Geometry", saveGeometry() );

    qApp->quit();
}
bool journaliste_mission::eventFilter( QObject * object, QEvent * event )
{
    QScrollArea * scrollArea = ui->scrollArea;

    if ( object == scrollArea )
    {
        if ( event->type() == QEvent::MouseButtonPress )
        {
            QMouseEvent * mouseEvent = static_cast < QMouseEvent * > ( event );
            if ( mouseEvent->button() == Qt::LeftButton )
            {
                lastPos = mouseEvent->pos();

                if( scrollArea->horizontalScrollBar()->isVisible()
                        || scrollArea->verticalScrollBar()->isVisible() )
                    scrollArea->setCursor( Qt::ClosedHandCursor );
                else
                    scrollArea->setCursor( Qt::ArrowCursor );
            }

        }else if ( event->type() == QEvent::MouseMove )
        {
            QMouseEvent *mouseEvent = static_cast < QMouseEvent * > ( event );

            if ( mouseEvent->buttons() == Qt::LeftButton )
            {
                lastPos -= mouseEvent->pos();

                int hValue = scrollArea->horizontalScrollBar()->value();
                int vValue = scrollArea->verticalScrollBar()->value();

                scrollArea->horizontalScrollBar()->setValue( lastPos.x() + hValue );
                scrollArea->verticalScrollBar()->setValue( lastPos.y() + vValue );

                lastPos = mouseEvent->pos();
            }

        }else if ( event->type() == QEvent::MouseButtonRelease )
            scrollArea->setCursor( Qt::ArrowCursor );
    }

    return QWidget::eventFilter(object, event);
}

void journaliste_mission::on_calendarWidget_clicked(const QDate &date)
{
    *currdate = date.toString("yyyy.MM.dd");
    //QTextStream out(stdout);
    //out << QString(date.toString("yyyy.MM.dd"));
    ui->checkBox_3->setChecked(0);
    QString fname = "files/"+*currdate;
    //out << fname;
    QFile file(fname);

    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream ReadFile(&file);
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->setPlainText(ReadFile.readAll());
    file.close();
}

void journaliste_mission::on_pushButton_2_clicked()
{
     QCoreApplication::exit();
}

void journaliste_mission::on_actionExit_triggered()
{
    QCoreApplication::exit();
}

void journaliste_mission::on_plainTextEdit_textChanged()
{

}

void journaliste_mission::on_push_clicked()
{
    QString fname = "files/"+*currdate;
    QFile file(fname);

    file.open(QFile::ReadWrite | QFile::Text);

    QTextStream OutFile(&file);
    QString text = ui->plainTextEdit->toPlainText();
    OutFile << text;

    file.close();
}



void journaliste_mission::on_checkBox_3_clicked(bool checked)
{
    if(checked)
        ui->plainTextEdit->setReadOnly(false);
    else
        ui->plainTextEdit->setReadOnly(true);
}

void journaliste_mission::on_actionSave_triggered()
{
    QString fname = "files/"+*currdate;
    QFile file(fname);

    file.open(QFile::ReadWrite | QFile::Text);

    QTextStream OutFile(&file);
    QString text = ui->plainTextEdit->toPlainText();
    OutFile << text;

    file.close();
}





void journaliste_mission::on_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                        tr("Fichiers d'extension Excel (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->tab_journaliste_2);

        // you can change the column order and
        // choose which colum to export
        obj.addField(0, "Nom", "char(20)");
        obj.addField(1, "Nom", "char(20)");
        obj.addField(2, "prenom", "char(20)");
        obj.addField(3, "fonction", "char(20)");
        obj.addField(4, "diplome", "char(20)");


        int retVal = obj.export2Excel();

        if( retVal > 0)
        {
            QMessageBox::information(this, tr("FAIS!"),
                                     QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                     );
        }
}





void journaliste_mission::on_makeShot_clicked()
{
    this->hide();
    qApp->processEvents();
#ifdef _WIN32
    Sleep(3000);
#else
    Kek::wait(200);
#endif

    QPixmap okno = QPixmap::grabWindow(QApplication::desktop()->winId());
    QDateTime t = QDateTime::currentDateTime();
    QString saveWhere = qApp->applicationDirPath() + QString("/Scr_%1-%2-%3-%4-%5-%6.png")
            .arg(t.date().year()).arg(t.date().month()).arg(t.date().day())
            .arg(t.time().hour()).arg(t.time().minute()).arg(t.time().second());
    QString saveAs = QFileDialog::getSaveFileName(NULL, "Save screenshot as...",
                                                  saveWhere,
                                                  "PNG Picture (*.png)",
                                                  nullptr,
                                                  QFileDialog::DontUseNativeDialog);
    if(!saveAs.isEmpty())
        okno.save(saveAs, "PNG");

    this->show();
}


void journaliste_mission::on_qrcode_clicked()
{
    int tabev=ui->tab_journaliste_2->currentIndex().row();
    QVariant idd=ui->tab_journaliste_2->model()->data(ui->tab_journaliste_2->model()->index(tabev,0));
    QString id= idd.toString();
    QSqlQuery qry;
    qry.prepare("select * from journaliste where id=:id");
    qry.bindValue(":id",id);
    qry.exec();
    QString nom,prenom,fonction,diplome,ids;
    while(qry.next()){
        nom=qry.value(1).toString();
        prenom=qry.value(2).toString();
        diplome=qry.value(3).toString();
        fonction=qry.value(4).toString();
    }
    ids=QString(id);
    ids="ID: "+ids+" Nom: "+nom+" prenom: "+prenom+" fonction: "+fonction+" diplome : "+diplome;
    QrCode qr = QrCode::encodeText(ids.toUtf8().constData(), QrCode::Ecc::HIGH);

    // Read the black & white pixels
    QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            int color = qr.getModule(x, y);  // 0 for white, 1 for black

            // You need to modify this part
            if(color==0)
                im.setPixel(x, y,qRgb(254, 254, 254));
            else
                im.setPixel(x, y,qRgb(0, 0, 0));
        }
    }
    im=im.scaled(100,100);
    ui->label_21->setPixmap(QPixmap::fromImage(im));
    int i=0 ;
    for(i=0;i<100;i=i+0.1){
        i++;
    }
}


void journaliste_mission::on_saveit_clicked()
{
    const QString & path = QFileDialog::getSaveFileName( this, QString::null, "qrcode", saveFormats() );
    if ( path.isNull() )
        return;
    ui->label_21->pixmap()->save( path );

}

void journaliste_mission::open()
{
    QString path = QFileDialog::getOpenFileName( this, QString::null, QString::null, getFilter() );
    if ( path.isEmpty() )
        return;

    ui->labelQRCodeImage->setPixmap( QPixmap( path ) );
    decode();
}
void journaliste_mission::decode()
{
    QImage qrImage = ui->labelQRCodeImage->pixmap()->toImage();
    const QString & decodeText = zxing.decodeImage( qrImage );

    ui->pTextEditQRCodeText->setPlainText( decodeText );
    ui->labelSizeText->setText( QString::number( decodeText.size() ) );
}
void journaliste_mission::on_pButtonOpen_clicked()
{
    open();
}
void journaliste_mission::dragEnterEvent( QDragEnterEvent * event )
{
    const QMimeData * mime = event->mimeData();
    const QList < QUrl > & urls = mime->urls();

    // С QString удобнее работать, чем с QByteArray
    QStringList formats;
    foreach ( const QByteArray & format, QImageReader::supportedImageFormats() )
        formats += format;

    // Будем принимать только один файл и то читабельного формата
    if ( urls.size() == 1 )
    {
        const QString & path = urls.first().toLocalFile();
        const QString & suffix = QFileInfo( path ).suffix();

        // если формат принимаемого файла есть в списке
        if( formats.contains( suffix, Qt::CaseInsensitive ) )
            event->acceptProposedAction();
    }
}
void journaliste_mission::dropEvent( QDropEvent * event )
{
    const QMimeData * mime = event->mimeData();
    const QList < QUrl > & urls = mime->urls();

    QString path = urls.first().toLocalFile();
    ui->labelQRCodeImage->setPixmap( QPixmap( path ) );

    decode();
}


bool journaliste_mission::eventFilterscanner(QObject *object, QEvent *event)
{
    QScrollArea * scrollArea = ui->scrollArea_2;
    if ( object == scrollArea )
    {
        if ( event->type() == QEvent::MouseButtonPress )
        {
            QMouseEvent * mouseEvent = static_cast < QMouseEvent * > ( event );
            if ( mouseEvent->button() == Qt::LeftButton )
            {
                lastPos = mouseEvent->pos();

                if( scrollArea->horizontalScrollBar()->isVisible() || scrollArea->verticalScrollBar()->isVisible() )
                    scrollArea->setCursor( Qt::ClosedHandCursor );
                else
                    scrollArea->setCursor( Qt::ArrowCursor );
            }

        }else if ( event->type() == QEvent::MouseMove )
        {
            QMouseEvent *mouseEvent = static_cast < QMouseEvent * > ( event );

            if ( mouseEvent->buttons() == Qt::LeftButton )
            {
                lastPos -= mouseEvent->pos();

                int hValue = scrollArea->horizontalScrollBar()->value();
                int vValue = scrollArea->verticalScrollBar()->value();

                scrollArea->horizontalScrollBar()->setValue( lastPos.x() + hValue );
                scrollArea->verticalScrollBar()->setValue( lastPos.y() + vValue );

                lastPos = mouseEvent->pos();
            }

        }else if ( event->type() == QEvent::MouseButtonRelease )
            scrollArea->setCursor( Qt::ArrowCursor );
    }

    return QWidget::eventFilter(object, event);
}



void journaliste_mission::on_add_to_list_clicked()
{
    if(ui->item_text->text() != ""){
        QListWidgetItem* temp_check_list_item = new QListWidgetItem(ui->item_text->text());
        temp_check_list_item->setFlags(temp_check_list_item->flags() | Qt::ItemIsUserCheckable);
        temp_check_list_item->setCheckState(Qt::Unchecked);
        ui->list_items->insertItem(0, temp_check_list_item);
        ui->item_text->setText("");
    }
}

void journaliste_mission::on_list_items_itemChanged(QListWidgetItem *item)
{
    bool checked = item->checkState() == Qt::Checked;

    if(checked){
        int current_row = ui->list_items->row(item);
        ui->list_items->takeItem(current_row);
        //item->setBackgroundColor(checked_color);
        ui->list_items->addItem(item);
    }else{
        int current_row = ui->list_items->row(item);
        ui->list_items->takeItem(current_row);
      //  item->setBackgroundColor(unchecked_color);
        ui->list_items->insertItem(0, item);
    }
}

void journaliste_mission::on_item_text_returnPressed()
{
    on_add_to_list_clicked();
}

void journaliste_mission::on_move_item_up_clicked()
{
    QList<QListWidgetItem*> items = ui->list_items->selectedItems();
    foreach (QListWidgetItem* item, items) {
        bool checked = item->checkState() == Qt::Checked;
        if(!checked){
            int current_row = ui->list_items->row(item);
            ui->list_items->takeItem(current_row);
            ui->list_items->insertItem(current_row-1, item);
            item->setSelected(true);
        }
    }
}

void journaliste_mission::on_move_item_down_clicked()
{
    QList<QListWidgetItem*> items = ui->list_items->selectedItems();
    foreach (QListWidgetItem* item, items) {
        bool checked = item->checkState() == Qt::Checked;
        if(!checked){
            int current_row = ui->list_items->row(item);
            ui->list_items->takeItem(current_row);
            ui->list_items->insertItem(current_row+1, item);
            item->setSelected(true);
        }
    }
}

void journaliste_mission::on_delete_item_clicked()
{
    QList<QListWidgetItem*> items = ui->list_items->selectedItems();
    foreach (QListWidgetItem* item, items) {
        int current_row = ui->list_items->row(item);
        QListWidgetItem* remove_item = ui->list_items->takeItem(current_row);
        delete remove_item;
    }
}

void journaliste_mission::on_musicNext_clicked()
{

    int length = sizeof(songsList) / sizeof(songsList[0]);
    currentSong = (currentSong + 1)%length;
    musicPlayer->setMedia(QUrl("qrc:/" + songsList[currentSong]));
    musicPlayer->play();

}

void journaliste_mission::on_musicPlay_clicked()
{

    musicPlayer->play();
    ui->musicStop->setVisible(true);
    ui->musicPlay->setVisible(false);

}

void journaliste_mission::on_musicBack_clicked()
{
    int length = sizeof(songsList) / sizeof(songsList[0]);

    currentSong = (currentSong - 1);
    if(currentSong<0)
    {
        currentSong = length-1;
    }
    musicPlayer->setMedia(QUrl("qrc:/music/" + songsList[currentSong]));
    musicPlayer->play();
}

void journaliste_mission::on_musicStop_clicked()
{
    musicPlayer->pause();
    ui->musicStop->setVisible(false);
    ui->musicPlay->setVisible(true);
}
QString journaliste_mission::getTime()
{
    ostringstream ss;
    time_t now = time(0);
    tm *lt = localtime(&now); // local time

    int hour = lt->tm_hour;
    int min = lt->tm_min;

    if(hour > 12) {
        hour -= 12;
    }

    if(min < 10) {
        ss << hour << ":0" << min;

    }
    else {
        ss << hour << ":" << min;
    }

    return QString::fromStdString(ss.str());
}
void journaliste_mission::timerEvent(QTimerEvent *event)
{
    QString time;
    event->accept();

    time = getTime();
    ui->clock->display(time);}





void journaliste_mission::on_googlesearch_clicked()
{
    search.show();
}
