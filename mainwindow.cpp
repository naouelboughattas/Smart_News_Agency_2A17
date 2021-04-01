#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "article.h"
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{

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

    }
      else

          QMessageBox::critical(nullptr, QObject::tr("Ajouter un article"),
                      QObject::tr("Erreur !\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      ui->tab_article->setModel(g->afficher());
    }

void MainWindow::on_modifier_clicked()
{
    int id_Article = ui->le_ID_2->text().toInt();
    QString libelle_Article= ui->le_libelle_2->text();
    QString description_Article=ui->la_description_2->text();
    int nbre_page=ui->le_nbredepage_2->text().toInt();
    int priorite=ui->la_priorite_2->text().toInt();
    QString format=ui->le_format->text();


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
}

void MainWindow::on_supprimer_clicked()
{


    int id_Article = ui->id_3->text().toInt();

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
    }





void MainWindow::on_pushButton_clicked()
{
    ui->tab_article->setModel(g->afficher());
}

void MainWindow::on_gestion_article_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_return_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_trier_clicked()
{

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

void MainWindow::on_recherche_clicked()
{
    QString libelle_Article= ui->libelle_rechercher->text();
    ui->resultat->setModel(r->rechercher(libelle_Article));
    ui->tab_article->setModel(g->afficher());
}

void MainWindow::on_pdf_clicked()
{
    Article E4;
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:/Users/Asus/Desktop/qt_pdf/pdf");

        QPainter painter;
        if(!painter.begin(&printer)){
            qWarning("failed to open");}
            QSqlQuery qry;
            qry.prepare("select * from article");
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
            painter.drawText(300,100,"liste des articles");
            painter.setFont(QFont("Times",15));
            painter.setPen(Qt::black);
         painter.drawText(100,kk,n);
         painter.drawText(200,kk,d);
         painter.drawText(100,dd,e);
         painter.drawText(200,dd,f);
         painter.drawText(100,bb,g);
        }
          painter.end();
        }

    qDebug()<<"le pdf a ete cree";
    QMessageBox::information(this,"pdf cree","ce pdf a ete cree");


}
