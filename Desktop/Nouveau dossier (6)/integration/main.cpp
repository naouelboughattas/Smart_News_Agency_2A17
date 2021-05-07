
#include <QApplication>
#include <QWidget>
#include "mainwindow.h"


#include <QMessageBox>
#include "connection.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);



a.setWindowIcon(QIcon(":/img_mus/icone.ico"));



    MainWindow w;
    connection c;
    bool test=c.createConnection();
    if(test)
        //qDebug() <<"Connectionb reussite";
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    //else qDebug() <<"erreur de connection ";




    return a.exec();
}
