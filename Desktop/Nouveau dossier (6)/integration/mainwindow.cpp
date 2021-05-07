
//****includet skandeer***//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "article.h"
#include "statistique.h"
#include "historique.h"
#include "exportexcelobjet.h"
#include "QPainter"
#include "QPdfWriter"
#include "QtPrintSupport/QPrinter"
#include"qsqlquery.h"
#include "qobject.h"
#include "qsqlerror.h"
#include"QIntValidator"
#include"qcoreapplication.h"
#include"qdebug.h"
#include "smtp.h"
#include <QFileDialog>
#include "qrcode.h"
#include <QImageWriter>
#include"qmainwindow.h"
#include"mainwindow.h"
#include <QMediaPlayer>
#include <QtCharts/QChartView>
#include <QtCharts/qlineseries.h>
#include <QtCharts/QBarSet>
#include "qsqlquery.h"
#include "aaa.hpp"
//include amine//
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
#include"qmainwindow.h"
#include"missions.h"
#include"mainwindow.h"
#include <QPropertyAnimation>
#include <QDesktopServices>
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
#include <QIntValidator>
#include <QSound>
#include <QTimerEvent>
#include <ctime>
#include <sstream>
#include "statistiques.h"
#include"historiques.h"
#include <QComboBox>

using namespace std;
using namespace qrcodegen;
double firstNum;
bool user_is_typing_secondNumber=false;
const QString gsearchUrl = QStringLiteral("http://www.google.com/search?q=%1");



int timer = 0; // Event Timer
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
  successfulEncoding(false),  successfulEncoding2(false)


{currdate = new QString();
    QString windowTitle("newsgenix");
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    ui->scrollArea_5->installEventFilter( this );


    QTimer *timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
        timer->start();

    click = new QMediaPlayer();
            click->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Nouveau dossier (6)/integration/img_mus/click.mp3"));
            QDateTime Date_p=QDateTime::currentDateTime();
            QString Date_txt=Date_p.toString("dddd dd MMMM yyyy");
            ui->DigitalClock_2->setText(Date_txt);
            ui->DigitalClock_4->setText(Date_txt);
            /*Article A;
            A.statistique(ui->widget);*/


             zxing.setDecoder( QZXing::DecoderFormat_QR_CODE );

            QSettings ini2( getIniPath(), QSettings::IniFormat );
            ui->splitter_8->restoreState( ini2.value( ui->splitter_8->objectName() ).toByteArray() );
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
                    ui->splitter_8->restoreState( ini.value( ui->splitter_8->objectName() ).toByteArray() );
                    ui->splitter_9->restoreState( ini.value( ui->splitter_9->objectName() ).toByteArray() );
                    ui->sBoxScale->setValue( ini.value( ui->sBoxScale->objectName(), 4 ).toInt() );
                   // restorestate( ini.value( "State" ).toByteArray() );
                    restoreGeometry( ini.value( "Geometry" ).toByteArray() );

                    setScale( ui->sBoxScale_4->value() );
                    updateQRImage2();





                       //ui->id->setValidator( new QIntValidator(0, 999999999, this));
                       //ui->id_mission_2->setValidator( new QIntValidator(0, 999999999, this));



                          if(autoPlay)
                          {

                              musicPlayer->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Nouveau dossier (6)/integration/img_mus/" + songsList[currentSong]));
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


                          ui->tarif_publicitesahar->setValidator(new QIntValidator(1, 999999, this));
                          ui->tarif_publicite_2sahar->setValidator(new QIntValidator(1, 999999, this));
                          ui->id_publicite_2sahar->setValidator(new QIntValidator(1, 999999, this));
                         ui->id_3sahar->setValidator(new QIntValidator(1, 999999, this));
                          ui->id_publicitesahar->setValidator(new QIntValidator(1,999999, this));
                          ui->id_clientsahar->setValidator(new QIntValidator(1, 999999, this));
                          ui->id_client_2sahar->setValidator(new QIntValidator(1, 999999, this));
                          ui->id_sponsorsahar->setValidator(new QIntValidator(1, 999999, this));
                          ui->id_sponsor_2sahar->setValidator(new QIntValidator(1, 999999, this));
                          ui->id_sponsor_3sahar->setValidator(new QIntValidator(1, 999999, this));


        /******************************emnnaaaaaaaaaaa***************************/

                          connect(ui->pushButton_0emna,SIGNAL(released()),this,SLOT(digit_pressed()));
                          connect(ui->pushButton_1emna,SIGNAL(released()),this,SLOT(digit_pressed()));
                          connect(ui->pushButton_2emna,SIGNAL(released()),this,SLOT(digit_pressed()));
                          connect(ui->pushButton_3emna,SIGNAL(released()),this,SLOT(digit_pressed()));
                          connect(ui->pushButton_4emna,SIGNAL(released()),this,SLOT(digit_pressed()));
                          connect(ui->pushButton_5emna,SIGNAL(released()),this,SLOT(digit_pressed()));
                          connect(ui->pushButton_6emna,SIGNAL(released()),this,SLOT(digit_pressed()));
                          connect(ui->pushButton_7emna,SIGNAL(released()),this,SLOT(digit_pressed()));
                          connect(ui->pushButton_8emna,SIGNAL(released()),this,SLOT(digit_pressed()));
                          connect(ui->pushButton_9emna,SIGNAL(released()),this,SLOT(digit_pressed()));

                          connect(ui->pushButton_plusMinus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
                          connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

                          connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
                          connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
                          connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
                          connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

                          ui->pushButton_add->setCheckable(true);
                          ui->pushButton_multiply->setCheckable(true);
                          ui->pushButton_divide->setCheckable(true);
                          ui->pushButton_minus->setCheckable(true);
                          //setFixedSize( 241,366);
                          connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{

        click->play();
        qDebug()<<click ->errorString();
        int id_Article = ui->le_ID->text().toInt();
        QString libelle_Article= ui->le_libelle->text();
        QString description_Article=ui->la_description->text();
        int nbre_page=ui->le_nbredepage->text().toInt();
        int priorite=ui->la_priorite->currentText().toInt();
        QString format=ui->le_format->text();

      Article a(id_Article,libelle_Article,description_Article,nbre_page,priorite,format);
      bool test=a.ajouter();
      if(test)
    {

    QMessageBox::information(nullptr, QObject::tr("Ajouter un article"),
                      QObject::tr("article ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_article->setModel(s->afficher());
    Smtp* smtp;
        smtp = new Smtp("smartnewsagency1@gmail.com", "SMARTNEWSAGENCY", "smtp.gmail.com");
        //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

        smtp->sendMail("smartnewsagency1@gmail.com", "smartnewsagency1@gmail.com" , "Mail d'ajout","Bonjour,\n Votre article a été ajouté avec succée. \nCordialement ");

    }
      else

          QMessageBox::critical(nullptr, QObject::tr("Ajouter un article"),
                      QObject::tr("Erreur !\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      if (ui->le_ID->text().isEmpty())
           {
               QToolTip::showText(ui->le_ID->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
               ui->le_ID->setStyleSheet("border: 1px solid red ");
      }
      if (ui->le_libelle->text().isEmpty())
           {
               QToolTip::showText(ui->le_libelle->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
               ui->le_libelle->setStyleSheet("border: 1px solid red ");
      }
      if (ui->la_description->text().isEmpty())
           {
               QToolTip::showText(ui->la_description->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
               ui->la_description->setStyleSheet("border: 1px solid red ");
      }
      if (ui->le_nbredepage->text().isEmpty())
           {
               QToolTip::showText(ui->le_nbredepage->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
               ui->le_nbredepage->setStyleSheet("border: 1px solid red ");
      }
      if (ui->le_format->text().isEmpty())
           {
               QToolTip::showText(ui->le_format->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
               ui->le_format->setStyleSheet("border: 1px solid red ");
      }
      ui->tab_article->setModel(s->afficher());
      QString textajouter;
      int k=id_Article;
      historique h;
      QSqlQuery qry;
      qry.prepare("select * from article");
      textajouter="L'ajout d'un article a la base de donnees de reference = "+QString::number(k)+" a ete effectue avec succees";
      h.write(textajouter);

    }

void MainWindow::on_modifier_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_Article = ui->le_ID_2->text().toInt();
    QString libelle_Article= ui->le_libelle_2->text();
    QString description_Article=ui->la_description_2->text();
    int nbre_page=ui->le_nbredepage_2->text().toInt();
    int priorite=ui->la_priorite_2->text().toInt();
    QString format=ui->le_format_2->text();


          Article j(id_Article,libelle_Article,description_Article,nbre_page,priorite,format);

             bool test =j.modifier();

             if(test)

             {
                 QMessageBox::information(nullptr, QObject::tr("Modifier un article"),
                             QObject::tr("article modifiée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_article->setModel(s->afficher());

             }

             else

             {
                 QMessageBox::critical(nullptr, QObject::tr("modifier un article"),
                             QObject::tr("Erreur !\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_article->setModel(s->afficher());

             }
             if (ui->le_ID_2->text().isEmpty())
                  {
                      QToolTip::showText(ui->le_ID_2->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
                      ui->le_ID_2->setStyleSheet("border: 1px solid red ");
             }
             if (ui->le_libelle_2->text().isEmpty())
                  {
                      QToolTip::showText(ui->le_libelle_2->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
                      ui->le_libelle_2->setStyleSheet("border: 1px solid red ");
             }
             if (ui->la_description_2->text().isEmpty())
                  {
                      QToolTip::showText(ui->la_description_2->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
                      ui->la_description_2->setStyleSheet("border: 1px solid red ");
             }
             if (ui->le_nbredepage_2->text().isEmpty())
                  {
                      QToolTip::showText(ui->le_nbredepage_2->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
                      ui->le_nbredepage_2->setStyleSheet("border: 1px solid red ");
             }
             if (ui->la_priorite_2->text().isEmpty())
                  {
                      QToolTip::showText(ui->la_priorite_2->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
                      ui->la_priorite_2->setStyleSheet("border: 1px solid red ");}
             if (ui->le_format_2->text().isEmpty())
                  {
                      QToolTip::showText(ui->le_format_2->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
                      ui->le_format_2->setStyleSheet("border: 1px solid red ");
             }
             QString textajouter;
             int k=id_Article;
             historique h;
             QSqlQuery qry;
             qry.prepare("select * from article");
             textajouter="La modification d'un article a la base de donnees de reference = "+QString::number(k)+" a ete effectue avec succees";
             h.write(textajouter);
}
void MainWindow::on_afficher_s_clicked()
{click->play();
    qDebug()<<click ->errorString();
    ui->tab_article->setModel(s->afficher());
}


void MainWindow::on_supprimer_clicked()
{

    click->play();
    qDebug()<<click ->errorString();
    int id_Article = ui->le_ID_2->text().toInt();

        bool test=s->supprimer(id_Article);
        if(test)
        {
            ui->tab_article->setModel(s->afficher());

            QMessageBox::information(nullptr, QObject::tr("Supprimer un article"),
                        QObject::tr("article supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un article"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_article->setModel(s->afficher());
        QString textajouter;
        int k=id_Article;
        historique h;
        QSqlQuery qry;
        qry.prepare("select * from article");
        textajouter="La suppression d'un article a la base de donnees de reference = "+QString::number(k)+" a ete effectue avec succees";
        h.write(textajouter);
    }





void MainWindow::on_pushButton_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->tab_article->setModel(s->afficher());
    /*Article A;
    A.statistique(ui->widget);*/
}

void MainWindow::on_gestion_article_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_return_2_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_trier_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    bool test = s->tri_libelle();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des articles"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_article->setModel(s->tri_libelle());}//refresh
           else
           {QMessageBox::critical(nullptr, QObject::tr("tri des articles"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_article->setModel(s->tri_libelle());}//refresh
}

void MainWindow::on_recherche_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    QString libelle_Article= ui->libelle_rechercher->text();
    ui->resultat->setModel(s->rechercher(libelle_Article));
    ui->tab_article->setModel(s->afficher());
}

void MainWindow::on_pdf_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
        QPdfWriter pdf("C:/Users/user/Desktop/Nouveau dossier (6)/integration/pdfskander");
                                  QPainter painter(&pdf);
                                 int i = 4000;
                                      painter.setPen(Qt::red);
                                      painter.setFont(QFont("Arial", 30));
                                      painter.drawText(2300,1200,"Liste Des Articles");
                                      painter.setPen(Qt::black);
                                      painter.setFont(QFont("Arial", 50));
                                      //painter.drawText(1100,2000,afficheDC);
                                      painter.drawRect(1500,200,7300,2600);
                                      painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Asus/Desktop/qt_pdf/pdf_article"));
                                      painter.drawRect(0,3000,9600,500);
                                      painter.setFont(QFont("Arial", 9));
                                      painter.drawText(300,3300,"id_Article");
                                      painter.drawText(1800,3300,"libelle_Article");
                                      painter.drawText(3300,3300,"description_Article");
                                      painter.drawText(4800,3300,"nbre_page");
                                      painter.drawText(6300,3300,"priorite");
                                      painter.drawText(7800,3300,"format");




                                      QSqlQuery query;
                                      query.prepare("select * from article");
                                      query.exec();
                                      while (query.next())
                                      {
                                          painter.drawText(300,i,query.value(0).toString());
                                          painter.drawText(1800,i,query.value(1).toString());
                                          painter.drawText(3300,i,query.value(2).toString());
                                          painter.drawText(4800,i,query.value(3).toString());
                                          painter.drawText(6300,i,query.value(4).toString());
                                          painter.drawText(7800,i,query.value(5).toString());




                                         i = i +500;
                                      }
                                      qDebug()<<"le pdf a ete cree";
                                      QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
    }

void MainWindow::on_tab_article_activated(const QModelIndex &index)
{


        click->play();
        qDebug()<<click ->errorString();
        QString val=ui->tab_article->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from article where id_Article='"+val+"'or libelle_Article='"+val+"'or description_Article='"+val+"'or nbre_page='"+val+"'or priorite='"+val+"' or format='"+val+"'");

        if(query.exec())
        {

         while(query.next())
        {
                ui->le_ID_2->setText(query.value(0).toString());
                ui->le_libelle_2->setText(query.value(1).toString());
                ui->la_description_2->setText(query.value(2).toString());
                ui->le_nbredepage_2->setText(query.value(3).toString());
                ui->la_priorite_2->setText(query.value(4).toString());
                ui->le_format_2->setText(query.value(5).toString());

    }

      }
        else {
            QMessageBox::critical(nullptr, QObject::tr("article"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
       }



void MainWindow::on_gestion_categorie_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pb_ajouter_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_Categorie = ui->le_ID_5->text().toInt();
    QString libelle_Categorie= ui->le_libelle_5->text();
    QString description_Categorie=ui->la_description_5->text();
    QString type_Categorie=ui->le_type_5->text();

  Categorie c(id_Categorie,libelle_Categorie,description_Categorie,type_Categorie);
  bool test=c.ajouter_c();
  if(test)
{

QMessageBox::information(nullptr, QObject::tr("Ajouter une categorie"),
                  QObject::tr("categorie ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_categorie->setModel(h->afficher_c());
Smtp* smtp;
    smtp = new Smtp("smartnewsagency1@gmail.com", "SMARTNEWSAGENCY", "smtp.gmail.com");
    //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

    smtp->sendMail("smartnewsagency1@gmail.com", "smartnewsagency1@gmail.com" , "Mail d'ajout","Bonjour,\n Votre Commande a été ajoutée avec succée. \nCordialement ");
}
  else

      QMessageBox::critical(nullptr, QObject::tr("Ajouter une categorie"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  if (ui->le_ID_5->text().isEmpty())
  {
      QToolTip::showText(ui->le_ID_5->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
      ui->le_ID_5->setStyleSheet("border: 1px solid red ");
}
  if (ui->le_libelle_5->text().isEmpty())
  {
      QToolTip::showText(ui->le_libelle_5->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
      ui->le_libelle_5->setStyleSheet("border: 1px solid red ");
}
  if (ui->la_description_5->text().isEmpty())
  {
      QToolTip::showText(ui->la_description_5->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
      ui->la_description_5->setStyleSheet("border: 1px solid red ");
}
  if (ui->le_type_5->text().isEmpty())
  {
      QToolTip::showText(ui->le_type_5->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
      ui->le_type_5->setStyleSheet("border: 1px solid red ");
}
  ui->tab_categorie->setModel(h->afficher_c());
}

void MainWindow::on_pushButton_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->tab_categorie->setModel(h->afficher_c());
}

void MainWindow::on_modifier_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_Categorie = ui->le_ID_6->text().toInt();
    QString libelle_Categorie= ui->le_libelle_6->text();
    QString description_Categorie=ui->la_description_6->text();
    QString type_Categorie=ui->le_type_6->text();


          Categorie e(id_Categorie,libelle_Categorie,description_Categorie,type_Categorie);

             bool test =e.modifier_c();

             if(test)

             {
                 QMessageBox::information(nullptr, QObject::tr("Modifier une categorie"),
                             QObject::tr("categorie modifiée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_categorie->setModel(h->afficher_c());

             }

             else

             {
                 QMessageBox::critical(nullptr, QObject::tr("modifier une categorie"),
                             QObject::tr("Erreur !\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 if (ui->le_ID_6->text().isEmpty())
                 {
                     QToolTip::showText(ui->le_ID_6->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
                     ui->le_ID_6->setStyleSheet("border: 1px solid red ");
               }
                 if (ui->le_libelle_6->text().isEmpty())
                 {
                     QToolTip::showText(ui->le_libelle_6->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
                     ui->le_libelle_6->setStyleSheet("border: 1px solid red ");
               }
                 if (ui->la_description_6->text().isEmpty())
                 {
                     QToolTip::showText(ui->la_description_6->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
                     ui->la_description_6->setStyleSheet("border: 1px solid red ");
               }
                 if (ui->le_type_6->text().isEmpty())
                 {
                     QToolTip::showText(ui->le_type_6->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
                     ui->le_type_6->setStyleSheet("border: 1px solid red ");
               }
             ui->tab_categorie->setModel(h->afficher_c());

             }
}

void MainWindow::on_supprimer_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_Categorie = ui->le_ID_6->text().toInt();

        bool test=h->supprimer_c(id_Categorie);
        if(test)
        {
            ui->tab_categorie->setModel(h->afficher_c());

            QMessageBox::information(nullptr, QObject::tr("Supprimer une categorie"),
                        QObject::tr("article supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une categorie"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_categorie->setModel(h->afficher_c());

}

void MainWindow::on_trier_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    bool test = h->tri_libelle_c();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des categories"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_categorie->setModel(h->tri_libelle_c());}//refresh
           else
           {QMessageBox::critical(nullptr, QObject::tr("tri des categories"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_categorie->setModel(h->tri_libelle_c());}//refresh
}

void MainWindow::on_pdf_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
        QPdfWriter pdf("C:/Users/Asus/Desktop/qt_pdf/pdf_categorie");
                                  QPainter painter(&pdf);
                                 int i = 4000;
                                      painter.setPen(Qt::red);
                                      painter.setFont(QFont("Arial", 30));
                                      painter.drawText(2300,1200,"Liste Des categories");
                                      painter.setPen(Qt::black);
                                      painter.setFont(QFont("Arial", 50));
                                      //painter.drawText(1100,2000,afficheDC);
                                      painter.drawRect(1500,200,7300,2600);
                                      painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Asus/Desktop/qt_pdf/pdf_article"));
                                      painter.drawRect(0,3000,9600,500);
                                      painter.setFont(QFont("Arial", 9));
                                      painter.drawText(300,3300,"id_Categorie");
                                      painter.drawText(2800,3300,"libelle_Categorie");
                                      painter.drawText(5300,3300,"description_Categorie");
                                      painter.drawText(7800,3300,"type_Categorie");





                                      QSqlQuery query;
                                      query.prepare("select * from categorie");
                                      query.exec();
                                      while (query.next())
                                      {
                                          painter.drawText(300,i,query.value(0).toString());
                                          painter.drawText(2800,i,query.value(1).toString());
                                          painter.drawText(5300,i,query.value(2).toString());
                                          painter.drawText(7800,i,query.value(3).toString());




                                         i = i +500;
                                      }
                                      qDebug()<<"le pdf a ete cree";
                                      QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
    }

void MainWindow::on_recherche_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    QString libelle_Categorie= ui->libelle_rechercher_3->text();
    int id_Categorie= ui->ID_rechercher->text().toInt();
    ui->resultat_3->setModel(h->rechercher_c(libelle_Categorie,id_Categorie));
    ui->tab_categorie->setModel(h->afficher_c());
}

void MainWindow::on_tab_categorie_activated(const QModelIndex &index)
{
    click->play();
    qDebug()<<click ->errorString();
    QString val=ui->tab_categorie->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from categorie where id_Categorie='"+val+"'or libelle_Categorie='"+val+"'or description_Categorie='"+val+"'or type_Categorie='"+val+"'");

    if(query.exec())
    {

     while(query.next())
    {
            ui->le_ID_6->setText(query.value(0).toString());
            ui->le_libelle_6->setText(query.value(1).toString());
            ui->la_description_6->setText(query.value(2).toString());
            ui->le_type_6->setText(query.value(3).toString());

}

  }
    else {
        QMessageBox::critical(nullptr, QObject::tr("categorie"),
                    QObject::tr("Erreur !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_return_4_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_trier2_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    bool test = s->tri_id();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des articles"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_article->setModel(s->tri_id());}//refresh
           else
           {QMessageBox::critical(nullptr, QObject::tr("tri des articles"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_article->setModel(s->tri_id());}//refresh
}

void MainWindow::on_trier2_2_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    bool test = h->tri_id_c();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des categories"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_categorie->setModel(h->tri_id_c());}//refresh
           else
           {QMessageBox::critical(nullptr, QObject::tr("tri des categories"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_categorie->setModel(h->tri_id_c());}//refresh
}

void MainWindow::on_mailing_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    Smtp* smtp;
        smtp = new Smtp("smartnewsagency1@gmail.com", "SMARTNEWSAGENCY", "smtp.gmail.com");
        //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

        smtp->sendMail("smartnewsagency1@gmail.com", "smartnewsagency1@gmail.com" , "test","test ");
        qDebug()<<"mail a été envoyé";
        QMessageBox::information(this,"mail envoyé","mail a ete envoyé");
}




void MainWindow::updateQRImage()
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
void MainWindow::setScale(int scale)
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
void MainWindow::on_pButtonSave_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    const QString & path = QFileDialog::getSaveFileName( this, QString::null, "qrcode", saveFormats() );
    if ( path.isNull() )
        return;

    ui->image_label->pixmap()->save( path );
}
void MainWindow::on_sBoxScale_valueChanged(int arg1)
{
    setScale( arg1 );
}
void MainWindow::on_pTextEditQRText_textChanged()
{
    updateQRImage();
}
void MainWindow::on_pButtonQuit_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    close();
}

void MainWindow::closeEvent(QCloseEvent *)
{
    QSettings ini( getIniPath(), QSettings::IniFormat );
    ini.setValue( ui->splitter->objectName(), ui->splitter->saveState() );
    ini.setValue( ui->splitter_2->objectName(), ui->splitter_2->saveState() );
    ini.setValue( ui->sBoxScale->objectName(), ui->sBoxScale->value() );
  //  ini.setValue( "State", saveState() );
    ini.setValue( "Geometry", saveGeometry() );

    qApp->quit();
}
bool MainWindow::eventFilter( QObject * object, QEvent * event )
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

void MainWindow::on_pushButton_2_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    statistique s;
    s.exec();
}

void MainWindow::on_historique_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_historique_4->setCurrentIndex(1);
}

void MainWindow::on_back_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_historique_4->setCurrentIndex(0);
    ui->Tab_C->show();
    ui->textBrowser_4->hide();
}

void MainWindow::on_historique_2_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_C->hide();
    historique h;
    ui->textBrowser_4->show();
    ui->textBrowser_4->setPlainText(h.read());
}

void MainWindow::on_pushButton_5_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    Smtp* smtp;
        smtp = new Smtp("Smartnewsagency1@gmail.com", "SMARTNEWSAGENCY", "smtp.gmail.com");
        //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

        smtp->sendMail(ui->mail_2->text(), ui->mail_2->text() ,ui->objet_2->text(), ui->message_2->text());
        qDebug()<<"mail a été envoyé";
        QMessageBox::information(this,"mail envoyé","mail a ete envoyé");
}

void MainWindow::on_excel_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                            tr("Fichiers d'extension Excel (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "mydata", ui->tab_categorie);

            // you can change the column order and
            // choose which colum to export
            obj.addField(0, "id", "char(20)");
            obj.addField(1, "libelle", "char(20)");
            obj.addField(2, "description", "char(20)");
            obj.addField(3, "type", "char(20)");


            int retVal = obj.export2Excel();

            if( retVal > 0)
            {
                QMessageBox::information(this, tr("FAIS!"),
                                         QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                         );
            }
}


void MainWindow::showTime()
{
        QTime time=QTime::currentTime();
        QString time_txt=time.toString("hh:mm:ss");
        ui->DigitalClock->setText(time_txt);
        ui->DigitalClock_3->setText(time_txt);
        ui->DigitalClock1emna->setText(time_txt);
        ui->DigitalClock1emna_2->setText(time_txt);
        ui->DigitalClock1emna_3->setText(time_txt);
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    Article A;
    A.statistique(ui->widget_2);
}

void MainWindow::on_tabWidget_3_currentChanged(int index)
{
    Article A;
    A.statistique(ui->widget);
}





void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/*
 WORKAROUND to escape "protected" limitation and use that freaking static function!
 */
class Kek : public QThread
{
public:
    static void wait(unsigned long)
    {
        QThread::msleep(200);
    }
};

void MainWindow::on_makeShot_clicked()
{
    this->hide();
    qApp->processEvents();
#ifdef _WIN32
    //Sleep(3000);
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
void MainWindow::on_qrcode_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int tabev=ui->tab_article->currentIndex().row();
    QVariant idd=ui->tab_article->model()->data(ui->tab_article->model()->index(tabev,0));
    QString id= idd.toString();
    QSqlQuery qry;
    qry.prepare("select * from evenements where id_Article=:id");
    qry.bindValue(":id",id);
    qry.exec();
    QString nom,debut,fin,idp,ids;
    while(qry.next()){
        nom=qry.value(1).toString();
        debut=qry.value(2).toString();
        fin=qry.value(3).toString();
        idp=qry.value(4).toString();
    }
    ids=QString(id);
    ids="ID: "+ids+" Nom: "+nom+" Date de debut: "+debut+" Date de fin: "+fin+"ID produit : "+idp;
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
    im=im.scaled(200,200);
    ui->image_label->setPixmap(QPixmap::fromImage(im));
}

/*/***************************************amine**************************************************/



void MainWindow::on_pb_ajouter_8_clicked()
{

    click->play();
    qDebug()<<click ->errorString();


int id = ui->_id->text().toInt();
QString nom= ui->_le_nom_2->text();
QString prenom=ui->_le_prenom_2->text();
QString fonction=ui->_le_fonction_2->text();
QString diplome=ui->_le_diplome_2->text();

if (ui->_id->text().isEmpty())
 {


    ui->_id->setStyleSheet("border: 1px solid red ");
     QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;
     QToolTip::showText(ui->_id->mapToGlobal(QPoint(100,0)), tr("INSERT ID"));
}else if(ui->_le_nom_2->text().isEmpty()||nom.size()>21){


    ui->_le_nom_2->setStyleSheet("border: 1px solid red ");
     QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP  NOM!!!!") ;
      QToolTip::showText(ui->_le_nom_2->mapToGlobal(QPoint(100,0)), tr("nom doit etre entre 0 et 20 charactere"));
}
else if(prenom.isEmpty()||prenom.size()>21){

        ui->_le_prenom_2->setStyleSheet("border: 1px solid red ");
         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP PRENOM!!!!") ;
         QToolTip::showText(ui->_le_prenom_2->mapToGlobal(QPoint(100,0)), tr("prenom doit etre entre 0 et 20 charactere"));

    }

else if(fonction.isEmpty()||fonction.size()>21){

        ui->_le_fonction_2->setStyleSheet("border: 1px solid red ");
         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP FOCNTION!!!!") ;
         QToolTip::showText(ui->_le_fonction_2->mapToGlobal(QPoint(100,0)), tr("fonction doit etre entre 0 et 20 charactere"));


    }

else if(diplome.isEmpty()||diplome.size()>21){

        ui->_le_diplome_2->setStyleSheet("border: 1px solid red ");
         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP DIPLOME!!!!") ;
         QToolTip::showText(ui->_le_diplome_2->mapToGlobal(QPoint(100,0)), tr("diplome doit etre entre 0 et 20 charactere"));

    }
else {


gesjournaliste j(id,nom,prenom,fonction,diplome);
bool test=j.ajouter();
if(test)
{

QMessageBox::information(nullptr, QObject::tr("Ajouter un journaliste"),
              QObject::tr("journaliste ajouté.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
ui->_tab_journaliste_2->setModel(g->afficher());
ui->_id->setStyleSheet("border: 1px solid blue ");
ui->_le_nom_2->setStyleSheet("border: 1px solid blue ");
ui->_le_prenom_2->setStyleSheet("border: 1px solid blue ");
ui->_le_fonction_2->setStyleSheet("border: 1px solid blue ");
ui->_le_diplome_2->setStyleSheet("border: 1px solid blue ");


}
else

  QMessageBox::critical(nullptr, QObject::tr("Ajouter un journaliste"),
              QObject::tr("id journaliste existe deja  !\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
ui->_tab_journaliste_2->setModel(g->afficher());
}
}



void MainWindow::on_modifierp_7_clicked()
{
    click->play();
    qDebug()<<click ->errorString();

int id = ui->_le_id_6->text().toInt();
QString nom= ui->_le_nom_5->text();
QString prenom=ui->_le_prenom_5->text();
QString fonction=ui->_le_fonction_4->text();
QString diplome=ui->_le_diplome_4->text();


      gesjournaliste j(id,nom,prenom,fonction,diplome);

         bool test =j.modifier();

         if(test)

         {
             QMessageBox::information(nullptr, QObject::tr("Modifier un journaliste"),
                         QObject::tr("journaliste modifiée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->_tab_journaliste_2->setModel(g->afficher());

         }

         else

         {
             QMessageBox::critical(nullptr, QObject::tr("modifier un journaliste"),
                         QObject::tr("Erreur !\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->_tab_journaliste_2->setModel(g->afficher());

         }
}

void MainWindow::on_supprimer_8_clicked()
{
    click->play();
    qDebug()<<click ->errorString();


int id = ui->_le_id_6->text().toInt();
if (ui->_le_id_6->text().isEmpty())
 {

    QToolTip::showText(ui->_le_id_6->mapToGlobal(QPoint(100,0)), tr("INSERT ID"));
    ui->_le_id_6->setStyleSheet("border: 1px solid red ");
     QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;

 }
else {
    bool test=g->supprimer(id);
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("Supprimer un journaliste"),
                    QObject::tr("journaliste supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->_tab_journaliste_2->setModel(g->afficher());
        ui->_le_id_6->setStyleSheet("border: 1px solid blue ");

    }

}
}

void MainWindow::on_recherchep_7_clicked()
{

    click->play();
    qDebug()<<click ->errorString();

if (ui->_id_rechercher_2->text().isEmpty())
 {

     QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;
     QToolTip::showText(ui->_id_rechercher_2->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
     ui->_id_rechercher_2->setStyleSheet("border: 1px solid red ");



 }
else {
QString nom= ui->_id_rechercher_2->text();
ui->_tab_journaliste_2->setModel(g->rechercher(nom));
ui->_id_rechercher_2->setStyleSheet("border: 1px solid blue ");

}
}

void MainWindow::on_afficherp_7_clicked()
{click->play();
    qDebug()<<click ->errorString();
    ui->_tab_journaliste_2->setModel(g->afficher());

}

void MainWindow::on_tri_p_7_clicked()
{

    click->play();
    qDebug()<<click ->errorString();

    bool test = g->tri_nom();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des journaliste"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->_tab_journaliste_2->setModel(g->tri_nom());}//refresh
           else
               QMessageBox::critical(nullptr, QObject::tr("tri des journaliste"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->_tab_journaliste_2->setModel(g->tri_nom());}//refresh


void MainWindow::on_trieprenom_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();

    bool test = g->tri_prenom();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des journaliste"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->_tab_journaliste_2->setModel(g->tri_prenom());}//refresh
           else
               QMessageBox::critical(nullptr, QObject::tr("tri des journaliste"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->_tab_journaliste_2->setModel(g->tri_prenom());}//refresh


void MainWindow::on_pdf_p_7_clicked()
{
    click->play();
    qDebug()<<click ->errorString();


QPdfWriter pdf("C:/Users/user/Desktop/Nouveau dossier (6)/integration/pdfamine");
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

void MainWindow::on_pushButton_7_clicked()
{click->play();
    qDebug()<<click ->errorString();
    bool test=true;


    if (ui->_mail->text().isEmpty())
     {

        QToolTip::showText(ui->_mail->mapToGlobal(QPoint(100,0)), tr("INSERT MAIL"));
        ui->_mail->setStyleSheet("border: 1px solid red ");
         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP MAIL!!!!") ;

     }
    else {


        QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
        mailREX.setCaseSensitivity(Qt::CaseInsensitive);
        mailREX.setPatternSyntax(QRegExp::RegExp);
        qDebug() << mailREX.exactMatch("me@me.com");

        if(!mailREX.exactMatch(ui->_mail->text()))
        {

            ui->_mail->setStyleSheet("border: 1px solid red ");
             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP MAIL!!!!") ;
             QToolTip::showText(ui->_mail->mapToGlobal(QPoint(100,0)), tr("MAUVAISE MAIL FORMAT"));

           test=false;
        }
    }
    if (ui->_objet->text().isEmpty()){

        ui->_objet->setStyleSheet("border: 1px solid red ");
         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP OBJET!!!!") ;
        QToolTip::showText(ui->_objet->mapToGlobal(QPoint(100,0)), tr("INSERT OBJET"));
    }
    if (ui->_message->text().isEmpty()){

        ui->_message->setStyleSheet("border: 1px solid red ");
         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP MESSAGE!!!!") ;
        QToolTip::showText(ui->_message->mapToGlobal(QPoint(100,0)), tr("INSERT MESSAGE"));
    }
    if(test==true){
        ui->_mail->setStyleSheet("border: 1px solid blue ");
        ui->_objet->setStyleSheet("border: 1px solid blue ");
        ui->_message->setStyleSheet("border: 1px solid blue ");

    Smtp* smtp;
        smtp = new Smtp("Smartnewsagency1@gmail.com", "SMARTNEWSAGENCY", "smtp.gmail.com");
        //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

        smtp->sendMail(ui->_mail->text(), ui->_mail->text() ,ui->_objet->text(), ui->_message->text());

}
}



void MainWindow::updateQRImage2()
{
    int sizeText = ui->pTextEditQRText_4->toPlainText().size();
    ui->labelSizeText_4->setText( QString::number( sizeText ) );

    int levelIndex = 1;
    int versionIndex = 0;
    bool bExtent = true;
    int maskIndex = -1;
    QString encodeString = ui->pTextEditQRText_4->toPlainText();

    successfulEncoding2 = qrEncode2.EncodeData( levelIndex, versionIndex, bExtent, maskIndex, encodeString.toUtf8().data() );
    if ( !successfulEncoding2 )
    {
        ui->image_label_4->clear();
        ui->image_label_4->setText( tr("QR Code...") );
        ui->labelSize_4->clear();
        ui->pButtonSave_4->setEnabled( successfulEncoding2 );
        return;
    }

    int qrImageSize = qrEncode2.m_nSymbleSize;

    // Создаем двумерный образ кода
    encodeImageSize2 = qrImageSize + ( QR_MARGIN * 2 );
    QImage encodeImage( encodeImageSize2, encodeImageSize2, QImage::Format_Mono );
    encodeImage.fill( 1 );

    // Создать двумерный образ кода
    for ( int i = 0; i < qrImageSize; i++ )
        for ( int j = 0; j < qrImageSize; j++ )
            if ( qrEncode2.m_byModuleData[i][j] )
                encodeImage.setPixel( i + QR_MARGIN, j + QR_MARGIN, 0 );

    ui->image_label_4->setPixmap( QPixmap::fromImage( encodeImage ) );

    setScale(ui->sBoxScale_4->value());
    ui->pButtonSave_4->setEnabled( successfulEncoding2 );
}
void MainWindow::setScale2(int scale)
{
    if ( successfulEncoding2 )
    {
        int scale_size = encodeImageSize2 * scale;

        const QPixmap & scale_image = ui->image_label_4->pixmap()->scaled( scale_size, scale_size );
        ui->image_label_4->setPixmap( scale_image );

        const QString & size_info = QString( "%1x%2" ).arg( scale_size ).arg( scale_size );
        ui->labelSize_4->setText( size_info );
    }
}
void MainWindow::on_pButtonSave_4_clicked()
{   click->play();
    qDebug()<<click ->errorString();
    const QString & path = QFileDialog::getSaveFileName( this, QString::null, "qrcode", saveFormats() );
    if ( path.isNull() )
        return;

    ui->image_label_4->pixmap()->save( path );
}
void MainWindow::on_sBoxScale_4_valueChanged(int arg1)
{
    setScale2( arg1 );
}
void MainWindow::on_pTextEditQRText_4_textChanged()
{
    updateQRImage2();
}
void MainWindow::on_pButtonQuit_4_clicked()
{   click->play();
    qDebug()<<click ->errorString();
    close();
}

void MainWindow::closeEvent2(QCloseEvent *)
{
    QSettings ini( getIniPath(), QSettings::IniFormat );
    ini.setValue( ui->splitter_8->objectName(), ui->splitter_8->saveState() );
    ini.setValue( ui->splitter_9->objectName(), ui->splitter_9->saveState() );
    ini.setValue( ui->sBoxScale_4->objectName(), ui->sBoxScale_4->value() );
  //  ini.setValue( "State", saveState() );
    ini.setValue( "Geometry", saveGeometry() );

    qApp->quit();
}
bool MainWindow::eventFilter2( QObject * object, QEvent * event )
{
    QScrollArea * scrollArea = ui->scrollArea_5;

    if ( object == scrollArea )
    {
        if ( event->type() == QEvent::MouseButtonPress )
        {
            QMouseEvent * mouseEvent = static_cast < QMouseEvent * > ( event );
            if ( mouseEvent->button() == Qt::LeftButton )
            {
                lastPos2 = mouseEvent->pos();

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
                lastPos2 -= mouseEvent->pos();

                int hValue = scrollArea->horizontalScrollBar()->value();
                int vValue = scrollArea->verticalScrollBar()->value();

                scrollArea->horizontalScrollBar()->setValue( lastPos2.x() + hValue );
                scrollArea->verticalScrollBar()->setValue( lastPos2.y() + vValue );

                lastPos2 = mouseEvent->pos();
            }

        }else if ( event->type() == QEvent::MouseButtonRelease )
            scrollArea->setCursor( Qt::ArrowCursor );
    }

    return QWidget::eventFilter(object, event);}



void MainWindow::on_calendarWidget_2_clicked(const QDate &date)
{
    *currdate = date.toString("yyyy.MM.dd");
    //QTextStream out(stdout);
    //out << QString(date.toString("yyyy.MM.dd"));
    ui->checkBox_4->setChecked(0);
    QString fname = "files/"+*currdate;
    //out << fname;
    QFile file(fname);

    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream ReadFile(&file);
    ui->plainTextEdit_2->setReadOnly(true);
    ui->plainTextEdit_2->setPlainText(ReadFile.readAll());
    file.close();
}



void MainWindow::on_push_2_clicked()
{
    QString fname = "files/"+*currdate;
    QFile file(fname);

    file.open(QFile::ReadWrite | QFile::Text);

    QTextStream OutFile(&file);
    QString text = ui->plainTextEdit_2->toPlainText();
    OutFile << text;

    file.close();
}



void MainWindow::on_checkBox_4_clicked(bool checked)
{
    if(checked)
        ui->plainTextEdit_2->setReadOnly(false);
    else
        ui->plainTextEdit_2->setReadOnly(true);
}



void MainWindow::on_actionSave_triggered()
{
    QString fname = "files/"+*currdate;
    QFile file(fname);

    file.open(QFile::ReadWrite | QFile::Text);

    QTextStream OutFile(&file);
    QString text = ui->plainTextEdit_2->toPlainText();
    OutFile << text;

    file.close();
}




void MainWindow::on_excel_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                        tr("Fichiers d'extension Excel (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->_tab_journaliste_2);

        // you can change the column order and
        // choose which colum to export
        obj.addField(0, "id", "char(20)");
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

void MainWindow::on_qrcode_4_clicked()
{

    click->play();
    qDebug()<<click ->errorString();
    int tabev=ui->_tab_journaliste_2->currentIndex().row();
    QVariant idd=ui->_tab_journaliste_2->model()->data(ui->_tab_journaliste_2->model()->index(tabev,0));
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
    ui->qrlab->setPixmap(QPixmap::fromImage(im));
    int i=0 ;
    for(i=0;i<100;i=i+0.1){
        i++;
    }
}

void MainWindow::on_saveit_2_clicked()
{
    const QString & path = QFileDialog::getSaveFileName( this, QString::null, "qrcode", saveFormats() );
    if ( path.isNull() )
        return;
    ui->qrlab->pixmap()->save( path );

}


void MainWindow::open()
{
    QString path = QFileDialog::getOpenFileName( this, QString::null, QString::null, getFilter() );
    if ( path.isEmpty() )
        return;

    ui->labelQRCodeImage_2->setPixmap( QPixmap( path ) );
    decode();
}
void MainWindow::decode()
{
    QImage qrImage = ui->labelQRCodeImage_2->pixmap()->toImage();
    const QString & decodeText = zxing.decodeImage( qrImage );

    ui->pTextEditQRCodeText_2->setPlainText( decodeText );
    ui->labelSizeText_4->setText( QString::number( decodeText.size() ) );
}
void MainWindow::on_pButtonOpen_2_clicked()
{
    open();
}
void MainWindow::dragEnterEvent( QDragEnterEvent * event )
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
void MainWindow::dropEvent( QDropEvent * event )
{
    const QMimeData * mime = event->mimeData();
    const QList < QUrl > & urls = mime->urls();

    QString path = urls.first().toLocalFile();
    ui->labelQRCodeImage_2->setPixmap( QPixmap( path ) );

    decode();
}




void MainWindow::on_loginbutton_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
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

void MainWindow::on_signupbutton_clicked()
{   click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_completeRegButton_clicked()
{   click->play();
    qDebug()<<click ->errorString();
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

void MainWindow::on_backButton_clicked()
{   click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_mission_clicked()
{
    click->play();
    qDebug()<<click ->errorString();

      int id_mission_2 = ui->id_mission_2->text().toInt();
      QString libelle_2= ui->libelle_2->text();
      QString description_2=ui->description_2->text();
      QString confidentialite_2=ui->confidentialite_2->text();




       if (ui->id_mission_2->text().isEmpty())
        {


           ui->id_mission_2->setStyleSheet("border: 1px solid red ");
            QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;
            QToolTip::showText(ui->id_mission_2->mapToGlobal(QPoint(100,0)), tr("INSERT ID"));
       }else if(ui->libelle_2->text().isEmpty()||libelle_2.size()>21){


           ui->libelle_2->setStyleSheet("border: 1px solid red ");
            QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP  LIBELLE!!!!") ;
             QToolTip::showText(ui->libelle_2->mapToGlobal(QPoint(100,0)), tr("LIBELLE doit etre entre 0 et 20 charactere"));
       }
       else if(description_2.isEmpty()||description_2.size()>21){

               ui->description_2->setStyleSheet("border: 1px solid red ");
                QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP DESCRIPTION!!!!") ;
                QToolTip::showText(ui->description_2->mapToGlobal(QPoint(100,0)), tr("description doit etre entre 0 et 20 charactere"));

           }

       else if(confidentialite_2.isEmpty()||confidentialite_2.size()>21){

               ui->confidentialite_2->setStyleSheet("border: 1px solid red ");
                QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP confidentialite!!!!") ;
                QToolTip::showText(ui->confidentialite_2->mapToGlobal(QPoint(100,0)), tr("confidentialite doit etre entre 0 et 20 charactere"));


           }


       else {








    missions m(id_mission_2,libelle_2,description_2,confidentialite_2);
    bool test=m.ajouter();
    if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Ajouter mission "),
                    QObject::tr("mission ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tab_mission->setModel(a->afficher());
  ui->id_mission_2->setStyleSheet("border: 1px solid blue ");
  ui->libelle_2->setStyleSheet("border: 1px solid blue ");
  ui->description_2->setStyleSheet("border: 1px solid blue ");
  ui->confidentialite_2->setStyleSheet("border: 1px solid blue ");

  }
    else

        QMessageBox::critical(nullptr, QObject::tr("Ajouter mission"),
                    QObject::tr("Erreur !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_mission->setModel(a->afficher());
  }
}

void MainWindow::on_modifierp_6_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_mission = ui->id_miss_mod_2->text().toInt();
    QString libelle= ui->libelle_miss_mod_2->text();
    QString description=ui->description_mod_2->text();
    QString confidentialite=ui->confidentialite_mod_2->text();


          missions j(id_mission,libelle,description,confidentialite);

             bool test =j.modifier();

             if(test)

             {
                 QMessageBox::information(nullptr, QObject::tr("Modifier mission"),
                             QObject::tr("mission modifiée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_mission->setModel(a->afficher());

             }

             else

             {
                 QMessageBox::critical(nullptr, QObject::tr("modifier mission"),
                             QObject::tr("Erreur !\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_mission->setModel(a->afficher());

             }
}

void MainWindow::on_supprimer_7_clicked()
{
    click->play();
    qDebug()<<click ->errorString();

       int id_mission = ui->id_miss_mod_2->text().toInt();
        if (ui->id_miss_mod_2->text().isEmpty())
         {

            QToolTip::showText(ui->id_miss_mod_2->mapToGlobal(QPoint(100,0)), tr("INSERT ID"));
            ui->id_miss_mod_2->setStyleSheet("border: 1px solid red ");
             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;

         }
        else {
           bool test=a->supprimer(id_mission);
           if(test)
           {
               ui->tab_mission->setModel(a->afficher());

               QMessageBox::information(nullptr, QObject::tr("Supprimer mission"),
                           QObject::tr("mission supprimée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
               ui->id_miss_mod_2->setStyleSheet("border: 1px solid blue ");

           }
           else
               QMessageBox::critical(nullptr, QObject::tr("Supprimer mission"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_mission->setModel(a->afficher());
   }
}

void MainWindow::on_afficherp_6_clicked()
{   click->play();
    qDebug()<<click ->errorString();
    ui->tab_mission->setModel(a->afficher());

}

void MainWindow::on_tri_p_6_clicked()
{
    click->play();
    qDebug()<<click ->errorString();

       bool test = a->tri_id_mission();
              if (test){
                  QMessageBox::information(nullptr, QObject::tr("tri des missions"),
                              QObject::tr("succée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tab_mission->setModel(a->tri_id_mission());}//refresh
              else
                  QMessageBox::critical(nullptr, QObject::tr("tri des missions"),
                              QObject::tr("Erreur !\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tab_mission->setModel(a->tri_id_mission());}


void MainWindow::on_pdf_p_6_clicked()
{
    click->play();
    qDebug()<<click ->errorString();

        missions E4;
            QPrinter printer;
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("C:/Users/user/Desktop/Nouveau dossier (6)/integration/pdfamine");
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

void MainWindow::on_recherchep_6_clicked()
{
    click->play();
    qDebug()<<click ->errorString();

       QString libelle= ui->id_rechercher_6->text();


        if (ui->id_rechercher_6->text().isEmpty())
         {

            QToolTip::showText(ui->id_rechercher_6->mapToGlobal(QPoint(100,0)), tr("INSERT LIBELLE"));
            ui->id_rechercher_6->setStyleSheet("border: 1px solid red ");
             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP LIBELLE!!!!") ;

         }
        else {

       ui->recherche_tab_6->setModel(a->rechercher(libelle));
       ui->id_rechercher_6->setStyleSheet("border: 1px solid blue ");

       ui->tab_mission->setModel(a->afficher());
   }
}

void MainWindow::on_tab_mission_activated(const QModelIndex &index)
{
    QString val=ui->tab_mission->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from mission where id_mission='"+val+"'or libelle='"+val+"'or description='"+val+"'or confidentialite='"+val+"'");

    if(query.exec())
    {

     while(query.next())
    {
            ui->id_miss_mod_2->setText(query.value(0).toString());
            ui->libelle_miss_mod_2->setText(query.value(1).toString());
            ui->description_mod_2->setText(query.value(2).toString());
            ui->confidentialite_mod_2->setText(query.value(3).toString());


}}
    else {
        QMessageBox::critical(nullptr, QObject::tr("missions"),
                    QObject::tr("Erreur !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
void MainWindow::on__tab_journaliste_2_activated(const QModelIndex &index)
{


QString val=ui->_tab_journaliste_2->model()->data(index).toString();
QSqlQuery query;
query.prepare("select * from journaliste where id='"+val+"'or nom='"+val+"'or prenom='"+val+"'or fonction='"+val+"'or diplome='"+val+"'");

if(query.exec())
{

 while(query.next())
{
        ui->_le_id_6->setText(query.value(0).toString());
        ui->_le_nom_5->setText(query.value(1).toString());
        ui->_le_prenom_5->setText(query.value(2).toString());
        ui->_le_fonction_4->setText(query.value(3).toString());
        ui->_le_diplome_4->setText(query.value(4).toString());

}

}
else {
    QMessageBox::critical(nullptr, QObject::tr("journaliste"),
                QObject::tr("Erreur !\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_makeShot_4_clicked()
{   click->play();
    qDebug()<<click ->errorString();
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





void MainWindow::on_add_to_list_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    if(ui->item_text_3->text() != ""){
        QListWidgetItem* temp_check_list_item = new QListWidgetItem(ui->item_text_3->text());
        temp_check_list_item->setFlags(temp_check_list_item->flags() | Qt::ItemIsUserCheckable);
        temp_check_list_item->setCheckState(Qt::Unchecked);
        ui->list_items_3->insertItem(0, temp_check_list_item);
        ui->item_text_3->setText("");
    }
}

void MainWindow::on_list_items_3_itemChanged(QListWidgetItem *item)
{
    bool checked = item->checkState() == Qt::Checked;

    if(checked){
        int current_row = ui->list_items_3->row(item);
        ui->list_items_3->takeItem(current_row);
        //item->setBackgroundColor(checked_color);
        ui->list_items_3->addItem(item);
    }else{
        int current_row = ui->list_items_3->row(item);
        ui->list_items_3->takeItem(current_row);
      //  item->setBackgroundColor(unchecked_color);
        ui->list_items_3->insertItem(0, item);
    }
}

void MainWindow::on_item_text_3_returnPressed()
{
    on_add_to_list_3_clicked();
}

void MainWindow::on_move_item_up_3_clicked()
{
    QList<QListWidgetItem*> items = ui->list_items_3->selectedItems();
    foreach (QListWidgetItem* item, items) {
        bool checked = item->checkState() == Qt::Checked;
        if(!checked){
            int current_row = ui->list_items_3->row(item);
            ui->list_items_3->takeItem(current_row);
            ui->list_items_3->insertItem(current_row-1, item);
            item->setSelected(true);
        }
    }
}

void MainWindow::on_move_item_down_3_clicked()
{
    QList<QListWidgetItem*> items = ui->list_items_3->selectedItems();
    foreach (QListWidgetItem* item, items) {
        bool checked = item->checkState() == Qt::Checked;
        if(!checked){
            int current_row = ui->list_items_3->row(item);
            ui->list_items_3->takeItem(current_row);
            ui->list_items_3->insertItem(current_row+1, item);
            item->setSelected(true);
        }
    }
}

void MainWindow::on_delete_item_3_clicked()
{

    QList<QListWidgetItem*> items = ui->list_items_3->selectedItems();
    foreach (QListWidgetItem* item, items) {
        int current_row = ui->list_items_3->row(item);
        QListWidgetItem* remove_item = ui->list_items_3->takeItem(current_row);
        delete remove_item;
    }
}




void MainWindow::on_gestion_des_mission_clicked()
{   click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_gestion_journaliste_clicked()
{   click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_backButton_2_clicked()
{   click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_musicNext_clicked()
{

    int length = sizeof(songsList) / sizeof(songsList[0]);
    currentSong = (currentSong + 1)%length;
    musicPlayer->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Nouveau dossier (6)/integration/img_mus/" + songsList[currentSong]));
    musicPlayer->play();

}

void MainWindow::on_musicPlay_clicked()
{

    musicPlayer->play();
    ui->musicStop->setVisible(true);
    ui->musicPlay->setVisible(false);

}

void MainWindow::on_musicBack_clicked()
{
    int length = sizeof(songsList) / sizeof(songsList[0]);

    currentSong = (currentSong - 1);
    if(currentSong<0)
    {
        currentSong = length-1;
    }
    musicPlayer->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Nouveau dossier (6)/integration/img_mus/" + songsList[currentSong]));
    musicPlayer->play();
}

void MainWindow::on_musicStop_clicked()
{
    musicPlayer->pause();
    ui->musicStop->setVisible(false);
    ui->musicPlay->setVisible(true);
}



QString MainWindow::getTime()
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
void MainWindow::on_recherchep_11_clicked()
{
    search.show();
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    QString time;
    event->accept();

    time = getTime();
    ui->clock->display(time);}






/*******sahar******///
void MainWindow::on_p_ajoutersahar_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_publicitesahar = ui->id_publicitesahar->text().toInt();
    int id_clientsahar = ui->id_clientsahar->text().toInt();
    QString type_publicitesahar= ui->type_publicitesahar->text();
    float tarif_publicitesahar= ui->tarif_publicitesahar->text().toFloat();
    QString date_lancementsahar=ui->date_lancementsahar->text();
    QString duree_publicitesahar=ui->duree_publicitesahar->text();
    int k=id_publicitesahar;


          publicite p(id_publicitesahar,id_clientsahar,type_publicitesahar,tarif_publicitesahar,date_lancementsahar,duree_publicitesahar);
          bool test=p.ajouter();
          if(test)
        {

        QMessageBox::information(nullptr, QObject::tr("Ajouter une publicité "),
                          QObject::tr("Publicité ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


        }
          else

              QMessageBox::critical(nullptr, QObject::tr("Ajouter une publicité "),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          QString textajouter;
          historiques h;
          QSqlQuery qry;
          qry.prepare("select * from publicite");
          textajouter="L'ajout d'une publicite a la base de donnees de reference = "+QString::number(k)+" a ete effectue avec succees";
          h.write(textajouter);
}

void MainWindow::on_Afficherpsahar_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->tab_pubsahar->setModel(b->afficher());
}

void MainWindow::on_Modifierpsahar_clicked()
{
    click->play();
    qDebug()<<click ->errorString();

    int id_publicitesahar = ui->id_publicite_2sahar->text().toInt();
    int id_clientsahar = ui->id_client_2sahar->text().toInt();
    QString type_publicitesahar= ui->type_publicite_2sahar->text();
    float tarif_publicitesahar= ui->tarif_publicite_2sahar->text().toFloat();
    QString date_lancementsahar=ui->date_lancement_2sahar->text();
    QString duree_publicitesahar=ui->duree_publicite_2sahar->text();


              publicite p(id_publicitesahar,id_clientsahar,type_publicitesahar,tarif_publicitesahar,date_lancementsahar,duree_publicitesahar);

                 bool test =p.modifier();

                 if(test)

                 {
                     QMessageBox::information(nullptr, QObject::tr("Modifier une publicite"),
                                 QObject::tr("Publicite modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tab_pubsahar->setModel(b->afficher());

                 }

                 else

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Modifier une publicite"),
                                 QObject::tr("Erreur !\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_pubsahar->setModel(b->afficher());

                 }

}

void MainWindow::on_supprimerpsahar_clicked()
{

    click->play();
    qDebug()<<click ->errorString();

        int id = ui->id_3sahar->text().toInt();
        if (ui->id_3sahar->text().isEmpty())
            {

                QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;

            }
           else
        {
            bool test=b->supprimer(id);
            if(test)
            {
                ui->tab_pubsahar->setModel(b->afficher());

                QMessageBox::information(nullptr, QObject::tr("Supprimer une publicité"),
                            QObject::tr("publicité supprimée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer une publicité"),
                            QObject::tr("Erreur !\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_pubsahar->setModel(b->afficher());


}
}





void MainWindow::on_recherche_publicitesahar_clicked()
{

    click->play();
    qDebug()<<click ->errorString();
        QString type_publicitesahar= ui->type_recherchesahar->text();
        ui->resultatsahar->setModel(b->rechercher(type_publicitesahar));
        ui->tab_pubsahar->setModel(b->afficher());

}

void MainWindow::on_tri_publicitesahar_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    bool test = b->tri_type_publicite();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des publicités"),
                           QObject::tr("succès.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_pubsahar->setModel(b->tri_type_publicite());}//refresh
           else
               QMessageBox::critical(nullptr, QObject::tr("tri des publicités"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_pubsahar->setModel(b->tri_type_publicite());}//refresh



void MainWindow::on_pushButtonsahar_clicked()
{

        click->play();
        qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_2sahar_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_pushButton_3sahar_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_4sahar_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_p_ajouter_2sahar_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_sponsorsahar = ui->id_sponsorsahar->text().toInt();
    QString domaine_sponsorsahar = ui->domaine_sponsorsahar->text();
    QString nom_sponsorsahar= ui->nom_sponsorsahar->text();
    QString adresse_sponsorsahar=ui->adresse_sponsorsahar->text();
    QString type_sponsorsahar=ui->type_sponsorsahar->text();

          sponsors_crud p(id_sponsorsahar,domaine_sponsorsahar,nom_sponsorsahar,adresse_sponsorsahar,type_sponsorsahar);
          bool test=p.ajouter();
          if(test)
        {

        QMessageBox::information(nullptr, QObject::tr("Ajouter un sponsor "),
                          QObject::tr("Sponsor ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


        }
          else

              QMessageBox::critical(nullptr, QObject::tr("Ajouter un sponsor "),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_Afficherp_2sahar_clicked()
{ click->play();
    qDebug()<<click ->errorString();
      ui->tab_sponsorsahar->setModel(e->afficher());
}

void MainWindow::on_Modifierp_2sahar_clicked()
{  click->play();
    qDebug()<<click ->errorString();
    int id_sponsorsahar = ui->id_sponsor_2sahar->text().toInt();
    QString domaine_sponsorsahar= ui->domaine_sponsor_2sahar->text();
    QString nom_sponsorsahar= ui->nom_sponsor_2sahar->text();
    QString adresse_sponsorsahar=ui->adresse_sponsor_2sahar->text();
    QString type_sponsorsahar=ui->type_sponsor_2sahar->text();


              sponsors_crud p(id_sponsorsahar,domaine_sponsorsahar,nom_sponsorsahar,adresse_sponsorsahar,type_sponsorsahar);

                 bool test =p.modifier();

                 if(test)

                 {
                     QMessageBox::information(nullptr, QObject::tr("Modifier un sponsor"),
                                 QObject::tr("Sponsor modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tab_sponsorsahar->setModel(e->afficher());

                 }

                 else

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Modifier un sponsor"),
                                 QObject::tr("Erreur !\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_sponsorsahar->setModel(e->afficher());

                 }
}


void MainWindow::on_supprimerp_2sahar_clicked()
{  click->play();
    qDebug()<<click ->errorString();
    int id_sponsorsahar = ui->id_sponsor_3sahar->text().toInt();
    if (ui->id_sponsor_3sahar->text().isEmpty())
        {

            QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;

        }
       else
{
        bool test=e->supprimer(id_sponsorsahar);
        if(test)
        {
            ui->tab_sponsorsahar->setModel(e->afficher());

            QMessageBox::information(nullptr, QObject::tr("Supprimer un sponsor"),
                        QObject::tr("Sponsor supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un sponsor"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_sponsorsahar->setModel(e->afficher());
}
}

void MainWindow::on_tri_publicite_2sahar_clicked()
{click->play();
    qDebug()<<click ->errorString();
    bool test = e->tri_nom_sponsor();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des types de sponsors"),
                           QObject::tr("succès.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_sponsorsahar->setModel(e->tri_nom_sponsor());}//refresh
           else
               QMessageBox::critical(nullptr, QObject::tr("tri des types de sponsors"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_sponsorsahar->setModel(e->tri_nom_sponsor());}//refresh


void MainWindow::on_recherche_publicite_2sahar_clicked()
{click->play();
    qDebug()<<click ->errorString();
    QString nom_sponsorsahar= ui->nom_recherchesahar->text();
    ui->resultat_2sahar->setModel(e->rechercher(nom_sponsorsahar));
    ui->tab_sponsorsahar->setModel(e->afficher());
}


void MainWindow::on_pushButton_5sahar_clicked()
{click->play();
    qDebug()<<click ->errorString();
    bool test = e->tri_type_sponsor();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des types de sponsors"),
                           QObject::tr("succès.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_sponsorsahar->setModel(e->tri_type_sponsor());}//refresh
           else
               QMessageBox::critical(nullptr, QObject::tr("tri des types de sponsors"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_sponsorsahar->setModel(e->tri_type_sponsor());}//refresh




void MainWindow::on_pushButton_7sahar_clicked()
{click->play();
    qDebug()<<click ->errorString();
    QPdfWriter pdf("C:/Users/user/Desktop/Nouveau dossier (6)/integration/pdfsahar");
QPainter painter(&pdf);
     int i = 4000;
 painter.setPen(Qt::red);
 painter.setFont(QFont("Arial", 30));
 painter.drawText(2300,1200,"Liste Des Sponsors");
 painter.setPen(Qt::black);
 painter.setFont(QFont("Arial", 50));
 //painter.drawText(1100,2000,afficheDC);
 painter.drawRect(1500,200,7300,2600);
 painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Asus/Desktop/projet_qt/PDF.pdf"));
 painter.drawRect(0,3000,9600,500);
 painter.setFont(QFont("Arial", 9));
 painter.drawText(300,3300,"id_sponsor");
 painter.drawText(1800,3300,"domaine_sponsor");
 painter.drawText(3300,3300,"nom_sponsor");
 painter.drawText(4800,3300,"adresse_sponsor");
 painter.drawText(6300,3300,"type_sponsor");



 QSqlQuery query;
 query.prepare("select * from sponsors");
      query.exec();
      while (query.next())
         {
          painter.drawText(300,i,query.value(0).toString());
          painter.drawText(1800,i,query.value(1).toString());
          painter.drawText(3300,i,query.value(2).toString());
          painter.drawText(4800,i,query.value(3).toString());
          painter.drawText(6300,i,query.value(4).toString());

          i = i +500;
                                  }
qDebug()<<"le pdf a ete cree";
  QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
}

void MainWindow::on_pushButton_6sahar_clicked()
{
    click->play();
        qDebug()<<click ->errorString();
        bool test = b->tri_id_publicite();
               if (test){
                   QMessageBox::information(nullptr, QObject::tr("tri des id des publicités"),
                               QObject::tr("succès.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
               ui->tab_pubsahar->setModel(b->tri_id_publicite());}//refresh
               else
                   QMessageBox::critical(nullptr, QObject::tr("tri des id des publicités"),
                               QObject::tr("Erreur !\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
               ui->tab_pubsahar->setModel(b->tri_id_publicite());}//refresh




void MainWindow::on_tab_pubsahar_activated(const QModelIndex &index)
{
    QString val=ui->tab_pubsahar->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from publicite where id_publicitesahar='"+val+"'or id_clientsahar='"+val+"'or type_publicitesahar='"+val+"'or tarif_publicitesahar='"+val+"'or date_lancementsahar='"+val+"'or duree_publicitesahar='"+val+"'" );

        if(query.exec())
        {

         while(query.next())
        {
                ui->id_publicite_2sahar->setText(query.value(0).toString());
                ui->id_client_2sahar->setText(query.value(1).toString());
                ui->type_publicite_2sahar->setText(query.value(2).toString());
                ui->tarif_publicite_2sahar->setText(query.value(3).toString());
                ui->date_lancement_2sahar->setText(query.value(4).toString());
                ui->duree_publicite_2sahar->setText(query.value(5).toString());



    }}
        else {
            QMessageBox::critical(nullptr, QObject::tr("publicite"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_tab_sponsorsahar_activated(const QModelIndex &index)
{
    QString val=ui->tab_sponsorsahar->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from sponsors_crud where id_sponsorsahar='"+val+"'or domaine_sponsorsahar='"+val+"'or nom_sponsorsahar='"+val+"'or adresse_sponsorsahar='"+val+"'or type_sponsorsahar='"+val+"'");

        if(query.exec())
        {

         while(query.next())
        {
                ui->id_sponsor_2sahar->setText(query.value(0).toString());
                ui->domaine_sponsor_2sahar->setText(query.value(1).toString());
                ui->nom_sponsor_2sahar->setText(query.value(2).toString());
                ui->adresse_sponsor_2sahar->setText(query.value(3).toString());
                ui->type_sponsor_2sahar->setText(query.value(3).toString());


    }}
        else {
            QMessageBox::critical(nullptr, QObject::tr("sponsors_crud"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

}

void MainWindow::on_mailingsahar_clicked()
{
    click->play();
        qDebug()<<click ->errorString();
        Smtp* smtp;
            smtp = new Smtp("smartnewsagency1@gmail.com", "SMARTNEWSAGENCY", "smtp.gmail.com");
            //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

            smtp->sendMail("smartnewsagency1@gmail.com", "smartnewsagency1@gmail.com" , "test","test ");
}


/*void MainWindow::on_exitsahar_clicked()
{
    this->close();
}*/
void MainWindow::updateQRImagesahar()
{
    int sizeText = ui->pTextEditQRText_3sahar->toPlainText().size();
    ui->labelSizeText_3sahar->setText( QString::number( sizeText ) );

    int levelIndex = 1;
    int versionIndex = 0;
    bool bExtent = true;
    int maskIndex = -1;
    QString encodeString = ui->pTextEditQRText_3sahar->toPlainText();

    successfulEncodingsahar = qrEncodesahar.EncodeData( levelIndex, versionIndex, bExtent, maskIndex, encodeString.toUtf8().data() );
    if ( !successfulEncodingsahar )
    {
        ui->image_label_3sahar->clear();
        ui->image_label_3sahar->setText( tr("QR Code...") );
        ui->labelSize_3sahar->clear();
        ui->pButtonSave_3sahar->setEnabled( successfulEncodingsahar );
        return;
    }

    int qrImageSize = qrEncodesahar.m_nSymbleSize;

    // Создаем двумерный образ кода
    encodeImageSizesahar = qrImageSize + ( QR_MARGIN * 2 );
    QImage encodeImage( encodeImageSizesahar, encodeImageSizesahar, QImage::Format_Mono );
    encodeImage.fill( 1 );

    // Создать двумерный образ кода
    for ( int i = 0; i < qrImageSize; i++ )
        for ( int j = 0; j < qrImageSize; j++ )
            if ( qrEncodesahar.m_byModuleData[i][j] )
                encodeImage.setPixel( i + QR_MARGIN, j + QR_MARGIN, 0 );

    ui->image_label_3sahar->setPixmap( QPixmap::fromImage( encodeImage ) );

    setScalesahar(ui->sBoxScale_3sahar->value());
    ui->pButtonSave_3sahar->setEnabled( successfulEncodingsahar );
}
void MainWindow::setScalesahar(int scale)
{
    if ( successfulEncodingsahar )
    {
        int scale_size = encodeImageSizesahar * scale;

        const QPixmap & scale_image = ui->image_label_3sahar->pixmap()->scaled( scale_size, scale_size );
        ui->image_label_3sahar->setPixmap( scale_image );

        const QString & size_info = QString( "%1x%2" ).arg( scale_size ).arg( scale_size );
        ui->labelSize_3sahar->setText( size_info );
    }
}
void MainWindow::on_pButtonSave_3sahar_clicked()
{
    const QString & path = QFileDialog::getSaveFileName( this, QString::null, "qrcode", saveFormats() );
    if ( path.isNull() )
        return;

    ui->image_label_3sahar->pixmap()->save( path );
}
void MainWindow::on_sBoxScale_3sahar_valueChanged(int arg1)
{
    setScalesahar( arg1 );
}
void MainWindow::on_pTextEditQRText_3sahar_textChanged()
{
    updateQRImagesahar();
}
void MainWindow::on_pButtonQuit_3sahar_clicked()
{
    close();
}

void MainWindow::closeEventsahar(QCloseEvent *)
{
    QSettings ini( getIniPath(), QSettings::IniFormat );
    ini.setValue( ui->splitter_5sahar->objectName(), ui->splitter_5sahar->saveState() );
    ini.setValue( ui->splitter_6sahar->objectName(), ui->splitter_6sahar->saveState() );
    ini.setValue( ui->sBoxScale_3sahar->objectName(), ui->sBoxScale_3sahar->value() );
  //  ini.setValue( "State", saveState() );
    ini.setValue( "Geometry", saveGeometry() );

    qApp->quit();
}
bool MainWindow::eventFiltersahar( QObject * object, QEvent * event )
{
    QScrollArea * scrollArea = ui->scrollArea_3sahar;

    if ( object == scrollArea )
    {
        if ( event->type() == QEvent::MouseButtonPress )
        {
            QMouseEvent * mouseEvent = static_cast < QMouseEvent * > ( event );
            if ( mouseEvent->button() == Qt::LeftButton )
            {
                lastPossahar = mouseEvent->pos();

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
                lastPossahar -= mouseEvent->pos();

                int hValue = scrollArea->horizontalScrollBar()->value();
                int vValue = scrollArea->verticalScrollBar()->value();

                scrollArea->horizontalScrollBar()->setValue( lastPossahar.x() + hValue );
                scrollArea->verticalScrollBar()->setValue( lastPossahar.y() + vValue );

                lastPossahar = mouseEvent->pos();
            }

        }else if ( event->type() == QEvent::MouseButtonRelease )
            scrollArea->setCursor( Qt::ArrowCursor );
    }

    return QWidget::eventFilter(object, event);
}

void MainWindow::on_statistiquesahar_clicked()
{
    statistiques s;
        s.exec();
}

void MainWindow::on_historiquesahar_clicked()
{
     ui->stackedWidget_3sahar->setCurrentIndex(1);
}

void MainWindow::on_backsahar_clicked()
{
    ui->stackedWidget_3sahar->setCurrentIndex(0);
    ui->tab_pub_2sahar->show();
    ui->textBrowser_3->hide();
}

void MainWindow::on_voir_historiquesahar_clicked()
{
    ui->tab_pub_2sahar->hide();
    historiques h;
    ui->textBrowser_3->show();
    ui->textBrowser_3->setPlainText(h.read());
}

void MainWindow::changeEventsahar(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/*
 WORKAROUND to escape "protected" limitation and use that freaking static function!
 */

void MainWindow::on_makeShotsahar_clicked()
{
    class Kek : public QThread
    {
    public:
        static void wait(unsigned long)
        {
            QThread::msleep(200);
        }
    };

    this->hide();
    qApp->processEvents();
#ifdef _WIN32
    //Sleep(3000);
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

void MainWindow::on_excelsahar_clicked()
{click->play();
    qDebug()<<click ->errorString();
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                            tr("Fichiers d'extension Excel (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "mydata", ui->tab_sponsorsahar);

            // you can change the column order and
            // choose which colum to export
            obj.addField(0, "Id", "char(20)");
            obj.addField(1, "Domaine", "char(20)");
            obj.addField(2, "Nom", "char(20)");
            obj.addField(3, "Adresse", "char(20)");
            obj.addField(4, "Type", "char(20)");


            int retVal = obj.export2Excel();

            if( retVal > 0)
            {
                QMessageBox::information(this, tr("FAIS!"),
                                         QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                         );
            }
}


/*********emna**********************************************************************************/











void MainWindow::on_p_ajouter_2emna_clicked()
{click->play();
    int id_Fournisseur=ui->le_id_2emna->text().toInt();
    QString nom_Fournisseur=ui->le_nom_2emna->text();
    QString matricule_fiscale=ui->le_matricule_2emna->text();
    QString adresse_Fournisseur=ui->le_adresse_2emna->text();
    Fournisseur F(id_Fournisseur,nom_Fournisseur,adresse_Fournisseur,matricule_fiscale);

    bool test=F.ajouter_Fournisseur();
    if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur "),
                    QObject::tr("fournisseur ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


  }
    else

        QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur "),
                    QObject::tr("Erreur !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_p_ajouterE_2emna_clicked()
{
    click->play();
    int id_Equipement=ui->le_ide_2emna->text().toInt();
    QString libelle=ui->le_libelle_2emna->text();
    QString description=ui->le_description_2emna->text();
    QString marque=ui->le_marque_2emna->text();
    QDate date_acqui=ui->p_ajouterdateacqui_2emna->date();
    QString prix=ui->le_prix_2emna->text();
    equipement E (id_Equipement,libelle,description,marque,date_acqui,prix);

    bool test=E.ajouter_Equipement();
    if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Ajouter un équipement "),
                    QObject::tr("équipement ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


  }
    else

        QMessageBox::critical(nullptr, QObject::tr("Ajouter un équipement "),
                    QObject::tr("Erreur !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_afficherE_2emna_clicked()
{
    click->play();
    ui->tableView_4emna->setModel(v->afficher_Equipement());
}


void MainWindow::on_afficherF_2emna_clicked()
{
    click->play();
     ui->tableView_3emna->setModel(f->afficher_Fournisseur());
}

void MainWindow::on_ModifierE_2emna_clicked()
{
click->play();
    int idd = ui->mod_idE_2emna->text().toInt();
    QString prix = ui->mod_prix_2emna->text();
    QString libelle = ui->mod_libelle_2emna->text();
    QString marque= ui->mod_marque_2emna->text();
    QString description= ui->mod_description_2emna->text();
    QDate date_acqui=ui->mod_dateacqui_2emna->date();


              equipement e(idd,libelle,description,marque,date_acqui,prix);

                 bool test =e.modifier_Equipement();

                 if(test)

                 {
                     QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                                 QObject::tr("fournisseur modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tableView_3emna->setModel(f->afficher_Fournisseur());

                 }

                 else

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                                 QObject::tr("Erreur !\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tableView_3emna->setModel(f->afficher_Fournisseur());

                 }
}

void MainWindow::on_modifierF_2emna_clicked()
{
click->play();
    int idd = ui->mod_idF_2emna->text().toInt();
    QString adresse_Fournisseur = ui->mod_adresse_2emna->text();
    QString nom_Fournisseur= ui->mod_nom_2emna->text();
    QString matricule_fiscale=ui->mod_matricule_2emna->text();


              Fournisseur F(idd,adresse_Fournisseur,nom_Fournisseur,matricule_fiscale);

                 bool test=f->modifier_Fournisseur(idd,adresse_Fournisseur,nom_Fournisseur,matricule_fiscale);

                 if(test)

                 {
                     QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                                 QObject::tr("fournisseur modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tableView_3emna->setModel(f->afficher_Fournisseur());

                 }

                 else

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                                 QObject::tr("Erreur !\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tableView_3emna->setModel(f->afficher_Fournisseur());

                 }
}

void MainWindow::on_supprimerF_2emna_clicked()
{
    click->play();
    int id = ui->id_supp_2emna->text().toInt();

        bool test=f->supprimer_Fournisseur(id);
        if(test)
        {
            ui->tableView_3emna->setModel(f->afficher_Fournisseur());

            QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                        QObject::tr("fournisseur supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_3emna->setModel(f->afficher_Fournisseur());

}

void MainWindow::on_supprimerE_2emna_clicked()
{
    click->play();
    int id = ui->idE_supp_2emna->text().toInt();

        bool test=v->supprimer_Equipement(id);
        if(test)
        {
            ui->tableView_4emna->setModel(v->afficher_Equipement());

            QMessageBox::information(nullptr, QObject::tr("Supprimer un équipement"),
                        QObject::tr("équipement supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un équipement"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_4emna->setModel(v->afficher_Equipement());
}


void MainWindow::on_radioButton_4emna_clicked()
{
    click->play();
    ui->tableView_3emna->setModel( f->trier_id());
}

void MainWindow::on_radioButton_2emna_clicked()
{
    click->play();
    ui->tableView_3emna->setModel( f->trier_nom());
}

void MainWindow::on_radioButton_3emna_clicked()
{
    click->play();
    ui->tableView_3emna->setModel( f->trier_matricule());
}

void MainWindow::on_p_rech_id_2emna_clicked()
{
    click->play();
    QString id = ui->rech_id_2emna->text();
    ui->tableView_4emna->setModel(v->recherche_id(id));
}

void MainWindow::on_p_rech_libelle_2emna_clicked()
{
    click->play();
    QString libelle = ui->rech_libelle_2emna->text();
    ui->tableView_4emna->setModel(v->recherche_libelle(libelle));
}

void MainWindow::on_p_rech_marque_2emna_clicked()
{
    click->play();
    QString marque = ui->rech_marque_2emna->text();
    ui->tableView_4emna->setModel(v->recherche_marque(marque));
}

void MainWindow::on_pdf_2emna_clicked()
{click->play();
    qDebug()<<click ->errorString();
    QPdfWriter pdf("C:/Users/emnat/OneDrive/Bureau/Atelier_Connexion/DesktopPdf.pdf");
                          QPainter painter(&pdf);
                         int i = 4000;
                              painter.setPen(Qt::red);
                              painter.setFont(QFont("Arial", 30));
                              painter.drawText(2300,1200,"Liste Des Equipements");
                              painter.setPen(Qt::black);
                              painter.setFont(QFont("Arial", 50));
                             // painter.drawText(1100,2000,afficheDC);
                              painter.drawRect(1500,200,7300,2600);
                              //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                              painter.drawRect(0,3000,9600,500);
                              painter.setFont(QFont("Arial", 9));
                              painter.drawText(300,3300,"ID_EQUIPEMENT");
                              painter.drawText(2300,3300,"LIBELLE");
                              painter.drawText(4300,3300,"MARQUE");
                              painter.drawText(6300,3300,"DATE_ACQUIS");




                              QSqlQuery query;
                              query.prepare("select * from equipements");
                              query.exec();
                              while (query.next())
                              {
                                  painter.drawText(300,i,query.value(0).toString());
                                  painter.drawText(2300,i,query.value(1).toString());
                                  painter.drawText(4300,i,query.value(2).toString());
                                  painter.drawText(6300,i,query.value(3).toString());




                                 i = i +500;
                              }
                              int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                  if (reponse == QMessageBox::Yes)
                                  {
                                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/emnat/OneDrive/Bureau/Atelier_Connexion/DesktopPdf.pdf"));

                                      painter.end();
                                  }
                                  if (reponse == QMessageBox::No)
                                  {
                                       painter.end();
                                  }
}



void MainWindow::showTimeemna()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->DigitalClock->setText(time_text);
      ui->DigitalClock1emna->setText(time_text);
        ui->DigitalClock2emna->setText(time_text);
          //   ui->DigitalClock4->setText(time_text);

}

void MainWindow::on_pushButtonemna_clicked()
{click->play();
    qDebug()<<click ->errorString();
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                  tr("Fichiers d'extension Excel (*.xls)"));
                  if (fileName.isEmpty())
                      return;

                  ExportExcelObject obj(fileName, "mydata", ui->tableView_3emna);

                  // you can change the column order and
                  // choose which colum to export
                  obj.addField(0, "ID", "char(20)");
                  obj.addField(1, "FOURNISSEUR", "char(20)");
                  obj.addField(2, "MATRICULE_FISCALE", "char(20)");
                  obj.addField(3, "ADRESSE_FOURNISSEUR", "char(20)");

                  //obj.addField(5, "servespeed3", "char(20)");


                  int retVal = obj.export2Excel();

                  if( retVal > 0)
                  {
                      QMessageBox::information(this, tr("FAIS!"),
                                               QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                               );
                  }
}


void MainWindow::changeEventemna(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}



void MainWindow::on_makeShotemna_clicked()
{click->play();
    qDebug()<<click ->errorString();
    /*
     WORKAROUND to escape "protected" limitation and use that freaking static function!
     */
    class Kek : public QThread
    {
    public:
        static void wait(unsigned long)
        {
            QThread::msleep(200);
        }
    };

    this->hide();
    qApp->processEvents();
#ifdef _WIN32
    //Sleep(3000);
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


void MainWindow::digit_pressed()
{
   // qDebug() << "test";
    QPushButton * button = (QPushButton *)sender();
    QString input;
    double labelnumber;

    if((ui->pushButton_add->isChecked() || ui->pushButton_divide->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_multiply->isChecked()) && (!user_is_typing_secondNumber))
    {
        user_is_typing_secondNumber=true;
        labelnumber = button->text().toDouble();
        input = QString::number(labelnumber,'g',15);
    }

    else
    {
        if(ui->labelemna->text().contains(".") && button->text() == "0")
        {
            input=ui->labelemna->text() + button->text();
        }
        else
        {
            labelnumber = (ui->labelemna->text() + button->text()).toDouble();
            input = QString::number(labelnumber,'g',15);
        }
        //labelnumber = (ui->label->text() + button->text()).toDouble();
    }
    ui->labelemna->setText(input);

}

void MainWindow::on_pushButton_dot_released()
{
    // check for appearance of decimal, exit function if there is one
         if(ui->labelemna->text().contains(".")){

                 return;
         }
    ui->labelemna->setText(ui->labelemna->text() + ".");
    //check for extra decimal
}

void MainWindow::unary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    double labelnumber;
    QString input;

    if(button->text() == "+/-")
    {
        labelnumber = (ui->labelemna->text()).toDouble();
        labelnumber *= -1;
        input = QString::number(labelnumber,'g',15);
        ui->labelemna->setText(input);
    }

    else if(button->text() == "%")
    {
        labelnumber = (ui->labelemna->text()).toDouble();
        labelnumber *= 0.01;
        input = QString::number(labelnumber,'g',15);
        ui->labelemna->setText(input);
    }

    //error correction codse is still missing
}

void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    user_is_typing_secondNumber=false;

    ui->labelemna->setText("0");
}

void MainWindow::on_pushButton_equals_released()
{
    double labelnumber,secondNum;
    QString input;
    labelnumber=0;

    secondNum = ui->labelemna->text().toDouble();

    if(ui->pushButton_add->isChecked())
    {
        labelnumber = firstNum + secondNum;
        ui->pushButton_add->setChecked(false);
    }

    else if(ui->pushButton_minus->isChecked())
    {
        labelnumber = firstNum - secondNum;
        ui->pushButton_minus->setChecked(false);
    }

    else if(ui->pushButton_multiply->isChecked())
    {
        labelnumber = firstNum * secondNum;
        ui->pushButton_multiply->setChecked(false);
    }

    else if(ui->pushButton_divide->isChecked())
    {
        labelnumber = firstNum / secondNum;
        ui->pushButton_divide->setChecked(false);
    }

    input = QString::number(labelnumber,'g',15);
    ui->labelemna->setText(input);

    user_is_typing_secondNumber=false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    //double labelnumber;
    //QString input;

    firstNum = ui->labelemna->text().toDouble();
    button->setChecked(true);

}





void MainWindow::on_tache_emna_1_clicked()
{click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_tache_emna_clicked()
{click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(10);

}

void MainWindow::on_backButton_5_clicked()
{click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_return_5_clicked()
{click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(2);
}

/************************Ayedi**********************************************/


void MainWindow::on_ajouteryass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    int id = ui->idyass->text().toInt();
            QString adresse_siege= ui->adreyass->text();
            QString proprietaire_journal=ui->proyass->text();
            QString libelle_journal=ui->libeyass->text();


          journaux a(id,adresse_siege,proprietaire_journal,libelle_journal);
          bool test=a.ajouter();
          if(test)
        {

        QMessageBox::information(nullptr, QObject::tr("Ajouter un journaux"),
                          QObject::tr("journaux ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
       // ui->tab_article->setModel(g->afficher());

        }
          else

              QMessageBox::critical(nullptr, QObject::tr("Ajouter un journaux"),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        //  ui->tab_article->setModel(g->afficher());
}


void MainWindow::on_pushButtonyass_clicked()
{click->play();
    qDebug()<<click ->errorString();
   ui->tabjournauxyass->setModel(t->afficher());
}

void MainWindow::on_modifieryass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    int id = ui->id_3yass->text().toInt();
    QString adresse_siege = ui->adre_3yass->text();
    QString proprietaire_journal= ui->pro_3yass->text();
    QString libelle_journal= ui->libe_3yass->text();



              journaux p(id,adresse_siege,proprietaire_journal,libelle_journal);

                 bool test =p.modifier();

                 if(test)

                 {
                     QMessageBox::information(nullptr, QObject::tr("Modifier journaux"),
                                 QObject::tr("journaux modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tabjournauxyass->setModel(t->afficher());

                 }

                 else

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Modifier une journaux"),
                                 QObject::tr("Erreur !\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                  ui->tabjournauxyass->setModel(t->afficher());

                 }

}

void MainWindow::on_supprimeryass_clicked()
{click->play();
    qDebug()<<click ->errorString();

    int id = ui->id_4yass->text().toInt();

        bool test=t->supprimer(id);
        if(test)
        {
            ui->tabjournauxyass->setModel(a->afficher());

            QMessageBox::information(nullptr, QObject::tr("Supprimer une journaux"),
                        QObject::tr("journaux supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une journaux"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tabjournauxyass->setModel(t->afficher());

}

void MainWindow::on_rechercher_2yass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    QString adresse_siege= ui->id_reyass->text();
    ui->resultatyass->setModel(t->rechercher(adresse_siege));
    ui->tabjournauxyass->setModel(t->afficher());
}

void MainWindow::on_trieyass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    bool test = t->tri_adresse_siege();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des journaux"),
                           QObject::tr("succès.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tabjournauxyass->setModel(t->tri_adresse_siege());}//refresh
           else
               QMessageBox::critical(nullptr, QObject::tr("tri des journaux"),
                           QObject::tr("Erreur !\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tabjournauxyass->setModel(t->tri_adresse_siege());
}

void MainWindow::on_ajouter_2yass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    int id_commande = ui->id_2yass->text().toInt();
           int date_commande= ui->date_2yass->text().toInt();
            int quantite_commande=ui->qua_2yass->text().toInt();



         commande b(id_commande,date_commande,quantite_commande);
          bool test=b.ajouterr();
          if(test)
        {

        QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
                          QObject::tr("commande ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
       // ui->tab_article->setModel(g->afficher());

        }
          else

              QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        //  ui->tab_article->setModel(g->afficher());
}


void MainWindow::on_pushButton_3yass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    ui->tabcommandeyass->setModel(n->afficherr());
 }


void MainWindow::on_rechercher_5yass_clicked()
{click->play();
    qDebug()<<click ->errorString();
   int date_commande= ui->date_commande_3yass->text().toInt();
    ui->resultat_3yass->setModel(n->rechercherr(date_commande));
    ui->tabcommandeyass->setModel(n->afficherr());
}

void MainWindow::on_trie_3yass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    bool test = n->tri_id_commande();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des commande"),
                           QObject::tr("succès.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tabcommandeyass->setModel(n->tri_id_commande());}//refresh
           else
               QMessageBox::critical(nullptr, QObject::tr("tri des commande"),
                           QObject::tr("Erreur !\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tabcommandeyass->setModel(n->tri_id_commande());
}

void MainWindow::on_modifier_3yass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    int id_commande = ui->id_5yass->text().toInt();
    int date_commande = ui->adre_6yass->text().toInt();
    int quantite_commande= ui->pro_6yass->text().toInt();




              commande b(id_commande,date_commande,quantite_commande );

                 bool test =b.modifierr();

                 if(test)

                 {
                     QMessageBox::information(nullptr, QObject::tr("Modifier une commande"),
                                 QObject::tr("commande modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tabcommandeyass->setModel(b.afficherr());

                 }

                 else

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Modifier une commande"),
                                 QObject::tr("Erreur !\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

                     ui->tabcommandeyass->setModel(b.afficherr());

                 }
}

void MainWindow::on_supprimer_3yass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    int id_commande = ui->id_6yass->text().toInt();

        bool test=n->supprimerr(id_commande);
        if(test)
        {
            ui->tabcommandeyass->setModel(n->afficherr());

            QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                        QObject::tr("commande supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tabcommandeyass->setModel(n->afficherr());

}

void MainWindow::on_afficher_2yass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    ui->tabcommandeyass->setModel(n->afficherr());
 }




void MainWindow::on_journauxyass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_commandeyass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_return1yass_clicked()
{click->play();
    qDebug()<<click ->errorString();
  ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_return_2yass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_mailingyass_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    Smtp* smtp;
        smtp = new Smtp("Smartnewsagency1@gmail.com", "SMARTNEWSAGENCY", "smtp.gmail.com");
        //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

        smtp->sendMail(ui->text_emailyass->text(), ui->text_emailyass->text() ,ui->text_textyass->text(), ui->text_messageyass->text());

}



void MainWindow::on_excelyass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                            tr("Fichiers d'extension Excel (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "mydata", ui->tabcommandeyass);

            // you can change the column order and
            // choose which colum to export
            obj.addField(0, "id", "char(20)");
            obj.addField(1, "date", "char(20)");
            obj.addField(2, "quantite", "char(20)");



            int retVal = obj.export2Excel();

            if( retVal > 0)
            {
                QMessageBox::information(this, tr("FAIS!"),
                                         QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                         );
            }
}

void MainWindow::changeEventyass(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/*
 WORKAROUND to escape "protected" limitation and use that freaking static function!
 */


void MainWindow::on_makeShotyass_clicked()
{class Kek : public QThread
    {
    public:
        static void wait(unsigned long)
        {
            QThread::msleep(200);
        }
    };
    this->hide();
    qApp->processEvents();
#ifdef _WIN32
    //Sleep(3000);
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

void MainWindow::on_PDFyass_clicked()
{click->play();
    qDebug()<<click ->errorString();
    QPdfWriter pdf("C:/Users/yassi/Desktop/Atelier_Connexion/PDF.pdf");
    QPainter painter(&pdf);
         int i = 4000;
     painter.setPen(Qt::red);
     painter.setFont(QFont("Arial", 30));
     painter.drawText(2300,1200,"Liste Des journaux");
     painter.setPen(Qt::black);
     painter.setFont(QFont("Arial", 50));
     //painter.drawText(1100,2000,afficheDC);
     painter.drawRect(1500,200,7300,2600);
     painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/yassi/Desktop/Atelier_Connexion/PDF.pdf"));
     painter.drawRect(0,3000,9600,500);
     painter.setFont(QFont("Arial", 9));
     painter.drawText(300,3300,"id");
     painter.drawText(1800,3300,"adresse_siege");
     painter.drawText(3300,3300,"PROPRIETAIRE_JOURNAL");
     painter.drawText(4800,3300,"LIBELLE_JOURNAL");




     QSqlQuery query;
     query.prepare("select * from journaux");
          query.exec();
          while (query.next())
             {
              painter.drawText(300,i,query.value(0).toString());
              painter.drawText(1800,i,query.value(1).toString());
              painter.drawText(3300,i,query.value(2).toString());
              painter.drawText(4800,i,query.value(3).toString());
              painter.drawText(6300,i,query.value(4).toString());

              i = i +500;
                                      }
    qDebug()<<"le pdf a ete cree";
      QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
}


void MainWindow::updateQRImageyass()
{
    int sizeText = ui->pTextEditQRTextyass->toPlainText().size();
    ui->labelSizeTextyass->setText( QString::number( sizeText ) );

    int levelIndex = 1;
    int versionIndex = 0;
    bool bExtent = true;
    int maskIndex = -1;
    QString encodeString = ui->pTextEditQRTextyass->toPlainText();

    successfulEncodingyass = qrEncodeyass.EncodeData( levelIndex, versionIndex, bExtent, maskIndex, encodeString.toUtf8().data() );
    if ( !successfulEncodingyass )
    {
        ui->image_labelyass->clear();
        ui->image_labelyass->setText( tr("QR Code...") );
        ui->labelSizeyass->clear();
        ui->pButtonSaveyass->setEnabled( successfulEncodingyass );
        return;
    }

    int qrImageSize = qrEncodeyass.m_nSymbleSize;

    // Создаем двумерный образ кода
    encodeImageSizeyass = qrImageSize + ( QR_MARGIN * 2 );
    QImage encodeImage( encodeImageSizeyass, encodeImageSizeyass, QImage::Format_Mono );
    encodeImage.fill( 1 );

    // Создать двумерный образ кода
    for ( int i = 0; i < qrImageSize; i++ )
        for ( int j = 0; j < qrImageSize; j++ )
            if ( qrEncodeyass.m_byModuleData[i][j] )
                encodeImage.setPixel( i + QR_MARGIN, j + QR_MARGIN, 0 );

    ui->image_labelyass->setPixmap( QPixmap::fromImage( encodeImage ) );

    setScaleyass(ui->sBoxScaleyass->value());
    ui->pButtonSaveyass->setEnabled( successfulEncodingyass );
}
void MainWindow::setScaleyass(int scale)
{
    if ( successfulEncodingyass )
    {
        int scale_size = encodeImageSizeyass * scale;

        const QPixmap & scale_image = ui->image_labelyass->pixmap()->scaled( scale_size, scale_size );
        ui->image_labelyass->setPixmap( scale_image );

        const QString & size_info = QString( "%1x%2" ).arg( scale_size ).arg( scale_size );
        ui->labelSizeyass->setText( size_info );
    }
}
void MainWindow::on_pButtonSaveyass_clicked()
{
    const QString & path = QFileDialog::getSaveFileName( this, QString::null, "qrcode", saveFormats() );
    if ( path.isNull() )
        return;

    ui->image_labelyass->pixmap()->save( path );
}
void MainWindow::on_sBoxScaleyass_valueChanged(int arg1)
{
    setScaleyass( arg1 );
}
void MainWindow::on_pTextEditQRTextyass_textChanged()
{
    updateQRImageyass();
}
void MainWindow::on_pButtonQuityass_clicked()
{
    close();
}

void MainWindow::closeEventyass(QCloseEvent *)
{
    QSettings ini( getIniPath(), QSettings::IniFormat );
    ini.setValue( ui->splitter_6yass->objectName(), ui->splitter_6yass->saveState() );
    ini.setValue( ui->splitter_5yass->objectName(), ui->splitter_5yass->saveState() );
    ini.setValue( ui->sBoxScaleyass->objectName(), ui->sBoxScaleyass->value() );
  //  ini.setValue( "State", saveState() );
    ini.setValue( "Geometry", saveGeometry() );

    qApp->quit();
}
bool MainWindow::eventFilteryass( QObject * object, QEvent * event )
{
    QScrollArea * scrollArea = ui->scrollArea_3yass;

    if ( object == scrollArea )
    {
        if ( event->type() == QEvent::MouseButtonPress )
        {
            QMouseEvent * mouseEvent = static_cast < QMouseEvent * > ( event );
            if ( mouseEvent->button() == Qt::LeftButton )
            {
                lastPosyass = mouseEvent->pos();

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
                lastPosyass -= mouseEvent->pos();

                int hValue = scrollArea->horizontalScrollBar()->value();
                int vValue = scrollArea->verticalScrollBar()->value();

                scrollArea->horizontalScrollBar()->setValue( lastPosyass.x() + hValue );
                scrollArea->verticalScrollBar()->setValue( lastPosyass.y() + vValue );

                lastPosyass = mouseEvent->pos();
            }

        }else if ( event->type() == QEvent::MouseButtonRelease )
            scrollArea->setCursor( Qt::ArrowCursor );
    }

    return QWidget::eventFilter(object, event);
}













void MainWindow::on_backButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

