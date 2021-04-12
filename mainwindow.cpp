#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "publicite.h"
#include "sponsors_crud.h"
#include "qmessagebox.h"
#include "qsqlquery.h"
#include "qpainter.h"
#include "qpdfwriter.h"
#include "QtPrintSupport/qprinter.h"
#include "qdebug.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    click = new QMediaPlayer();
        click->setMedia(QUrl::fromLocalFile("C:/Users/Sahar Zouari/Desktop/PROJET C++/projet_qt/click.wav"));
        animation =new QPropertyAnimation(ui->pushButton,"geometry");
        animation->setDuration(5000);
        animation->setStartValue(ui->pushButton->geometry());
        animation->setEndValue(QRect(220,120,361,71));
        animation->start();
        animation1 =new QPropertyAnimation(ui->pushButton_2,"geometry");
        animation1->setDuration(5000);
        animation1->setStartValue(ui->pushButton_2->geometry());
        animation1->setEndValue(QRect(220,210,361,71));
        animation1->start();
       // ui->id_publicite_4->setValidator(new QIntValidator(1, 999999, this));
        //ui->id_publicite_2->setValidator(new QIntValidator(1, 999999, this));
       // ui->id_4->setValidator(new QIntValidator(1, 999999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_p_ajouter_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_publicite = ui->id_publicite->text().toInt();
    int id_client = ui->id_client->text().toInt();
    QString type_publicite= ui->type_publicite->text();
    float tarif_publicite= ui->tarif_publicite->text().toFloat();
    QString date_lancement=ui->date_lancement->text();
    QString duree_publicite=ui->duree_publicite->text();

          publicite p(id_publicite,id_client,type_publicite,tarif_publicite,date_lancement,duree_publicite);
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

}

void MainWindow::on_Afficherp_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->tab_pub->setModel(a->afficher());
}

void MainWindow::on_Modifierp_clicked()
{
    click->play();
    qDebug()<<click ->errorString();

    int id_publicite = ui->id_publicite_2->text().toInt();
    int id_client = ui->id_client_2->text().toInt();
    QString type_publicite= ui->type_publicite_2->text();
    float tarif_publicite= ui->tarif_publicite_2->text().toFloat();
    QString date_lancement=ui->date_lancement_2->text();
    QString duree_publicite=ui->duree_publicite_2->text();


              publicite p(id_publicite,id_client,type_publicite,tarif_publicite,date_lancement,duree_publicite);

                 bool test =p.modifier();

                 if(test)

                 {
                     QMessageBox::information(nullptr, QObject::tr("Modifier une publicite"),
                                 QObject::tr("Publicite modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tab_pub->setModel(a->afficher());

                 }

                 else

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Modifier une publicite"),
                                 QObject::tr("Erreur !\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_pub->setModel(a->afficher());

                 }

}

void MainWindow::on_supprimerp_clicked()
{

    click->play();
    qDebug()<<click ->errorString();

        int id = ui->id_3->text().toInt();
        if (ui->id_3->text().isEmpty())
            {

                QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;

            }
           else
        {
            bool test=b->supprimer(id);
            if(test)
            {
                ui->tab_pub->setModel(b->afficher());

                QMessageBox::information(nullptr, QObject::tr("Supprimer une publicité"),
                            QObject::tr("publicité supprimée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer une publicité"),
                            QObject::tr("Erreur !\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_pub->setModel(b->afficher());
}
}





void MainWindow::on_recherche_publicite_clicked()
{

    click->play();
    qDebug()<<click ->errorString();
        QString type_publicite= ui->type_recherche->text();
        ui->resultat->setModel(d->rechercher(type_publicite));
        ui->tab_pub->setModel(b->afficher());

}

void MainWindow::on_tri_publicite_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    bool test = c->tri_type_publicite();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des publicités"),
                           QObject::tr("succès.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_pub->setModel(c->tri_type_publicite());}//refresh
           else
               QMessageBox::critical(nullptr, QObject::tr("tri des publicités"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_pub->setModel(c->tri_type_publicite());}//refresh



void MainWindow::on_pushButton_clicked()
{

        click->play();
        qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_4_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_p_ajouter_2_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_sponsor = ui->id_sponsor->text().toInt();
    QString domaine_sponsor = ui->domaine_sponsor->text();
    QString nom_sponsor= ui->nom_sponsor->text();
    QString adresse_sponsor=ui->adresse_sponsor->text();
    QString type_sponsor=ui->type_sponsor->text();

          sponsors_crud p(id_sponsor,domaine_sponsor,nom_sponsor,adresse_sponsor,type_sponsor);
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


void MainWindow::on_Afficherp_2_clicked()
{ click->play();
    qDebug()<<click ->errorString();
      ui->tab_sponsor->setModel(e->afficher());
}

void MainWindow::on_Modifierp_2_clicked()
{  click->play();
    qDebug()<<click ->errorString();
    int id_sponsor = ui->id_sponsor_2->text().toInt();
    QString domaine_sponsor= ui->domaine_sponsor_2->text();
    QString nom_sponsor= ui->nom_sponsor_2->text();
    QString adresse_sponsor=ui->adresse_sponsor_2->text();
    QString type_sponsor=ui->type_sponsor_2->text();


              sponsors_crud p(id_sponsor,domaine_sponsor,nom_sponsor,adresse_sponsor,type_sponsor);

                 bool test =p.modifier();

                 if(test)

                 {
                     QMessageBox::information(nullptr, QObject::tr("Modifier un sponsor"),
                                 QObject::tr("Sponsor modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tab_sponsor->setModel(e->afficher());

                 }

                 else

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Modifier un sponsor"),
                                 QObject::tr("Erreur !\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_sponsor->setModel(e->afficher());

                 }
}


void MainWindow::on_supprimerp_2_clicked()
{  click->play();
    qDebug()<<click ->errorString();
    int id_sponsor = ui->id_sponsor_3->text().toInt();
    if (ui->id_sponsor_3->text().isEmpty())
        {

            QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID!!!!") ;

        }
       else
{
        bool test=f->supprimer(id_sponsor);
        if(test)
        {
            ui->tab_sponsor->setModel(f->afficher());

            QMessageBox::information(nullptr, QObject::tr("Supprimer un sponsor"),
                        QObject::tr("Sponsor supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un sponsor"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_sponsor->setModel(f->afficher());
}
}

void MainWindow::on_tri_publicite_2_clicked()
{click->play();
    qDebug()<<click ->errorString();
    bool test = h->tri_nom_sponsor();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des types de sponsors"),
                           QObject::tr("succès.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_sponsor->setModel(h->tri_nom_sponsor());}//refresh
           else
               QMessageBox::critical(nullptr, QObject::tr("tri des types de sponsors"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_sponsor->setModel(h->tri_nom_sponsor());}//refresh


void MainWindow::on_recherche_publicite_2_clicked()
{click->play();
    qDebug()<<click ->errorString();
    QString nom_sponsor= ui->nom_recherche->text();
    ui->resultat_2->setModel(h->rechercher(nom_sponsor));
    ui->tab_sponsor->setModel(f->afficher());
}


void MainWindow::on_pushButton_5_clicked()
{click->play();
    qDebug()<<click ->errorString();
    bool test = h->tri_type_sponsor();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des types de sponsors"),
                           QObject::tr("succès.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_sponsor->setModel(h->tri_type_sponsor());}//refresh
           else
               QMessageBox::critical(nullptr, QObject::tr("tri des types de sponsors"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_sponsor->setModel(h->tri_type_sponsor());}//refresh




void MainWindow::on_pushButton_7_clicked()
{click->play();
    qDebug()<<click ->errorString();
    sponsors_crud pdf;
            QPrinter printer;
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("C:/Users/Sahar Zouari/Desktop/PROJET C++/projet_qt/pdf");
            QPainter painter;
            if(!painter.begin(&printer)){
                qWarning("failed to open");}
                QSqlQuery qry;
                qry.prepare("select * from sponsors");
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
                painter.drawText(300,100,"liste des sponsors");
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
              qDebug()<<"le pdf a été crée";
              QMessageBox::information(this,"pdf crée","ce pdf a été crée");


}

void MainWindow::on_pushButton_6_clicked()
{
    click->play();
        qDebug()<<click ->errorString();
        bool test = s->tri_id_publicite();
               if (test){
                   QMessageBox::information(nullptr, QObject::tr("tri des id des publicités"),
                               QObject::tr("succès.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
               ui->tab_pub->setModel(s->tri_id_publicite());}//refresh
               else
                   QMessageBox::critical(nullptr, QObject::tr("tri des id des publicités"),
                               QObject::tr("Erreur !\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
               ui->tab_pub->setModel(s->tri_id_publicite());}//refresh




void MainWindow::on_tab_pub_activated(const QModelIndex &index)
{
    QString val=ui->tab_pub->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from publicite where id_publicite='"+val+"'or id_client='"+val+"'or type_publicite='"+val+"'or tarif_publicite='"+val+"'or date_lancement='"+val+"'or duree_publicite='"+val+"'" );

        if(query.exec())
        {

         while(query.next())
        {
                ui->id_publicite_2->setText(query.value(0).toString());
                ui->id_client_2->setText(query.value(1).toString());
                ui->type_publicite_2->setText(query.value(2).toString());
                ui->tarif_publicite_2->setText(query.value(3).toString());
                ui->date_lancement_2->setText(query.value(4).toString());
                ui->duree_publicite_2->setText(query.value(5).toString());



    }}
        else {
            QMessageBox::critical(nullptr, QObject::tr("publicite"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_tab_sponsor_activated(const QModelIndex &index)
{
    QString val=ui->tab_sponsor->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from sponsors_crud where id_sponsor='"+val+"'or domaine_sponsor='"+val+"'or nom_sponsor='"+val+"'or adresse_sponsor='"+val+"'or type_sponsor='"+val+"'");

        if(query.exec())
        {

         while(query.next())
        {
                ui->id_sponsor_2->setText(query.value(0).toString());
                ui->domaine_sponsor_2->setText(query.value(1).toString());
                ui->nom_sponsor_2->setText(query.value(2).toString());
                ui->adresse_sponsor_2->setText(query.value(3).toString());
                ui->type_sponsor_2->setText(query.value(3).toString());


    }}
        else {
            QMessageBox::critical(nullptr, QObject::tr("sponsors_crud"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

}
