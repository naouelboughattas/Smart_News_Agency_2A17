#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "equipement.h"
#include "qmessagebox.h"
#include "qsqlquery.h"
#include<QDebug>
#include"QIntValidator"
#include <QMessageBox>
#include <QComboBox>
#include<QSound>
#include<QFile>
#include<QMediaPlayer>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include<QStackedWidget>
#include<QSqlTableModel>
#include <QTimer>
#include <QDateTime>
#include"exportexcelobjet.h"
#include<QFileDialog>
#include <QPixmap>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QDateTime>
#include <QThread>


double firstNum;
bool user_is_typing_secondNumber=false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clic=new QMediaPlayer();
    clic->setMedia(QUrl("qrc:/new/prefix1/click.mp3"));
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

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


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_p_ajouter_2_clicked()
{clic->play();
    int id_Fournisseur=ui->le_id_2->text().toInt();
    QString nom_Fournisseur=ui->le_nom_2->text();
    QString matricule_fiscale=ui->le_matricule_2->text();
    QString adresse_Fournisseur=ui->le_adresse_2->text();
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


void MainWindow::on_p_ajouterE_2_clicked()
{
    clic->play();
    int id_Equipement=ui->le_ide_2->text().toInt();
    QString libelle=ui->le_libelle_2->text();
    QString description=ui->le_description_2->text();
    QString marque=ui->le_marque_2->text();
    QDate date_acqui=ui->p_ajouterdateacqui_2->date();
    QString prix=ui->le_prix_2->text();
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

void MainWindow::on_afficherE_2_clicked()
{
    clic->play();
    ui->tableView_4->setModel(e->afficher_Equipement());
}


void MainWindow::on_afficherF_2_clicked()
{
    clic->play();
     ui->tableView_3->setModel(f->afficher_Fournisseur());
}

void MainWindow::on_ModifierE_2_clicked()
{
clic->play();
    int idd = ui->mod_idE_2->text().toInt();
    QString prix = ui->mod_prix_2->text();
    QString libelle = ui->mod_libelle_2->text();
    QString marque= ui->mod_marque_2->text();
    QString description= ui->mod_description_2->text();
    QDate date_acqui=ui->mod_dateacqui_2->date();


              equipement e(idd,libelle,description,marque,date_acqui,prix);

                 bool test =e.modifier_Equipement();

                 if(test)

                 {
                     QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                                 QObject::tr("fournisseur modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tableView_3->setModel(f->afficher_Fournisseur());

                 }

                 else

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                                 QObject::tr("Erreur !\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tableView_3->setModel(f->afficher_Fournisseur());

                 }
}

void MainWindow::on_modifierF_2_clicked()
{
clic->play();
    int idd = ui->mod_idF_2->text().toInt();
    QString adresse_Fournisseur = ui->mod_adresse_2->text();
    QString nom_Fournisseur= ui->mod_nom_2->text();
    QString matricule_fiscale=ui->mod_matricule_2->text();


              Fournisseur F(idd,adresse_Fournisseur,nom_Fournisseur,matricule_fiscale);

                 bool test=f->modifier_Fournisseur(idd,adresse_Fournisseur,nom_Fournisseur,matricule_fiscale);

                 if(test)

                 {
                     QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                                 QObject::tr("fournisseur modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tableView_3->setModel(f->afficher_Fournisseur());

                 }

                 else

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                                 QObject::tr("Erreur !\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tableView_3->setModel(f->afficher_Fournisseur());

                 }
}

void MainWindow::on_supprimerF_2_clicked()
{
    clic->play();
    int id = ui->id_supp_2->text().toInt();

        bool test=f->supprimer_Fournisseur(id);
        if(test)
        {
            ui->tableView_3->setModel(f->afficher_Fournisseur());

            QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                        QObject::tr("fournisseur supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_3->setModel(f->afficher_Fournisseur());

}

void MainWindow::on_supprimerE_2_clicked()
{
    clic->play();
    int id = ui->idE_supp_2->text().toInt();

        bool test=e->supprimer_Equipement(id);
        if(test)
        {
            ui->tableView_4->setModel(e->afficher_Equipement());

            QMessageBox::information(nullptr, QObject::tr("Supprimer un équipement"),
                        QObject::tr("équipement supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un équipement"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_4->setModel(e->afficher_Equipement());
}


void MainWindow::on_radioButton_4_clicked()
{
    clic->play();
    ui->tableView_3->setModel( f->trier_id());
}

void MainWindow::on_radioButton_2_clicked()
{
    clic->play();
    ui->tableView_3->setModel( f->trier_nom());
}

void MainWindow::on_radioButton_3_clicked()
{
    clic->play();
    ui->tableView_3->setModel( f->trier_matricule());
}

void MainWindow::on_p_rech_id_2_clicked()
{
    clic->play();
    QString id = ui->rech_id_2->text();
    ui->tableView_4->setModel(e->recherche_id(id));
}

void MainWindow::on_p_rech_libelle_2_clicked()
{
    clic->play();
    QString libelle = ui->rech_libelle_2->text();
    ui->tableView_4->setModel(e->recherche_libelle(libelle));
}

void MainWindow::on_p_rech_marque_2_clicked()
{
    clic->play();
    QString marque = ui->rech_marque_2->text();
    ui->tableView_4->setModel(e->recherche_marque(marque));
}

void MainWindow::on_pdf_2_clicked()
{
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

void MainWindow::on_connexion_clicked()

{
        if(ui->username->text()=="admin" && ui->mdp->text()=="admin")
        {ui->stackedWidget->setCurrentIndex(1);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Login"),
                        QObject::tr("Votre nom d'utilisateur ou mot de passe est erroné."), QMessageBox::Cancel);
}

void MainWindow::on_deconnexion_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->DigitalClock->setText(time_text);
      ui->DigitalClock1->setText(time_text);
        ui->DigitalClock2->setText(time_text);
          //   ui->DigitalClock4->setText(time_text);

}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                  tr("Fichiers d'extension Excel (*.xls)"));
                  if (fileName.isEmpty())
                      return;

                  ExportExcelObject obj(fileName, "mydata", ui->tableView_3);

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
        if(ui->label->text().contains(".") && button->text() == "0")
        {
            input=ui->label->text() + button->text();
        }
        else
        {
            labelnumber = (ui->label->text() + button->text()).toDouble();
            input = QString::number(labelnumber,'g',15);
        }
        //labelnumber = (ui->label->text() + button->text()).toDouble();
    }
    ui->label->setText(input);

}

void MainWindow::on_pushButton_dot_released()
{
    // check for appearance of decimal, exit function if there is one
         if(ui->label->text().contains(".")){

                 return;
         }
    ui->label->setText(ui->label->text() + ".");
    //check for extra decimal
}

void MainWindow::unary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    double labelnumber;
    QString input;

    if(button->text() == "+/-")
    {
        labelnumber = (ui->label->text()).toDouble();
        labelnumber *= -1;
        input = QString::number(labelnumber,'g',15);
        ui->label->setText(input);
    }

    else if(button->text() == "%")
    {
        labelnumber = (ui->label->text()).toDouble();
        labelnumber *= 0.01;
        input = QString::number(labelnumber,'g',15);
        ui->label->setText(input);
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

    ui->label->setText("0");
}

void MainWindow::on_pushButton_equals_released()
{
    double labelnumber,secondNum;
    QString input;
    labelnumber=0;

    secondNum = ui->label->text().toDouble();

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
    ui->label->setText(input);

    user_is_typing_secondNumber=false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    //double labelnumber;
    //QString input;

    firstNum = ui->label->text().toDouble();
    button->setChecked(true);

}
