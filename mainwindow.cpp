#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "article.h"
#include "statistique.h"
#include "historique.h"
#include "exportexcelobjet.h"
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
#include"qdebug.h"
#include <QPropertyAnimation>
#include "smtp.h"
#include <QFileDialog>
#include "qrcode.h"
#include <QImageWriter>
#include"qmainwindow.h"
#include"mainwindow.h"
#include <QDesktopServices>
#include <QMediaPlayer>
#include <QtCharts/QChartView>
#include <QtCharts/qlineseries.h>
#include <QtCharts/QBarSet>
#include "qsqlquery.h"
#include <QSound>
#include <QFile>
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
#include <QTimer>
#include <QDateTime>
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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
  successfulEncoding(false)
{
    QString windowTitle("newsgenix");
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
        timer->start();
    QPropertyAnimation * animation = new QPropertyAnimation(ui->animation, "geometry");
        animation->setDuration(10000);
        animation->setLoopCount(-1);
        animation->setStartValue(QRect(-20, -125, 371, 400));
        animation->setEndValue(QRect(1050, -125, 371, 400));
        animation->start();
    click = new QMediaPlayer();
            click->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/projetqt/Atelier_Connexion/click.wav"));
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
        int priorite=ui->la_priorite->text().toInt();
        QString format=ui->le_format->text();

      Article a(id_Article,libelle_Article,description_Article,nbre_page,priorite,format);
      bool test=a.ajouter();
      if(test)
    {

    QMessageBox::information(nullptr, QObject::tr("Ajouter un article"),
                      QObject::tr("article ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_article->setModel(g->afficher());
    Smtp* smtp;
        smtp = new Smtp("smartnewsagency1@gmail.com", "SMARTNEWSAGENCY", "smtp.gmail.com");
        //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

        smtp->sendMail("smartnewsagency1@gmail.com", "smartnewsagency1@gmail.com" , "Mail d'ajout","Bonjour,\n Votre article a été ajouté avec succée. \nCordialement ");

    }
      else

          QMessageBox::critical(nullptr, QObject::tr("Ajouter un article"),
                      QObject::tr("Erreur !\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      ui->tab_article->setModel(g->afficher());
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
                 ui->tab_article->setModel(g->afficher());

             }

             else

             {
                 QMessageBox::critical(nullptr, QObject::tr("modifier un article"),
                             QObject::tr("Erreur !\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_article->setModel(g->afficher());

             }
             QString textajouter;
             int k=id_Article;
             historique h;
             QSqlQuery qry;
             qry.prepare("select * from article");
             textajouter="La modification d'un article a la base de donnees de reference = "+QString::number(k)+" a ete effectue avec succees";
             h.write(textajouter);
}

void MainWindow::on_supprimer_clicked()
{

    click->play();
    qDebug()<<click ->errorString();
    int id_Article = ui->le_ID_2->text().toInt();

        bool test=g->supprimer(id_Article);
        if(test)
        {
            ui->tab_article->setModel(g->afficher());

            QMessageBox::information(nullptr, QObject::tr("Supprimer un article"),
                        QObject::tr("article supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un article"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_article->setModel(g->afficher());
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
    ui->tab_article->setModel(g->afficher());
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
    bool test = t->tri_libelle();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des articles"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_article->setModel(t->tri_libelle());}//refresh
           else
           {QMessageBox::critical(nullptr, QObject::tr("tri des articles"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_article->setModel(t->tri_libelle());}//refresh
}

void MainWindow::on_recherche_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    QString libelle_Article= ui->libelle_rechercher->text();
    ui->resultat->setModel(r->rechercher(libelle_Article));
    ui->tab_article->setModel(g->afficher());
}

void MainWindow::on_pdf_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
        QPdfWriter pdf("C:/Users/Asus/Desktop/qt_pdf/pdf_article");
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
ui->tab_categorie->setModel(d->afficher_c());
Smtp* smtp;
    smtp = new Smtp("smartnewsagency1@gmail.com", "SMARTNEWSAGENCY", "smtp.gmail.com");
    //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

    smtp->sendMail("smartnewsagency1@gmail.com", "smartnewsagency1@gmail.com" , "Mail d'ajout","Bonjour,\n Votre Commande a été ajoutée avec succée. \nCordialement ");
}
  else

      QMessageBox::critical(nullptr, QObject::tr("Ajouter une categorie"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tab_categorie->setModel(d->afficher_c());
}

void MainWindow::on_pushButton_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->tab_categorie->setModel(d->afficher_c());
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
                 ui->tab_categorie->setModel(d->afficher_c());

             }

             else

             {
                 QMessageBox::critical(nullptr, QObject::tr("modifier une categorie"),
                             QObject::tr("Erreur !\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_categorie->setModel(d->afficher_c());

             }
}

void MainWindow::on_supprimer_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_Categorie = ui->le_ID_6->text().toInt();

        bool test=d->supprimer_c(id_Categorie);
        if(test)
        {
            ui->tab_categorie->setModel(d->afficher_c());

            QMessageBox::information(nullptr, QObject::tr("Supprimer une categorie"),
                        QObject::tr("article supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une categorie"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_categorie->setModel(d->afficher_c());

}

void MainWindow::on_trier_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    bool test = f->tri_libelle_c();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des categories"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_categorie->setModel(f->tri_libelle_c());}//refresh
           else
           {QMessageBox::critical(nullptr, QObject::tr("tri des categories"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_categorie->setModel(f->tri_libelle_c());}//refresh
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
    ui->tab_categorie->setModel(d->afficher_c());
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
    bool test = t->tri_id();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des articles"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_article->setModel(t->tri_id());}//refresh
           else
           {QMessageBox::critical(nullptr, QObject::tr("tri des articles"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_article->setModel(t->tri_id());}//refresh
}

void MainWindow::on_trier2_2_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    bool test = f->tri_id_c();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des categories"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_categorie->setModel(f->tri_id_c());}//refresh
           else
           {QMessageBox::critical(nullptr, QObject::tr("tri des categories"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_categorie->setModel(f->tri_id_c());}//refresh
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

void MainWindow::on_cancel_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_signup_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_save_clicked()
{
    QString username= ui->username->text();
    QString password= ui->password->text();
    QString nom= ui->name->text();
    QString prenom= ui->lastname->text();
    QString mail= ui->email->text();



    account e(username,password,nom,prenom,mail);
    bool test=e.ajouter();
    if(test)
  {
        qDebug()<<click ->errorString();
        ui->stackedWidget->setCurrentIndex(0);
        //refresh
           // ui->comboBox->setModel(tmpmatch.afficher_list());
  QMessageBox::information(nullptr, QObject::tr("Ajouter account"),
                    QObject::tr("account ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter account"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->name->clear();
    ui->username->clear();
    ui->lastname->clear();
    ui->email->clear();
    ui->password->clear();

    //hide();

}

void MainWindow::on_login_clicked()
{
    QString username=ui->username_2->text();
       QString password= ui->password_2->text();
int n = username.size();
int n1 = password.size();
if ((n != 0  or n1  != 0)  ) {


  if (n>3 and n<21)

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
                  qDebug()<<click ->errorString();
                  ui->stackedWidget->setCurrentIndex(2);
                  QMessageBox::information(nullptr, QObject::tr("LOGIN"),
                                                      QObject::tr("\nCONNNECTED SUCCESFULLY !\n"), QMessageBox::Ok);
                   //this->hide();

               }
                    else
                       { QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                                    QObject::tr("\nUser Name or Password is incorrect try again !\n"), QMessageBox::Cancel);
              ui->password->setStyleSheet("border: 1px solid red");
              ui->username->setStyleSheet("border: 1px solid red");
              ui->username->clear();
              ui->password->clear();}

      }
      else
      { QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                                  QObject::tr("\n PASSWORD MUST BE BETWEEN \n"
                                              "6 AND 21 CHARACHTERS"), QMessageBox::Cancel);
          ui->password->setStyleSheet("border: 1px solid red");
          ui->username->setStyleSheet("border: 1px solid red");}
  }

  else
     {  QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                  QObject::tr("\n USER NAME MUST BE BETWEEN \n"
                              "4 AND 21 CHARACHTERS"), QMessageBox::Cancel);
      ui->password->setStyleSheet("border: 1px solid red");
      ui->username->setStyleSheet("border: 1px solid red");}
}

else {

                    QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                                QObject::tr("\n PLEASE FILL THE INFO\n"), QMessageBox::Cancel);
                    ui->password->setStyleSheet("border: 1px solid red");
                    ui->username->setStyleSheet("border: 1px solid red");


}
}

void MainWindow::on_exit_clicked()
{
    this->close();
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
    statistique s;
    s.exec();
}

void MainWindow::on_historique_clicked()
{
    ui->stackedWidget_historique_4->setCurrentIndex(1);
}

void MainWindow::on_back_clicked()
{
    ui->stackedWidget_historique_4->setCurrentIndex(0);
    ui->Tab_C->show();
    ui->textBrowser_4->hide();
}

void MainWindow::on_historique_2_clicked()
{
    ui->Tab_C->hide();
    historique h;
    ui->textBrowser_4->show();
    ui->textBrowser_4->setPlainText(h.read());
}

void MainWindow::on_pushButton_5_clicked()
{
    Smtp* smtp;
        smtp = new Smtp("Smartnewsagency1@gmail.com", "SMARTNEWSAGENCY", "smtp.gmail.com");
        //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

        smtp->sendMail(ui->mail_2->text(), ui->mail_2->text() ,ui->objet_2->text(), ui->message_2->text());
        qDebug()<<"mail a été envoyé";
        QMessageBox::information(this,"mail envoyé","mail a ete envoyé");
}

void MainWindow::on_excel_clicked()
{
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
    QString time_text=time.toString("hh : mm : ss");
    ui->DigitalClock->setText(time_text);
}
