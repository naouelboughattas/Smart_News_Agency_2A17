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
#include "smtp.h"
#include "qrcode.h"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"
#include"qsqlquery.h"
#include "qobject.h"
#include "qsqlerror.h"
#include"QIntValidator"
#include"qcoreapplication.h"
#include"qdebug.h"
#include <QPropertyAnimation>

#include <QImageWriter>
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



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    successfulEncoding(false)
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
        ui->tarif_publicite->setValidator(new QIntValidator(1, 999999, this));
        ui->tarif_publicite_2->setValidator(new QIntValidator(1, 999999, this));
        ui->id_publicite_2->setValidator(new QIntValidator(1, 999999, this));
       ui->id_3->setValidator(new QIntValidator(1, 999999, this));
        ui->id_publicite->setValidator(new QIntValidator(1,999999, this));
        ui->id_client->setValidator(new QIntValidator(1, 999999, this));
        ui->id_client_2->setValidator(new QIntValidator(1, 999999, this));
        ui->id_sponsor->setValidator(new QIntValidator(1, 999999, this));
        ui->id_sponsor_2->setValidator(new QIntValidator(1, 999999, this));
        ui->id_sponsor_3->setValidator(new QIntValidator(1, 999999, this));

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
    QPdfWriter pdf("C:/Users/Sahar Zouari/Desktop/PROJET C++/projet_qt/PDF.pdf");
QPainter painter(&pdf);
     int i = 4000;
 painter.setPen(Qt::red);
 painter.setFont(QFont("Arial", 30));
 painter.drawText(2300,1200,"Liste Des Sponsors");
 painter.setPen(Qt::black);
 painter.setFont(QFont("Arial", 50));
 //painter.drawText(1100,2000,afficheDC);
 painter.drawRect(1500,200,7300,2600);
 painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Sahar Zouari/Desktop/PROJET C++/projet_qt/PDF.pdf"));
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

void MainWindow::on_mailing_clicked()
{
    click->play();
        qDebug()<<click ->errorString();
        Smtp* smtp;
            smtp = new Smtp("smartnewsagency1@gmail.com", "SMARTNEWSAGENCY", "smtp.gmail.com");
            //connect(smtp, SIGNAL(clicked()), this, SLOT(on_Mail_clicked()));

            smtp->sendMail("smartnewsagency1@gmail.com", "smartnewsagency1@gmail.com" , "test","test ");
}


/*void MainWindow::on_exit_clicked()
{
    this->close();
}*/
void MainWindow::updateQRImage()
{
    int sizeText = ui->pTextEditQRText_3->toPlainText().size();
    ui->labelSizeText_3->setText( QString::number( sizeText ) );

    int levelIndex = 1;
    int versionIndex = 0;
    bool bExtent = true;
    int maskIndex = -1;
    QString encodeString = ui->pTextEditQRText_3->toPlainText();

    successfulEncoding = qrEncode.EncodeData( levelIndex, versionIndex, bExtent, maskIndex, encodeString.toUtf8().data() );
    if ( !successfulEncoding )
    {
        ui->image_label_3->clear();
        ui->image_label_3->setText( tr("QR Code...") );
        ui->labelSize_3->clear();
        ui->pButtonSave_3->setEnabled( successfulEncoding );
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

    ui->image_label_3->setPixmap( QPixmap::fromImage( encodeImage ) );

    setScale(ui->sBoxScale_3->value());
    ui->pButtonSave_3->setEnabled( successfulEncoding );
}
void MainWindow::setScale(int scale)
{
    if ( successfulEncoding )
    {
        int scale_size = encodeImageSize * scale;

        const QPixmap & scale_image = ui->image_label_3->pixmap()->scaled( scale_size, scale_size );
        ui->image_label_3->setPixmap( scale_image );

        const QString & size_info = QString( "%1x%2" ).arg( scale_size ).arg( scale_size );
        ui->labelSize_3->setText( size_info );
    }
}
void MainWindow::on_pButtonSave_3_clicked()
{
    const QString & path = QFileDialog::getSaveFileName( this, QString::null, "qrcode", saveFormats() );
    if ( path.isNull() )
        return;

    ui->image_label_3->pixmap()->save( path );
}
void MainWindow::on_sBoxScale_3_valueChanged(int arg1)
{
    setScale( arg1 );
}
void MainWindow::on_pTextEditQRText_3_textChanged()
{
    updateQRImage();
}
void MainWindow::on_pButtonQuit_3_clicked()
{
    close();
}

void MainWindow::closeEvent(QCloseEvent *)
{
    QSettings ini( getIniPath(), QSettings::IniFormat );
    ini.setValue( ui->splitter_5->objectName(), ui->splitter_5->saveState() );
    ini.setValue( ui->splitter_6->objectName(), ui->splitter_6->saveState() );
    ini.setValue( ui->sBoxScale_3->objectName(), ui->sBoxScale_3->value() );
  //  ini.setValue( "State", saveState() );
    ini.setValue( "Geometry", saveGeometry() );

    qApp->quit();
}
bool MainWindow::eventFilter( QObject * object, QEvent * event )
{
    QScrollArea * scrollArea = ui->scrollArea_3;

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
