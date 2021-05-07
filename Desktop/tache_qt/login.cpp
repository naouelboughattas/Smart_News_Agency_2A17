#include "login.h"
#include "ui_login.h"
#include "account.h"
#include "signup.h"

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QLabel>
#include <QPixmap>
#include "journaliste_mission.h"
#include "ui_journaliste_mission.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}




void login::on_loginbutton_clicked()
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
                                                      QObject::tr("\nCONNNECTED SUCCESFULLY !\n"), QMessageBox::Ok);
                   this->hide();
                    journaliste_mission d;
                    //d.exec();
               }
                    else
                       { QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                                    QObject::tr("\nUser Name or Password is incorrect try again !\n"), QMessageBox::Cancel);

              ui->username->clear();
              ui->password->clear();}

      }
      else
      { QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                                  QObject::tr("\n PASSWORD MUST BE BETWEEN \n"
                                              "6 AND 21 CHARACHTERS"), QMessageBox::Cancel); }
  }

  else
     {  QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                  QObject::tr("\n USER NAME MUST BE BETWEEN \n"
                              "4 AND 10 CHARACHTERS"), QMessageBox::Cancel);}
}

else {

                    QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                                QObject::tr("\n PLEASE FILL THE INFO\n"), QMessageBox::Cancel);


}
}



void login::on_signupbutton_2_clicked()
{
    this->close();

}


void login::on_signupbutton_clicked()
{
    signup d;

     d.exec();
}

